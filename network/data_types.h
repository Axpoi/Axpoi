//
// Created by axoford12 on 9/1/17.
//

#ifndef AXPOI_DATA_TYPES_H
#define AXPOI_DATA_TYPES_H

typedef char byte;

typedef struct{
    char data[4];
}rak_int;

typedef struct{
    char data[2];
}rak_short;

typedef struct{
    char data[8];
}rak_long;
const unsigned char magic[16] = {
        0x00,0xff,0xff,0xfe,
        0x00,0xfe,0xfe,0xfe,
        0xfd,0xfd,0xfd,0xfd,
        0x12,0x34,0x56,0x78
};

typedef struct{
    short length;
    char* string;
};

typedef struct{
    char address[7];
}address;

typedef struct{
    char first;
    char second;
    char last;
}uint24le;
// 一个uuid是16字节的,
// 我是打算这样储存的,不知道有没毛病..
// Graph:
//  0000   0000 - 0000 - 0000 - 0000 - 0000 0000 0000
// |           |  |                |   |            |
// |  first[4] |  |   second[6]    |   |   last[6]  |
// |           |  |                |   |            |
typedef struct{
    char first[4];
    char second[6];
    char last[6];
}uuid;

typedef struct{
    int x;
    int y;
    int z;
}position;

typedef struct{
    int x;
    int y;
    int z;
}block_position;
// 不要质疑我编译器扭曲int类型,32位和64位的编译器貌似int都是4字节
// 不是的话你大可魔改此处代码,
// 不觉得,char有点反人类?


#endif //AXPOI_DATA_TYPES_H
