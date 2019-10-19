#include "stm32f4xx_hal.h"              // Keil::Device:STM32Cube HAL:Common

#define green GPIO_PIN_12
#define orange GPIO_PIN_13
#define red GPIO_PIN_14
#define blue GPIO_PIN_15

void GPIO_Init(void);
	
int main()
{
	GPIO_Init();
	int i;
	while(1)
	{
		HAL_GPIO_TogglePin(GPIOD,green|orange|red|blue);
		for(i=0;i<500000;i++){}
	}
}
void GPIO_Init(void)
{
	GPIO_InitTypeDef GPIO_InitStruct;
	/*GPIO Ports Clock Enable */
	__HAL_RCC_GPIOH_CLK_ENABLE();
	__HAL_RCC_GPIOD_CLK_ENABLE();
	HAL_GPIO_WritePin(GPIOD,GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15,GPIO_PIN_RESET);
	
	/* Configure GPIO pins : PD12 PD13 PD14 PD15 */
	GPIO_InitStruct.Pin=GPIO_PIN_12|GPIO_PIN_13|GPIO_PIN_14|GPIO_PIN_15;
	GPIO_InitStruct.Mode=GPIO_MODE_OUTPUT_PP;
	GPIO_InitStruct.Pull=GPIO_NOPULL;
	GPIO_InitStruct.Speed=GPIO_SPEED_FREQ_LOW;
	HAL_GPIO_Init(GPIOD,&GPIO_InitStruct);
}
