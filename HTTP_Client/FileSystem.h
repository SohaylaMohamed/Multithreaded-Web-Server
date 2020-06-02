//
// Created by sohayla on 20/11/19.
//

#ifndef HTTP_CLIENT_FILESYSTEM_H
#define HTTP_CLIENT_FILESYSTEM_H


#include <string>
#include <vector>
#include "Request.h"

class FileSystem {
private:
    std::string main_dir;

public:
    FileSystem(std::string directoy);
    bool file_exists(std::string path);
    int read(std::string& path, void* dataBytes, int len);
    int write(std::string& path, char * dataBytes, int len);
    int file_size(std::string path);
    std::vector<Request*> getRequests(std::string path);
    std::string contentType(std::string path);
};


#endif //HTTP_CLIENT_FILESYSTEM_H
