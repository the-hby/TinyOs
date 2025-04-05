#ifndef SYSCALL_H
#define SYSCALL_H

#include "comm/types.h"

#define SYSCALL_PARAM_COUNT 5
#define SYS_SLEEP          0
#define SYS_GETPID         1
#define SYS_PRINT_MSG      100
#define SYS_FORK           2
#define SYS_EXECVE         3
#define SYS_YIELD          4

#define SYS_OPEN           50
#define SYS_READ           51
#define SYS_WRITE          52
#define SYS_CLOSE          53
#define SYS_LSEEK          54
#define SYS_ISATTY         55
#define SYS_SBRK           56
#define SYS_FSTAT          57

typedef struct _syscall_frame_t{
    uint32_t eflags;
    uint32_t gs,fs,es,ds;
    uint32_t edi,esi,ebp,dummy,ebx,edx,ecx,eax;
    uint32_t eip,cs;
    uint32_t func_id,arg0,arg1,arg2,arg3;
    uint32_t esp,ss;
}syscall_frame_t;

void exception_handler_syscall(void);

#endif