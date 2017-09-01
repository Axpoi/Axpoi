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
    char first;
    char second;
    char last;
}uint24le;



#endif //AXPOI_DATA_TYPES_H
