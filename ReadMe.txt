========================================================================
AnalogRGB Project Overview
========================================================================

NOTICE!!! THIS REPO IS CURRENTLY UNSTABLE. IT IS USABLE BUT NOT RECOMMENDED.

AnalogRGB.cpp
    This is the main application source file.

========================================================================
USAGE
========================================================================

Initialize an AnalogRGB object
	AnalogRGB strip(1, 2, 3); // Using pins 1, 2, 3 as an example only
	analogStrip.setColor(255, 255, 255); // Setting the strip to pure white

	analogStrip.fadeTo(100, 100, 100, 3); // Fade to a dimmer white with a speed of 3ms

===============

And so forth

TODO:
- Implement non-blocking code.
