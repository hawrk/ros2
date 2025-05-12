/*
 * @Author: hawrkchen
 * @Date: 2024-12-10 14:48:52
 * @Description: 
 * @FilePath: /sys_server/common/file_sys.cpp
 */

#include "file_sys.hpp"

#include <string.h>

namespace fs = std::filesystem;

bool FileSys::decompress_gzip(const std::string& gzip_file, const std::string& output_file)
{
    gzFile inFile = gzopen(gzip_file.c_str(), "rb");
    if(!inFile) {
        std::cerr << "Failed to open file: " << gzip_file << std::endl;
        return false;
    }

    FILE* outFile = fopen(output_file.c_str(), "wb");
    if(!outFile) {
        std::cerr << "Failed to create file: " << output_file << std::endl;
        gzclose(inFile);
        return false;
    }

    char buffer[4096];
    int bytes_read;
    while((bytes_read = gzread(inFile, buffer, sizeof(buffer))) > 0) {
        fwrite(buffer, 1, bytes_read, outFile);
    }

    gzclose(inFile);
    fclose(outFile);

    return true;
}

bool FileSys::extract_tar_gz_v2(const std::string& tarGzFilePath, const std::string& destinationDir) {
    struct archive *a;
    struct archive_entry *entry;
    int r;

    a = archive_read_new();
    archive_read_support_format_tar(a);
    archive_read_support_filter_gzip(a);

    r = archive_read_open_filename(a, tarGzFilePath.c_str(), 10240);
    if (r != ARCHIVE_OK) {
        std::cerr << "Failed to open archive: " << archive_error_string(a) << std::endl;
        archive_read_free(a);
        return false;
    }

    while (archive_read_next_header(a, &entry) == ARCHIVE_OK) {
        const char *entryPath = archive_entry_pathname(entry);
        fs::path absFilePath = fs::path(destinationDir) / entryPath;

        // 处理目录
        if (archive_entry_filetype(entry) == AE_IFDIR) {
            fs::create_directories(absFilePath);
        }
        // 处理普通文件
        else if (archive_entry_filetype(entry) == AE_IFREG) {
            fs::create_directories(absFilePath.parent_path());
            std::ofstream ofs(absFilePath, std::ios::binary);
            if (!ofs) {
                std::cerr << "Failed to open file for writing: " << absFilePath << std::endl;
                archive_read_free(a);
                return false;
            }

            const void *buffer;
            size_t size;
            la_int64_t offset;

            while (archive_read_data_block(a, &buffer, &size, &offset) == ARCHIVE_OK) {
                ofs.write(static_cast<const char*>(buffer), size);
            }

            // 设置文件权限
            std::error_code ec;
            fs::permissions(absFilePath,
                static_cast<fs::perms>(archive_entry_perm(entry)), ec);
            if (ec) {
                std::cerr << "Failed to set file permissions: " << ec.message() << std::endl;
            }
            
            // 设置文件最后修改时间
            //time_t mtime = archive_entry_mtime(entry);
            //fs::last_write_time(absFilePath,ec);
            //if (ec) {
               // std::cerr << "Failed to set file mtime: " << ec.message() << std::endl;
            //}
        }
        // 处理符号链接
        else if (archive_entry_filetype(entry) == AE_IFLNK) {
            const char* target = archive_entry_symlink(entry);
            if (!target) {
                std::cerr << "Failed to get symlink target for: " << entryPath << std::endl;
            } else {
                fs::create_directories(absFilePath.parent_path());
                fs::create_symlink(target, absFilePath);
            }
        }

        archive_read_data_skip(a);
    }

    r = archive_read_close(a);
    if (r != ARCHIVE_OK) {
        std::cerr << "Failed to close archive: " << archive_error_string(a) << std::endl;
    }

    archive_read_free(a);
    return true;
}

void FileSys::scan_directory(const std::string& dir_path) 
{
    for(const auto& entry : std::filesystem::directory_iterator(dir_path)) {
        if(entry.is_directory()) {
            std::cout << "Directory: " << entry.path() << std::endl;
        } else if(entry.is_regular_file()) {
            std::cout << "File: " << entry.path() << std::endl;
        }
    }
}

void FileSys::copy_file(const std::string& src_file, const std::string& dst_file) 
{
    std::filesystem::copy(src_file, dst_file, std::filesystem::copy_options::overwrite_existing);
}

void FileSys::copy_directory(const std::string& src_dir, const std::string& dst_dir) 
{
    std::filesystem::copy(src_dir, dst_dir, std::filesystem::copy_options::recursive|
        std::filesystem::copy_options::overwrite_existing);
}


std::string FileSys::get_absolute_path() {
    return std::filesystem::current_path().string();
}