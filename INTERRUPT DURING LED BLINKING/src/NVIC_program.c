/******************************************************************/
/* Author      : Mahmoud Makhlouf                                 */
/* Date        : 24 Aug 2020                                      */
/* Version     : V01                                              */
/******************************************************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"


void MNVIC_VoidEnableInterrupt (u8 Copy_u8InterruptNumber)
{
	if(Copy_u8InterruptNumber <=31)
	{
		NVIC_ISER0 = ( 1 << Copy_u8InterruptNumber );
	}

	else if (Copy_u8InterruptNumber <= 59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ISER1 = ( 1 << Copy_u8InterruptNumber );
	}

	else
	{
		/* Error Message */
	}
}

void MNVIC_VoidDisableInterrupt (u8 Copy_u8InterruptNumber)
{
	if(Copy_u8InterruptNumber <=31)
	{
		NVIC_ICER0 = ( 1 << Copy_u8InterruptNumber );
	}

	else if (Copy_u8InterruptNumber <= 59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ICER1 = ( 1 << Copy_u8InterruptNumber );
	}

	else
	{
		/* Error Message */
	}
}

void MNVIC_VoidSetPendingFlag (u8 Copy_u8InterruptNumber)
{
	if(Copy_u8InterruptNumber <=31)
	{
		NVIC_ISPR0 = ( 1 << Copy_u8InterruptNumber );
	}

	else if (Copy_u8InterruptNumber <= 59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ISPR1 = ( 1 << Copy_u8InterruptNumber );
	}

	else
	{
		/* Error Message */
	}
}

void MNVIC_VoidClearPendingFlag (u8 Copy_u8InterruptNumber)
{
	if(Copy_u8InterruptNumber <=31)
	{
		NVIC_ICPR0 = ( 1 << Copy_u8InterruptNumber );
	}

	else if (Copy_u8InterruptNumber <= 59)
	{
		Copy_u8InterruptNumber -= 32;
		NVIC_ICPR1 = ( 1 << Copy_u8InterruptNumber );
	}

	else
	{
		/* Error Message */
	}
}

u8 MNVIC_u8GetActiveFlag (u8 Copy_u8InterruptNumber)
{
	u8 Local_u8Result = 0;
	if(Copy_u8InterruptNumber <=31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8InterruptNumber);
	}

	else if (Copy_u8InterruptNumber <= 59)
	{
		Copy_u8InterruptNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8InterruptNumber);
	}

	else
	{
		/* Error Message */
	}

	return Local_u8Result;
}


void MNVIC_VoidSetPriority(s8 Copy_u8InterruptNumber , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority)
{
	/* For External Interrupts */
	u8 Local_u8Priority = Copy_u8SubPriority | Copy_u8GroupPriority << ((MNVIC_GROUP_SUB_DISTRIBUTION - MNVIC_GROUP_4_SUB_0)/0x100);
	if(Copy_u8InterruptNumber >= 0)
	{
		IPR [Copy_u8InterruptNumber] = Local_u8Priority << 4;
	}

	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;


	/* For Core Interupts */
}
