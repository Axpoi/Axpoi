/*
 ▄▄▄      ▒██   ██▒ ██▓███   ▒█████   ██▓
▒████▄    ▒▒ █ █ ▒░▓██░  ██▒▒██▒  ██▒▓██▒
▒██  ▀█▄  ░░  █   ░▓██░ ██▓▒▒██░  ██▒▒██▒
░██▄▄▄▄██  ░ █ █ ▒ ▒██▄█▓▒ ▒▒██   ██░░██░
 ▓█   ▓██▒▒██▒ ▒██▒▒██▒ ░  ░░ ████▓▒░░██░
 ▒▒   ▓▒█░▒▒ ░ ░▓ ░▒▓▒░ ░  ░░ ▒░▒░▒░ ░▓
  ▒   ▒▒ ░░░   ░▒ ░░▒ ░       ░ ▒ ▒░  ▒ ░
  ░   ▒    ░    ░  ░░       ░ ░ ░ ▒   ▒ ░
      ░  ░ ░    ░               ░ ░   ░

 */
#include <stdio.h>
#include "consts.h"

#define DIRS_LEN 3
#ifdef WINDOWS
#include<io.h>
#include<direct.h>
#endif
#ifdef UNIX

#include<unistd.h>
#include <sys/stat.h>

#endif

#include "utils/list/list.h"
#include "conf/config.h"

#define VERSION "0.0"

void check_dir_auto_make(const char *dir_name) {
#ifdef DEBUG
    printf("[DEBUG]Trying to check dir:%s\n", dir_name);
#endif
    if (access(dir_name, F_OK)) {
#ifdef DEBUG
        printf("[DEBUG]%s will be created.\n", dir_name);
#endif
#ifdef WINDOWS
        _mkdir(dir_name);
#endif
#ifdef UNIX
        mkdir(dir_name, 0755); // 8进制权限位,本用户可读可写可执行
        // 同组用户及其他用户可读
#endif
    }
#ifdef DEBUG
    else {
        printf("[DEBUG]%s exists.No need to create.\n", dir_name);
    }
#endif
}

void check_env() {
    const char *dirs[DIRS_LEN] = {
            "./world", "./plugins", "./players"
    };
    for (int i = 0; i < DIRS_LEN; ++i) {
        check_dir_auto_make(dirs[i]);
    }
}

int main() {
    printf("Welcome to Axpoi v%s\n", VERSION);
    list* config;
    list_construct(&config);
    printf("Reading Configuration...\n");
    config_init(config);
    list_destruct(config);
    check_env();
    return 0;
}