#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delay.h"
#include "air32f10x.h"
#include "log_print.h"

int main(void)
{
    delay_init();
    UART_to_log_init(115200);
    while (1)
    {
        AX_DEBUG_PRINTF("Hello,xzp");
        delay_ms(100);
    }
}
