#ifndef CPU_H
#define CPU_H

#include "comm/types.h"
#include "os_cfg.h"
#include "comm/cpu_instr.h"

#pragma pack(1)
typedef struct _segment_desc_t{
    uint16_t limit15_0; // 段界限的低16位
    uint16_t base15_0;  // 段基址的低16位
    uint8_t base23_16; // 段基址的16位到23位
    uint16_t attr;     // 段界限+段属性 其布局为 8bit段属性+4bit段界限+4bit段属性 （顺序由低到高）
    uint8_t base31_24; // 段基址24到31位
}segment_desc_t;

// idt表项结构体
typedef struct _gate_desc_t{
    uint16_t offset15_0;
    uint16_t selector;
    uint16_t attr;
    uint16_t offset31_16;
}gate_desc_t;
// 定义idt的attr位
// 设置P位指示该idt表项是否存在
#define GATE_P_PRESENT (1 << 15)
// 设置DPL权限
#define GATE_DPL0 (0 << 13)
#define GATE_DPL3 (3 << 13)
// 设置为32位中断
#define GATE_TYPE_INT (0xE << 8)
#define GATE_TYPE_SYSCALL  (0xC << 8)

// 定义gdt的attr位
// 注意位是从0开始！！！！

// 段描述符属性G标志位， 
// 如果G = 0，说明段描述符中的Limit的单位是字节，
// 段长度Limit范围可从1B～1MB，即在20位的前面补3个0即可；
// 如果G = 1，说明段描述符中的Limit的单位是字节为4KB，
// 段长度Limit范围可从4KB～4GB，在20位的后面补充FFF即可。
// 举个例子，如果Limit拼接后的为FFFFF，如果G为0则为000FFFFF，反之为FFFFFFF。
#define SEG_G (1 << 15) 

// D/B标志位D = 1采用32位寻址方式,D = 0采用16位寻址方式。
#define SEG_D (1 << 14)

// L标志位用于64位位于第13位 以及AVL标志位位于第12位。这两位一般都为0
// 段描述符的P标志位，指示该描述符是否存在
#define SEG_P_PRESENT (1 << 7) 

// 设置其特权0标志位
// 位于第6位和第7位 DPL即描述符特权级别
#define SEG_DPL0 (0 << 5)
 
// 设置特权3标志位
#define SEG_DPL3 (0x3 << 5)

#define SEG_CPL0 (0 << 0)
#define SEG_CPL3 (3 << 0)
// 设置S标志位，S = 1代码段或者数据段描述符，S = 0系统段描述符。位于第5位
#define SEG_S_SYSTEM (0 << 4)
#define SEG_S_NORMAL (1 << 4)

// 低四位共同组成type标志位
// TYPE标志位决定了段的类型，这里我们只用code和data段就行
#define SEG_TYPE_CODE (1 << 3)
#define SEG_TYPE_DATA (0 << 3)

// 决定其是否为可读写
#define SEG_TYPE_RW (1 << 1)

// 这里设置的TSS对应的type
#define SEG_TYPE_TSS (9<<0)

// 设置EFLAGS的标志位
// 该位默认为1
#define EFLAGS_DEFAULT (1<<1)
// 开中断
#define EFLAGS_IF      (1<<9)

void cpu_init(void);
void segment_desc_set(int selector,uint32_t base,uint32_t limit,uint16_t attr);
void gate_desc_set(gate_desc_t* desc,uint16_t selector,uint32_t offset,uint16_t attr);
// 寻找空闲的gdt表项并设置
int gdt_alloc_desc();
void gdt_free_sel(int tss_sel);
typedef struct _tss_t{
    uint32_t pre_link;
    uint32_t esp0,ss0,esp1,ss1,esp2,ss2;
    uint32_t cr3; // 使用的页表
    uint32_t eip,eflags,eax,ecx,edx,ebx,esp,ebp,esi,edi;
    uint32_t es,cs,ss,ds,fs,gs;
    uint32_t ldt;
    uint32_t iomap; // IO位图
}tss_t;
// 切换对应tss

#pragma pack()
void switch_to_tss(int tss_sel);
#endif