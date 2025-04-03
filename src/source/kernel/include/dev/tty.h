#ifndef TTY_H
#define TTY_H

#include "dev/dev.h"
#include "ipc/sem.h"

// tty设备的缓存大小
#define TTY_OBUF_SIZE  512
#define TTY_IBUF_SIZE  512
#define TTY_OCRLF      (1<<0) // 换行时输出\r\n
// 终端设备的个数
#define TTY_NR  8

typedef struct _tty_fifo_t{
    char* buf;
    int size;

    // 读指针，写指针
    int read,write;

    int count;
}tty_fifo_t;

typedef struct _tty_t{
    char obuf[TTY_OBUF_SIZE];
    char ibuf[TTY_IBUF_SIZE];

    // 读缓存和写缓存
    tty_fifo_t ofifo;
    tty_fifo_t ififo;

    // 对应的console的索引号
    int console_index;

    // 输出信号量
    sem_t osem;

    int oflags; // 输出标志
}tty_t;

int tty_open(device_t* dev);
int tty_read(device_t* dev,int addr,char* buf,int size);
int tty_write(device_t* dev,int addr,char* buf,int size);
int tty_control(device_t*dev,int cmd,int arg0,int arg1);
void tty_close(device_t* dev);

void tty_fifo_init(tty_fifo_t* fifo,char* buf,int size);
int tty_fifo_put(tty_fifo_t* fifo,char c);
int tty_fifo_get(tty_fifo_t* fifo,char* c);
#endif