//    FILE: buttonhandler.cpp

#include "buttonhandler.h"

#define BTN_UNDEFINED                -1
#define ADC_MAX                    1023
#define THRESHOLD_NOTHING_PRESSED    50
#define NOTHING_PRESSED               0

// btn count = 2
//                   btn1			           btn2
//         THNP ............... MAX/2*1  ............... MAX/2*2
//                 0..MAX/2                MAX/2 .. MAX    
// Arr[2]:	THNP    MAX/2*1                    MAX/2*2        


// btn count = 3
//  GND     1k		 BTN1        1k           BTN2        1k        BTN3         1k       VCC
//	0.00 ............1.25V ................. 2.50V ................ 3,75V ............... 5.00V--	
//  0............... 255 .................... 512 ...................767 ................ 1023
//                   btn1			          btn2                   btn3
//            0 ............... MAX/3*1 ............... MAX/3*2 ............... MAX/3*3
//                0..MAX/3*1          MAX/3*1 .. MAX/3*2    
// Arr[3]: THNP,   MAX/3*1,                 MAX/3*2,                MAX/3*3     
// Arr[3]: {50,                  341,                     682,                    1023}


unsigned short *boundaries;


void buttonhandler::init(int adcPin, int buttonCount){
	myAdcPin = adcPin;
	btnCount = buttonCount;

	unsigned short[(btnCount+1)] array;
	array[0] = THRESHOLD_NOTHING_PRESSED; 	// fixed lower boundary for first button

	unsigned short i = 0;
	for(i=1; i<btnCount; i++){
		array[i] = (unsigned short)((ADC_MAX / btnCount) * i);
	}

	array[btnCount] = ADC_MAX;

	*boundaries = &array[0];
	//*boundaries = array;
}


/*
 * 	Return the ID of pressed button (ids starts from 1)
 *  Valid ID range: [1..buttonCount]
 *  or returns 0 if no button pressed currently.
 */
int buttonhandler::getButtonIdForValue(int value){

	if((value >= 0) && (value < THRESHOLD_NOTHING_PRESSED)){
		return NOTHING_PRESSED;
	}

	unsigned short i = 1;
	for(i=1; i<=btnCount; i++){
		if(value <= boundaries[i])
			return i;

	}

	if((value < 0) || (value > ADC_MAX)){
		return BTN_UNDEFINED;
	}

}


int buttonhandler::getPressed(){
	int adcVal = analogRead(myAdcPin);
	return buttonhandler::getButtonIdForValue(adcVal);
}


int buttonhandler::isPressed(){
	return ((buttonhandler::getPressed() > NOTHING_PRESSED)?1:0);
}


int buttonhandler::isReleased(){
	return ((buttonhandler::isPressed() == NOTHING_PRESSED)?1:0);
}