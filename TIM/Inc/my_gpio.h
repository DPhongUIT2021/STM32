
#ifndef _MY_GPIO_H
#define _MY_GPIO_H


#include "stm32f10x.h"

/** @defgroup GPIO_pins_define GPIO pins define
  * @{
  */
#define GPIO_PIN_0                 ((uint16_t)0x0001)  /* Pin 0 selected    */
#define GPIO_PIN_1                 ((uint16_t)0x0002)  /* Pin 1 selected    */
#define GPIO_PIN_2                 ((uint16_t)0x0004)  /* Pin 2 selected    */
#define GPIO_PIN_3                 ((uint16_t)0x0008)  /* Pin 3 selected    */
#define GPIO_PIN_4                 ((uint16_t)0x0010)  /* Pin 4 selected    */
#define GPIO_PIN_5                 ((uint16_t)0x0020)  /* Pin 5 selected    */
#define GPIO_PIN_6                 ((uint16_t)0x0040)  /* Pin 6 selected    */
#define GPIO_PIN_7                 ((uint16_t)0x0080)  /* Pin 7 selected    */
#define GPIO_PIN_8                 ((uint16_t)0x0100)  /* Pin 8 selected    */
#define GPIO_PIN_9                 ((uint16_t)0x0200)  /* Pin 9 selected    */
#define GPIO_PIN_10                ((uint16_t)0x0400)  /* Pin 10 selected   */
#define GPIO_PIN_11                ((uint16_t)0x0800)  /* Pin 11 selected   */
#define GPIO_PIN_12                ((uint16_t)0x1000)  /* Pin 12 selected   */
#define GPIO_PIN_13                ((uint16_t)0x2000)  /* Pin 13 selected   */
#define GPIO_PIN_14                ((uint16_t)0x4000)  /* Pin 14 selected   */
#define GPIO_PIN_15                ((uint16_t)0x8000)  /* Pin 15 selected   */
#define GPIO_PIN_All               ((uint16_t)0xFFFF)  /* All pins selected */

#define GPIO_MODE_OUTPUT_PP ((uint32_t)0x03) /* Mode[]=11 max speed 50MHz, CNF[]=00 push pull*/
#define GPIO_MODE_OUTPUT_OD ((uint32_t)0x07)

#define GPIO_MODE_INPUT_PU_PD ((uint32_t)0x08)
#define GPIO_MODE_INPUT_F ((uint32_t)0x04)

#define GPIO_MODE_AF_PP ((uint32_t)0x0B)
#define GPIO_MODE_AF_OD ((uint32_t)0x0F)

/*===========LOCAL TYPES (STRUCTURES, UNIONS, ENUMS)=======*/
        

typedef struct      
{
  uint32_t Pin;
  uint32_t Mode;
}GPIO_InitTypeDef;       


/*======LOCAL VARIABLES=========*/

void GPIO_CR_V01(GPIO_TypeDef *GPIOx, uint32_t Mode, uint32_t Pin);
void GPIO_CR(GPIO_TypeDef *GPIOx, GPIO_InitTypeDef *GPIO_Struct);
void GPIO_Toggle(GPIO_TypeDef *GPIOx, uint16_t GPIO_Pin);




#endif



