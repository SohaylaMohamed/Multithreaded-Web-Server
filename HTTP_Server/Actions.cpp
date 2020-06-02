//
// Created by sohayla on 19/11/19.
//

#include <cstring>
#include <sys/socket.h>
#include "Actions.h"
Actions::Actions(int max_line, std::string main_dir) {
    MAX_LINE = max_line;
    p = new Parser(main_dir, new FileSystem(main_dir));
}
int Actions::send_response(int client_fd, char *message, int size) {
    char *ptr = message;
    int length = size;
    printf(message);
    while (length > 0) {
        int i = send(client_fd, ptr, length, 0);
        if (i < 0)
            return -1;
        if (i == 0)
            break;
        ptr += i;
        length -= i;
    }
    return size;
}
std::string Actions::recieve_req(int fd) {
    char *buffer = new char [MAX_LINE]();
    memset(buffer, '\0', MAX_LINE);

    int len_recv = recv(fd, buffer, MAX_LINE, 0);
    printf(std::string(buffer).c_str());

    if (len_recv == 0) {
        printf("Client disconnected\n");
    } else if (len_recv == -1) {
        perror("reading from socket failed\n");
    } else {
        std::string req(buffer);
        return  req;
    }
    return "error";
}

int Actions::recieve_sized_req(int fd, char *buff, int sz) {
    int len = sz;
    while(sz > 0) {
        std::vector<char> buffer(sz, 0);
        int valread = recv(fd, &buffer[0] , sz, 0)  ;
        if(valread < 0){
            return -1;
        }
        if(valread == 0){
            break;
        }
        sz -= valread;
        std::string r = std::string(buffer.begin(), buffer.begin() + ((valread < len) ? valread : len));
        std::strcat(buff, r.c_str());
    }

    return len-sz;
}
