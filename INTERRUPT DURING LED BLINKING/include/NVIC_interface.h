/******************************************************************/
/* Author      : Mahmoud Makhlouf                                 */
/* Date        : 24 Aug 2020                                      */
/* Version     : V01                                              */
/******************************************************************/\

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_VoidEnableInterrupt (u8 Copy_u8InterruptNumber);
void MNVIC_VoidDisableInterrupt (u8 Copy_u8InterruptNumber);
void MNVIC_VoidSetPendingFlag (u8 Copy_u8InterruptNumber);
void MNVIC_VoidClearPendingFlag (u8 Copy_u8InterruptNumber);
u8 MNVIC_u8GetActiveFlag (u8 Copy_u8InterruptNumber);
void MNVIC_VoidSetPriority(s8 Copy_u8InterruptNumber , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority );


#endif /* NVIC_INTERFACE_H */
