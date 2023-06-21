//include libraries
#include  "My_stm32f4_uart_lib.h"
#include "my_stm32f4_gpio_driver.h"
#include "My_stm32f4_uart_driver.h"

//main
int main(void){
	
	int control = 0; //variable to control the loop
	
	
	LIB_UART_Init(BR_9600); //set up uart

	while(control < 10000){
		
		LIB_UART_Write(control); //send control value to DR

		LIB_UART_Read();	//read DR
		++control;

	}
	
	
	
		
   
}
