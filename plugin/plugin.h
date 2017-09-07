/*************************************************************************
	> File Name: plugin.h
	> Author: 
	> Mail: 
	> Created Time: Tue 05 Sep 2017 05:45:09 PM CST
 ************************************************************************/

#ifndef _PLUGIN_H
#define _PLUGIN_H
#include "../utils/list/list.h"
#include<dlfcn.h>
typedef enum{
    OK = 0,
    ERROR_LOADING_PLUGIN_PATH,
    ERROR_LOADING_PLUGIN_SYMBOL,
}plugin_init_errors
void plugin_init(*list);
#endif //_PLUGIN_H
