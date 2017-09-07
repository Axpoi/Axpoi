/*************************************************************************
	> File Name: plugin.c
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Sep 2017 11:00:58 AM CST
 ************************************************************************/
#include "plugin.h"
#include <errno.h>
// 插件框架和加载器
void* plugin_load_one(char* plugin_path){
#ifdef UNIX
    void* plugin_handle = dlopen(path,RTLD_NOW);
    if(plugin_handle == NULL){
        printf("Load plugin error\n");
        printf("Reason:%s\n",dlerror());
        return plugin_handle;
    }
#endif
}
// 初始化插件加载器
list* plugin_init(list* config){
    list * l = NULL;
    errno = 0;
    list_construct(&l);
    return l;
}

/* TODO 遍历文件夹的所有.so / .dll 动态链接库文件，并实现函数虚表内的函数
 * 予以调用
 */
