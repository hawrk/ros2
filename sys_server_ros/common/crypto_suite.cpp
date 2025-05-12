/*
 * @Author: hawrkchen
 * @Date: 2024-12-05 15:07:08
 * @Description: 
 * @FilePath: /sys_server_ros/common/crypto_suite.cpp
 */

#include "crypto_suite.hpp"

#include <fstream>
#include <sstream>
#include <iomanip>
#include <openssl/rand.h>
#include <openssl/evp.h>
#include <openssl/aes.h>
#include <openssl/md5.h>
#include <openssl/sha.h>
#include <openssl/des.h>
#include <openssl/rsa.h>
#include <openssl/pem.h>
#include <sys/stat.h>
#include <openssl/err.h>

std::string CryptoSuite::base64_encode(const std::string& input)
{   
    BIO* bio, *b64;
    BUF_MEM* buffer;

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new(BIO_s_mem());
    bio = BIO_push(b64, bio);

    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);  // 去掉换行符
    BIO_write(bio, input.c_str(), input.length());
    BIO_flush(bio);
    BIO_get_mem_ptr(bio, &buffer);

    std::string output(buffer->data, buffer->length);   
    BIO_free_all(bio);
    BUF_MEM_free(buffer);

    return output;

}

std::string CryptoSuite::base64_decode(const std::string& input)
{
    BIO* bio, *b64;
    char* buffer = new char[input.length()];
    memset(buffer, 0, input.length());

    b64 = BIO_new(BIO_f_base64());
    bio = BIO_new_mem_buf((void*)input.c_str(), input.length());
    bio = BIO_push(b64, bio);

    // 启动解密
    BIO_set_flags(bio, BIO_FLAGS_BASE64_NO_NL);  // 去掉换行符
    int decode_len = BIO_read(bio, buffer, input.length());

    std::string output(buffer, decode_len);
    BIO_free_all(bio);
    delete[] buffer;

    return output;
}

std::string CryptoSuite::get_md5_string(const char* data) 
{
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    if (context == nullptr) {
        std::cerr << "Failed to create EVP_MD_CTX" << std::endl;
        return "";
    }

    //unsigned char md5_digest[EVP_MD_size(EVP_md5())];
    unsigned char md5_digest[EVP_MAX_MD_SIZE];
    unsigned int digest_len = 0;

    if (EVP_DigestInit_ex(context, EVP_md5(), nullptr) != 1 ||
        EVP_DigestUpdate(context, data, strlen(data)) != 1 ||
        EVP_DigestFinal_ex(context, md5_digest, &digest_len) != 1) {
        std::cerr << "Failed to compute MD5 digest" << std::endl;
        EVP_MD_CTX_free(context);
        return "";
    }

    EVP_MD_CTX_free(context);

    std::ostringstream oss;
    for (unsigned int i = 0; i < digest_len; i++) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)md5_digest[i];
    }
    return oss.str();
}

std::string CryptoSuite::get_file_md5(const std::string& file_name)
{
    std::ifstream ifs(file_name.c_str(), std::ios::in | std::ios::binary);
    if (!ifs) {
        std::cerr << "Failed to open file: " << file_name << std::endl;
        return "";
    }

    // 初始化EVP MD5上下文
    EVP_MD_CTX* context = EVP_MD_CTX_new();
    if (!context) {
        std::cerr << "Failed to create EVP MD5 context" << std::endl;
        ifs.close();
        return "";
    }

    if (EVP_DigestInit_ex(context, EVP_md5(), nullptr) != 1) {
        std::cerr << "Failed to initialize EVP MD5 context" << std::endl;
        EVP_MD_CTX_free(context);
        ifs.close();
        return "";
    }

    ifs.seekg(0, ifs.end);
    const auto file_size = ifs.tellg();
    ifs.seekg(0, ifs.beg);

    char buffer[1024] = {0};
    unsigned long long total_count = 0;
    decltype(ifs.good()) read_count = 0;

    while (ifs.good()) {
        ifs.read(buffer, sizeof(buffer));
        read_count = ifs.gcount();
        if (read_count > 0) {
            if (EVP_DigestUpdate(context, buffer, read_count) != 1) {
                std::cerr << "Failed to update MD5 digest" << std::endl;
                EVP_MD_CTX_free(context);
                ifs.close();
                return "";
            }
            total_count += read_count;
        }
    }

    ifs.close();

    if (total_count != (unsigned long long)file_size) {
        std::cerr << "Failed to read file: " << file_name << std::endl;
        EVP_MD_CTX_free(context);
        return "";
    }

    unsigned char md5_digest[EVP_MAX_MD_SIZE] = {0};
    unsigned int md5_digest_len = 0;
    if (EVP_DigestFinal_ex(context, md5_digest, &md5_digest_len) != 1) {
        std::cerr << "Failed to finalize MD5 digest" << std::endl;
        EVP_MD_CTX_free(context);
        return "";
    }

    EVP_MD_CTX_free(context);

    std::ostringstream oss;
    for (unsigned int i = 0; i < md5_digest_len; i++) {
        oss << std::hex << std::setw(2) << std::setfill('0') << (int)md5_digest[i];
    }
    return oss.str();
}


