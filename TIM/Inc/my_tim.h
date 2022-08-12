
#ifndef __MY_TIM_H
#define __MY_TIM_H


#include"stm32f10x.h"

void tim_SysTick_delay_1s(void);
void tim_SysTick_delay_s(uint32_t seconds);
void tim_SysTick_Init_IT(void);

void tim_TIM1_Init(void);
void tim_TIM1_delay_s(uint32_t s);
void tim_TIM1_delay_1s(void);

void tim_TIM2_Init(void);
void tim_TIM2_delay_ms(uint32_t ms);

void tim_TIM3_Init(void);
void tim_TIM3_OUTPUT_COMPARE(void);



#endif
