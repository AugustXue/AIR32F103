#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delay.h"
#include "air32f10x.h"
#include "log_print.h"
#include "btn.h"

int main(void)
{
    delay_init();
    UART_to_log_init(115200);

    btn_init();

    while (1)
    {
        AX_DEBUG_PRINTF("key_val = %d", get_key_val());
        delay_ms(100);
    }
}
