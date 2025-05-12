/*
 * @Author: hawrkchen
 * @Date: 2024-12-10 09:25:22
 * @Description: 
 * @FilePath: /sys_server/common/file_sys.hpp
 */
#pragma once

#include <sys/stat.h>
#include <string>
#include <iostream>
#include <fstream>  
#include "unistd.h"
#include "zlib.h"
#include <filesystem>

#include <archive.h>
#include <archive_entry.h>


class FileSys {
    public: 
        FileSys() = default;
        ~FileSys() = default;   

        static bool decompress_gzip(const std::string& gzip_file, const std::string& output_file);

        // 依赖 libz, libarchive 库
        /*
        * @param gz_filename: .tar.gz压缩文件名
        * @param output_dir: 解压输出目录
        * @return: 无
        */
        static bool extract_tar_gz_v2(const std::string& tarGzFilePath, const std::string& destinationDir);


        /*
        *@param dir_path: 待扫描目录路径
        *@return: 无
        */
        static void scan_directory(const std::string& dir_path); 

        /*
        *@param src_file: 源文件路径
        *@param dst_file: 目标文件路径
        *@return: 无
        */
        static void copy_file(const std::string& src_file, const std::string& dst_file); 


        /*
        *@param src_dir: 源目录路径
        *@param dst_dir: 目标目录路径
        *@return: 无
        */
        static void copy_directory(const std::string& src_dir, const std::string& dst_dir);

        // 获取当前目录绝对路径
        static std::string get_absolute_path();
};
