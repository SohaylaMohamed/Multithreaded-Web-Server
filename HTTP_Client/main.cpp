#include <iostream>
#include "Client.h"

#define  DIR "."

int main(int argc, char *argv[]) {
    Client* client = new Client(".");
    Request* req = new Request("POST", "/test.txt", "HTTP/1.1", 8080, "127.0.0.1");
    client->connect_to_server("127.0.0.1", "8080");
    //client->sendReq(req);

   /* int port = atoi(argv[2]);
    char *serverAddress = argv[1];
    char *fileName = argv[3];
  //  Client* client = new Client(DIR);
    client->connect_to_server(serverAddress, std::to_string(port));
  //  client->sendReq(fileName);*/



    return 0;
}