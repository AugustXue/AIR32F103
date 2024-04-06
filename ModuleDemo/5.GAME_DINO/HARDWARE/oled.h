#ifndef __OLED_H
#define __OLED_H

//--------------OLED²ÎÊý¶¨Òå---------------------
#define PAGE_SIZE 8
#define XLevelL 0x02
#define XLevelH 0x10
#define YLevel 0xB0
#define Brightness 0xFF
#define WIDTH 128
#define HEIGHT 64

//-------------Ð´ÃüÁîºÍÊý¾Ý¶¨Òå-------------------
#define OLED_CMD 0  // Ð´ÃüÁî
#define OLED_DATA 1 // Ð´Êý¾Ý

//-----------------OLED¶Ë¿Ú¶¨Òå----------------
#define OLED_CS GPIO_Pin_10  // Æ¬Ñ¡ÐÅºÅ           PB11
#define OLED_DC GPIO_Pin_11  // Êý¾Ý/ÃüÁî¿ØÖÆÐÅºÅ  PB10
#define OLED_RST GPIO_Pin_12 // ¸´Î»ÐÅºÅ           PB12

//-----------------OLED¶Ë¿Ú²Ù×÷¶¨Òå----------------
#define OLED_CS_Clr() GPIO_ResetBits(GPIOB, OLED_CS)
#define OLED_CS_Set() GPIO_SetBits(GPIOB, OLED_CS)

#define OLED_DC_Clr() GPIO_ResetBits(GPIOB, OLED_DC)
#define OLED_DC_Set() GPIO_SetBits(GPIOB, OLED_DC)

#define OLED_RST_Clr() GPIO_ResetBits(GPIOB, OLED_RST)
#define OLED_RST_Set() GPIO_SetBits(GPIOB, OLED_RST)

// OLED¿ØÖÆÓÃº¯Êý
void OLED_WR_Byte(unsigned dat, unsigned cmd);
void OLED_Display_On(void);
void OLED_Display_Off(void);
void OLED_Set_Pos(unsigned char x, unsigned char y);
void OLED_Reset(void);
void OLED_Init_GPIO(void);
void OLED_Init(void);
void OLED_Set_Pixel(unsigned char x, unsigned char y, unsigned char color);
void OLED_Display(void);
void OLED_Clear(unsigned dat);

/******************************************************************************************/
void OLED_DrawBMPFast(const unsigned char BMP[]);
void oled_drawbmp_block_clear(int bx, int by, int clear_size);
void OLED_DrawGround(void);
void OLED_DrawCloud(void);
void OLED_DrawDino(void);
void OLED_DrawCactus(void);
int OLED_DrawCactusRandom(unsigned char ver, unsigned char reset);
int OLED_DrawDinoJump(char reset);
void OLED_DrawRestart(void);
void OLED_DrawCover(void);

#endif
