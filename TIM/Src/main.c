

#include "my_tim.h"
#include "my_exti.h"
#include "my_gpio.h"

void GPIO_Init(void);

int main(void)
{

	GPIO_Init();

	tim_SysTick_Init_IT();

	tim_TIM1_Init();
	tim_TIM2_Init();

	tim_TIM3_OUTPUT_COMPARE();

	while (1)
	{
		tim_TIM2_delay_ms(1000);
		GPIO_Toggle(GPIOC, GPIO_PIN_13);
		tim_TIM1_delay_s(3);
	}
}

void SysTick_Handler(void)
{
	GPIO_Toggle(GPIOC, GPIO_PIN_13);
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
