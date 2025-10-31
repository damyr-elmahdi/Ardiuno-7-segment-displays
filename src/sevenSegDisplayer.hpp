#ifndef SEVEN_SEG_DISPLAY_HPP
#define SEVEN_SEG_DISPLAY_HPP

#include <Arduino.h>

class SevenSegDisplayer
{
public:
	SevenSegDisplayer(int A, int B, int C , int D, int E, int F, int G);

	//  0 if success
	int printNumber(int digit);

	void reset();
	void setAll();

	template<typename T, typename ...Args>
	void set(T pin, Args... pins) {
		pinMode(pin, OUTPUT);
		digitalWrite(pin, HIGH);
		set(pins...);
	}
	void set(){}

private:
	int A_, B_, C_ , D_, E_, F_, G_;
};

#endif