#ifndef _MY_STMA32F4_UART_LIB_H_
#define _MY_STMA32F4_UART_LIB_H_
#include "My_stm32f4_uart_driver.h"

typedef enum{
    rx =0,
    tx,
    rxtx

}UART_ComType;

typedef enum{
    Baud_9600 =0,
    Baud_115200 

}UART_BaudrateType;


int LIB_UART_Write(int c);
int LIB_UART_Read(void);

void LIB_UART_Init(UART_BaudrateType BR);






#endif