void CryptoSuite::get_sha256_string(const char* data,std::string& out) 
{
    unsigned char sha256_digest[33] = {0};
    SHA256((unsigned char*)data, strlen(data), sha256_digest);

    char buf[65] = {0};
    char tmp[3] = {0};
    for (int i = 0; i < 32; i++) {
        sprintf(tmp, "%02x", sha256_digest[i]);
        strcat(buf, tmp);
    }
    buf[32] = '\0';
    out = std::string(buf);
}

std::string CryptoSuite::aes_encrypt(const std::string& plain_text, const std::string& key)
{
    if(key.length() != 16) {
        std::cerr << "AES key length should be 16 bytes" << std::endl;
        return "";
    }
    // 生成随机16字节IV
    std::vector<unsigned char> iv(16, 0);
    RAND_bytes(iv.data(), iv.size());

    // 初始化上下文
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if(ctx == nullptr) {
        std::cerr << "Failed to create cipher context" << std::endl;
        return "";
    }

    // 设置加密算法为AES-128-CBC
    const EVP_CIPHER* cipher = EVP_aes_128_cbc();
    if(cipher == nullptr) {
        std::cerr << "Failed to create cipher" << std::endl;
        return "";
    }

    // 设置密钥和IV
    int ret = EVP_EncryptInit_ex(ctx, cipher, nullptr, (const unsigned char*)key.c_str(), (const unsigned char*)iv.data());
    if(ret != 1) {
        std::cerr << "Failed to initialize cipher context" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }
    // 加密
    int outlen = 0;
    int ciphertext_len;
    std::vector<unsigned char> cipher_vec(plain_text.length() + AES_BLOCK_SIZE, 0);
    ret = EVP_EncryptUpdate(ctx, cipher_vec.data(), &outlen, (const unsigned char*)plain_text.c_str(), plain_text.length());
    if(ret != 1) {
        std::cerr << "Failed to encrypt data" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }
    ciphertext_len = outlen;

    //完成加密
    ret = EVP_EncryptFinal_ex(ctx, cipher_vec.data() + outlen, &outlen);
    if(ret != 1) {  
        std::cerr << "Failed to finalize encryption" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }
    ciphertext_len += outlen;

    // 释放上下文
    EVP_CIPHER_CTX_free(ctx);

    // 合并IV和密文
    std::string cipher_text(iv.begin(), iv.end());
    cipher_text.append((char*)cipher_vec.data(), ciphertext_len);

    return cipher_text;

}

