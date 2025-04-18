#include "fs/fs.h"
#include "comm/types.h"
#include "tools/klib.h"
#include "comm/boot_info.h"
#include "comm/cpu_instr.h"
#include "dev/console.h"
#include "fs/file.h"
#include "dev/dev.h"
#include "core/task.h"
#include "dev/tty.h"

#define TEMP_FILE_ID        100

static uint8_t TEMP_ADDR[100*1024];
static uint8_t* temp_pos;

static void read_disk(int sector, int sector_count, uint8_t * buf) {
    outb(0x1F6, (uint8_t) (0xE0));

	outb(0x1F2, (uint8_t) (sector_count >> 8));
    outb(0x1F3, (uint8_t) (sector >> 24));		
    outb(0x1F4, (uint8_t) (0));					
    outb(0x1F5, (uint8_t) (0));					

    outb(0x1F2, (uint8_t) (sector_count));
	outb(0x1F3, (uint8_t) (sector));			
	outb(0x1F4, (uint8_t) (sector >> 8));		
	outb(0x1F5, (uint8_t) (sector >> 16));		

	outb(0x1F7, (uint8_t) 0x24);

	
	uint16_t *data_buf = (uint16_t*) buf;

	// 这里是要读取的扇区
	while (sector_count-- > 0) {
		
		while ((inb(0x1F7) & 0x88) != 0x8) {}

		// 以每次2字节方式读取每个扇区
		for (int i = 0; i < SECTOR_SIZE / 2; i++) {
			*data_buf++ = inw(0x1F0);
		}
	}
}

static int is_path_valid(const char* path){
    if((path==(const char*)0) || (path[0]=='\0')){
        return 0;
    }

    return 1;
}

int sys_open(const char* name,int flags,...){
    if(kernel_strncmp(name,"tty:",3)==0){
        if(!is_path_valid(name)){
            log_printf("path is invalid\n");
            return -1;
        }

        int fd=-1;
        file_t* file=file_alloc();
        if(file){
            fd=task_alloc_fd(file);
            if(fd<0){
                goto sys_open_failed;
            }
        }
        else{
            goto sys_open_failed;
        }

        // 因为有：所以是4 tty:0
        int num=name[4]-'0';
        int dev_id=dev_open(DEV_TTY,num,0);
        if(dev_id<0){
            goto sys_open_failed;
        }

        file->dev_id=dev_id;
        file->mode=0;
        file->pos=0;
        file->ref=1;
        file->type=FILE_TYPE_TTY;
        kernel_strncpy(file->file_name,name,FILE_NAME_SIZE);
        return fd;

sys_open_failed:
        if(file){
            file_free(file);
        }
        if(fd>=0){
            task_remove_fd(fd);
        }
        
    }
    else{
        if(name[0]=='/'){
            read_disk(5000,80,(uint8_t*)TEMP_ADDR);
            temp_pos=(uint8_t*)TEMP_ADDR;

            return TEMP_FILE_ID;
        }
    }

    return -1;
}

int sys_read(int file,char* ptr,int len){
   if(file==TEMP_FILE_ID){
        kernel_memcpy(ptr,temp_pos,len);
        temp_pos+=len;

        return len;
   }
   else{
        file=0;
        
        file_t* p_file=task_file(file);
        if(!p_file){
            log_printf("file not opened\n");
            return -1;
        }

        return dev_read(p_file->dev_id,0,ptr,len);
    }
   
   return -1;
}

// 这里file就是fd
int sys_write(int file,char* ptr,int len){
    
    file_t* p_file=task_file(file);
    if(!p_file){
        log_printf("file not opened\n");
        return -1;
    }

    return dev_write(p_file->dev_id,0,ptr,len);
}

int sys_lseek(int file,int ptr,int dir){
    if(file==TEMP_FILE_ID){

        temp_pos=(uint8_t*)(TEMP_ADDR+ptr);
        return 0;
    }

    return -1;
}   

int sys_close(int file){
    return 0;
}

int sys_isatty(int file){
    return -1;
}

int sys_fstat(int file,struct stat* st){
    return -1;
}

void fs_init(void){
    file_table_init();
}

/**
* @brief 复制文件描述符，返回新的文件描述符
* @return 新的文件描述符，失败返回-1
* @param file 旧的文件描述符
*/
int sys_dup(int file){
    if((file<0) && (file>=TASK_OFILE_NR)){
        return -1;
    }

    file_t* p_file=task_file(file);
    if(!p_file){
        log_printf("file not opened\n");
        return -1;
    }

    int fd=task_alloc_fd(p_file);
    if(fd >= 0){
        p_file->ref++;
        return fd;
    }

    log_printf("alloc fd failed\n");
    return -1;
}