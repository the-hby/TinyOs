#include "lib_syscall.h"
#include <stdio.h>

char cmd_buf[256];

int main(int argc,char** argv){
#if 0
    sbrk(0);
    sbrk(100);
    sbrk(200);
    sbrk(4096*2+200);
    sbrk(4096*5+1234);
    printf("Hello from shell\n");

    printf("abef\b\b\b\bcd\n");
    printf("abcd\x7f;fg\n");
    printf("\0337hello,world\0338123\n");

    // 必须加换行符 \n 要不然会跳过这句话的打印出现一些问题，会被缓存
    printf("\033[31;42mHello,word!\033[39;49m123\n");

    printf("123\033[2DHello,word!\n");  // 光标左移2，1Hello,word!
    printf("123\033[2CHello,word!\n");  // 光标右移2，123  Hello,word!

    printf("\033[31m");  // ESC [pn m, Hello,world红色，其余绿色
    printf("\033[10;10H test!\n");  // 定位到10, 10，test!
    printf("\033[20;20H test!\n");  // 定位到20, 20，test!
    printf("\033[32;25;39m123\n");  // ESC [pn m, Hello,world红色，其余绿色  

    printf("\033[2J\n");
#endif

    // 打开tty0设备
    open(argv[0],0);
    dup(0);
    dup(0);

    printf("Hello from shell\n");
    
    for(;;){
        gets(cmd_buf);
        puts(cmd_buf);
    }
}