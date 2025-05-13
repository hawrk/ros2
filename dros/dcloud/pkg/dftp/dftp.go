/*
 * @Author: hawrkchen
 * @Date: 2025-03-12 15:36:39
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-25 18:47:58
 * @Description:
 * @FilePath: /dcloud/pkg/dftp/dftp.go
 */
package dftp

import (
	"dcloud/global"
	"fmt"
	"os"
	"time"

	"github.com/jlaffaye/ftp"
)

// UploadFileToFTP 上传文件到FTP服务器
func UploadFileToFTP(dstPath, encFilePath, url string) error {
	// 连接FTP服务器
	conn, err := ftp.Dial(url, ftp.DialWithTimeout(5*time.Second))
	if err != nil {
		fmt.Println("Error connecting to FTP server:", err.Error())
		return err
	}
	defer conn.Quit()

	// 匿名登录FTP服务器
	err = conn.Login(global.FTP_USER, global.FTP_PASSWD)
	if err != nil {
		fmt.Println("Error logging in to FTP server:", err.Error())
		return err
	}
	// 打开要上传的文件
	file, err := os.Open(encFilePath)
	if err != nil {
		fmt.Println("Error opening file:", err.Error())
		return err
	}
	defer file.Close()

	// 上传文件到FTP服务器
	// 注意这里的目标路径文件和本地上传的文件
	// 如果ftp默认的路径是 /home/ftpuser/,需要放在app_dir下，则dstPath为 app_dir/xxx.tar.gz.enc
	// encFilePath 则为本地要上传的绝对路径
	//fmt.Println("dstPath:", dstPath, "encFilePath:", encFilePath)
	err = conn.Stor(dstPath, file)
	if err != nil {
		fmt.Println("Error uploading file:", err.Error())
		return err
	}

	fmt.Println("File uploaded successfully")
	return nil

}

// CheckFileExist 检查文件是否存在于FTP服务器
func CheckFileExist(filePath string, url string) (bool, error) {
	// 连接FTP服务器
	conn, err := ftp.Dial(url, ftp.DialWithTimeout(5*time.Second))
	if err != nil {
		fmt.Println("Error connecting to FTP server:", err.Error())
		return false, err
	}
	defer conn.Quit()

	// 匿名登录FTP服务器
	err = conn.Login(global.FTP_USER, global.FTP_PASSWD)
	if err != nil {
		fmt.Println("Error logging in to FTP server:", err.Error())
		return false, err
	}

	// 检查文件是否存在
	entries, err := conn.List(filePath)
	if err != nil {
		fmt.Println("Error listing file:", err.Error())
		return false, err
	}
	if len(entries) == 0 {
		return false, nil
	}
	// 检查是否存在与filePath匹配的条目
	for _, entry := range entries {
		if entry.Name == filePath { // 匹配到，直接返回
			return true, nil
		}
	}
	return false, nil
}
