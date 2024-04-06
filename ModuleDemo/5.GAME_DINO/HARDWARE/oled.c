#include "oled.h"
#include "stdlib.h"
#include "string.h"
#include "delay.h"
#include "spi.h"
#include "oled_font.h"

static unsigned char OLED_buffer[1024] =
	{
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
		0x00,
};

/*******************************************************************
 * @name       :void OLED_WR_Byte(unsigned dat,unsigned cmd)
 * @date       :2018-08-27
 * @function   :Write a byte of content to the OLED screen
 * @parameters :dat:Content to be written
				cmd:0-write command
									1-write data
 * @retvalue   :None
********************************************************************/
void OLED_WR_Byte(unsigned dat, unsigned cmd)
{
	if (cmd)
	{
		OLED_DC_Set();
	}
	else
	{
		OLED_DC_Clr();
	}
	OLED_CS_Clr();
	SPI_WriteByte(SPI2, dat);
	OLED_CS_Set();
}

/*******************************************************************
 * @name       :void OLED_Set_Pos(unsigned char x, unsigned char y)
 * @date       :2018-08-27
 * @function   :Set coordinates in the OLED screen
 * @parameters :x:x coordinates
				y:y coordinates
 * @retvalue   :None
********************************************************************/
void OLED_Set_Pos(unsigned char x, unsigned char y)
{
	// OLED_WR_Byte(YLevel + y / PAGE_SIZE, OLED_CMD);
	// OLED_WR_Byte((((x + 2) & 0xf0) >> 4) | 0x10, OLED_CMD);
	// OLED_WR_Byte(((x + 2) & 0x0f), OLED_CMD);

	OLED_WR_Byte(0xb0 + y, OLED_CMD);
	OLED_WR_Byte(((x & 0xf0) >> 4) | 0x10, OLED_CMD);
	OLED_WR_Byte((x & 0x0f), OLED_CMD);
}

/*******************************************************************
 * @name       :void OLED_Display_On(void)
 * @date       :2018-08-27
 * @function   :Turn on OLED display
 * @parameters :None
 * @retvalue   :None
 ********************************************************************/
void OLED_Display_On(void)
{
	OLED_WR_Byte(0X8D, OLED_CMD); // SET DCDCÃüÁî
	OLED_WR_Byte(0X14, OLED_CMD); // DCDC ON
	OLED_WR_Byte(0XAF, OLED_CMD); // DISPLAY ON
}

/*******************************************************************
 * @name       :void OLED_Display_Off(void)
 * @date       :2018-08-27
 * @function   :Turn off OLED display
 * @parameters :None
 * @retvalue   :None
 ********************************************************************/
void OLED_Display_Off(void)
{
	OLED_WR_Byte(0X8D, OLED_CMD); // SET DCDCÃüÁî
	OLED_WR_Byte(0X10, OLED_CMD); // DCDC OFF
	OLED_WR_Byte(0XAE, OLED_CMD); // DISPLAY OFF
}

/*******************************************************************
 * @name       :void OLED_Set_Pixel(unsigned char x, unsigned char y,unsigned char color)
 * @date       :2018-08-27
 * @function   :set the value of pixel to RAM
 * @parameters :x:the x coordinates of pixel
				y:the y coordinates of pixel
								color:the color value of the point
									  1-white
											0-black
 * @retvalue   :None
********************************************************************/
void OLED_Set_Pixel(unsigned char x, unsigned char y, unsigned char color)
{
	if (color)
	{
		OLED_buffer[(y / PAGE_SIZE) * WIDTH + x] |= (1 << (y % PAGE_SIZE)) & 0xff;
	}
	else
	{
		OLED_buffer[(y / PAGE_SIZE) * WIDTH + x] &= ~((1 << (y % PAGE_SIZE)) & 0xff);
	}
}

/*******************************************************************
 * @name       :void OLED_Display(void)
 * @date       :2018-08-27
 * @function   :Display in OLED screen
 * @parameters :None
 * @retvalue   :None
 ********************************************************************/
