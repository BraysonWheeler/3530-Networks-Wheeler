//
//  main.c
//  server
//
//  Created by Logan on 3/23/21.
//

#include <stdio.h>
#include <sys/socket.h>
#include <string.h>
#include <unistd.h>
#include <netinet/in.h>
#include <stdlib.h>
#include <arpa/inet.h>
#define port 20282

int main(int argc, const char * argv[]) {
    struct sockaddr_in address;
    int adderlen = sizeof (address);
    char buffer[1024] = {0};
    int server_fieldd, new_socket, vread;
    int opt = 1;
    char *h = "ping";

    address.sin_family = AF_INET;
    address.sin_addr.s_addr = inet_addr("127.0.0.1");
    address.sin_port = htons( port );

    server_fieldd = socket(AF_INET, SOCK_STREAM, 0);
    setsockopt(server_fieldd, SOL_SOCKET, SO_REUSEADDR | SO_REUSEPORT, &opt, sizeof(1));

    bind(server_fieldd,(struct sockaddr *)&address, sizeof(address));
    listen(server_fieldd,3);
    while(1){
        new_socket = accept(server_fieldd, (struct sockaddr *)&address,(socklen_t*)&adderlen);

        vread = read(new_socket, buffer, 1024);
        printf("recieved from %s: %s\n",inet_ntoa(address.sin_addr),buffer);
    }


    shutdown(server_fieldd, SHUT_RD);
    shutdown(new_socket, SHUT_RD);
    close(server_fieldd);
    close(new_socket);
}
