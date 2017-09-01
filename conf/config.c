//
// Created by axoford12 on 8/29/17.
//

#include "config.h"
#include<stdlib.h>
#include <memory.h>
#include <errno.h>
#include <stdio.h>
#include "../utils/filter_char.h"
#include "../consts.h"
#define LINE_LENGTH 1024
#define ATTR_MAX_LENGTH 40



void handle(char *attr_name, char *attr_value,list *attr_dst) {
    list_add(attr_dst,NULL,0,attr_name,attr_value);
}

/**
 * 解析一个无Section的ini文件。并且不含include
 * @param f
 * @param attr_dst
 * @return 错误
 */
config_init_error parse(FILE *f, list* attr_dst) {
    char *buf;
    buf = malloc(sizeof(char) * LINE_LENGTH);
    while (fgets(buf, LINE_LENGTH, f)) {
        char* attr_name = malloc(ATTR_MAX_LENGTH * sizeof(char)); // 读出的属性名称
        char* attr_value = malloc(ATTR_MAX_LENGTH * sizeof(char)); // 读出的属性值
        int equal_index = 0;
        if (buf[0] == '#' || buf[0] == '\n')
            continue;

        filter_char(buf, ' ');
        for (equal_index = 0; buf[equal_index] != '='; ++equal_index) {
            if (equal_index > ATTR_MAX_LENGTH)return ERR_MAX_LENGTH_TOO_SHORT;
            attr_name[equal_index] = buf[equal_index];
        }
        attr_name[++equal_index] = '\0';
        int counter;
        for (counter = equal_index; buf[counter] != '\0'; ++counter) { // Counter的存在是为了修正偏移
            if (counter > ATTR_MAX_LENGTH)return ERR_MAX_LENGTH_TOO_SHORT;
            attr_value[counter - equal_index] = buf[counter];
        }
        if(attr_value[counter - equal_index - 1] == '\n')
            counter--;
        attr_value[counter - equal_index] = '\0'; // 显式加上结束符
        handle(attr_name,attr_value,attr_dst);
    }
    free(buf);
    return PARSE_OK;
}



config_init_error config_init(list* config) {
    errno = 0;
    FILE* config_file;
    config_file = fopen(CONFIG_FILE, "r");
    printf("Trying to open file:%s\n",CONFIG_FILE);
    if(errno){
        printf("Error occurred during opening config file:%s\n",strerror(errno));
        return ERR_CONFIG_FILE_NOT_FOUND;
    }

    config_init_error err = parse(config_file,config);
    fclose(config_file); // 昨天忘关了？
    return err;

}
