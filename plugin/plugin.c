/*************************************************************************
	> File Name: plugin.c
	> Author: 
	> Mail: 
	> Created Time: Sun 03 Sep 2017 11:00:58 AM CST
 ************************************************************************/
// TODO Header file.
#ifdef UNIX
#include<dlfcn.h>
#endif
// 插件框架和加载器
void plugin_load_one(char* plugin_path){
#ifdef UNIX
    void* plugin_handle = dlopen(path,RTLD_NOW);
    if(plugin_handle == NULL){
        printf("Load plugin error\n");
        printf("Reason:%s\n",dlerror());
        return;
    }
    void (*sym)() =  dlsym(plugin_handle,"on_load");
    if(sym == NULL){
        printf("Loading plugin's on_load function error,\n");
        printf("Reason : %s\n",dlerror());
        return;
    }
    (*sym)();
#endif
}
