//
// Created by axoford12 on 8/29/17.
//

#ifndef AXPOI_CONFIG_H
#define AXPOI_CONFIG_H

#include "../utils/list/list.h"

typedef enum{
    PARSE_OK = 0,
    ERR_MAX_LENGTH_TOO_SHORT,
    ERR_CONFIG_FILE_NOT_FOUND
}config_init_error;
/**
 * 初始化conf，从../fg.ini中读取文件。
 * @return
 * 错误
 */
config_init_error config_init(list* config);
#endif //AXPOI_CONFIG_H
