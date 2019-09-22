/*
 * Keypad.h
 *
 *  Created on: Oct 23, 2016
 *      Author: AmirEmeel
 */

#ifndef KEYPAD_H_
#define KEYPAD_H_

#include "DIO.h"
#include "PLATFORM_TYPES.h"
#include <avr/io.h>
#include <util/delay.h>

/* * * *c1  c2 c3   c4
 * row1  1  2  3   A        pin 8 in the keypad starting from left
 * row2  4  5  6   B        pin 7 in keypad
 * row3  7  8  9   C        pin 6  in keypad
 * row4  *  0   #   D         pin5  in keypad
 * pin   4  3  2    1
 *
 *
 */

/* proper connection
 *  keypad      Atmega
 *   pin8       PA2
 *   pin7       PA1
 *   pin6       PA0
 *   pin5       PA4
 *   pin4       PC5
 *   pin3       PC6
 *   pin2       PC7
 *   pin1       PC4
 *
 * */


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




#define KEYPAD_PORT_OUT_R PORTA
#define KEYPAD_PORT_IN_R  PINA
#define KEYPAD_PORT_DIR_R DDRA

#define KEYPAD_PORT_OUT_C PORTC
#define KEYPAD_PORT_IN_C  PINC
#define KEYPAD_PORT_DIR_C DDRC

#define FIRST_ROW  (2)      //pa2
#define SECOND_ROW (1)       //pa1
#define THIRD_ROW  (0)       //pa0
#define FOURTH_ROW (4)       //pa4

#define FIRST_COL  (5)      //PC5
#define SECOND_COL (6)       //PC6
#define THIRD_COL  (7)       //Pc7
#define  FOURTH_COL (4)     //pc4


void  Keypad_init(void);
uint8 Keypad_get_pressed_key(void);


#endif /* KEYPAD_H_ */
