//    FILE: buttonhandler.cpp

#include "buttonhandler.h"


//unsigned short boundaries[MAX_BUTTON_COUNT];
unsigned short *boundaries;


// btn count = 2
//                   btn1                     btn2
//         THNP ............... MAX/2*1  ............... MAX/2*2
//                 0..MAX/2                MAX/2 .. MAX
// Arr[2]: THNP    MAX/2*1                    MAX/2*2


// btn count = 3
//  GND     1k       BTN1        1k           BTN2        1k        BTN3         1k       VCC
//	0.00 ............1.25V ................. 2.50V ................ 3,75V ............... 5.00V--
//  0............... 255 .................... 512 ...................767 ................ 1023
//                   btn1                     btn2                   btn3
//            0 ............... MAX/3*1 ............... MAX/3*2 ............... MAX/3*3
//                0..MAX/3*1          MAX/3*1 .. MAX/3*2
// Arr[3]: THNP,   MAX/3*1,                 MAX/3*2,                MAX/3*3
// Arr[3]: {50,                 341,                     682,                    1023}

//in test:         246                        488                      742


void ButtonHandler::init(int adcPin, int buttonCount){
	myAdcPin = adcPin;
	btnCount = buttonCount;

	//unsigned short array[(btnCount+1)];
	boundaries = new unsigned short[buttonCount+1];
	boundaries[0] = THRESHOLD_NOTHING_PRESSED; 	// fixed lower boundary for first button

	unsigned short i = 0;
	for(i=1; i<btnCount; i++){
		boundaries[i] = (unsigned short)((BTN_HANDLER_ADC_MAX / btnCount) * i);
	}

	boundaries[btnCount] = BTN_HANDLER_ADC_MAX;

	//boundaries = array;
}


/*
 * 	Return the ID of pressed button (ids starts from 1)
 *  Valid ID range: [1..buttonCount]
 *  or returns 0 if no button pressed currently.
 */
int ButtonHandler::getButtonIdForValue(int value){

	if((value >= 0) && (value < THRESHOLD_NOTHING_PRESSED)){
		return NOTHING_PRESSED;
	}

	unsigned short i = 1;
	for(i=1; i<=btnCount; i++){
		if(value <= boundaries[i])
			return i;

	}

	if((value < 0) || (value > BTN_HANDLER_ADC_MAX)){
		return BTN_UNDEFINED;
	}

}

int ButtonHandler::getPressed(){
	int adcVal = analogRead(myAdcPin);
	if(debugMode){
		if(adcVal > 25){
			Serial.print("AdcVal: ");
			Serial.print(String(adcVal));
			Serial.print("\n");
		}
	}
	return ButtonHandler::getButtonIdForValue(adcVal);
}

int ButtonHandler::isPressed(unsigned short btnId){
	return ((ButtonHandler::getPressed() == btnId)?1:0);
}

int ButtonHandler::isPressedAny(){
	return ((ButtonHandler::getPressed() > NOTHING_PRESSED)?1:0);
}


int ButtonHandler::isReleasedAll(){
	return ((ButtonHandler::isPressedAny() == 0)?1:0);
}

// for debug purpose
String ButtonHandler::getBoundaryValues(){
	String res = "";
	unsigned short i = 0;
	for( ; i < btnCount+1; i++){
		res += (String(boundaries[i]) + ", ");
	}
	res += "\n";
	return res;
}

void ButtonHandler::setDebugMode(unsigned char status){
	debugMode = status;
}
