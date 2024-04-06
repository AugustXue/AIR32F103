#ifndef _SPI_H_
#define _SPI_H_
// #include "sys.h"
#include "delay.h"

// ±¾²âÊÔ³ÌÐòÊ¹ÓÃµÄÊÇÓ²¼þSPI½Ó¿ÚÇý¶¯
// SPIÊ±ÖÓÐÅºÅÒÔ¼°SPI¶Á¡¢Ð´ÐÅºÅÒý½Å²»¿É¸ü¸Ä
// SPIµÄÊ±ÖÓÒý½Å¶¨Òå¹Ì¶¨ÎªPB13
// SPIµÄ¶ÁÊý¾ÝÒý½Å¶¨Òå¹Ì¶¨ÎªPB14
// SPIµÄÐ´Êý¾ÝÒý½Å¶¨Òå¹Ì¶¨ÎªPB15

u8 SPI_WriteByte(SPI_TypeDef *SPIx, u8 Byte);
void SPI_SendData(SPI_TypeDef *SPIx, uint8_t *data, uint16_t size);
void SPI2_Init(void);
void SPI_SetSpeed(SPI_TypeDef *SPIx, u8 SpeedSet);

#endif
