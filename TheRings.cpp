#include "TheRings.h"

TheRings::TheRings(Adafruit_NeoPixel* strip, int delay)
{
	_strip = strip;
	_lastMilliSeconds = 0;
	_currentInterval = 0;
	_delay = delay;
}

void TheRings::RunTheRings(unsigned long milliseconds)
{
	_currentInterval = milliseconds - _lastMilliSeconds;
	if (_currentInterval > _delay)
	{
		Ring();
		_lastMilliSeconds = milliseconds;
	}
}

void TheRings::Ring()
{
	static long hueR1 = 0;	
	static long hueReverse = 5 * 65536 / 3;
	static long hueR2 = 5 * 65536 / 6;

	hueR1 %= 5 * 65536;	
	hueReverse %= 5 * 65536;
	hueR2 %= 5 * 65536;
	for (int i = 0; i < _strip->numPixels(); i++)
	{				
		_strip->setPixelColor(i, RingV1(i, hueR1) | RingV1(i, hueReverse) | RingV1(i, hueR2));
	}	
	hueR1 += 256;
	hueReverse -= 96;
	hueR2 += 16;	
	
	_strip->show();
}

unsigned long TheRings::RingV1(int position, long hue)
{			
	int pixelHue = hue + (position * 65536L / _strip->numPixels());	
	return	_strip->gamma32(_strip->ColorHSV(pixelHue));
}

