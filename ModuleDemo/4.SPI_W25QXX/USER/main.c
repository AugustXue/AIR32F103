#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delay.h"
#include "air32f10x.h"
#include "w25qxx.h"

#define PRINTF_LOG printf

USART_TypeDef *USART_TEST = USART1;

void UART_Configuration(uint32_t bound);

int main(void)
{
    delay_init();
    UART_Configuration(115200);

    PRINTF_LOG("hello,xzp!\n");
    W25QXX_Init();
    while (W25QXX_ReadID() != W25Q128) // 检测不到W25Q128
    {
        PRINTF_LOG("W25Q128 Check Failed!\n");
        PRINTF_LOG("Read ID: 0x%x\n", W25QXX_ReadID());
        delay_s(2);
    }

    uint8_t xzp = 0;
    W25QXX_Write(&xzp, 0, 1);
    PRINTF_LOG("write is ending");
    while (1)
    {
        W25QXX_Read(&xzp, 0, 1);
        PRINTF_LOG("xzp = %d\n", xzp);
        xzp = xzp + 1;
        W25QXX_Write(&xzp, 0, 1);
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
