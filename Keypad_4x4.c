/*
 * Keypad.c
 *
 *  Created on: Oct 23, 2016
 *      Author: AmirEmeel
 */

#include "Keypad.h"

/* * * *c1  c2 c3   c4
 * row1  1  2  3   A        pin 8 in the keypad starting from left
 * row2  4  5  6   B        pin 7 in keypad
 * row3  7  8  9   C        pin 6  in keypad
 * row4  *  0   #   D         pin5  in keypad
 * pin   4  3  2    1
 *
 *
 */

/*Keypad initialization*/
void Keypad_init(void)
{
	/*configure Keypad columns as outputs others as inputs*/
	KEYPAD_PORT_DIR_R&=0xE8;
	KEYPAD_PORT_DIR_C|=0xF0;

	/*Pull up resistors for all rows*/
	SET_BIT(KEYPAD_PORT_OUT_R,FIRST_ROW);
	SET_BIT(KEYPAD_PORT_OUT_R,SECOND_ROW);
	SET_BIT(KEYPAD_PORT_OUT_R,THIRD_ROW);
	SET_BIT(KEYPAD_PORT_OUT_R,FOURTH_ROW);
/*  ouput 1 on columns so we could poll*/
	SET_BIT(KEYPAD_PORT_OUT_C,FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,THIRD_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,FOURTH_COL);
}

	
/* example code
 * int x; your variable
 * do{
 * x=Keypad_get_pressed_key();
 *
 *
 *    }while(x=="@");
 *
 * this code wiill keep searching til user press a proper key from the keypad
 *
 *
 */






/*Scanning any pressed key */
uint8 Keypad_get_pressed_key(void)
{
    uint8 KeyPressed="@";
	/*First column */

	_delay_ms(5);

	CLEAR_BIT(KEYPAD_PORT_OUT_C,FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,THIRD_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,FOURTH_COL);
	_delay_ms(5); //Configuration Stability

	if(BIT_CLEARED(KEYPAD_PORT_IN_R,FIRST_ROW)){KeyPressed='1';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,SECOND_ROW)){KeyPressed='4';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,THIRD_ROW)){KeyPressed='7';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,FOURTH_ROW)){KeyPressed='*';}

	/*Second column */
	SET_BIT(KEYPAD_PORT_OUT_C,FIRST_COL);
	CLEAR_BIT(KEYPAD_PORT_OUT_C,SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,THIRD_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,FOURTH_COL);
	_delay_ms(5);

	if(BIT_CLEARED(KEYPAD_PORT_IN_R,FIRST_ROW)){KeyPressed='2';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,SECOND_ROW)){KeyPressed='5';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,THIRD_ROW)){KeyPressed='8';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,FOURTH_ROW)){KeyPressed='0';}

	/*Third column */
	SET_BIT(KEYPAD_PORT_OUT_C,FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,SECOND_COL);
	CLEAR_BIT(KEYPAD_PORT_OUT_C,THIRD_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,FOURTH_COL);
	_delay_ms(5);

	if(BIT_CLEARED(KEYPAD_PORT_IN_R,FIRST_ROW)){KeyPressed='3';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,SECOND_ROW)){KeyPressed='6';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,THIRD_ROW)){KeyPressed='9';}
	else if(BIT_CLEARED(KEYPAD_PORT_IN_R,FOURTH_ROW)){KeyPressed='#';}


_delay_ms(5);
//check input for last col......fourth column
SET_BIT(KEYPAD_PORT_OUT_C,FIRST_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,SECOND_COL);
	SET_BIT(KEYPAD_PORT_OUT_C,THIRD_COL);
	CLEAR_BIT(KEYPAD_PORT_OUT_C,FOURTH_COL);
	_delay_ms(5);
	if(BIT_CLEARED(KEYPAD_PORT_IN_R,FIRST_ROW)){KeyPressed='A';}
		else if(BIT_CLEARED(KEYPAD_PORT_IN_R,SECOND_ROW)){KeyPressed='B';}
		else if(BIT_CLEARED(KEYPAD_PORT_IN_R,THIRD_ROW)){KeyPressed='C';}
		else if(BIT_CLEARED(KEYPAD_PORT_IN_R,FOURTH_ROW)){KeyPressed='D';}
	return KeyPressed;
}
