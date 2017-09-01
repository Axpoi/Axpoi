//
// Created by axoford12 on 9/1/17.
//

#ifndef AXPOI_UDP_SOCKET_H
#define AXPOI_UDP_SOCKET_H

#include "../utils/list/list.h"
#include <stdio.h>

#include "../consts.h"
#ifdef UNIX
int socket_create(list *l);
#endif //UNIX
#endif //AXPOI_UDP_SOCKET_H