void OLED_Display(void)
{
	u8 i, n;
	for (i = 0; i < PAGE_SIZE; i++)
	{
		OLED_WR_Byte(YLevel + i, OLED_CMD); // ÉèÖÃÒ³µØÖ·£¨0~7£©
		OLED_WR_Byte(XLevelL, OLED_CMD);	// ÉèÖÃÏÔÊ¾Î»ÖÃ¡ªÁÐµÍµØÖ·
		OLED_WR_Byte(XLevelH, OLED_CMD);	// ÉèÖÃÏÔÊ¾Î»ÖÃ¡ªÁÐ¸ßµØÖ·
		for (n = 0; n < WIDTH; n++)
		{
			OLED_WR_Byte(OLED_buffer[i * WIDTH + n], OLED_DATA);
		}
	} // ¸üÐÂÏÔÊ¾
}

/*******************************************************************
 * @name       :void OLED_Clear(unsigned dat)
 * @date       :2018-08-27
 * @function   :clear OLED screen
 * @parameters :dat:0-Display full black
					1-Display full white
 * @retvalue   :None
********************************************************************/
void OLED_Clear(unsigned dat)
{
	if (dat)
	{
		memset(OLED_buffer, 0xff, sizeof(OLED_buffer));
	}
	else
	{
		memset(OLED_buffer, 0, sizeof(OLED_buffer));
	}
	OLED_Display();
}

/*******************************************************************
 * @name       :void OLED_Reset(void)
 * @date       :2018-08-27
 * @function   :Reset OLED screen
 * @parameters :dat:0-Display full black
					1-Display full white
 * @retvalue   :None
********************************************************************/
void OLED_Reset(void)
{
	OLED_RST_Set();
	delay_ms(100);
	OLED_RST_Clr();
	delay_ms(100);
	OLED_RST_Set();
}

/*******************************************************************
 * @name       :void OLED_Init_GPIO(void)
 * @date       :2018-08-27
 * @function   :Reset OLED screen
 * @parameters :None
 * @retvalue   :None
 ********************************************************************/
void OLED_Init_GPIO(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOB, ENABLE);				   // Ê¹ÄÜB¶Ë¿ÚÊ±ÖÓ
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12; // GPIOB10,11,12
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_Out_PP;					   // ÍÆÍìÊä³ö
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;					   // ËÙ¶È50MHz
	GPIO_Init(GPIOB, &GPIO_InitStructure);								   // ³õÊ¼»¯GPIOB10¡¢11¡¢12
	GPIO_SetBits(GPIOB, GPIO_Pin_10 | GPIO_Pin_11 | GPIO_Pin_12);
}

// /*******************************************************************
//  * @name       :void OLED_Init(void)
//  * @date       :2018-08-27
//  * @function   :initialise OLED SH1106 control IC
//  * @parameters :None
//  * @retvalue   :None
//  ********************************************************************/
void OLED_Init(void)
{
	SPI2_Init();	  // ³õÊ¼»¯SPI2
	OLED_Init_GPIO(); // ³õÊ¼»¯GPIO
	delay_ms(200);
	OLED_Reset(); // ¸´Î»OLED

	/**************³õÊ¼»¯SH1106*****************/
	OLED_Display_Off();			  // power off
	OLED_WR_Byte(0xAE, OLED_CMD); //--turn off oled panel
	OLED_WR_Byte(0x02, OLED_CMD); //---set low column address
	OLED_WR_Byte(0x10, OLED_CMD); //---set high column address
	OLED_WR_Byte(0x40, OLED_CMD); //--set start line address  Set Mapping RAM Display Start Line (0x00~0x3F)
	OLED_WR_Byte(0x81, OLED_CMD); //--set contrast control register
	OLED_WR_Byte(0xCF, OLED_CMD); // Set SEG Output Current Brightness
	OLED_WR_Byte(0xA1, OLED_CMD); //--Set SEG/Column Mapping     0xa0×óÓÒ·´ÖÃ 0xa1Õý³£
	OLED_WR_Byte(0xC8, OLED_CMD); // Set COM/Row Scan Direction   0xc0ÉÏÏÂ·´ÖÃ 0xc8Õý³£
	OLED_WR_Byte(0xA6, OLED_CMD); //--set normal display
	OLED_WR_Byte(0xA8, OLED_CMD); //--set multiplex ratio(1 to 64)
	OLED_WR_Byte(0x3f, OLED_CMD); //--1/64 duty
	OLED_WR_Byte(0xD3, OLED_CMD); //-set display offset	Shift Mapping RAM Counter (0x00~0x3F)
	OLED_WR_Byte(0x00, OLED_CMD); //-not offset
	OLED_WR_Byte(0xd5, OLED_CMD); //--set display clock divide ratio/oscillator frequency
	OLED_WR_Byte(0x80, OLED_CMD); //--set divide ratio, Set Clock as 100 Frames/Sec
	OLED_WR_Byte(0xD9, OLED_CMD); //--set pre-charge period
	OLED_WR_Byte(0xF1, OLED_CMD); // Set Pre-Charge as 15 Clocks & Discharge as 1 Clock
	OLED_WR_Byte(0xDA, OLED_CMD); //--set com pins hardware configuration
	OLED_WR_Byte(0x12, OLED_CMD);
	OLED_WR_Byte(0xDB, OLED_CMD); //--set vcomh
	OLED_WR_Byte(0x40, OLED_CMD); // Set VCOM Deselect Level
	OLED_WR_Byte(0x20, OLED_CMD); //-Set Page Addressing Mode (0x00/0x01/0x02)
	OLED_WR_Byte(0x02, OLED_CMD); //
	OLED_WR_Byte(0x8D, OLED_CMD); //--set Charge Pump enable/disable
	OLED_WR_Byte(0x14, OLED_CMD); //--set(0x10) disable
	OLED_WR_Byte(0xA4, OLED_CMD); // Disable Entire Display On (0xa4/0xa5)
	OLED_WR_Byte(0xA6, OLED_CMD); // Disable Inverse Display On (0xa6/a7)
	OLED_WR_Byte(0xAF, OLED_CMD); //--turn on oled panel
	OLED_Display_On();			  // power on
}

