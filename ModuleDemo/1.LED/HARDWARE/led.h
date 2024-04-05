#ifndef __LED_H__
#define __LED_H__

#include <stdint.h>

void led_init(void);
void led_on(uint8_t led);
void led_off(uint8_t led);

#endif
