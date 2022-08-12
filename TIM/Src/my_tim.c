
/* Learn Timer--> mac dinh dung HSI RC 8MHz*/
/*SysTick(24bit)  (if CLKSOURCE=0 AHB/8)
    if 8MHz(CLKSOURCE=1) ==> 1s ~ 0x7A1200 (24 bit)
    if 1MHz(CLKSOURCE=0) ==> 1s ~ 0xF4240
    */
#include "my_tim.h"


void tim_SysTick_Init_IT(void)
{
    SysTick->CTRL = 0;          /*Stop all mode*/
    SysTick->LOAD = 0xF4240;    /*CLKSOURE 0: AHB/8 = 8/8 = 1MHz*/
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_TICKINT_Msk | SysTick_CTRL_ENABLE_Msk;
}

void tim_SysTick_delay_1s(void)
{
    SysTick->LOAD = 0x7A1200;
    SysTick->VAL = 0;
    SysTick->CTRL = SysTick_CTRL_CLKSOURCE | SysTick_CTRL_ENABLE_Msk;
    while ((SysTick->CTRL & SysTick_CTRL_COUNTFLAG_Msk) == 0)
    {
    }
    SysTick->CTRL &= ~SysTick_CTRL_ENABLE_Msk; /*Stop*/
    tim_SysTick_Init_IT();
}

void tim_SysTick_delay_s(uint32_t tim_second)
{
    while (tim_second > 0)
    {
        tim_SysTick_delay_1s();
        tim_second = tim_second - 1;
    }
}


/*TIMER counting 16 bit - All timer same clock
        8MHz RC:
                + Counting up: 1ms ~ 8000 = 0x00001F40
                */

/* Configure TIM2 Couting up 1ms*/
/*72MHZ/(72)=1MHz--> 1ms ~ 1000(0x3E8) tick(1MHz)*/
void tim_TIM2_Init(void) 
{
  RCC->APB1ENR |= RCC_APB1ENR_TIM2EN;
	TIM2->PSC=72-1;
  TIM2->ARR = 0xFFFF;
	TIM2->CR1 |= TIM_CR1_CEN | TIM_CR1_UDIS;
}

void tim_TIM2_delay_ms(uint32_t ms)
{
    while (ms > 0)
    {
      TIM2->CNT = 0;
			while((TIM2->CNT) < 1000);
			ms--;
    }
}


/* Configure TIM3 Couting up 1ms*/
void tim_TIM3_Init(void)
{
  RCC->APB1ENR |= RCC_APB1ENR_TIM3EN;
	TIM3->PSC = 72-1;
	TIM3->ARR = 10000;
	TIM3->EGR |= TIM_EGR_UG;
	TIM3->CR1 |= TIM_CR1_CEN;
}
/* Timer 3 chanel 1 - A6*/
void tim_TIM3_OUTPUT_COMPARE(void)
{
	
	tim_TIM3_Init();
	
  TIM3->CCER = TIM_CCER_CC1E;
	TIM3->CCMR1 = (TIM_CCMR1_OC1M_0 | TIM_CCMR1_OC1M_1); /*mode 3 Toggle active when CNT=CCR*/ 
	
	TIM3->CCR1 = 1000;
}



/* Configure TIM1 Couting down 1s*/
void tim_TIM1_Init(void)
{
    RCC->APB2ENR |= RCC_APB2ENR_TIM1EN;
    TIM1->CR1 |= TIM_CR1_ARPE | TIM_CR1_DIR;
    TIM1->ARR = 0x2710;
	TIM1->PSC = 7200-1; /* 8MHz / (PSC+1) = 10KHz*/
}

void tim_TIM1_delay_s(uint32_t s)
{
    while (s > 0)
    {
        s--;
        tim_TIM1_delay_1s();
    }
}
void tim_TIM1_delay_1s(void)
{
    TIM1->CR1 |= TIM_CR1_CEN;
    while ((TIM1->SR & TIM_SR_UIF) == 0)
    {
    }
    TIM1->CR1 &= ~TIM_CR1_CEN;
    TIM1->SR &= ~TIM_SR_UIF;
}