std::string CryptoSuite::aes_decrypt(const std::string& cipher_text, const std::string& key)
{
    if(key.length() != 16) {
        std::cerr << "AES key length should be 16 bytes" << std::endl;
        return "";
    }
    if(cipher_text.length() < 16) {
        std::cerr << "Cipher text length should be greater than 16 bytes" << std::endl;
        return "";
    }
    // 获取IV
    std::vector<unsigned char> iv(cipher_text.begin(), cipher_text.begin() + 16);
    std::string encrypted_text(cipher_text.begin() + 16, cipher_text.end());   // 截取密文
    // 初始化上下文
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if(ctx == nullptr) {
        std::cerr << "Failed to create cipher context" << std::endl;
        return "";
    }
   // 设置加密算法为AES-128-CBC
    const EVP_CIPHER* cipher = EVP_aes_128_cbc();
    if(cipher == nullptr) {
        std::cerr << "Failed to create cipher" << std::endl;
        return "";
    }
    // 设置密钥和IV
    int ret = EVP_DecryptInit_ex(ctx, cipher, nullptr, (const unsigned char*)key.c_str(), (const unsigned char*)iv.data());
    if(ret != 1) {
        std::cerr << "Failed to initialize cipher context" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }
    // 解密
    int outlen = 0;
    int plaintext_len;
    std::vector<unsigned char> plain_vec(encrypted_text.length(), 0);
    // 解密数据
    ret = EVP_DecryptUpdate(ctx, plain_vec.data(), &outlen, (const unsigned char*)encrypted_text.c_str(), encrypted_text.length());
    if(ret != 1) {
        std::cerr << "Failed to decrypt data" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }
    plaintext_len = outlen;
    // 完成解密
    ret = EVP_DecryptFinal_ex(ctx, plain_vec.data() + outlen, &outlen);
    if(ret != 1) {
        std::cerr << "Failed to finalize decryption" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return "";
    }
    plaintext_len += outlen;
    // 释放上下文
    EVP_CIPHER_CTX_free(ctx);
    // 转换为字符串
    std::string plain_text((char*)plain_vec.data(), plaintext_len);
    return plain_text;  

}

std::tuple<std::string, std::string> CryptoSuite::generate_key_pair()
{
      // 创建一个 EVP_PKEY 对象
    EVP_PKEY_CTX* pctx = EVP_PKEY_CTX_new_id(EVP_PKEY_RSA, nullptr);
    if (!pctx) {
        std::cerr << "Failed to create EVP_PKEY_CTX" << std::endl;
        return std::make_tuple("", "");
    }

    // 初始化密钥生成过程
    if (EVP_PKEY_keygen_init(pctx) <= 0) {
        std::cerr << "Failed to initialize key generation" << std::endl;
        EVP_PKEY_CTX_free(pctx);
        return std::make_tuple("", "");
    }

    // 设置 RSA 密钥长度
    if (EVP_PKEY_CTX_set_rsa_keygen_bits(pctx, 2048) <= 0) {
        std::cerr << "Failed to set RSA key size" << std::endl;
        EVP_PKEY_CTX_free(pctx);
        return std::make_tuple("", "");
    }

    // 生成 RSA 密钥对
    EVP_PKEY* pkey = nullptr;
    if (EVP_PKEY_keygen(pctx, &pkey) <= 0) {
        std::cerr << "Failed to generate RSA key pair" << std::endl;
        EVP_PKEY_CTX_free(pctx);
        return std::make_tuple("", "");
    }

    // 获取私钥
    BIO* private_key_bio = BIO_new(BIO_s_mem());
    PEM_write_bio_PrivateKey(private_key_bio, pkey, nullptr, nullptr, 0, nullptr, nullptr);
    char* private_key_str = nullptr;
    long private_key_len = BIO_get_mem_data(private_key_bio, &private_key_str);
    std::string private_key(private_key_str, private_key_len);

    // 获取公钥
    BIO* public_key_bio = BIO_new(BIO_s_mem());
    PEM_write_bio_PUBKEY(public_key_bio, pkey);
    char* public_key_str = nullptr;
    long public_key_len = BIO_get_mem_data(public_key_bio, &public_key_str);
    std::string public_key(public_key_str, public_key_len);

    // 释放资源
    BIO_free_all(private_key_bio);
    BIO_free_all(public_key_bio);
    EVP_PKEY_free(pkey);
    EVP_PKEY_CTX_free(pctx);

    return std::make_tuple(private_key, public_key);

}

