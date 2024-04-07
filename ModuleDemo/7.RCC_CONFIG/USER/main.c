#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delay.h"
#include "air32f10x.h"
#include "log_print.h"
#include "rcc_config.h"

int main(void)
{
    RCC_ClocksTypeDef clocks;
    RCC_ClkConfiguration(); // 配置时钟
    delay_init();
    UART_to_log_init(115200); // 初始化打印串口
    AX_DEBUG_PRINTF("AIR32F103 RCC Clock Config.\n");
    RCC_GetClocksFreq(&clocks); // 获取时钟频率

    AX_DEBUG_PRINTF("\n");
    AX_DEBUG_PRINTF("SYSCLK: %3.1fMhz, \nHCLK: %3.1fMhz, \nPCLK1: %3.1fMhz, \nPCLK2: %3.1fMhz, \nADCCLK: %3.1fMhz\n",
                    (float)clocks.SYSCLK_Frequency / 1000000, (float)clocks.HCLK_Frequency / 1000000,
                    (float)clocks.PCLK1_Frequency / 1000000, (float)clocks.PCLK2_Frequency / 1000000, (float)clocks.ADCCLK_Frequency / 1000000);

    while (1)
    {
        delay_ms(100);
    }
}
