#include "TheFlash.h"

TheFlash::TheFlash(Adafruit_NeoPixel* strip, int delay, int flashmillis)
{
	_strip = strip;
	_lastMilliSeconds = 0;
	_currentInterval = 0;
	_delay = delay;
	_flashmillis = flashmillis;
}

void TheFlash::RunFlash(unsigned long milliseconds)
{
	_currentInterval = milliseconds - _lastMilliSeconds;
	if (_currentInterval > _delay)
	{
		Flash();
		_lastMilliSeconds = milliseconds;
	}
}

void TheFlash::Flash()
{	
	StripOn();
	delay(_flashmillis);
	StripOff();
}

void TheFlash::StripOn()
{
	for (int i = 0; i < _strip->numPixels(); i++)
	{
		_strip->setPixelColor(i, 255, 255, 255);
	}
	_strip->show();
}

void TheFlash::StripOff()
{
	for (int i = 0; i < _strip->numPixels(); i++)
	{
		_strip->setPixelColor(i, 0, 0, 0);
	}
	_strip->show();
}