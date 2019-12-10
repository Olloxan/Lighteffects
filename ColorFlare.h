#pragma once
#include <Adafruit_NeoPixel.h>

class ColorFlare
{
public:
	ColorFlare(Adafruit_NeoPixel* strip, int delay);
	void RunColorFlare(unsigned long milliseconds);
	void RunCandle(unsigned long milliseconds);

private:
	Adafruit_NeoPixel* _strip;
	unsigned long _lastMilliSeconds;
	unsigned int _currentInterval;
	int _delay;

	void Flare();	
	void Candle();
	long rand(long color);
	uint8_t rand();

	uint16_t _lowerBound;
	uint16_t _upperBound;
};
