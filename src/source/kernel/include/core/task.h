#ifndef TASK_H
#define TASK_H

#include "cpu/cpu.h"
#include "comm/types.h"
#include "tools/list.h"
#include "tools/klib.h"
#include "tools/log.h"
#include "os_cfg.h"
#include "comm/cpu_instr.h"
#include "cpu/irq.h"
#include "fs/file.h"

#define TASK_NAME_SIZE 32
#define TASK_TIME_SLICE_DEFAULT 10

#define TASK_FLAGS_SYSTEM       (1 << 0)

// 打开的文件表数量
#define TASK_OFILE_NR 128

typedef struct _task_t{
    enum{
        TASK_CREATED,
        TASK_RUNNING,
        TASK_SLEEP,
        TASK_READY,
        TASK_WAITING,
    }state;

    int pid;
    struct _task_t* parent;
    uint32_t heap_start;
    uint32_t heap_end;

    int sleep_ticks;
    int slice_ticks;
    int time_ticks;

    char name[TASK_NAME_SIZE];

    // 打开文件表
    file_t* file_table[TASK_OFILE_NR];

    list_node_t run_node;
    list_node_t all_node;
    list_node_t wait_node;

    tss_t tss;
    int tss_sel;
}task_t;

typedef struct _task_arg_t{
    uint32_t ret_addr;
    uint32_t argc;
    char**argv;
}task_args_t;

typedef struct _task_manager_t{
    task_t* curr_task;

    list_t ready_list;
    list_t task_list;
    list_t sleep_list;

    task_t first_task;
    task_t idle_task;

    int app_code_sel;
    int app_data_sel;
}task_manager_t;

void task_manager_init(void);
void task_first_init(void);
int task_init(task_t* task,const char* name,int flag,uint32_t entry,uint32_t esp);

void task_switch_from_to(task_t*from,task_t*to);
task_t* task_first_task(void);
void task_set_ready(task_t* task);
void task_set_block(task_t*task);
void task_start(task_t* task);
int sys_sched_yield(void);
void task_dispatch(void);
task_t* task_current(void);
task_t* task_next_run(void);
void task_time_tick(void);

void task_set_sleep(task_t* task,uint32_t ticks);
void task_set_wakeup(task_t*task);
void sys_msleep(uint32_t ms);
int sys_getpid(void);
int sys_fork(void);
int sys_execve(char* name,char** argv,char** env);

// 分配文件描述符
int task_alloc_fd(file_t* file);
// 释放文件描述符
void task_remove_fd(int fd);
// 获取文件描述符对应的文件结构体
file_t* task_file(int fd);

#endif