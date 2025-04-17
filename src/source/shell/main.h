#ifndef MAIN_H
#define MAIN_H

/// @brief  command line interface 命令行输入的大小
#define CLI_INPUT_SIZE  1024

/**
 * @brief 描述单个命令的结构体
 * @param name 命令名称
 * @param usage 命令的使用方法
 * @param do_func 命令的处理函数
 */
typedef struct _cli_cmd_t{
    const char* name;
    const char* usage;
    int (*do_func)(int argc,char** argv);
}cli_cmd_t;


/**
 * @brief 描述命令行的结构体
 * @param curr_input 输入命令缓冲区
 * @param cmd_start 命令列表的起始地址
 * @param cmd_end 命令列表的结束地址
 * @param prompt 指向特定字符串，每次按下回车键显示该字符串
 */
typedef struct _cli_t{
    char curr_input[CLI_INPUT_SIZE];
    const cli_cmd_t* cmd_start;
    const cli_cmd_t* cmd_end;
    const char* prompt;
}cli_t;


#endif