std::string CryptoSuite::rsa_signature_data(const std::string& data, const std::string& private_key)
{
    // 加载私钥
    BIO* private_key_bio = BIO_new_mem_buf((void*)private_key.c_str(), private_key.length());
    EVP_PKEY* pkey = PEM_read_bio_PrivateKey(private_key_bio, nullptr, nullptr, nullptr);
    if (!pkey) {
        std::cerr << "Failed to load private key" << std::endl;
        BIO_free_all(private_key_bio);
        return "";
    }

    // 创建EVP_MD_CTX
    EVP_MD_CTX* ctx = EVP_MD_CTX_new();
    if (!ctx) {
        std::cerr << "Failed to create EVP_MD_CTX" << std::endl;
        EVP_PKEY_free(pkey);
        BIO_free_all(private_key_bio);
        return "";
    }

    // 初始化签名操作
    if (EVP_DigestSignInit(ctx, nullptr, EVP_sha256(), nullptr, pkey) <= 0) {
        std::cerr << "Failed to initialize signing operation" << std::endl;
        EVP_MD_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        BIO_free_all(private_key_bio);
        return "";
    }

    // 更新要签名的数据
    if (EVP_DigestSignUpdate(ctx, data.c_str(), data.length()) <= 0) {
        std::cerr << "Failed to update signing data" << std::endl;
        EVP_MD_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        BIO_free_all(private_key_bio);
        return "";
    }

    // 获取签名长度
    size_t signature_len;
    if (EVP_DigestSignFinal(ctx, nullptr, &signature_len) <= 0) {
        std::cerr << "Failed to get signature length" << std::endl;
        EVP_MD_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        BIO_free_all(private_key_bio);
        return "";
    }

    // 分配签名缓冲区
    unsigned char* signature = new unsigned char[signature_len];

    // 生成签名
    if (EVP_DigestSignFinal(ctx, signature, &signature_len) <= 0) {
        std::cerr << "Failed to generate signature" << std::endl;
        delete[] signature;
        EVP_MD_CTX_free(ctx);
        EVP_PKEY_free(pkey);
        BIO_free_all(private_key_bio);
        return "";
    }

    // 将签名转换为字符串
    std::string signatureResult((char*)signature, signature_len);

    // 释放资源
    delete[] signature;
    EVP_MD_CTX_free(ctx);
    EVP_PKEY_free(pkey);
    BIO_free_all(private_key_bio);

    return signatureResult;
}

bool CryptoSuite::rsa_verify_signature(const std::string& data, const std::string& signature, 
    const std::string& public_key)
{
       // 使用智能指针管理资源
    std::unique_ptr<BIO, decltype(&BIO_free_all)> public_key_bio(
        BIO_new_mem_buf(public_key.data(), public_key.length()), 
        BIO_free_all
    );
    if (!public_key_bio) {
        std::cerr << "Failed to create BIO for public key" << std::endl;
        return false;
    }

    // 使用 EVP_PKEY 代替 RSA
    std::unique_ptr<EVP_PKEY, decltype(&EVP_PKEY_free)> pkey(
        PEM_read_bio_PUBKEY(public_key_bio.get(), nullptr, nullptr, nullptr), 
        EVP_PKEY_free
    );
    if (!pkey) {
        std::cerr << "Failed to load public key" << std::endl;
        return false;
    }

    // 创建 EVP_MD_CTX 用于验证
    std::unique_ptr<EVP_MD_CTX, decltype(&EVP_MD_CTX_free)> ctx(EVP_MD_CTX_new(), EVP_MD_CTX_free);
    if (!ctx) {
        std::cerr << "Failed to create EVP_MD_CTX" << std::endl;
        return false;
    }

    // 初始化验证操作
    if (EVP_DigestVerifyInit(ctx.get(), nullptr, EVP_sha256(), nullptr, pkey.get()) <= 0) {
        std::cerr << "Failed to initialize verification" << std::endl;
        return false;
    }

    // 更新验证数据
    if (EVP_DigestVerifyUpdate(ctx.get(), data.data(), data.size()) <= 0) {
        std::cerr << "Failed to update verification data" << std::endl;
        return false;
    }

    // 验证签名
    int result = EVP_DigestVerifyFinal(ctx.get(), 
        reinterpret_cast<const unsigned char*>(signature.data()), signature.size());
    if (result != 1) {
        std::cerr << "Failed to verify signature" << std::endl;
        return false;
    }

    return true;

}

