#include <iostream>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#include <fstream>
#include <chrono>
#include <iomanip>
#define PORT 8080
 
int main(int argc, char const* argv[])
{
    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    std::string msg = "";
    for(int i = 0; i < 4096; i++){
	    msg += 'A';
    }

    //char* hello = "Hello there";
    char buffer[200000] = { 0 };
    std::ofstream myfile;
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }
 
    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);
 
    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        printf(
            "\nInvalid address/ Address not supported \n");
        return -1;
    }
 
    if ((client_fd
         = connect(sock, (struct sockaddr*)&serv_addr,
                   sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }
    auto start = std::chrono::high_resolution_clock::now();
    std::ios_base::sync_with_stdio(false);

    send(sock, msg.c_str(), msg.length(), 0);
    //printf("Hello message sent\n");
    valread = read(sock, buffer, 200000);
    auto end = std::chrono::high_resolution_clock::now();
    double time_taken = std::chrono::duration_cast<std::
    	chrono::nanoseconds>(end - start).count();

    time_taken *= 1e-9;
    
    myfile.open("tcpclientresult.txt", std::fstream::app);
    if(myfile.is_open()){
	    myfile << std::fixed << std::setprecision(9) << time_taken << std::endl;
	    myfile.close();
    }
    std::cout<<time_taken;
    //printf("%s\n", buffer);
    //msg = buffer;
    //std::cout<<msg<<std::endl;
 
    // closing the connected socket
    close(client_fd);
    return 0;
}

