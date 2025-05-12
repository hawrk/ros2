/*
 * @Author: hawrkchen
 * @Date: 2024-12-05 15:07:00
 * @Description: 加解密，完整性校验，数字签名等
 * @FilePath: /sys_server_ros/common/crypto_suite.hpp
 */

#pragma once

#include <string>
#include <cstring>
#include <vector>
#include <iostream>
#include <tuple>

constexpr const size_t CHUNK_SIZE = 8*1024*1024; // 8MB chunks for aes GCM encryption


class CryptoSuite {
    public:
        CryptoSuite(const CryptoSuite&) = delete;
        CryptoSuite& operator=(const CryptoSuite&) = delete;

        static CryptoSuite& get_instance() {
            static CryptoSuite instance;
            return instance;
        }
        

    private:
        CryptoSuite()  = default;
        virtual ~CryptoSuite() = default;

    public:

        // base64编码
        std::string base64_encode(const std::string& input);

        std::string base64_decode(const std::string& input);

        std::string get_md5_string(const char* data);

        std::string get_file_md5(const std::string& file_name);

        void get_sha256_string(const char* data,std::string& out);
        
        // cbc模式 128位密钥 16字节iv pkcs7 padding
        std::string aes_encrypt(const std::string& plain_text, const std::string& key);

        std::string aes_decrypt(const std::string& cipher_text, const std::string& key);

        // 完整性校验
        // 生成公私钥key
        std::tuple<std::string, std::string> generate_key_pair();

        // 生成签名
        std::string rsa_signature_data(const std::string& data, const std::string& private_key);

        // 验证签名
        bool rsa_verify_signature(const std::string& data, const std::string& signature, const std::string& public_key);

        // AES GCM模式 加密 
        // 适用于G级以下文件，如果是超大文件，使用AesStreamDecrypt
        bool aes_gcm_decrypt(const std::string& fileName, std::string& outFileName,const std::vector<unsigned char>& key);

        // 流方式解密，防止文件过大导致内存不足
        bool aes_gcm_stream_decrypt(const std::string& input_file, std::string& output_file, const std::vector<unsigned char>& key);

};


static CryptoSuite& g_crypto_suite  = CryptoSuite::get_instance();


