
#include "WhiteBright.h"

WhiteBright::WhiteBright(Adafruit_NeoPixel* strip, int delay)
{
	_strip = strip;
	_lastMilliSeconds = 0;
	_currentInterval = 0;
	_delay = delay;
}

void WhiteBright::RunWheel(unsigned long milliseconds)
{
	_currentInterval = milliseconds - _lastMilliSeconds;
	if (_currentInterval > _delay)
	{
		Wheel();
		_lastMilliSeconds = milliseconds;
	}
}

void WhiteBright::Wheel()
{
	static int currentStartpixel = 0;
	ShutOffStrip();
	int sequenceLenght = 5;
	for (int i = 0; i < sequenceLenght; i++)
	{
		int currentIndex = i + currentStartpixel;
		if (currentIndex > _strip->numPixels() - 1)
		{
			currentIndex -= _strip->numPixels();
		}
		_strip->setPixelColor(currentIndex, 255, 0, 0 );
	}
	_strip->show();
	currentStartpixel++;
	if (currentStartpixel > _strip->numPixels())
	{
		currentStartpixel = 0;
	}
}

void WhiteBright::ShutOffStrip()
{
	for (int i = 0; i < _strip->numPixels(); i++)
	{
		_strip->setPixelColor(i, 0, 0, 0);
	}
	_strip->show();
}