/*
 * @Author: hawrkchen
 * @Date: 2025-03-10 15:40:54
 * @LastEditors: Do not edit
 * @LastEditTime: 2025-03-13 09:15:37
 * @Description: 实现文件处理的一些操作
 * @FilePath: /dcloud/pkg/dfile/dfile.go
 */
package dfile

import (
	"archive/tar"
	"compress/gzip"
	"io"
	"os"
	"path/filepath"
)

// 源文件压缩成tar.gz格式
func CompressTarGz(src, dst string) error {

	// 创建tar.gz文件
	dstFile, err := os.Create(dst)
	if err != nil {
		return err
	}
	defer dstFile.Close()

	// 创建gzip writer
	gzipWriter := gzip.NewWriter(dstFile)
	defer gzipWriter.Close()

	// 创建tar writer
	tarWriter := tar.NewWriter(gzipWriter)
	defer tarWriter.Close()

	// 遍历源文件
	return filepath.Walk(src, func(file string, info os.FileInfo, err error) error {
		// 写入tar文件
		return VisitFile(file, info, err, tarWriter, src)
	})

}

func VisitFile(file string, info os.FileInfo, err error, tarWriter *tar.Writer, baseDir string) error {
	if err != nil {
		return err
	}
	// 获取文件相对于baseDir的路径
	relPath, err := filepath.Rel(filepath.Dir(baseDir), file) // 包含父目录结构
	if err != nil {
		return err
	}
	// 创建tar header
	header, err := tar.FileInfoHeader(info, relPath)
	if err != nil {
		return err
	}
	header.Name = relPath
	// 写入tar header
	if err := tarWriter.WriteHeader(header); err != nil {
		return err
	}
	// 写入文件内容
	if info.IsDir() {
		return nil
	}

	fileContent, err := os.Open(file)
	if err != nil {
		return err
	}
	defer fileContent.Close()

	if _, err := io.Copy(tarWriter, fileContent); err != nil {
		return err
	}

	return nil
}

func WriteToFile(FileName string, content []byte) error {
	// 先检查文件存不存在
	_, err := os.Stat(FileName)
	if os.IsExist(err) {
		os.Remove(FileName)
	}
	// 创建文件
	file, err := os.Create(FileName)
	if err != nil {
		return err
	}
	defer file.Close()
	// 写入文件内容
	_, err = file.Write(content)
	if err != nil {
		return err
	}
	return nil
}
