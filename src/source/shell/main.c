#include "lib_syscall.h"
#include "main.h"
#include <stdio.h>
#include <string.h>

/// @brief shell的命令行结构体
static cli_t cli;

/// @brief 命令行提示词，在提示词后输入命令
static const char* prompt="sh >>";

/// @brief 存储输入命令缓冲区
char cmd_buf[256];

/**
 * @brief help命令
 * @param argc 参数数量
 * @param argv 参数的字符串 
*/
static int do_help(int argc,char** argv){
    const cli_cmd_t* start=cli.cmd_start;

    while(start<cli.cmd_end){
        printf("%s %s\n",start->name,start->usage);
        start++;
    }

    return 0;
}

/// @brief 命令列表
static const cli_cmd_t cmd_list[]={
    {
        .name="help",
        .usage="help -- list supported command",
        .do_func=do_help
    }
};


/**
 * @brief 命令行的初始化函数
 * @param prompt 初始化cli_t结构体的prompt成员变量
 * @param cli_cmd_t 命令列表首地址
 * @param size 命令列表包含元素个数
*/
static void cli_init(const char* prompt,const cli_cmd_t* cmd_list,int size){
    cli.prompt=prompt;
    memset(cli.curr_input,0,CLI_INPUT_SIZE);
    cli.cmd_start=cmd_list;
    cli.cmd_end=cmd_list+size;
}

/**
 * @brief 显示命令行提示词
*/
static void show_prompt(void){
    printf("%s",cli.prompt);

    // 清空缓存
    fflush(stdout);
}

int main(int argc,char** argv){

    // 打开tty0设备
    open(argv[0],0);
    dup(0);
    dup(0);

    cli_init(prompt,cmd_list,sizeof(cmd_list)/sizeof(cmd_list[0]));

    for(;;){

        show_prompt();
        char* str=fgets(cli.curr_input,CLI_INPUT_SIZE,stdin);
        if(!str){
            continue;
        }

        // 去掉换行符
        char* cr=strchr(cli.curr_input,'\n');
        if(cr){
            *cr=0;
        }

        // 去掉回车符
        cr=strchr(cli.curr_input,'\r');
        if(cr){
            *cr=0;
        }
    }
}
