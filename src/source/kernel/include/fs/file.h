#ifndef FILE_H
#define FILE_H

#include "comm/types.h"

#define FILE_NAME_SIZE  32 // 文件名的大小
#define FILE_TABLE_SIZE  2048 // 文件表的大小

typedef enum _file_type_t{
    FILE_UNKNOWN=0, // 未知文件类型
    FILE_TYPE_TTY, // tty设备文件
}file_type_t;

typedef struct _file_t{
    char file_name[FILE_NAME_SIZE]; // 文件名
    file_type_t type; // 文件类型
    uint32_t size; // 文件大小
    int ref; // 引用计数
    int dev_id; // 设备号
    int pos; // 当前读写位置
    int mode; // 打开模式,只读、只写、读写
}file_t;

file_t* file_alloc(void);
void file_free(file_t* file);
void file_table_init(void);
#endif