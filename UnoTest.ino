/*
 Name:		UnoTest.ino
 Created:	25.10.2019 09:11:30
 Author:	langeoli
*/
#include <Adafruit_NeoPixel.h>
#include "ColorFlare.h"
#include "WhiteBright.h"
#include "TheRings.h"
#include "TheFlash.h"

#define NUM_PIXELS 20
#define PIXEL_PIN 6

// the setup function runs once when you press reset or power the board
Adafruit_NeoPixel strip(NUM_PIXELS, PIXEL_PIN, NEO_GRB);
int flareDelay = 150;
ColorFlare colorFlare(&strip, flareDelay);

int wheelDelay = 100;
WhiteBright whiteBright(&strip, wheelDelay);

int ringDelay = 50;
TheRings theRings(&strip, ringDelay);

int flashdelay = 500;
int flashtime = 15;
TheFlash theFlash(&strip, flashdelay, flashtime);

void setup() {
	strip.begin();           // INITIALIZE NeoPixel strip object (REQUIRED)
	strip.show();            // Turn OFF all pixels ASAP	
	//Serial.begin(9600);
}

// the loop function runs over and over again until power down or reset
void loop() {
	//theFlash.RunFlash(millis());
	theRings.RunTheRings(millis());
	//colorFlare.RunColorFlare(millis());
	//whiteBright.RunWheel(millis());	
	//rainbow(50);
	/*strip.setPixelColor(0, 65280 | 255 );
	strip.show();*/
}

void rainbow(int wait) {
	// Hue of first pixel runs 5 complete loops through the color wheel.
	// Color wheel has a range of 65536 but it's OK if we roll over, so
	// just count from 0 to 5*65536. Adding 256 to firstPixelHue each time
	// means we'll make 5*65536/256 = 1280 passes through this outer loop:
	for (long firstPixelHue = 0; firstPixelHue < 5 * 65536; firstPixelHue += 256) {
		for (int i = 0; i < strip.numPixels(); i++) { // For each pixel in strip...
		  // Offset pixel hue by an amount to make one full revolution of the
		  // color wheel (range of 65536) along the length of the strip
		  // (strip.numPixels() steps):
			int pixelHue = firstPixelHue + (i * 65536L / strip.numPixels());
			// strip.ColorHSV() can take 1 or 3 arguments: a hue (0 to 65535) or
			// optionally add saturation and value (brightness) (each 0 to 255).
			// Here we're using just the single-argument hue variant. The result
			// is passed through strip.gamma32() to provide 'truer' colors
			// before assigning to each pixel:
			strip.setPixelColor(i, strip.gamma32(strip.ColorHSV(pixelHue)));
		}
		strip.show(); // Update strip with new contents
		delay(wait);  // Pause for a moment
	}
}