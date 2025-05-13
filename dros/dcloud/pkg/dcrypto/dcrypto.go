/*
 * @Author: hawrkchen
 * @Date: 2025-03-10 11:46:03
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 18:52:15
 * @Description:
 * @FilePath: /dcloud/pkg/dcrypto/dcrypto.go
 */
// package dcrypto

package dcrypto

import (
	"crypto/aes"
	"crypto/cipher"
	"crypto/rand"
	"dcloud/global"
	"fmt"
	"io"
	"os"
)

// AesCrypto GCM模式加密
// 密钥长度16byte, 适合G级以下文件加密，如果需要超大文件加密，使用AesGCMStreamEncrypt
func AesGCMEncrypt(fileName string, key []byte) (string, error) {
	file, err := os.Open(fileName)
	if err != nil {
		return "", err
	}
	defer file.Close()

	// 定义加密后的文件名
	outFile, err := os.Create(fileName + ".enc")
	//outFile, err := os.Create(fileName)
	if err != nil {
		return "", err
	}
	defer outFile.Close()

	// 创建AES加密块
	block, err := aes.NewCipher(key)
	if err != nil {
		return "", err
	}

	// 创建GCM模式对象
	gcm, err := cipher.NewGCM(block)
	if err != nil {
		return "", err
	}

	// 生成随机nonce
	nonce := make([]byte, gcm.NonceSize())
	if _, err := io.ReadFull(rand.Reader, nonce); err != nil {
		return "", err
	}
	// nonce 写入到加密文件
	if _, err = outFile.Write(nonce); err != nil {
		return "", err
	}

	// 整体读出 （当文件较大时，可能会有性能瓶颈?
	data, err := io.ReadAll(file)
	if err != nil {
		return "", err
	}
	// 加密数据
	writer := gcm.Seal(nil, nonce, data, nil)
	// 加密数据写入到加密文件
	if _, err = outFile.Write(writer); err != nil {
		return "", err
	}
	return outFile.Name(), nil

}

func AesGCMStreamEncrypt(fileName string, key []byte) error {
	// 打开原始文件
	inFile, err := os.Open(fileName)
	if err != nil {
		return fmt.Errorf("failed to open input file: %w", err)
	}
	defer inFile.Close()

	// 创建输出文件
	outFile, err := os.Create(fileName + ".enc")
	if err != nil {
		return fmt.Errorf("failed to create output file: %w", err)
	}
	defer outFile.Close()

	// 创建AES cipher
	block, err := aes.NewCipher(key)
	if err != nil {
		return fmt.Errorf("failed to create AES cipher: %w", err)
	}

	// 创建GCM模式实例
	gcm, err := cipher.NewGCM(block)
	if err != nil {
		return fmt.Errorf("failed to create GCM: %w", err)
	}

	// 生成随机nonce
	nonce := make([]byte, gcm.NonceSize())
	if _, err := io.ReadFull(rand.Reader, nonce); err != nil {
		return fmt.Errorf("failed to generate nonce: %w", err)
	}

	// 先写入nonce到文件头部
	if _, err := outFile.Write(nonce); err != nil {
		return fmt.Errorf("failed to write nonce: %w", err)
	}

	// 创建加密流
	stream := cipher.NewCTR(block, nonce)
	authenticator := gcm.Seal(nil, nonce, nil, nil) // 初始化认证器

	// 使用缓冲流处理
	buf := make([]byte, global.AES_GCM_bufferSize)
	for {
		n, err := inFile.Read(buf)
		if err != nil && err != io.EOF {
			return fmt.Errorf("read error: %w", err)
		}

		if n > 0 {
			// 加密数据块
			ciphertext := make([]byte, n)
			stream.XORKeyStream(ciphertext, buf[:n])

			// 更新认证数据
			authenticator = gcm.Seal(authenticator[:0], nonce, ciphertext, nil)

			// 写入加密数据
			if _, err := outFile.Write(ciphertext); err != nil {
				return fmt.Errorf("write error: %w", err)
			}
		}

		if err == io.EOF {
			break
		}
	}

	// 写入认证标签到文件尾部
	if _, err := outFile.Write(authenticator[len(authenticator)-gcm.Overhead():]); err != nil {
		return fmt.Errorf("failed to write auth tag: %w", err)
	}

	return nil
}
