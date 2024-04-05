#include "btn.h"
#include "air32f10x.h"

#define BTN1_PIN GPIO_Pin_8
#define BTN2_PIN GPIO_Pin_11
#define BTN3_PIN GPIO_Pin_12
#define BTN4_PIN GPIO_Pin_15

void btn_init(void)
{
    // 初始化按键引脚
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = BTN1_PIN | BTN2_PIN | BTN3_PIN | BTN4_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int get_key_val(void)
{
    if (GPIO_ReadInputDataBit(GPIOA, BTN1_PIN) == Bit_RESET)
    {
        return 1;
    }
    if (GPIO_ReadInputDataBit(GPIOA, BTN2_PIN) == Bit_RESET)
    {
        return 2;
    }
    if (GPIO_ReadInputDataBit(GPIOA, BTN3_PIN) == Bit_RESET)
    {
        return 3;
    }
    if (GPIO_ReadInputDataBit(GPIOA, BTN4_PIN) == Bit_RESET)
    {
        return 4;
    }
    return 0;
}
