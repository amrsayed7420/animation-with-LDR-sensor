/*
 * main.c
 *
 *  Created on: Aug 14, 2023
 *      Author: First
 */

#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/DIO/DIO_interface.h"
#include "MCAL/ADC/ADC_interface.h"
#include "HAL/CLCD/CLCD_interface.h"
#include <util/delay.h>



u8 PLAYER[]=
{
		0x0E,
		0x0A,
		0x0E,
		0x04,
		0x0E,
		0x15,
		0x0A,
		0x11
};

u8 PLAYER21[]=
{
		 0x00,
		  0x00,
		  0x1E,
		  0x13,
		  0x13,
		  0x1E,
		  0x00,
		  0x00
};


u8 PLAYER22[]=
{
		 0x00,
		  0x04,
		  0x0A,
		  0x1C,
		  0x1C,
		  0x0A,
		  0x04,
		  0x00
};

int main(void)
{


	DIO_voidSetPinDirection(DIO_PORTA , DIO_PIN0 , DIO_INPUT);
	ADC_voidInit();
	CLCD_voidInit();


	DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN7,DIO_OUTPUT) ;
	DIO_voidSetPinDirection(DIO_PORTC,DIO_PIN6,DIO_OUTPUT) ;


	u32 Local_DigitalValue ;
	u32 Local_AnalogValue ;

	while(1)
	{

		// Digital
		Local_DigitalValue = ADC_u16ConvertedValue(ADC_CHANNEL_0);

		// Analog Value
//		Local_AnalogValue = (((u32)(Local_DigitalValue *2560))/1024) ;


		if (Local_DigitalValue>600)
				{
				CLCD_voidCLearDisplay();

				CLCD_voidSendString("GOOD NIGHT") ;

				CLCD_voidSendExtraChar(2,PLAYER21,CLCD_ROW_2,CLCD_COL_15)	;
				CLCD_voidSendExtraChar(3,PLAYER22,CLCD_ROW_2,CLCD_COL_16)	;



				_delay_ms(500) ;

				}
				else
				{	CLCD_voidCLearDisplay();
				CLCD_voidSendString("GOOD MORNING") ;

					CLCD_voidSendExtraChar(0,PLAYER,CLCD_ROW_2,CLCD_COL_16)	;



					_delay_ms(500) ;

				}


				CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_1);
				CLCD_voidSendNumber(Local_DigitalValue);


				CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_1);
				CLCD_voidSendNumber(Local_AnalogValue);



		///////////////////////////////
//		CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_1);
//		CLCD_voidSendString("TEMP=") ;
//		CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_7);
//		CLCD_voidSendNumber(TEMP);
//


		////////////////////////////////




//		// Analog Value
//				Local_AnalogValue = Local_DigitalValue *2560 ;
//
//		CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_1);
//			CLCD_voidSendNumber(Local_AnalogValue);
//
//
//		Local_AnalogValue=Local_AnalogValue/1024;
//
//		TEMP= Local_AnalogValue / 10  ;
//
//		CLCD_voidSetPosition(CLCD_ROW_1 , CLCD_COL_1);
//		CLCD_voidSendNumber(Local_DigitalValue);
//
//
//		CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_1);
//		CLCD_voidSendNumber(Local_AnalogValue);
//
//		CLCD_voidSetPosition(CLCD_ROW_2 , CLCD_COL_8);
//		CLCD_voidSendNumber(TEMP);


//		CLCD_voidSendData('.');
//		Local_AnalogValue = ((u32)(Local_DigitalValue *5 )% 1000) ;
//		CLCD_voidSendNumber(Local_AnalogValue );
//		_delay_ms(250);
//		CLCD_voidSendCommand(CLCD_CLEAR_DISPLAY);

//
//		if (Local_DigitalValue>600)
//		{
//		CLCD_voidCLearDisplay();
//		CLCD_voidSendExtraChar(0,PLAYER,CLCD_ROW_1,CLCD_COL_1)	;
//
//		DIO_voidSetPinValue(DIO_PORTC , DIO_PIN7 , DIO_LOW);
//		DIO_voidSetPinValue(DIO_PORTC , DIO_PIN6 , DIO_HIGH);
//
//		_delay_ms(500) ;
//
//		}
//		else
//		{	CLCD_voidCLearDisplay();
//			CLCD_voidSendExtraChar(0,PLAYER,CLCD_ROW_1,CLCD_COL_16)	;
//
//			DIO_voidSetPinValue(DIO_PORTC , DIO_PIN6 , DIO_LOW);
//			DIO_voidSetPinValue(DIO_PORTC , DIO_PIN7 , DIO_HIGH);
//
//			_delay_ms(500) ;
//
//		}
//

	}
	return 0 ;
}
