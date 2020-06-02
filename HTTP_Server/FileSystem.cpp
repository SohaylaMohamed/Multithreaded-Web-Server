//
// Created by sohayla on 19/11/19.
//

#include <sys/stat.h>
#include <sstream>
#include <fstream>
#include "FileSystem.h"
FileSystem::FileSystem(std::string directoy) {
    this->main_dir = directoy;
}

bool FileSystem::file_exists(std::string path) {
    std::stringstream file_path;
    file_path << main_dir << path;
    //printf(file_path.str().c_str());
    std::ifstream f(file_path.str().c_str());
    bool good = f.good();
    f.close();
    struct stat attr;
    stat(file_path.str().c_str(), &attr);
    return good && (attr.st_mode & S_IFREG);
}


time_t FileSystem::last_modified(std::string path) {
    std::stringstream file_path;
    file_path << main_dir << path;
    struct stat attr;
    stat(file_path.str().c_str(), &attr);
    return attr.st_mtim.tv_sec;
}

int FileSystem::file_size(std::string path) {
    std::stringstream file_path;
    file_path << main_dir << path;
    std::ifstream f(file_path.str().c_str());
    f.seekg(0, f.end);
    int length = static_cast<int>(f.tellg());
    f.close();
    return length;
}

int FileSystem::read(std::string &path, void *dataBytes, int len) {
    std::ifstream myfile;
    std::stringstream file_path;
    file_path << main_dir << path;
    myfile.open(file_path.str().c_str(),  std::ios::binary);
    myfile.read (static_cast<char *>(dataBytes), len);
    //dataBytes = myfile.rdbuf();
   // FILE* fp = fopen(file_path.str().c_str(), "rb");
 //   int read = static_cast<int>(fread(dataBytes, 1, static_cast<size_t>(len), fp));
 //   fclose(fp);
   myfile.close();
    return 1;

}

int FileSystem::write(std::string &path, void *dataBytes, int len) {
    std::stringstream file_path;
    file_path << main_dir << path;
    std::ofstream my_file(file_path.str().c_str(), std::ios::binary);
    my_file.write(static_cast<const char *>(dataBytes), len);
    my_file.close();
    return 1;
}
