
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
void SysTick_Handler(void);


#endif
