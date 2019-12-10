#pragma once

#include <Adafruit_NeoPixel.h>

class TheFlash
{
public:
	TheFlash(Adafruit_NeoPixel* strip, int delay, int flashmillis);
	void RunFlash(unsigned long milliseconds);

private:
	Adafruit_NeoPixel* _strip;
	unsigned long _lastMilliSeconds;
	unsigned int _currentInterval;
	int _delay;
	int _flashmillis;

	void Flash();
	void StripOn();
	void StripOff();
};
