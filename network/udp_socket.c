//
// Created by axoford12 on 9/1/17.
//

#include "udp_socket.h"


#ifdef WINDOWS
#include<winsock2.h>
#endif //WINDOWS
#ifdef UNIX

#include<sys/socket.h>

#endif //UNIX


int socket_create() {

}