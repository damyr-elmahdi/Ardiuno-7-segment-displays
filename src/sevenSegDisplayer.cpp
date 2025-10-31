#include "sevenSegDisplayer.hpp"
#include <Arduino.h>

SevenSegDisplayer::SevenSegDisplayer(int A, int B, int C , int D, int E, int F, int G)
	: A_(A), B_(B), C_(C), D_(D), E_(E), F_(F), G_(G)
{
	reset();
}


void SevenSegDisplayer::reset()
{
	int leds [] = {A_, B_, C_, D_, E_, F_, G_};
	for (auto pin : leds) {
		pinMode(pin, OUTPUT);
		digitalWrite(pin, LOW); // initially shutdown
	}
}

void SevenSegDisplayer::setAll()
{
	int leds [] = {A_, B_, C_, D_, E_, F_, G_};
	for (auto pin : leds) {
		pinMode(pin, OUTPUT);
		digitalWrite(pin, HIGH);
	}
}

int SevenSegDisplayer::printNumber(int digit)
{
	int retCode = 0;
	reset();
	switch (digit)
	{
	case 0:
		set(A_, B_, C_, D_, E_, F_);
		break;
	case 1:
		set(B_, C_);
		break;
	case 2:
		set(A_, B_, G_, D_, E_);
		break;
	case 3:
		set(A_, B_, G_,C_, D_);
		break;
	case 4:
		set(F_, G_, B_, C_);
		break;
	case 5:
		set(A_, F_, G_, C_, D_);
		break;
	case 6:
		set(A_, F_, G_, C_, D_, E_);
		break;
	case 7:
		set(A_, B_, C_);
		break;
	case 8:
		setAll();
		break;
	case 9:
		set(A_, B_, G_, F_, C_, D_);
		break;
	
	default:
		retCode = -1;
		break;
	}

	return retCode;
}

