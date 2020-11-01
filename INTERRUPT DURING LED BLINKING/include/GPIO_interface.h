/**************************************************/
/* Author  : Mahmoud Makhlouf  					  */
/* Date    : 12 Aug 2020  						  */
/* Version : v01                                  */
/**************************************************/

#ifndef GPIO_INTERFACE_H_
#define GPIO_INTERFACE_H_

#define HIGH     1
#define LOW      0

#define HIGH_PORTL  0x00FF
#define HIGH_PORTH  0xFF00

#define GPIOA    0
#define GPIOB    1
#define GPIOC    2

#define PIN0     0
#define PIN1     1
#define PIN2     2
#define PIN3     3
#define PIN4     4
#define PIN5     5
#define PIN6     6
#define PIN7     7
#define PIN8     8
#define PIN9     9
#define PIN10    10
#define PIN11    11
#define PIN12    12
#define PIN13    13
#define PIN14    14
#define PIN15    15

/******* Modes for input case ********/
#define INPUT_ANLOG               0b0000
#define INPUT_FLOATING            0b0100
#define INPUT_PULLUP_PULLDOWN     0b1000

/******* Modes for output case *******/
      /* For Speed 10 MHZ */
#define OUTPUT_SPEED_10MHZ_PP     0b0001
#define OUTPUT_SPEED_10MHZ_OD     0b0101
#define OUTPUT_SPEED_10MHZ_AFPP   0b1001
#define OUTPUT_SPEED_10MHZ_AFOD   0b1101
      /* For Speed 50 MHZ */
#define OUTPUT_SPEED_2MHZ_PP      0b0010
#define OUTPUT_SPEED_2MHZ_OD      0b0110
#define OUTPUT_SPEED_2MHZ_AFPP    0b1010
#define OUTPUT_SPEED_2MHZ_AFOD    0b1110
      /* For Speed 2 MHZ */
#define OUTPUT_SPEED_50MHZ_PP     0b0011
#define OUTPUT_SPEED_50MHZ_OD     0b0111
#define OUTPUT_SPEED_50MHZ_AFPP   0b1011
#define OUTPUT_SPEED_50MHZ_AFOD   0b1111



void MGPIO_VoidSetPinDirection  ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Mode  );
void MGPIO_VoidSetPinValue      ( u8 Copy_u8Port , u8 Copy_u8Pin , u8 u8Copy_u8Value );
u8   MGPIO_u8GetPinValue        ( u8 Copy_u8Port , u8 Copy_u8Pin                     );
void MGPIO_voidSetPort          ( u8 Copy_u8port , u8 Copy_u8value                   );


#endif /* GPIO_INTERFACE_H_ */