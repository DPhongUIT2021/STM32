

#include "my_gpio.h"

void GPIO_Init(void);

int main(void)
{
	
	GPIO_Init();
	
	while(1)
	{
		GPIO_Toggle(GPIOC, GPIO_PIN_13);
	}
}

void GPIO_Init(void)
{
	/*I/O port C clock enable*/ 
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	/*I/O port C clock enable*/ 
	RCC->APB2ENR |= RCC_APB2ENR_IOPBEN;
	
	/*Configure pin C13 an output push pull mode*/
	
	GPIO_InitTypeDef GPIO_Info;
	GPIO_Info.Pin = GPIO_PIN_13;
	GPIO_Info.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_CR(GPIOC, &GPIO_Info);
	
	/*Configure pin B0 an input pull up*/
	
	GPIO_Info.Pin = GPIO_PIN_0;
	GPIO_Info.Mode = GPIO_MODE_INPUT_PU_PD;
	GPIO_CR(GPIOB, &GPIO_Info);
	/*Set B0 high*/
	GPIOB->BSRR = GPIO_PIN_0;
	
	/*Configure pin B1 an input pull down*/
	
	GPIO_Info.Pin = GPIO_PIN_1;
	GPIO_Info.Mode = GPIO_MODE_INPUT_PU_PD;
	GPIO_CR(GPIOB, &GPIO_Info);
	/*Set B0 low*/
	GPIOB->BRR = GPIO_PIN_0;
	
}

