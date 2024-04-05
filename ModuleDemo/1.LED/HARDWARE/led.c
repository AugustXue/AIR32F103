#include "led.h"
#include "air32f10x.h"

#define LED1_PIN GPIO_Pin_13
#define LED2_PIN GPIO_Pin_14
#define LED3_PIN GPIO_Pin_15

void led_init(void)
{
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOC, ENABLE); // 使能GPIOC组时钟

    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_InitStruct.GPIO_Pin = LED1_PIN | LED2_PIN | LED3_PIN;
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_PP;
    GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_Init(GPIOC, &GPIO_InitStruct);
    GPIO_SetBits(GPIOC, LED1_PIN | LED2_PIN | LED3_PIN);
}

void led_on(uint8_t led)
{
    if (led == 1)
    {
        GPIO_ResetBits(GPIOC, LED1_PIN);
    }
    else if (led == 2)
    {
        GPIO_ResetBits(GPIOC, LED2_PIN);
    }
    else if (led == 3)
    {
        GPIO_ResetBits(GPIOC, LED3_PIN);
    }
}

void led_off(uint8_t led)
{
    if (led == 1)
    {
        GPIO_SetBits(GPIOC, LED1_PIN);
    }
    else if (led == 2)
    {
        GPIO_SetBits(GPIOC, LED2_PIN);
    }
    else if (led == 3)
    {
        GPIO_SetBits(GPIOC, LED3_PIN);
    }
}