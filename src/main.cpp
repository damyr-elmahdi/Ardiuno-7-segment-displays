#include <Arduino.h>

#include "sevenSegDisplayer.hpp"

// Left display (tens digit) - pins 2-8 map to segments B,A,C,D,E,F,G
// So we pass them in order: A, B, C, D, E, F, G = 3, 2, 4, 5, 6, 7, 8
SevenSegDisplayer tensDisp {3, 2, 4, 5, 6, 7, 8};

// Right display (units digit) - pins 9-A1 map to segments A,B,C,D,E,F,G
// So we pass them in order: A, B, C, D, E, F, G = 9, 10, 11, 12, 13, A0, A1
SevenSegDisplayer unitsDisp {9, 10, 11, 12, 13, A0, A1};

void setup()
{
	for (int i = 0; i < 100; i++) {
		int tensDigit = i / 10;
		int unitsDigit = i % 10;
		
		tensDisp.printNumber(tensDigit);
		unitsDisp.printNumber(unitsDigit);
		
		delay(500);
	}
	
	tensDisp.reset();
	unitsDisp.reset();
}

void loop()
{

}