//
// Created by sohayla on 20/11/19.
//

#ifndef HTTP_CLIENT_CLIENT_H
#define HTTP_CLIENT_CLIENT_H


#include <string>
#include "Actions.h"

class Client {
private:
    std::string main_dir;
    std::string server_port;
    std::string server_addr;
    int c_fd;
    Actions* a;
public:
    Client(std::string main_dir);
    int connect_to_server(std::string server_add, std::string port);
    int sendReq(std::string f_path);
    int sendReq(Request* request);

    void send_req(std::vector<Request *> &vector);

    void closeConnection(int fd);
};


#endif //HTTP_CLIENT_CLIENT_H
