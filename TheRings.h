#pragma once

#include <Adafruit_NeoPixel.h>

class TheRings
{
public:
	TheRings(Adafruit_NeoPixel* strip, int delay);
	void RunTheRings(unsigned long milliseconds);

private:
	Adafruit_NeoPixel* _strip;
	unsigned long _lastMilliSeconds;
	unsigned int _currentInterval;
	int _delay;

	void Ring();

	unsigned long RingV1(int position, long hue);
};
