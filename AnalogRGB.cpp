/**
 * Purpose: Simple wrapper library to control analog RGB strips via arduino
 * Copyright 2015
 * Author: Andrew Subowo (asubowo on GitHub)
 * Version: 1.0 - ALOOF ALBATROSS
 * Website - www.andrewsubowo.com
 */

#include "AnalogRGB.h"

/**
  * Constructor for the AnalogRGB wrapper.
  * Usage:
  *		AnalogRGB strip(_redPin, _greenPin, _bluePin);
  */
AnalogRGB::AnalogRGB(int _redPin, int _greenPin, int _bluePin) {

	redPin = _redPin;
	greenPin = _greenPin;
	bluePin = _bluePin;
	brightness = MAX_BRIGHTNESS;

	// Set the pins on the arduino
	pinMode(redPin, OUTPUT);
	pinMode(greenPin, OUTPUT);
	pinMode(bluePin, OUTPUT);

}

void AnalogRGB::init(int red, int green, int blue) {
	// left empty on purpose
}

/**
  * Sets the RGB strip to the color values given. This will override any brightness settings.
  */
void AnalogRGB::setColor(int red, int green, int blue) {
	
	redVal = red;
	greenVal = green;
	blueVal = blue;

	analogWrite(redPin, redVal);
	analogWrite(greenPin, greenVal);
	analogWrite(bluePin, blueVal);
}

/**
  * Overloaded method used to immediately set a brightness and color 
  */
void AnalogRGB::setColor(int red, int green, int blue, int brightnessPercentage) {
	int adjustedRed_, adjustedGreen_, adjustedBlue_;

	adjustedRed_ = (red * brightnessPercentage) / 100;
	adjustedGreen_ = (green * brightnessPercentage) / 100;
	adjustedBlue_ = (blue * brightnessPercentage) / 100;


	setColor(adjustedRed_, adjustedGreen_, adjustedBlue_);
}	

/**
  * Sets the brightness of the LED strip by fading to the new target voltage
  */
void AnalogRGB::setBrightness(int percentage) {

	int adjustedRed_, adjustedGreen_, adjustedBlue_;

	// Account for someone going past allowed limits because they're trying to prove a point
	if (percentage > 100) {
		percentage = MAX_BRIGHTNESS;
	}
	else if (percentage < 0) {
		percentage = 0;
	}

	brightness = percentage;

	adjustedRed_ = (redVal * brightness) / 100;
	adjustedGreen_ = (greenVal * brightness) / 100;
	adjustedBlue_ = (blueVal * brightness) / 100;

	fadeTo(adjustedRed_, adjustedGreen_, adjustedBlue_, DEFAULT_FADE);
	
}

/**
* Decreases the brightness level by 10 percent.
*/
void AnalogRGB::decreaseBrightness() {
	setBrightness(brightness - BRIGHTNESS_INCREMENT);
}

/**
  * Increases the brightness level by 10 percent.
  */
void AnalogRGB::increaseBrightness() {
	setBrightness(brightness + BRIGHTNESS_INCREMENT);
}

/**
  * Fades towards the targeted RGB color. Can be used to fade between brightness levels, etc.
  */
void AnalogRGB::fadeTo(int newRed, int newGreen, int newBlue, float speed) {
	
	while (redVal != newRed || greenVal != newGreen || blueVal != newBlue) {

		// Steps the red channel towards the target red (newRed)
		if (redVal > newRed) {
			redVal--;
		}

		else if (redVal < newRed) {
			redVal++;
		}

		// Steps the green channel towards the target green (newGreen)
		if (greenVal > newGreen) {
			greenVal--;
		}

		else if (greenVal < newGreen) {
			greenVal++;
		}

		// Steps the blue channel towards the target blue (newBlue)
		if (blueVal > newBlue) {
			blueVal--;
		}

		else if (blueVal < newBlue) {
			blueVal++;
		}

		setColor(redVal, greenVal, blueVal);

		//TODO: FIND A WAY TO GET RID OF BLOCKING CODE
		delay(speed);
	}
}

/**
* Fades to the target color with the default fade speed
*/
void AnalogRGB::fadeTo(int newRed, int newGreen, int newBlue) {
	fadeTo(newRed, newGreen, newBlue, DEFAULT_FADE);
}


