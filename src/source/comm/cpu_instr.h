#ifndef CPU_INSTR_H
#define CPU_INSTR_H

/*
    内联汇编格式：
        __asm__ __volatile__(
            "汇编语句"  例如 "inb %[p],%[v]"
            :要输出到变量中的数据 例如 [v]"=a"(rv) 这里表示将将[v]指定放在ax寄存器中输出到rv变量中
            :要输入到汇编语句中的数据的数据 例如 [p]"d"(port) 就是将port的数据放入dx中输入
            另外这里的[p],[v]都是占位符号
            :这里要放入执行汇编语句除上述两条修改的寄存器，剩下也会修改的寄存器
        );
*/
#include "types.h"

static inline void cli(void){
    __asm__ __volatile__("cli");
}

static inline void sti(void){
    __asm__ __volatile__("sti");
}

// 注意in和out具体 in指令是指从外部设备读入到cpu 注意别搞反了
static inline uint8_t inb(uint16_t port){
    uint8_t rv;
    __asm__ __volatile__(
        "inb %[p],%[v]"
        :[v]"=a"(rv)
        :[p]"d"(port)
    );
    return rv;
}


static inline uint16_t inw(uint16_t port){
    uint16_t rv;
    __asm__ __volatile__(
        "in %[p],%[v]"
        :[v]"=a"(rv)
        :[p]"d"(port)
    );
    return rv;
}


static inline void outb(uint16_t port,uint8_t data){
    __asm__ __volatile(
        "outb %[v],%[p]"
        :
        :[p]"d"(port), [v]"a"(data)
    );
}

// 加载gdt表的函数
static inline void lgdt(uint32_t start,uint32_t size){
    // 这里设置的结构体是为了指明lgdt的48位
    // 即32位的地址以及 16位的大小
    // 这也是ds寄存器还是16位原因，因为其存储的是段选择子
    struct{
        uint16_t limit;
        uint16_t start15_0;
        uint16_t start31_16;
    }gdt;
    gdt.start31_16=start>>16;
    gdt.start15_0=start&0xFFFF;
    gdt.limit=size-1;
    __asm__ __volatile__(
        "lgdt %[g]"
        :
        :[g]"m"(gdt)
    );
}

// 设置读cr0寄存器
static inline uint32_t read_cr0(void){
    uint32_t cr0;
    __asm__ __volatile__(
        "mov %%cr0, %[v]"
        :[v]"=r"(cr0)
        :
    );
    return cr0;
}

// 设置写cr0寄存器
static inline void write_cr0(uint32_t v){
    __asm__ __volatile__(
        "mov %[v],%%cr0"
        :
        :[v]"r"(v)
    );
}

// 远跳转指令
static inline void far_jump(uint32_t selector,uint32_t offset){
    uint32_t addr[]={offset,selector};
    __asm__ __volatile__(
        "ljmpl *(%[a])"
        :
        :[a]"r"(addr)
    );
}

// 设置idt表
static inline void lidt(uint32_t start,uint32_t size){
    struct{
        uint16_t limit;
        uint16_t start15_0;
        uint16_t start31_16;
    }idt;
    idt.start31_16=start>>16;
    idt.start15_0=start&0xFFFF;
    idt.limit=size-1;
    __asm__ __volatile__(
        "lidt %[g]"
        :
        :[g]"m"(idt)
    );
}

// 让cpu暂停指令
static inline void hlt(void){
    __asm__ __volatile("hlt");
}

static inline void write_tr(uint16_t tss_sel){
    __asm__ __volatile__(
        "ltr %%ax"
        :
        :"a"(tss_sel)
    );
}

static inline uint32_t read_eflags(void){
    uint32_t eflags;
    __asm__ __volatile__(
        "pushf\n\tpop %%eax"
        :"=a"(eflags)
        :
    );
    return eflags;
}

static inline void write_eflags(uint32_t eflags){
    __asm__ __volatile__(
        "push %%eax\n\tpopf"
        :
        :"a"(eflags)
    );
}

static inline void write_cr3(uint32_t v){
    __asm__ __volatile__(
        "mov %[v],%%cr3"
        :
        :[v]"r"(v)
    );
}

static inline uint32_t read_cr3(void){
    uint32_t cr3;
    __asm__ __volatile__(
        "mov %%cr3,%[v]"
        :[v]"=r"(cr3)
        :
    );
    return cr3;
}

static inline void write_cr4(uint32_t v){
    __asm__ __volatile__(
        "mov %[v],%%cr4"
        :
        :[v]"r"(v)
    );
}

static inline uint32_t read_cr4(void){
    uint32_t cr4;
    __asm__ __volatile__(
        "mov %%cr4,%[v]"
        :[v]"=r"(cr4)
        :
    );
    return cr4;
}

static inline void write_cr2(uint32_t v){
    __asm__ __volatile__(
        "mov %[v],%%cr2"
        :
        :[v]"r"(v)
    );
}

static inline uint32_t read_cr2(void){
    uint32_t cr2;
    __asm__ __volatile__(
        "mov %%cr4,%[v]"
        :[v]"=r"(cr2)
        :
    );
    return cr2;
}
#endif