//
// Created by axoford12 on 9/1/17.
//

#include "udp_socket.h"
// Windows这里没有开发环境就让他去屎吧...
// 到时候慢慢移植.
// 现在手上只有Linux....
// 晕哦...
#ifdef WINDOWS
#include<winsock2.h>
#endif //WINDOWS

#ifdef UNIX

#include<sys/socket.h>
#include <netinet/in.h>
#include <memory.h>
#include <stdlib.h>
#include <errno.h>
int socket_create(list *l) {
    int socket_fd = 0; // 套接字描述符.
    socket_fd = socket(AF_INET,SOCK_DGRAM,0);
    if(socket_fd < 0){
        return -1;
    }
    uint16_t port;
    // 声明port.
    node* port_info = list_get(l,"port",strlen("port"));
    if(port_info == NULL){
        return -2;
    }
    port = (uint16_t )atoi(port_info->value);

    struct sockaddr_in sock_addr;
    int address_len = sizeof(struct sockaddr_in);

    bzero( &sock_addr, (size_t)address_len );

    sock_addr.sin_family = AF_INET;
    sock_addr.sin_addr.s_addr = htonl(INADDR_ANY); // 小端储存转大端储存.
    sock_addr.sin_port = htons(port);
    errno = 0;
    printf("Attempting to bind port:%d\n",port);
    if(bind(socket_fd,(struct sockaddr *)&sock_addr,sizeof(sock_addr)) < 0){
        // Bind error?
#ifdef DEBUG
        printf("[DEBUG]Bind error %d \n",errno);
#endif //DEBUG
        return -3;
    }

    return socket_fd;

}
#endif //UNIX