bool CryptoSuite::aes_gcm_decrypt(const std::string& fileName, std::string& outFileName,const std::vector<unsigned char>& key) {
    // 打开加密文件
    std::ifstream inFile(fileName, std::ios::binary);
    if (!inFile.is_open()) {
        ERR_print_errors_fp(stderr);
        return false;
    }

    // 读取全部加密内容
    std::vector<unsigned char> ciphertext(
        (std::istreambuf_iterator<char>(inFile)),
        std::istreambuf_iterator<char>()
    );
    inFile.close();

    // 验证最小文件尺寸：nonce(12) + 最小加密数据(1) + 标签(16)
    if (ciphertext.size() < 12 + 1 + 16) {
        std::cerr << "File too small to be valid" << std::endl;
        return false;
    }

    // 分离nonce和加密数据
    std::vector<unsigned char> nonce(ciphertext.begin(), ciphertext.begin() + 12);
    std::vector<unsigned char> encryptedData(ciphertext.begin() + 12, ciphertext.end());

    // 验证密钥长度
    const EVP_CIPHER* cipher = nullptr;
    switch (key.size()) {
        case 16: cipher = EVP_aes_128_gcm(); break;
        case 24: cipher = EVP_aes_192_gcm(); break;
        case 32: cipher = EVP_aes_256_gcm(); break;
        default:
            std::cerr << "Invalid key length: " << key.size() << " bytes" << std::endl;
            return false;
    }

    // 创建解密上下文
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        ERR_print_errors_fp(stderr);
        return false;
    }

    // 初始化解密操作
    if (1 != EVP_DecryptInit_ex(ctx, cipher, nullptr, key.data(), nonce.data())) {
        ERR_print_errors_fp(stderr);
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    // 分离加密数据和认证标签
    size_t ciphertext_len = encryptedData.size() - 16;
    std::vector<unsigned char> tag(encryptedData.end() - 16, encryptedData.end());
    std::vector<unsigned char> actualCiphertext(encryptedData.begin(), encryptedData.end() - 16);

    // 设置认证标签
    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, 16, tag.data())) {
        ERR_print_errors_fp(stderr);
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    // 解密数据
    std::vector<unsigned char> plaintext(ciphertext_len + EVP_MAX_BLOCK_LENGTH);
    int len, plaintext_len = 0;
    
    if (1 != EVP_DecryptUpdate(ctx, plaintext.data(), &len, actualCiphertext.data(), ciphertext_len)) {
        ERR_print_errors_fp(stderr);
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }
    plaintext_len = len;

    // 验证认证标签
    if (1 != EVP_DecryptFinal_ex(ctx, plaintext.data() + plaintext_len, &len)) {
        std::cerr << "Decryption failed" << std::endl;
        ERR_print_errors_fp(stderr);
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }
    plaintext_len += len;

    // 清理上下文
    EVP_CIPHER_CTX_free(ctx);

    // 生成输出文件名（移除.enc扩展名）
    size_t extPos = fileName.rfind(".enc");
    if (extPos == std::string::npos) {
        std::cerr << "Invalid encrypted file extension" << std::endl;
        return false;
    }

    outFileName = fileName.substr(0, extPos);
    // 写入解密数据
    std::ofstream outFile(outFileName, std::ios::binary);
    if (!outFile.is_open()) {
        std::cerr << "Cannot create output file" << std::endl;
        return false;
    }
    outFile.write(reinterpret_cast<const char*>(plaintext.data()), plaintext_len);
    outFile.close();

    return true;
}


