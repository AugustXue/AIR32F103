#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delay.h"
#include "air32f10x.h"
#include "log_print.h"
#include "u8g2.h"
#include "oled.h"
#include "spi.h"
#include "air32f10x_gpio.h"

uint8_t u8x8_byte_4wire_hw_spi(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_ptr)
{
    switch (msg)
    {
    case U8X8_MSG_BYTE_SEND:
        SPI_SendData(SPI2, (uint8_t *)arg_ptr, arg_int);
        break;
    case U8X8_MSG_BYTE_INIT:
        break;
    case U8X8_MSG_BYTE_SET_DC:
        u8x8_gpio_SetDC(u8x8, arg_int);
        break;
    case U8X8_MSG_BYTE_START_TRANSFER:
        GPIO_WriteBit(GPIOB, OLED_CS, Bit_RESET);
        break;
    case U8X8_MSG_BYTE_END_TRANSFER:
        GPIO_WriteBit(GPIOB, OLED_CS, Bit_SET);
        break;
    default:
        return 0;
    }
    return 1;
}

uint8_t u8x8_stm32_gpio_and_delay(u8x8_t *u8x8, uint8_t msg, uint8_t arg_int, void *arg_prt)
{
    switch (msg)
    {
    case U8X8_MSG_GPIO_AND_DELAY_INIT:
        delay_ms(1);
        break;
    case U8X8_MSG_DELAY_MILLI:
        delay_ms(arg_int);
        break;
    case U8X8_MSG_GPIO_CS: // CS (chip select) pin: Output level in arg_int
        GPIO_WriteBit(GPIOB, GPIO_Pin_10, arg_int);
        break;
    case U8X8_MSG_GPIO_DC: // DC (data/cmd, A0, register select) pin: Output level in arg_int
        GPIO_WriteBit(GPIOB, GPIO_Pin_11, arg_int);
        break;
    }
    return 1;
}

void u8g2_init(u8g2_t *u8g2)
{
    /********************************************
    U8G2_R0     //不旋转，不镜像
    U8G2_R1     //旋转90度
    U8G2_R2     //旋转180度
    U8G2_R3     //旋转270度
    U8G2_MIRROR   //没有旋转，横向显示左右镜像
    U8G2_MIRROR_VERTICAL    //没有旋转，竖向显示镜像
    ********************************************/
    u8g2_Setup_sh1106_128x64_noname_f(u8g2, U8G2_R0, u8x8_byte_4wire_hw_spi, u8x8_stm32_gpio_and_delay); // 初始化1.3寸OLED u8g2 结构体
    // u8g2_Setup_ssd1306_128x64_noname_f(u8g2, U8G2_R0, u8x8_byte_4wire_hw_spi, u8x8_stm32_gpio_and_delay); // 初始化0.96寸OLED u8g2 结构体
    u8g2_InitDisplay(u8g2);     // 初始化显示
    u8g2_SetPowerSave(u8g2, 0); // 开启显示
}

void u8g2_test_demo(u8g2_t *u8g2)
{
    u8g2_FirstPage(u8g2);
    do
    {
        u8g2_SetFontMode(u8g2, 1);              /*字体模式选择*/
        u8g2_SetFontDirection(u8g2, 0);         /*字体方向选择*/
        u8g2_SetFont(u8g2, u8g2_font_inb24_mf); /*字库选择*/
        u8g2_DrawStr(u8g2, 0, 20, "U");

        u8g2_SetFontDirection(u8g2, 1);
        u8g2_SetFont(u8g2, u8g2_font_inb30_mn);
        u8g2_DrawStr(u8g2, 21, 8, "8");

        u8g2_SetFontDirection(u8g2, 0);
        u8g2_SetFont(u8g2, u8g2_font_inb24_mf);
        u8g2_DrawStr(u8g2, 51, 30, "g");
        u8g2_DrawStr(u8g2, 67, 30, "\xb2");

        u8g2_DrawHLine(u8g2, 2, 35, 47);
        u8g2_DrawHLine(u8g2, 3, 36, 47);
        u8g2_DrawVLine(u8g2, 45, 32, 12);
        u8g2_DrawVLine(u8g2, 46, 33, 12);

        u8g2_SetFont(u8g2, u8g2_font_4x6_tr);
        u8g2_DrawStr(u8g2, 1, 54, "github.com/olikraus/u8g2");
    } while (u8g2_NextPage(u8g2));
}

int main(void)
{
    delay_init();             // 初始化延时
    SPI2_Init();              // 初始化SPI2
    OLED_Init_GPIO();         // 初始化GPIO引脚
    delay_ms(200);            // 延时一段时间
    OLED_Reset();             // 复位OLED
    UART_to_log_init(115200); // 初始化打印串口

    u8g2_t u8g2;      // 显示器初始化结构体
    u8g2_init(&u8g2); // 显示器调用初始化函数

    while (1)
    {
        u8g2_test_demo(&u8g2);
    }
}
