#ifndef _MY_STM32F4_GPIO_DRIVER_H_
#define _MY_STM32F4_GPIO_DRIVER_H_
#include <stdint.h>


#define PERIPH_BASE     0x40000000u
#define APB1PERIPH_BASE   (PERIPH_BASE + 0x00u) //base address APB1 bus
#define APB2PERIPH_BASE   (APB1PERIPH_BASE + 0x10000u) //base address APB2 bus

#define USART1_BASE     (APB2PERIPH_BASE + 0x1000u)
#define USART6_BASE     (APB2PERIPH_BASE + 0x1400u)
#define USART2_BASE  (APB1PERIPH_BASE + 0x4400u)

#define _USART volatile

typedef struct
{
    _USART uint32_t SR;
    _USART uint32_t DR;
    _USART uint32_t BBR;
    _USART uint32_t CR1;
    _USART uint32_t CR2;
    _USART uint32_t CR3;
    _USART uint32_t GTPR;

}USART_DefType;

#define USART2  ((USART_DefType*) USART2_BASE)
#define USART1  ((USART_DefType*) USART1_BASE)
#define USART6  ((USART_DefType*) USART6_BASE)













#endif