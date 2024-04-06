#include "delay.h"
#include "air32f10x.h"
#include "oled.h"
#include <stdio.h>
#include <stdlib.h>

#define BTN1_PIN GPIO_Pin_8
#define BTN2_PIN GPIO_Pin_11
#define BTN3_PIN GPIO_Pin_12
#define BTN4_PIN GPIO_Pin_15

#define PRINTF_LOG printf

USART_TypeDef *USART_TEST = USART1;

void UART_Configuration(uint32_t bound);

void NVIC_Configuration(void)
{
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_2);
}

void btn_init()
{
    // 初始化按键引脚
    GPIO_InitTypeDef GPIO_InitStructure;
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);
    GPIO_InitStructure.GPIO_Pin = BTN1_PIN | BTN2_PIN | BTN3_PIN | BTN4_PIN;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;

    GPIO_Init(GPIOA, &GPIO_InitStructure);
}

int get_key_val()
{
    if (GPIO_ReadInputDataBit(GPIOA, BTN1_PIN) == Bit_RESET)
    {
        return 1;
    }
    if (GPIO_ReadInputDataBit(GPIOA, BTN2_PIN) == Bit_RESET)
    {
        return 2;
    }

    return 0;
}

int main(void)
{
    unsigned char key_num = 0;         // 按键
    unsigned char cactus_category = 0; // 仙人掌种类
    unsigned char cactus_length = 8;   // 仙人掌长度
    unsigned int score = 0;            // 当前得分
    unsigned int highest_score = 0;    // 最高分
    int height = 0;                    // 高度
    int cactus_pos = 128;              // 仙人掌坐标
    unsigned char cur_speed = 30;      // 当前速度
    char failed = 0;                   // 失败标记位
    char reset = 0;                    // 重置标记位

    delay_init();
    NVIC_Configuration();
    UART_Configuration(115200);
    btn_init();
    OLED_Init();
    OLED_Clear(0);

    OLED_DrawCover(); // 绘制封面
    while (get_key_val() != 2)
    {
        // 等待按键2按下后跳出循环
    };
    delay_ms(100);
    OLED_Clear(0);

    while (1)
    {
        if (failed == 1)
        {
            OLED_DrawRestart();

            key_num = get_key_val();
            if (key_num == 2)
            {
                if (score > highest_score)
                    highest_score = score;
                score = 0;
                failed = 0;
                height = 0;
                reset = 1;
                OLED_DrawDinoJump(reset);
                OLED_DrawCactusRandom(cactus_category, reset);
                OLED_Clear(0);
            }
            continue;
        }
        score++;
        if (height <= 0)
            key_num = get_key_val();

        OLED_DrawGround();
        OLED_DrawCloud();

        if (height > 0 || key_num == 1)
            height = OLED_DrawDinoJump(reset);
        else
            OLED_DrawDino();

        cactus_pos = OLED_DrawCactusRandom(cactus_category, reset);
        if (cactus_category == 0)
            cactus_length = 8;
        else if (cactus_category == 1)
            cactus_length = 16;
        else
            cactus_length = 24;

        if (cactus_pos + cactus_length < 0)
        {
            cactus_category = rand() % 4;
            OLED_DrawCactusRandom(cactus_category, 1);
        }

        if ((height < 16) && ((cactus_pos >= 16 && cactus_pos <= 32) || (cactus_pos + cactus_length >= 16 && cactus_pos + cactus_length <= 32)))
        {
            failed = 1;
        }

        OLED_ShowString(35, 0, "HI:", 12);
        OLED_ShowNum(58, 0, highest_score, 5, 12);
        OLED_ShowNum(98, 0, score, 5, 12);

        reset = 0;

        cur_speed = score / 20;
        if (cur_speed > 29)
            cur_speed = 29;
        delay_ms(30 - cur_speed);
        //		HAL_Delay(500);
        key_num = 0;
    }
}

void UART_Configuration(uint32_t bound)
{
    GPIO_InitTypeDef GPIO_InitStructure;
    USART_InitTypeDef USART_InitStructure;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_USART1, ENABLE);
    RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOA, ENABLE);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_9;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN_FLOATING;
    GPIO_Init(GPIOA, &GPIO_InitStructure);

    USART_InitStructure.USART_BaudRate = bound;
    USART_InitStructure.USART_WordLength = USART_WordLength_8b;
    USART_InitStructure.USART_StopBits = USART_StopBits_1;
    USART_InitStructure.USART_Parity = USART_Parity_No;
    USART_InitStructure.USART_HardwareFlowControl = USART_HardwareFlowControl_None;
    USART_InitStructure.USART_Mode = USART_Mode_Rx | USART_Mode_Tx;

    USART_Init(USART_TEST, &USART_InitStructure);
    USART_Cmd(USART_TEST, ENABLE);
}

int SER_PutChar(int ch)
{
    while (!USART_GetFlagStatus(USART_TEST, USART_FLAG_TC))
        ;
    USART_SendData(USART_TEST, (uint8_t)ch);

    return ch;
}

int fputc(int c, FILE *f)
{
    /* Place your implementation of fputc here */
    /* e.g. write a character to the USART */
    if (c == '\n')
    {
        SER_PutChar('\r');
    }
    return (SER_PutChar(c));
}