// 在指定位置显示一个字符,包括部分字符
// x:0~127
// y:0~63
// mode:0,反白显示;1,正常显示
// size:选择字体 16/12
void OLED_ShowChar(u8 x, u8 y, u8 chr, u8 Char_Size)
{
	unsigned char c = 0, i = 0;
	c = chr - ' '; // 得到偏移后的值
	if (x > 128 - 1)
	{
		x = 0;
		y = y + 2;
	}
	if (Char_Size == 16)
	{
		OLED_Set_Pos(x, y);
		for (i = 0; i < 8; i++)
			OLED_WR_Byte(F8X16[c * 16 + i], OLED_DATA);
		OLED_Set_Pos(x, y + 1);
		for (i = 0; i < 8; i++)
			OLED_WR_Byte(F8X16[c * 16 + i + 8], OLED_DATA);
	}
	else
	{
		OLED_Set_Pos(x, y);
		for (i = 0; i < 6; i++)
			OLED_WR_Byte(F6x8[c][i], OLED_DATA);
	}
}

// m^n函数
u32 oled_pow(u8 m, u8 n)
{
	u32 result = 1;
	while (n--)
		result *= m;
	return result;
}
// 显示2个数字
// x,y :起点坐标
// len :数字的位数
// size:字体大小
// mode:模式	0,填充模式;1,叠加模式
// num:数值(0~4294967295);
void OLED_ShowNum(u8 x, u8 y, u32 num, u8 len, u8 size2)
{
	u8 t, temp;
	u8 enshow = 0;
	for (t = 0; t < len; t++)
	{
		temp = (num / oled_pow(10, len - t - 1)) % 10;
		if (enshow == 0 && t < (len - 1))
		{
			if (temp == 0)
			{
				//				OLED_ShowChar(x+(size2/2)*t,y,' ',size2);
				OLED_ShowChar(x + (size2 / 2) * t, y, '0', size2);
				continue;
			}
			else
				enshow = 1;
		}
		OLED_ShowChar(x + (size2 / 2) * t, y, temp + '0', size2);
	}
}
// 显示一个字符号串
void OLED_ShowString(u8 x, u8 y, u8 *chr, u8 Char_Size)
{
	unsigned char j = 0;
	while (chr[j] != '\0')
	{
		OLED_ShowChar(x, y, chr[j], Char_Size);
		x += 8;
		if (x > 120)
		{
			x = 0;
			y += 2;
		}
		j++;
	}
}

/*************************************************  ********************************************************/

