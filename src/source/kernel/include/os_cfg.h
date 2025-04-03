#ifndef OS_CFG_H
#define OS_CFG_H

#define GDT_TABLE_SIZE 256
// 设置内核代码段
#define KERNEL_SELECTOR_CS (1*8) 
// 设置内核数据段
#define KERNEL_SELECTOR_DS (2*8) 
#define KERNEL_STACK_SIZE (8*1024)

// 定时器多长时间中断一次
#define OS_TICK_MS              10
#define OS_VERSION              "1.0.0"
#define IDLE_TASK_SIZE          1024

#define SELECTOR_SYSCALL        (3*8)

#define TASK_NR                 128
#endif