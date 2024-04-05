#ifndef __DELAY_H
#define __DELAY_H 			   
#include 	"air32f10x.h"
	 
void delay_init(void);
void delay_ms(uint16_t nms);
void delay_us(uint32_t nus);
void delay_s(u16 ns);

#endif

