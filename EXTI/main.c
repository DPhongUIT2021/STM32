

#include "my_gpio.h"
#include "my_exti.h"

void GPIO_Init(void);
void EXTI0_Init(void);


int main(void)
{
	
	GPIO_Init();

	EXTI_Init();

	while(1)
	{

	}
}

void EXTI0_IRQHandler()
{
	if ((EXTI->PR & 0x0001) != 0) /* Check line 0 has triggered the IT */
	{
		EXTI->PR |= 0x0001;		  /* Clear the pending bit */
		GPIOB->ODR ^= GPIO_PIN_0; /* Toggle green led on PC0 */
	}
}

void GPIO_Init(void)
{
	/*I/O port C clock enable*/ 
	RCC->APB2ENR |= RCC_APB2ENR_IOPCEN;
	
	/*Configure pin C13 an output push pull mode*/
	GPIO_InitTypeDef GPIO_Info;
	GPIO_Info.Pin = GPIO_PIN_13;
	GPIO_Info.Mode = GPIO_MODE_OUTPUT_PP;
	GPIO_CR(GPIOC, &GPIO_Info);
	
}
void EXTI0_Init(void)
{
	EXTI_InitTypeDef EXTI_Info;

	EXTI_Info.line = GPIO_PIN_0;
	EXTI_Info.mode = EXTI_RISING;

	RCC_APB2ENR |= 0x01; /*Enable AFIO Clock*/
	AFIO_EXTICR(GPIOA, EXTI_Info.line);

	EXTI_REG(&EXTI_Info);

	/*Enable NVIC*/
	NVIC_EnableIRQ(EXTI0_IRQn);

	/*Set priority for EXTI0*/
	NVIC_SetPriority(EXTI0_IRQn, 0);
}


