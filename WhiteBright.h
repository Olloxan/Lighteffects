#pragma once
#include <Adafruit_NeoPixel.h>

class WhiteBright
{
public:
	WhiteBright(Adafruit_NeoPixel* strip, int delay);
	void RunWheel(unsigned long milliseconds);
	//void RunColorWheel(unsigned long milliseconds);

private:
	Adafruit_NeoPixel* _strip;
	unsigned long _lastMilliSeconds;
	unsigned int _currentInterval;
	int _delay;

	void Wheel();
	void ShutOffStrip();
};
