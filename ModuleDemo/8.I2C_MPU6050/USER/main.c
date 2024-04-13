#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "delay.h"
#include "air32f10x.h"
#include "log_print.h"
#include "mpu6050.h"

uint8_t ID;                     // 定义用于存放ID号的变量
int16_t AX, AY, AZ, GX, GY, GZ; // 定义用于存放各个数据的变量

int main(void)
{
    delay_init();
    UART_to_log_init(115200);
    MPU6050_Init();
    ID = MPU6050_GetID();
    AX_DEBUG_PRINTF("ID = %02x", ID);

    while (1)
    {
        MPU6050_GetData(&AX, &AY, &AZ, &GX, &GY, &GZ); // 获取MPU6050的数据
        AX_DEBUG_PRINTF("AX = %d, AY = %d, AZ = %d, GX = %d, GY = %d, GZ = %d", AX, AY, AZ, GX, GY, GZ);
        delay_ms(100);
    }
}
