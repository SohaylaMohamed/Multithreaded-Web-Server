//
// Created by sohayla on 20/11/19.
//

#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <cstring>
#include "Client.h"
#include "Request.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <zconf.h>

Client::Client(std::string main_dir) {
    this->main_dir = main_dir;
    a = new Actions(main_dir);
}

int Client::connect_to_server(std::string server_add, std::string  port) {
    this->server_addr = server_add;
    this->server_port = port;
    printf("Trying to connect to %s on port %s\n",server_add.c_str(), port.c_str());
    int sock;
    struct sockaddr_in serv_addr;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("\n Socket creation error \n");
        perror("Failed to connect to the server");
        exit(EXIT_FAILURE);
    }
    memset(&serv_addr, '0', sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(atoi(port.c_str()));

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, server_add.c_str(), &serv_addr.sin_addr) <= 0) {
        perror("\nInvalid address / Address not supported \n");
        perror("Failed to connect to the server");
        exit(EXIT_FAILURE);
    }
    // Server accepted my connection.
    if (connect(sock, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        perror("\nConnection Failed \n");
        perror("Failed to connect to the server");
        exit(EXIT_FAILURE);
    }
    c_fd = sock;
    printf("Connected Successfully to the server\n");

    return sock;
}

int Client::sendReq(std::string f_path) {
    std::ifstream inFile;
    inFile.open(f_path);
    if (!inFile) {
        printf("No such file or directory.\n");
        return -1;
    }
    std::vector<std::vector<Request *>> reqs = a->readInput(inFile);
    if(reqs.empty()) {
        printf("No Requests to send.\n");
        return -1;
    }
    /*for (int i = 0; i < reqs.size(); i++) {
        std::cout << reqs[i]->getMethod() << " " <<reqs[i]->geturi() << " "<< reqs[i]->getversion() << reqs[i]->getPort()<< std::endl;
    }*/
    //return a->sendRequestsUnpipelined(reqs);
    for (int i = 0; i < reqs.size(); i++) {
        send_req(reqs[i]);
       a->sendRequestsPipelined(reqs[i]);
    }
    return 0;
}

int Client::sendReq(Request *request) {
    if(request->getMethod() == "GET") {
        a->sendGet(request, c_fd);
    }else {
        a->sendPost(request, c_fd);
    }
    return 0;
}

void Client::send_req(std::vector<Request *> &reqs) {
    int sock_fd;
    int start_index = 0;
    int state = 0;
    while (state != -1) {
        sock_fd = connect_to_server(reqs[0]->getHostName(), std::to_string(reqs[0]->getPort()));
        a->sendRequestsUnpipelined(reqs, sock_fd);
        closeConnection(sock_fd);
    }

}

void Client::closeConnection(int fd) {
     close(fd);
}


