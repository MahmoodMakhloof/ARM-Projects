/*
 * main.c
 *
 *  Created on: Nov 1, 2020
 *      Author: ma7mo
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "RCC_interface.h"
#include "GPIO_interface.h"
#include "NVIC_interface.h"
#include "STK_interface.h"

void main (void)
{
	/* Clock initialization */
	RCC_voidInitSysClock();
	/* Enable GPIOA */
	RCC_voidEnableClock(RCC_APB2,2);

	/* LED in pin 0 is a blinking led */
	MGPIO_VoidSetPinDirection(GPIOA,PIN0,OUTPUT_SPEED_2MHZ_PP);
	/* LED in pin 1 is a interrupted led */
	MGPIO_VoidSetPinDirection(GPIOA,PIN1,OUTPUT_SPEED_2MHZ_PP);

	/* SysTick initialization */
	MSTK_voidInit();

	/* New variable for led status */
	/* High or LOW */
	u8 Local_u8LED_STATUS = HIGH;

	/* Set Priority for EXTI0 group 1 , sub group 1 */
	MNVIC_VoidSetPriority(6,1,1);
	/* Enable EXTI0 */
	MNVIC_VoidEnableInterrupt(6);

	/* Initialize new variable as a counter for interrupt */
	u8 Local_u8Counter = 0;

	while(1)
	{
		/* LED (ON/OFF) */
		MGPIO_VoidSetPinValue(GPIOA,PIN0,Local_u8LED_STATUS);

		/* Wait */
		MSTK_voidSetBusyWait(500000);

		/* Toggle */
		TOG_BIT(Local_u8LED_STATUS,0);

		/* Counter increment */
		Local_u8Counter ++;

		/* Check LED ON 10 times */
		if(Local_u8Counter / 2 == 10)
		{
			/* Counter equal zero */
			Local_u8Counter = 0;

			/* stop and go to interrupt */
			MNVIC_VoidSetPendingFlag(6);
		}
	}

}

/* ISR for EXTI0 */
void EXTI0_IRQHandler(void)
{
	MGPIO_VoidSetPinValue(GPIOA,PIN1,HIGH);
	MSTK_voidSetBusyWait(500000);
	MGPIO_VoidSetPinValue(GPIOA,PIN1,LOW);
}


