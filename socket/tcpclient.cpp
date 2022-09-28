#include <iostream>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#include <string>
#define PORT 8080
 
int main(int argc, char const* argv[])
{
    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    std::string msg = "";
    for(int i = 0; i < 4096; i++){
	    msg += 'A';
    }

    char* hello = "Hello there";
    char buffer[200000] = { 0 };
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
    send(sock, msg.c_str(), msg.length(), 0);
    printf("Hello message sent\n");
    valread = read(sock, buffer, 200000);
    printf("%s\n", buffer);
    //msg = buffer;
    //std::cout<<msg<<std::endl;
 
    // closing the connected socket
    close(client_fd);
    return 0;
}