// 快速绘制图像
void OLED_DrawBMPFast(const unsigned char BMP[])
{
	unsigned int j = 0;
	unsigned char x, y;

	for (y = 0; y < 8; y++)
	{
		OLED_Set_Pos(0, y);
		OLED_WR_Byte(0x78, OLED_CMD);
		OLED_WR_Byte(0x40, OLED_CMD);
		for (x = 0; x < 128; x++)
		{
			OLED_WR_Byte(BMP[j++], OLED_DATA);
		}
	}
}

void oled_drawbmp_block_clear(int bx, int by, int clear_size)
{
	unsigned int i;
	OLED_Set_Pos(bx, by);
	OLED_WR_Byte(0x78, OLED_CMD);
	OLED_WR_Byte(0x40, OLED_CMD);

	for (i = 0; i < clear_size; i++)
	{
		if (bx + i > 128)
			break;
		OLED_WR_Byte(0x0, OLED_DATA);
	}
}

void OLED_DrawGround(void)
{
	static unsigned int pos = 0;
	unsigned char speed = 5;
	unsigned int ground_length = sizeof(GROUND);
	unsigned char x;

	OLED_Set_Pos(0, 7);
	OLED_WR_Byte(0x78, OLED_CMD);
	OLED_WR_Byte(0x40, OLED_CMD);

	for (x = 0; x < 128; x++)
	{
		OLED_WR_Byte(GROUND[(x + pos) % ground_length], OLED_DATA);
	}

	pos = pos + speed;
	// if(pos>ground_length) pos=0;
}

// 绘制云朵
void OLED_DrawCloud(void)
{
	static int pos = 128;
	static char height = 0;
	char speed = 3;
	int x;
	int start_x = 0;
	int length = sizeof(CLOUD);
	unsigned char byte;

	// if (pos + length <= -speed) pos = 128;

	if (pos + length <= -speed)
	{
		pos = 128;
		height = rand() % 3;
	}
	if (pos < 0)
	{
		start_x = -pos;
		OLED_Set_Pos(0, 1 + height);
	}
	else
	{
		OLED_Set_Pos(pos, 1 + height);
	}

	OLED_WR_Byte(0x78, OLED_CMD);
	OLED_WR_Byte(0x40, OLED_CMD);

	for (x = start_x; x < length + speed; x++)
	{
		if (pos + x > 127)
			break;
		if (x < length)
			byte = CLOUD[x];
		else
			byte = 0x0;

		OLED_WR_Byte(byte, OLED_DATA);
	}

	pos = pos - speed;
}

// 绘制小恐龙
void OLED_DrawDino(void)
{
	static unsigned char dino_dir = 0;
	unsigned int j = 0;
	unsigned char x, y;
	unsigned char byte;

	dino_dir++;
	dino_dir = dino_dir % 2;
	for (y = 0; y < 2; y++)
	{
		OLED_Set_Pos(16, 6 + y);
		OLED_WR_Byte(0x78, OLED_CMD);
		OLED_WR_Byte(0x40, OLED_CMD);

		for (x = 0; x < 16; x++)
		{
			j = y * 16 + x;
			byte = DINO[dino_dir][j];
			OLED_WR_Byte(byte, OLED_DATA);
		}
	}
}

// 绘制仙人掌障碍物
void OLED_DrawCactus(void)
{
	char speed = 5;
	static int pos = 128;
	int start_x = 0;
	int length = sizeof(CACTUS_2) / 2;

	unsigned int j = 0;
	unsigned char x, y;
	unsigned char byte;

	if (pos + length <= 0)
	{
		oled_drawbmp_block_clear(0, 6, speed);
		pos = 128;
	}

	for (y = 0; y < 2; y++)
	{
		if (pos < 0)
		{
			start_x = -pos;
			OLED_Set_Pos(0, 6 + y);
		}
		else
		{
			OLED_Set_Pos(pos, 6 + y);
		}

		OLED_WR_Byte(0x78, OLED_CMD);
		OLED_WR_Byte(0x40, OLED_CMD);

		for (x = start_x; x < length; x++)
		{
			if (pos + x > 127)
				break;
			j = y * length + x;
			byte = CACTUS_2[j];
			OLED_WR_Byte(byte, OLED_DATA);
		}
	}
	oled_drawbmp_block_clear(pos + length, 6, speed); // 清除残影
	pos = pos - speed;
}

