//    FILE: buttonhandler.h

#ifndef buttonhandler_h
#define buttonhandler_h

	#if defined(ARDUINO) && (ARDUINO >= 100)
		#include <Arduino.h>
	#else
		#include <WProgram.h>
	#endif


class buttonhandler {

	private:
		int btnCount;
		int myAdcPin;

		/*
		 * 	Return the ID of pressed button (ids starts from 1)
		 *  Valid ID range: [1..buttonCount]
		 *  or returns 0 if no button pressed currently.
		 */
		int getButtonIdForValue(int value);

	public:
		void init(int adcPin, int buttonCount);

		/*
		 * 	Return the ID of pressed button (ids starts from 1)
		 *  Valid ID range: [1..buttonCount]
		 *  or returns NOTHING_PRESSED if no button pressed currently.
		 */
	    int getPressed();

	    
	    int isPressed();
	    int isReleased();
};

#endif