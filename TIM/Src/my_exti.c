
#include "my_exti.h"

void AFIO_EXTICR(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
    uint16_t value=0x00;
	unsigned char pos = 0;
	
    if (GPIOx == GPIOB)
    {
        value = 0x01;
    }
    else if (GPIOx == GPIOC)
    {
        value = 0x02;
    }
    
    while(GPIO_PIN != 0x00u)
    {
        if(GPIO_PIN & 0x01)
        {
            AFIO->EXTICR[pos>>2]=(uint32_t)(value<<((pos & 0x03) * 4));
        }
        GPIO_PIN = GPIO_PIN >> 1;
        pos += 1;
    }
}

void EXTI_REG(EXTI_InitTypeDef *EXTI_Info)
{
    if ((EXTI_Info->mode & EXTI_IT) == EXTI_IT)
    {
        /*Configure the interrrupt mask*/
        EXTI->IMR |= EXTI_Info->line;
        EXTI->EMR &= ~(EXTI_Info->line);
    }
    else
    {
        /*Configure the event mask*/
        EXTI->EMR |= EXTI_Info->line;
        EXTI->IMR &= ~(EXTI_Info->line);
    }

    /*Enable or disable the rising trigger*/
    if((EXTI_Info->mode & EXTI_RISING) == EXTI_RISING)
    {
        EXTI->RTSR |= EXTI_Info->line;
    }
    else
    {
        EXTI->RTSR &= ~(EXTI_Info->line);
    }
    /*Enable or disable the falling triger*/
    if((EXTI_Info->mode & EXTI_FALLING) == EXTI_FALLING)
    {
        EXTI->FTSR |= EXTI_Info->line;
    }
    else
    {
        EXTI->FTSR &= ~(EXTI_Info->line);
    }
}



