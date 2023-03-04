/******************************************************************************
 *
 * File Name: main.c
 *
 * Description: main file to display UltraSonic reading distance on LCD Screen
 *
 * Author: Omar Saad
 *
 *******************************************************************************/

#include "lcd.h"
#include "ultrasonic.h"
#include <util/delay.h> /* For the delay functions */


int main()
{
	/* distance variable to store distance from UltraSonic */
	uint16 distance = 0;

	/* Initialize the LCD */
	LCD_init();
	LCD_displayString("Distance= ");

	for(;;)
	{

		/* read distance value from UltraSonic*/
		distance= Ultrasonic_readDistance();

		/* Display the distance on LCD screen */
		LCD_moveCursor(0, 11);
		if(distance >= 100)
		{
			LCD_intgerToString(distance);
			LCD_displayString("cm");
		}
		else
		{
			LCD_intgerToString(distance);
			LCD_displayString("cm");
			/* In case the digital value is two or one digits print space in the next digit place */
			LCD_displayCharacter(' ');
		}
		_delay_ms(50);
	}
}
