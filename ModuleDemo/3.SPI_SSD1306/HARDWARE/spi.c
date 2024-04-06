#include "spi.h"

/*****************************************************************************
 * @name       :u8 SPI_WriteByte(SPI_TypeDef* SPIx,u8 Byte)
 * @date       :2018-08-27
 * @function   :Write a byte of data using STM32's hardware SPI
 * @parameters :SPIx: SPI type,x for 1,2,3
				Byte:Data to be written
 * @retvalue   :Data received by the bus
******************************************************************************/
u8 SPI_WriteByte(SPI_TypeDef *SPIx, u8 Byte)
{
	while ((SPIx->SR & SPI_I2S_FLAG_TXE) == RESET)
		;			 // µÈ´ý·¢ËÍÇø¿Õ
	SPIx->DR = Byte; // ·¢ËÍÒ»¸öbyte
	while ((SPIx->SR & SPI_I2S_FLAG_RXNE) == RESET)
		;			 // µÈ´ý½ÓÊÕÍêÒ»¸öbyte
	return SPIx->DR; // ·µ»ØÊÕµ½µÄÊý¾Ý
}

void SPI_SendData(SPI_TypeDef *SPIx, uint8_t *data, uint16_t size)
{
	for (uint16_t i = 0; i < size; i++)
	{
		while ((SPIx->SR & SPI_I2S_FLAG_TXE) == RESET)
			; // 等待发送缓冲区为空

		SPIx->DR = data[i]; // 发送一个字节数据

		while ((SPIx->SR & SPI_I2S_FLAG_RXNE) == RESET)
			; // 等待接收缓冲区非空

		// 读取SPI数据寄存器，清除RXNE标志位
		uint8_t dummy = SPIx->DR;
		(void)dummy; // 防止编译器警告
	}
}

/*****************************************************************************
 * @name       :void SPI_SetSpeed(SPI_TypeDef* SPIx,u8 SpeedSet)
 * @date       :2018-08-09
 * @function   :Set hardware SPI Speed
 * @parameters :SPIx: SPI type,x for 1,2,3
				SpeedSet:0-high speed
												 1-low speed
 * @retvalue   :None
******************************************************************************/
void SPI_SetSpeed(SPI_TypeDef *SPIx, u8 SpeedSet)
{
	SPIx->CR1 &= 0XFFC7;
	if (SpeedSet == 1) // ¸ßËÙ
	{
		SPIx->CR1 |= SPI_BaudRatePrescaler_2; // Fsck=Fpclk/2
	}
	else // µÍËÙ
	{
		SPIx->CR1 |= SPI_BaudRatePrescaler_32; // Fsck=Fpclk/32
	}
	SPIx->CR1 |= 1 << 6; // SPIÉè±¸Ê¹ÄÜ
}

/*****************************************************************************
 * @name       :void SPI2_Init(void)
 * @date       :2018-08-09
 * @function   :Initialize the STM32 hardware SPI2
 * @parameters :None
 * @retvalue   :None
 ******************************************************************************/
void SPI2_Init(void)
{
	SPI_InitTypeDef SPI_InitStructure;
	GPIO_InitTypeDef GPIO_InitStructure;

	// ÅäÖÃSPI2¹Ü½Å
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_AFIO | RCC_APB2Periph_GPIOB, ENABLE);
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_13 | GPIO_Pin_15;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF_PP;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_14;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	GPIO_Init(GPIOB, &GPIO_InitStructure);

	// SPI2ÅäÖÃÑ¡Ïî
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_SPI2, ENABLE);

	SPI_InitStructure.SPI_Direction = SPI_Direction_2Lines_FullDuplex;
	SPI_InitStructure.SPI_Mode = SPI_Mode_Master;
	SPI_InitStructure.SPI_DataSize = SPI_DataSize_8b;
	SPI_InitStructure.SPI_CPOL = SPI_CPOL_Low;
	SPI_InitStructure.SPI_CPHA = SPI_CPHA_1Edge;
	SPI_InitStructure.SPI_NSS = SPI_NSS_Soft;
	SPI_InitStructure.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_2;
	SPI_InitStructure.SPI_FirstBit = SPI_FirstBit_MSB;
	SPI_InitStructure.SPI_CRCPolynomial = 7;
	SPI_Init(SPI2, &SPI_InitStructure);

	// Ê¹ÄÜSPI2
	SPI_Cmd(SPI2, ENABLE);
}
