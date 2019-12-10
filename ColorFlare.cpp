#include "ColorFlare.h"

ColorFlare::ColorFlare(Adafruit_NeoPixel* strip, int delay)
{
	_strip = strip;
	_lastMilliSeconds = 0;
	_currentInterval = 0;
	_delay = delay;

	_lowerBound = 2000;
	_upperBound = 7500;
}

void ColorFlare::RunColorFlare(unsigned long milliseconds)
{
	_currentInterval = milliseconds - _lastMilliSeconds;
	if (_currentInterval > _delay)
	{
		Flare();
		_lastMilliSeconds = milliseconds;
	}
}

void ColorFlare::Flare()
{
	static long pixelHue = 0;
	
	pixelHue += 128;	
	if(pixelHue > 5 * 65536)	
		pixelHue = 0;
		
	for (int i = 0; i < _strip->numPixels(); i++)
	{
		_strip->setPixelColor(i, _strip->gamma32(_strip->ColorHSV(rand(pixelHue), 255, 255 - rand())));
	}
	_strip->show();
}

void ColorFlare::RunCandle(unsigned long milliseconds)
{
	_currentInterval = milliseconds - _lastMilliSeconds;
	if (_currentInterval > _delay)
	{
		Candle();
		_lastMilliSeconds = milliseconds;
	}
}

void ColorFlare::Candle()
{
	static long pixelHue = 0;
	static bool toYellow = true;

	if (toYellow)
	{
		pixelHue += 128;
		if (pixelHue > _upperBound)		
			toYellow = false;		
	}
	else
	{
		pixelHue -= 128;
		if (pixelHue < _lowerBound)		
			toYellow = true;		
	}		

	for (int i = 0; i < _strip->numPixels(); i++)
	{
		_strip->setPixelColor(i, _strip->gamma32(_strip->ColorHSV(rand(pixelHue), 255, 255 - rand())));
	}
	_strip->show();
}

long ColorFlare::rand(long color)
{
	long temp = random(-250, 250) + color;
	temp = min(temp, 5*65536);
	temp = max(temp, 0);
	return temp;
}

uint8_t ColorFlare::rand()
{
	return (uint8_t)random(32);
}