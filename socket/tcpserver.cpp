#include <iostream>
#include <netinet/in.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <vector>
#include <string>
#include <chrono>
#include <iomanip>
#include <fstream>
#define PORT 8080


int main(int argc, char const* argv[])
{
    int server_fd, new_socket, valread;
    struct sockaddr_in address;
    int opt = 1;
    int addrlen = sizeof(address);
    char buffer[512000] = { 0 };
    std::ofstream myfile;
   // std::vector <char> msg = {};
    std::string msg = "";

    for(int i = 0; i < 512000; i++){
	    msg += 'A';
    }
 
    // Creating socket file descriptor
    if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("socket failed");
        exit(EXIT_FAILURE);
    }
 
    // Forcefully attaching socket to the port 8080
    if (setsockopt(server_fd, SOL_SOCKET,
                   SO_REUSEADDR | SO_REUSEPORT, &opt,
                   sizeof(opt))) {
        perror("setsockopt");
        exit(EXIT_FAILURE);
    }
    address.sin_family = AF_INET;
    address.sin_addr.s_addr = INADDR_ANY;
    address.sin_port = htons(PORT);
 
    // Forcefully attaching socket to the port 8080
    if (bind(server_fd, (struct sockaddr*)&address,
             sizeof(address))
        < 0) {
        perror("bind failed");
        exit(EXIT_FAILURE);
    }
    if (listen(server_fd, 3) < 0) {
        perror("listen");
        exit(EXIT_FAILURE);
    }
    if ((new_socket
         = accept(server_fd, (struct sockaddr*)&address,
                  (socklen_t*)&addrlen))
        < 0) {
        perror("accept");
        exit(EXIT_FAILURE);
    }
    //valread = read(new_socket, buffer, 512000);
    //printf("%s\n", buffer);
    auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);

    send(new_socket, msg.c_str(), msg.length(), 0);
    //printf("Hello message sent\n");
    valread = read(new_socket, buffer, 512000);

    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::
    	chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;
    //std::cout << "time taken ";
    //std::cout <<std::fixed << std::setprecision(9) << time_taken << std::endl;
    myfile.open("serrst.txt", std::fstream::app);
    if(myfile.is_open()){
	    myfile << std::fixed << std::setprecision(9) << time_taken << std::endl;
	    myfile.close();
    }
    // closing the connected socket
    close(new_socket);
    // closing the listening socket
    shutdown(server_fd, SHUT_RDWR);
    return 0;
}
