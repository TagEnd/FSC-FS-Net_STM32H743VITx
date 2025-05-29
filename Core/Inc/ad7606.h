#ifndef __AD7606_H__
#define __AD7606_H__

#include "main.h"
#include "gpio.h"
#include "math.h"
#include "stdio.h"
#define AD7606Addr *(volatile short *)(0x60003000)

#define testCHs 8

#define ADRANG 10.0

#define BufferLen 1000
#define ArrBufferLen 1004

extern uint8_t ping_finish_flag;
extern uint8_t pong_finish_flag;
extern uint8_t pingPongFlag;

extern short test_ping_buffer1[BufferLen + 4];
extern short test_ping_buffer2[BufferLen + 4];
extern short test_ping_buffer3[BufferLen + 4];
extern short test_ping_buffer4[BufferLen + 4];
extern short test_ping_buffer5[BufferLen + 4];
extern short test_ping_buffer6[BufferLen + 4];
extern short test_ping_buffer7[BufferLen + 4];
extern short test_ping_buffer8[BufferLen + 4];

extern short test_pong_buffer1[BufferLen + 4];
extern short test_pong_buffer2[BufferLen + 4];
extern short test_pong_buffer3[BufferLen + 4];
extern short test_pong_buffer4[BufferLen + 4];
extern short test_pong_buffer5[BufferLen + 4];
extern short test_pong_buffer6[BufferLen + 4];
extern short test_pong_buffer7[BufferLen + 4];
extern short test_pong_buffer8[BufferLen + 4];

void adc7606_init();

void get_ad7606();

void test_ad7606();

#endif