// 绘制随机出现的仙人掌障碍物
int OLED_DrawCactusRandom(unsigned char ver, unsigned char reset)
{
	char speed = 5;
	static int pos = 128;
	int start_x = 0;
	int length = 0;

	unsigned int j = 0;
	unsigned char x, y;
	unsigned char byte;
	if (reset == 1)
	{
		pos = 128;
		oled_drawbmp_block_clear(0, 6, speed);
		return 128;
	}
	if (ver == 0)
		length = 8; // sizeof(CACTUS_1) / 2;
	else if (ver == 1)
		length = 16; // sizeof(CACTUS_2) / 2;
	else if (ver == 2 || ver == 3)
		length = 24;

	for (y = 0; y < 2; y++)
	{
		if (pos < 0)
		{
			start_x = -pos;
			OLED_Set_Pos(0, 6 + y);
		}
		else
		{
			OLED_Set_Pos(pos, 6 + y);
		}

		OLED_WR_Byte(0x78, OLED_CMD);
		OLED_WR_Byte(0x40, OLED_CMD);

		for (x = start_x; x < length; x++)
		{
			if (pos + x > 127)
				break;

			j = y * length + x;
			if (ver == 0)
				byte = CACTUS_1[j];
			else if (ver == 1)
				byte = CACTUS_2[j];
			else if (ver == 2)
				byte = CACTUS_3[j];
			else
				byte = CACTUS_4[j];

			OLED_WR_Byte(byte, OLED_DATA);
		}
	}

	oled_drawbmp_block_clear(pos + length, 6, speed);

	pos = pos - speed;
	return pos + speed;
}

// 绘制跳跃小恐龙
int OLED_DrawDinoJump(char reset)
{
	char speed_arr[] = {1, 1, 3, 3, 4, 4, 5, 6, 7};
	static char speed_idx = sizeof(speed_arr) - 1;
	static int height = 0;
	static char dir = 0;
	// char speed = 4;

	unsigned int j = 0;
	unsigned char x, y;
	char offset = 0;
	unsigned char byte;
	if (reset == 1)
	{
		height = 0;
		dir = 0;
		speed_idx = sizeof(speed_arr) - 1;
		return 0;
	}
	if (dir == 0)
	{
		height += speed_arr[speed_idx];
		speed_idx--;
		if (speed_idx < 0)
			speed_idx = 0;
	}
	if (dir == 1)
	{
		height -= speed_arr[speed_idx];
		speed_idx++;
		if (speed_idx > sizeof(speed_arr) - 1)
			speed_idx = sizeof(speed_arr) - 1;
	}
	if (height >= 31)
	{
		dir = 1;
		height = 31;
	}
	if (height <= 0)
	{
		dir = 0;
		height = 0;
	}
	if (height <= 7)
		offset = 0;
	else if (height <= 15)
		offset = 1;
	else if (height <= 23)
		offset = 2;
	else if (height <= 31)
		offset = 3;
	else
		offset = 4;

	for (y = 0; y < 3; y++) // 4
	{
		OLED_Set_Pos(16, 5 - offset + y);
		OLED_WR_Byte(0x78, OLED_CMD);
		OLED_WR_Byte(0x40, OLED_CMD);

		for (x = 0; x < 16; x++) // 32
		{
			j = y * 16 + x; // 32
			byte = DINO_JUMP[height % 8][j];

			OLED_WR_Byte(byte, OLED_DATA);
		}
	}
	if (dir == 0)
		oled_drawbmp_block_clear(16, 8 - offset, 16);
	if (dir == 1)
		oled_drawbmp_block_clear(16, 4 - offset, 16);
	return height;
}

// 绘制重启
void OLED_DrawRestart(void)
{
	unsigned int j = 0;
	unsigned char x, y;
	unsigned char byte;
	// OLED_Set_Pos(0, 0);
	for (y = 2; y < 5; y++)
	{
		OLED_Set_Pos(52, y);
		OLED_WR_Byte(0x78, OLED_CMD);
		OLED_WR_Byte(0x40, OLED_CMD);
		delay_ms(10);

		for (x = 0; x < 24; x++)
		{
			byte = RESTART[j++];
			OLED_WR_Byte(byte, OLED_DATA);
		}
	}
	OLED_ShowString(10, 3, "GAME", 16);
	OLED_ShowString(86, 3, "OVER", 16);
}

// 绘制封面
void OLED_DrawCover(void)
{
	OLED_DrawBMPFast(COVER);
}
