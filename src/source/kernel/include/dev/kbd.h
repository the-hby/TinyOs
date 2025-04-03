#ifndef KBD_H
#define KBD_H

#include "comm/types.h"

#define KEY_RSHIFT          0x36
#define KEY_LSHIFT          0x2A
#define KEY_CAPS            0x3A
#define KEY_ALT             0x38
#define KEY_CTRL            0x1D

#define KBD_PORT_DATA       0x60
#define KBD_PORT_STAT       0x64
#define KBD_PORT_CMD        0x64

#define KEY_F1              0x3B

#define KEY_E0              0xE0
#define KEY_E1              0xE1

#define KBD_STAT_RECV_READY     (1 << 0)

typedef struct _key_map_t{
    uint8_t normal;
    uint8_t func;
}key_map_t;

typedef struct _kbd_state_t{
    int caps_lock : 1;			
    int lshift_press : 1;       
    int rshift_press : 1;       
    int ralt_press : 1;          
    int lalt_press : 1;          
    int lctrl_press : 1;         
    int rctrl_press : 1;  
}kbd_state_t;

void kbd_init(void);
void exception_handler_kbd (void);

#endif