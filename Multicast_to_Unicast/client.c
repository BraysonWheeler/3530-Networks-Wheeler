//
//  main.c
//  client
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
    int s;
    int vread;
    struct sockaddr_in server_addr;

    char *h = "hello";
    char buffer[1024] = {0};

    server_addr.sin_family = AF_INET;
    server_addr.sin_port = htons( port );
    server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

    s = socket(AF_INET, SOCK_STREAM, 0);
    connect(s,(struct sockaddr*)&server_addr, sizeof(server_addr));
    send(s,h,strlen(h),0);
    /*
     if a server sends something
    vread = read(s,buffer,1024);
    printf("%s\n",buffer);
    */
    shutdown(s,SHUT_RD);
    close(s);
}
