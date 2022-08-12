
#ifndef _MY_EXTI_H
#define _MY_EXTI_H


#include "stm32f10x.h"

/*======EXTI_mode define=======*/
/* Elements values convention: 0x A000 0000
 *                         -A : 1.EXTI mode, 0.GIPO mode
 */

#define EXTI_IT      ((uint16_t)0x1000) /*check IT or EV*/

#define EXTI_RISING  ((uint16_t)0x1100) /*check rising trigger*/
#define EXTI_FALLING ((uint16_t)0x1200) /*check falling trigger*/


/*====LOCAL TYPES(STRUCTURES, UINIONS, ENUMS)===*/

typedef struct 
{
    uint16_t line;
    uint16_t mode;
}EXTI_InitTypeDef;

void AFIO_EXTICR(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN);
void EXTI_REG(EXTI_InitTypeDef *EXTI_Struct);
void EXTI0_IRQHandler(void);


void AFIO_EXTICR(GPIO_TypeDef *GPIOx, uint16_t GPIO_PIN)
{
    uint16_t value = 0x00;
    unsigned char pos = 0;

    if (GPIOx == GPIOB)
    {
        value = 0x01;
    }
    else if (GPIOx == GPIOC)
    {
        value = 0x02;
    }

    while (GPIO_PIN != 0x00u)
    {
        if (GPIO_PIN & 0x01)
        {
            AFIO->EXTICR[pos >> 2] = (uint32_t)(value << ((pos & 0x03) * 4));
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
    if ((EXTI_Info->mode & EXTI_RISING) == EXTI_RISING)
    {
        EXTI->RTSR |= EXTI_Info->line;
    }
    else
    {
        EXTI->RTSR &= ~(EXTI_Info->line);
    }
    /*Enable or disable the falling triger*/
    if ((EXTI_Info->mode & EXTI_FALLING) == EXTI_FALLING)
    {
        EXTI->FTSR |= EXTI_Info->line;
    }
    else
    {
        EXTI->FTSR &= ~(EXTI_Info->line);
    }
}

#endif
