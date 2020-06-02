#include <iostream>
#include <fstream>
#include <sstream>
#include "Server.h"

#define WORKING_DIRECTORY   "."


int main(int argc, char* argv[]) {
    std::cout << "Hello, World!" << std::endl;
    Server* server = new Server(8080, WORKING_DIRECTORY);
    server->start_server();
  /*  std::ifstream myfile;
    std::stringstream file_path;
    file_path << "." << "/image2.png";
    myfile.open(file_path.str().c_str(),   std::ios::in | std::ios::binary);
    char* dataBytes = new char[58000]();
    myfile.read (dataBytes, 58000);
    std::cout << dataBytes << std::endl;*/
    /*if(argc == 2) {
        int port = atoi(argv[1]);
        Server* server = new Server(port, WORKING_DIRECTORY);
        int status  = server.;
        if(status == 0){
            // run server.
            server->start_server();
        }else{
            perror("Error in creating Connection\n");
        }
    }
    std::cout << "Expected 1 argument\n";*/


    return 0;
}