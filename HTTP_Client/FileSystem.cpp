//
// Created by sohayla on 20/11/19.
//

#include <sstream>
#include <fstream>
#include <sys/stat.h>
#include <strings.h>
#include "FileSystem.h"

FileSystem::FileSystem(std::string directoy) {
    this->main_dir = directoy;

}


int FileSystem::write(std::string &path, char *dataBytes, int len) {
    /*std::stringstream file_path;
    file_path << main_dir << path;
    FILE* fp = fopen(file_path.str().c_str(), "rb");
    if(fp == NULL){

    }
     int write = static_cast<int>(fwrite(dataBytes, 1, static_cast<size_t>(len), fp));
    fclose(fp);
    return write;*/


    std::stringstream file_path;
    file_path << main_dir << path;
    std::ofstream my_file(file_path.str().c_str(), std::ios::binary);
    my_file.write(dataBytes, len);

   // FILE* fp = fopen(file_path.str().c_str(),"wb+");
   // int sz = len;
 /*   while (len > 0) {
        int written = fwrite(dataBytes, 1, len, fp);
        if(written == -1){
            return -1;
        }
        if(written == 0){
            break;
        }
        len -= written;
        dataBytes += written;

    }
    fclose(fp);*/

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

int FileSystem::read(std::string &path, void *dataBytes, int len) {
    std::ifstream myfile;
    std::stringstream file_path;
    file_path << main_dir << path;
    myfile.open(file_path.str().c_str(),  std::ios::binary);
    myfile.read (static_cast<char *>(dataBytes), len);
    myfile.close();
    return 1;

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

std::string FileSystem::contentType(std::string path) {
    std::string ff;
    if (strcasecmp(path.substr(path.find_last_of(".") + 1).c_str(), "html")
        == 0) {
        ff = "text/html";
    } else if (strcasecmp(path.substr(path.find_last_of(".") + 1).c_str(), "txt")
               == 0) {
        ff = "text/txt";
    } else if (strcasecmp(path.substr(path.find_last_of(".") + 1).c_str(), "css")
               == 0) {
        ff = "text/css";
    } else if (strcasecmp(path.substr(path.find_last_of(".") + 1).c_str(), "js")
               == 0) {
        ff = "text/javascript";
    }else if (strcasecmp(path.substr(path.find_last_of(".") + 1).c_str(), "png")
              == 0) {
        ff = "image/png";
    } else if (strcasecmp(path.substr(path.find_last_of(".") + 1).c_str(), "jpg")
               == 0) {
        ff = "image/jpg";
    } else if (strcasecmp(path.substr(path.find_last_of(".") + 1).c_str(), "jpeg")
               == 0) {
        ff = "image/jpg";
    } else if (strcasecmp(path.substr(path.find_last_of(".") + 1).c_str(), "gif")
               == 0) {
        ff = "image/gif";
    } else {
        ff = "none/none";
    }
    return ff;

}