bool CryptoSuite::aes_gcm_stream_decrypt(const std::string& input_file, std::string& output_file, const std::vector<unsigned char>& key) {
    // 打开加密文件
    std::ifstream inFile(input_file, std::ios::binary);
    if (!inFile) {
        std::cerr << "无法打开输入文件" << std::endl;
        return false;
    }

    // 获取文件大小
    struct stat st;
    if (stat(input_file.c_str(), &st) != 0) {
        std::cerr << "无法获取文件大小" << std::endl;
        return false;
    }
    const size_t fileSize = st.st_size;

    // 验证最小文件尺寸
    if (fileSize < 12 + 16 + 1) { // nonce(12) + tag(16) + min data(1)
        std::cerr << "文件尺寸无效" << std::endl;
        return false;
    }

    // 读取nonce（前12字节）
    unsigned char nonce[12];
    if (!inFile.read(reinterpret_cast<char*>(nonce), 12)) {
        std::cerr << "读取nonce失败" << std::endl;
        return false;
    }

    // 准备输出文件名
    size_t extPos = input_file.rfind(".enc");
    if (extPos == std::string::npos) {
        std::cerr << "无效的文件扩展名" << std::endl;
        return false;
    }
    output_file = input_file.substr(0, extPos);

    // 创建临时输出文件
    std::string tempFile = output_file + ".tmp";
    std::ofstream outFile(tempFile, std::ios::binary);
    if (!outFile) {
        std::cerr << "无法创建输出文件" << std::endl;
        return false;
    }

    // 初始化OpenSSL上下文
    EVP_CIPHER_CTX* ctx = EVP_CIPHER_CTX_new();
    if (!ctx) {
        std::cerr << "无法创建加密上下文" << std::endl;
        return false;
    }

    // 根据密钥长度选择算法
    const EVP_CIPHER* cipher = nullptr;
    switch (key.size()) {
        case 16: cipher = EVP_aes_128_gcm(); break;
        case 24: cipher = EVP_aes_192_gcm(); break;
        case 32: cipher = EVP_aes_256_gcm(); break;
        default:
            std::cerr << "无效的密钥长度: " << key.size() << std::endl;
            EVP_CIPHER_CTX_free(ctx);
            return false;
    }

    // 初始化解密操作
    if (1 != EVP_DecryptInit_ex(ctx, cipher, nullptr, key.data(), nonce)) {
        std::cerr << "初始化解密失败" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    // 计算加密数据长度（总长度 - nonce - tag）
    const size_t encryptedDataSize = fileSize - 12 - 16;
    size_t remaining = encryptedDataSize;

    // 流式解密缓冲区
    std::vector<unsigned char> inBuf(CHUNK_SIZE);
    std::vector<unsigned char> outBuf(CHUNK_SIZE + EVP_MAX_BLOCK_LENGTH);

    // 分块处理加密数据
    while (remaining > 0) {
        const size_t readSize = std::min(remaining, CHUNK_SIZE);
        if (!inFile.read(reinterpret_cast<char*>(inBuf.data()), readSize)) {
            std::cerr << "读取加密数据失败" << std::endl;
            EVP_CIPHER_CTX_free(ctx);
            return false;
        }

        int outLen = 0;
        if (1 != EVP_DecryptUpdate(ctx, outBuf.data(), &outLen, inBuf.data(), readSize)) {
            std::cerr << "解密数据块失败" << std::endl;
            EVP_CIPHER_CTX_free(ctx);
            return false;
        }

        if (!outFile.write(reinterpret_cast<char*>(outBuf.data()), outLen)) {
            std::cerr << "写入解密数据失败" << std::endl;
            EVP_CIPHER_CTX_free(ctx);
            return false;
        }

        remaining -= readSize;
    }

    // 读取认证标签（最后16字节）
    unsigned char tag[16];
    if (!inFile.read(reinterpret_cast<char*>(tag), 16)) {
        std::cerr << "读取认证标签失败" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    // 设置认证标签
    if (1 != EVP_CIPHER_CTX_ctrl(ctx, EVP_CTRL_GCM_SET_TAG, 16, tag)) {
        std::cerr << "设置认证标签失败" << std::endl;
        EVP_CIPHER_CTX_free(ctx);
        return false;
    }

    // 验证认证标签
    int finalLen = 0;
    const int ret = EVP_DecryptFinal_ex(ctx, outBuf.data(), &finalLen);

    // 清理上下文
    EVP_CIPHER_CTX_free(ctx);

    // 验证失败处理
    if (ret <= 0) {
        std::cerr << "认证失败！数据可能被篡改" << std::endl;
        outFile.close();
        remove(tempFile.c_str());
        return false;
    }

    // 写入最后的数据（如果有）
    if (finalLen > 0) {
        if (!outFile.write(reinterpret_cast<char*>(outBuf.data()), finalLen)) {
            std::cerr << "写入最终数据失败" << std::endl;
            outFile.close();
            remove(tempFile.c_str());
            return false;
        }
    }

    // 关闭文件流
    inFile.close();
    outFile.close();

    // 重命名临时文件
    if (rename(tempFile.c_str(), output_file.c_str()) != 0) {
        std::cerr << "重命名文件失败" << std::endl;
        remove(tempFile.c_str());
        return false;
    }

    return true;
}
