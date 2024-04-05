#ifndef __LOG_PRINT_H__
#define __LOG_PRINT_H__

#include <stdio.h>

#define DEBUG_ENABLE 1 // 是否打印日志

#if DEBUG_ENABLE

#define PRINTF_LOG_LEVEL_ERROR 0
#define PRINTF_LOG_LEVEL_WARING 1
#define PRINTF_LOG_LEVEL_INFO 2
#define PRINTF_LOG_LEVEL_DEBUG 3

#define PRINTF_LOG_LEVEL PRINTF_LOG_LEVEL_DEBUG

#define PRINT_DIR printf

#define PRINTF_LOG(fmt, ...)                                         \
    do                                                               \
    {                                                                \
        PRINT_DIR("[%s,%d]" fmt, __func__, __LINE__, ##__VA_ARGS__); \
        PRINT_DIR("\r\n");                                           \
        fflush(stdout);                                              \
    } while (0)

#define PRINTF_LEVEL_LOG(level, fmt, ...)                                                  \
    do                                                                                     \
    {                                                                                      \
        if (level <= PRINTF_LOG_LEVEL)                                                     \
        {                                                                                  \
            if (level == PRINTF_LOG_LEVEL_ERROR)                                           \
                PRINT_DIR("[%s][%s,%d]" fmt, "ERROR", __func__, __LINE__, ##__VA_ARGS__);  \
            else if (level == PRINTF_LOG_LEVEL_WARING)                                     \
                PRINT_DIR("[%s][%s,%d]" fmt, "WARING", __func__, __LINE__, ##__VA_ARGS__); \
            else if (level == PRINTF_LOG_LEVEL_INFO)                                       \
                PRINT_DIR("[%s][%s,%d]" fmt, "INFO", __func__, __LINE__, ##__VA_ARGS__);   \
            else if (level == PRINTF_LOG_LEVEL_DEBUG)                                      \
                PRINT_DIR("[%s][%s,%d]" fmt, "DEBUG", __func__, __LINE__, ##__VA_ARGS__);  \
        }                                                                                  \
    } while (0)

#define hex_len (2)
#define SNPRINTF_LEN 148
#define AX_SNPRINTF_LEN 148

#define PRINTF_LEVEL_LOG_HEX(level, buff, size)                                                             \
    do                                                                                                      \
    {                                                                                                       \
        uint8_t snprintf_buff[SNPRINTF_LEN] = "";                                                           \
        for (int i = 0, j = 0; i < (int)size; i++, j++)                                                     \
        {                                                                                                   \
            if (((j * hex_len) + (hex_len + 1)) >= SNPRINTF_LEN)                                            \
            {                                                                                               \
                PRINTF_LEVEL_LOG(level, #buff ": \r\n%s", snprintf_buff);                                   \
                j = 0;                                                                                      \
            }                                                                                               \
            snprintf((char *)(snprintf_buff + (j * hex_len)), (hex_len + 1), "%02x", ((uint8_t *)buff)[i]); \
        }                                                                                                   \
        PRINTF_LEVEL_LOG(level, #buff ": %s\r\n", snprintf_buff);                                           \
    } while (0)

#define PRINTF_LEVEL_LOG_INFO_HEX(level, info, buff, size)                                                  \
    do                                                                                                      \
    {                                                                                                       \
        PRINTF_LEVEL_LOG(level, "info:%s", info);                                                           \
        uint8_t snprintf_buff[SNPRINTF_LEN] = "";                                                           \
        for (int i = 0, j = 0; i < size; i++, j++)                                                          \
        {                                                                                                   \
            if (((j * hex_len) + (hex_len + 1)) >= SNPRINTF_LEN)                                            \
            {                                                                                               \
                PRINTF_LEVEL_LOG(level, #buff ": \r\n%s", snprintf_buff);                                   \
                j = 0;                                                                                      \
            }                                                                                               \
            snprintf((char *)(snprintf_buff + (j * hex_len)), (hex_len + 1), "%02x", ((uint8_t *)buff)[i]); \
        }                                                                                                   \
        PRINTF_LEVEL_LOG(level, #buff ": %s\r\n", snprintf_buff);                                           \
    } while (0)

#define PRINTF_LEVEL_LOG_FMT_PRINTF(level, buff, size, fmt)                                              \
    do                                                                                                   \
    {                                                                                                    \
        uint8_t snprintf_buff[AX_SNPRINTF_LEN] = "";                                                     \
        for (int i = 0, j = 0, n = 0; i < size; i++)                                                     \
        {                                                                                                \
            j = snprintf((char *)(snprintf_buff + n), (AX_SNPRINTF_LEN - n), fmt, ((uint8_t *)buff)[i]); \
            if ((AX_SNPRINTF_LEN - n - 1 - j - j) < 0)                                                   \
            {                                                                                            \
                PRINTF_LEVEL_LOG(level, #buff ": \r\n%s", snprintf_buff);                                \
                n = 0;                                                                                   \
            }                                                                                            \
            else                                                                                         \
            {                                                                                            \
                n += j;                                                                                  \
            }                                                                                            \
        }                                                                                                \
        PRINTF_LEVEL_LOG(level, #buff ": %s\r\n", snprintf_buff);                                        \
    } while (0)

#define char_len (1)
#define PRINTF_LEVEL_LOG_CHAR_PRINTF(buff, size)                                                                                                                                                                                                                \
    do                                                                                                                                                                                                                                                          \
    {                                                                                                                                                                                                                                                           \
        uint8_t snprintf_buff[AX_SNPRINTF_LEN] = "";                                                                                                                                                                                                            \
        for (int i = 0, j = 0; i < size; i++, j++)                                                                                                                                                                                                              \
        {                                                                                                                                                                                                                                                       \
            if (((j * char_len) + (char_len + 1)) >= AX_SNPRINTF_LEN)                                                                                                                                                                                           \
            {                                                                                                                                                                                                                                                   \
                PRINTF_LEVEL_LOG(level, #buff ": \r\n%s", snprintf_buff);                                                                                                                                                                                       \
                j = 0;                                                                                                                                                                                                                                          \
            }                                                                                                                                                                                                                                                   \
            ((((uint8_t *)buff)[i] < 0x7f) && (((uint8_t *)buff)[i] >= 0x20)) ? snprintf((snprintf_buff + (j * char_len)), (char_len + 1), "%c", ((uint8_t *)buff)[i]) : snprintf((snprintf_buff + (j * char_len)), (char_len + 1), ".", ((uint8_t *)buff)[i]); \
        }                                                                                                                                                                                                                                                       \
        PRINTF_LEVEL_LOG(level, #buff ": %s\r\n", snprintf_buff);                                                                                                                                                                                               \
    } while (0)

#define AX_DEBUG_PRINTF PRINTF_LOG
#define AX_DEBUG_HEX_PRINTF(buff, size) PRINTF_LEVEL_LOG_HEX(PRINTF_LOG_LEVEL_DEBUG, buff, size)
#define AX_RELEASE_PRINTF(fmt, ...)     \
    do                                  \
    {                                   \
        PRINTF_LOG(fmt, ##__VA_ARGS__); \
    } while (0)
#define AX_DEBUG_FMT_PRINTF(buff, size, fmt) PRINTF_LEVEL_LOG_FMT_PRINTF(PRINTF_LOG_LEVEL_DEBUG, buff, size, fmt)
#define AX_DEBUG_CHAR_PRINTF(buff, size) PRINTF_LEVEL_LOG_HEX(PRINTF_LOG_LEVEL_DEBUG, buff, size)
#define AX_DEBUG_PRINTF_VER(ver, fmt)        \
    do                                       \
    {                                        \
        AX_DEBUG_PRINTF(#ver ": " fmt, ver); \
    } while (0)

#endif

void UART_to_log_init(int baudrate);

#endif
