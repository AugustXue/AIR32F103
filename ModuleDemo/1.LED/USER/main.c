#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delay.h"
#include "air32f10x.h"
#include "log_print.h"
#include "led.h"

int main(void)
{
    delay_init();
    UART_to_log_init(115200);

    led_init();

    while (1)
    {
        for (int i = 1; i <= 3; i++)
        {
            led_on(i);
            delay_ms(100);
        }
        for (int i = 3; i >= 0; i--)
        {
            led_off(i);
            delay_ms(100);
        }
    }
}
