
#include "my_gpio.h"

void GPIO_CR(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Struct)
{
	unsigned char position = 0x00u;
	unsigned char check_pin = 0;
	volatile uint32_t *configreister;
	uint32_t pos_in_CR;

	while (GPIO_Struct->Pin != 0x00u)
	{
		check_pin = ((GPIO_Struct->Pin) & 0x01u);
		if (check_pin)
		{
			configreister = (position < 8) ? &GPIOx->CRL : &GPIOx->CRH;
			pos_in_CR = (position < 8) ? (position * 4) : ((position - 8) * 4);
			MODIFY_REG(*configreister, 0x0Ful << pos_in_CR, GPIO_Struct->Mode << pos_in_CR);
		}
		GPIO_Struct->Pin = ((GPIO_Struct->Pin) >> 1);
		position += 1;
	}
}

void GPIO_Toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin)
{
	uint32_t odr;
	odr = GPIOx->ODR & GPIO_Pin;
	GPIOx->BSRR = (odr << 16u) | (~odr & GPIO_Pin);
}

void GPIO_CR_V01(GPIO_TypeDef *GPIOx, uint32_t Pin, uint32_t Mode)
{
	GPIO_InitTypeDef GPIO_InitStruct = {0};
	GPIO_InitStruct.Pin = Pin;
	GPIO_InitStruct.Mode = Mode;
	GPIO_CR(GPIOx, &GPIO_InitStruct);
}
