/**
* Purpose: Simple wrapper library to control analog RGB strips via arduino
* Copyright 2015
* Author: Andrew Subowo (asubowo on GitHub)
* Version: 1.0 - ALOOF ALBATROSS
* Website - www.andrewsubowo.com
*/


#define _AnalogRGB.h

#include "Arduino.h"


// Define

#define LOW_BRIGHTNESS 30
#define MAX_BRIGHTNESS 100
#define BRIGHTNESS_INCREMENT 10
#define DEFAULT_FADE 4

class AnalogRGB {


public:

	int redPin, greenPin, bluePin;

	// Store the color data RGB
	int redVal, greenVal, blueVal;
	int brightness;

	AnalogRGB(int, int, int);
	void init(int, int, int);
	

	void setBrightness(int);
	void increaseBrightness();
	void decreaseBrightness();
	void setColor(int, int, int);
	void setColor(int, int, int, int);
	void fadeTo(int, int, int, float);

};