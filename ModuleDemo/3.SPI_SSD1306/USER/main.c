#include "delay.h"
#include "air32f10x.h"
#include "oled.h"

void NVIC_Configuration(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
}

int main(void)
{
    delay_init();
    NVIC_Configuration();
    OLED_Init();
    OLED_Clear(1);

    while (1)
    {
        OLED_Clear(1);
        delay_ms(1000);
        OLED_Clear(0);
        delay_ms(1000);
    }
}
