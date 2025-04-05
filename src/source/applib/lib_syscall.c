#include "lib_syscall.h"
#include "comm/types.h"
#include "core/syscall.h"
#include "os_cfg.h"

static inline int sys_call(syscall_args_t*args){
    uint32_t addr[]={0,SELECTOR_SYSCALL | 0};
    int ret;
    __asm__ __volatile__(
        "push %[arg3]\n\t"
        "push %[arg2]\n\t"
        "push %[arg1]\n\t"
        "push %[arg0]\n\t"
        "push %[id]\n\t"
        "lcall *(%[a])"
        :"=a"(ret)
        :[a]"r"(addr),
         [arg3]"r"(args->arg3),
         [arg2]"r"(args->arg2),
         [arg1]"r"(args->arg1),
         [arg0]"r"(args->arg0),
         [id]"r"(args->id)
    );
    return ret;
}

void msleep(int ms){
    if(ms<=0){
        return;
    }

    syscall_args_t args;
    args.id=SYS_SLEEP;
    args.arg0=ms;

    sys_call(&args);
}

int getpid(void){
    syscall_args_t args;
    args.id=SYS_GETPID;
    return sys_call(&args);
}

void print_msg(const char* fmt,int arg){
    syscall_args_t args;
    args.id=SYS_PRINT_MSG;
    args.arg0=(uint32_t)fmt;
    args.arg1=arg;
    sys_call(&args);
}

int fork(void){
    syscall_args_t args;
    args.id=SYS_FORK;
    return sys_call(&args);
}

int execve(const char* name,char* const* argv,char* const* env){
    syscall_args_t args;
    args.id=SYS_EXECVE;
    args.arg0=(int)name;
    args.arg1=(int)argv;
    args.arg2=(int)env;

    sys_call(&args);
}

int yield(void){
    syscall_args_t args;
    args.id=SYS_YIELD;

    return sys_call(&args);
}

int open(const char*name,int flags, ...){
    syscall_args_t args;
    args.id=SYS_OPEN;
    args.arg0=(int)name;
    args.arg1=(int)flags;

    return sys_call(&args);
}

int read(int file,char* ptr,int len){
    syscall_args_t args;
    args.id=SYS_READ;
    args.arg0=(int)file;
    args.arg1=(int)ptr;
    args.arg2=(int)len;

    return sys_call(&args);
}

int write(int file,char*ptr,int len){
    syscall_args_t args;
    args.id=SYS_WRITE;
    args.arg0=(int)file;
    args.arg1=(int)ptr;
    args.arg2=(int)len;

    return sys_call(&args);
}

int close(int file){
    syscall_args_t args;
    args.id=SYS_CLOSE;
    args.arg0=(int)file;

    return sys_call(&args);
}

int lseek(int file,int ptr,int dir){
    syscall_args_t args;
    args.id=SYS_LSEEK;
    args.arg0=(int)file;
    args.arg1=(int)ptr;
    args.arg2=(int)dir;
    return sys_call(&args);
}

int isatty(int file){
    syscall_args_t args;
    args.id=SYS_ISATTY;
    args.arg0=(int)file;

    return sys_call(&args);
}

int fstat(int file,struct stat* st){
    syscall_args_t args;
    args.id=SYS_FSTAT;
    args.arg0=(int)file;
    args.arg1=(int)st;

    return sys_call(&args);
}

void* sbrk(ptrdiff_t incr){
    syscall_args_t args;
    args.id=SYS_SBRK;
    args.arg0=(int)incr;

    return (void*)sys_call(&args);
}