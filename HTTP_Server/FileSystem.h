//
// Created by sohayla on 19/11/19.
//

#ifndef HTTP_SERVER_FILESYSTEM_H
#define HTTP_SERVER_FILESYSTEM_H


#include <string>

class FileSystem {
private:
    std::string main_dir;


public:
    FileSystem(std::string directoy);
    bool file_exists(std::string path);
    time_t last_modified(std::string path);
    int read(std::string& path, void* dataBytes, int len);
    int write(std::string& path, void* dataBytes, int len);
    int file_size(std::string path);


};


#endif //HTTP_SERVER_FILESYSTEM_H
