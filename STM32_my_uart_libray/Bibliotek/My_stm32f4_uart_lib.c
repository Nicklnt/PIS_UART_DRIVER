#include "My_stm32f4_uart_driver.h"
#include "My_stm32f4_uart_lib.h"
#include "my_stm32f4_gpio_driver.h"

#define USART_EN    0x2000u     //enable uart 
#define USART_DISABLE    0x0000u    //disable uart
#define USART_Rx_EN  0x04u  //enable transmite
#define USART_Tx_EN  0x08u  //enable receive

//uart stop bit configuration
#define USART_STOP_BIT_1 0x00u
#define USART_STOP_BIT_0_5 0x1000u
#define USART_STOP_BIT_2 0x2000u
#define USART_STOP_BIT_1_5 0x3000u

//flow control configuration
#define FLOW_CONTROL_RTS_EN 1u<<8 //request to send enable
#define FLOW_CONTROL_CTS_EN 1u<<9   //clear to send enable
#define FLOW_CONTROL_DIS 0x000

//configurate baud rate velocity
#define BAUD_RATE_9600 0x683u
#define BAUD_RATE_115200 0X9A0u

//define SR state
#define SR_EMPTY 0x0080u
#define SR_Data_recibe 0x0020u

#define BR_9600 UART_BaudrateType.Baud_9600 
#define BR_115200 UART_BaudrateType.Baud_115200

//funktion that set up UART
void LIB_UART_Init(UART_BaudrateType  BR)
{
    //1.enable clock access to uart2
    RCC->APB1ENR  |=  0x20000; 
    //2.enable clock access to portA
    RCC->AHB1ENR   |=0x01;
    //3.Enable pins for alternate fucntions, pa2, pa3
 
    GPIOA->MODER &=~0x00F0; //reset PA2 AND PA3
    GPIOA->MODER |= 0x00A0; //Enable alt. function for PA2, PA3
    //4.Configure type of alternate function

    GPIOA->AFR[0] &= ~0xFF00; //reset values 
    GPIOA->AFR[0] |= 0x7700;// alternative function USART in PA2 and PA3 (rx and tx)

    //Configure uart
  
    USART2->CR1  |=  USART_EN; //Enable uart 
    USART2->CR1  =  USART_Rx_EN + USART_Tx_EN; //Enabled tx rx
    USART2->CR2  =  USART_STOP_BIT_1; //default values
    USART2->CR3  =   FLOW_CONTROL_DIS; //default values
    if(BR == 0){
        USART2->BBR  =  BAUD_RATE_9600; //baud rate configuration int and fraction 9600

    }else{
         USART2->BBR  =  BAUD_RATE_115200; //baud rate configuration int and fraction 115200

    }
    
	
}

int LIB_UART_Read(void)
{
    while(!(USART2->SR & SR_Data_recibe)){} //while not data is  received
	return USART2->DR; // return data register
}

int LIB_UART_Write(int c)
{
    while(!(USART2->SR & SR_EMPTY)){} // while NO data is transfered to the shift register
	USART2->DR = (c & 0xFF); // data register = c (data)
	
  return c;

}


