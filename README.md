# Arduino button handler library

An arduino library to handle multiple buttons on 1 single ADC input.

Buttons should connected between  the resistors of a serial resistor line (voltage divider).
When no button pressed ADC shoul be pulled down to GND.

### Basic schematic

![Basic schematic with 3 buttons](https://raw.githubusercontent.com/bbkbarbar/Arduino-ButtonHandler-library/master/Docs/Schematic_with_3_buttons.png)

![Basic schematic with 3 buttons](https://raw.githubusercontent.com/bbkbarbar/Arduino-ButtonHandler-library/master/Docs/Schematic_with_5_buttons.png)

### Important note:
Resistor values can be changed, but all resistors must have the same value in the voltage divider line <br>
and the <b>total resistance</b> of voltage divider must be <b>at least 1kOhm</b><br>
(To avoid unwanted energy consumption.) <br>
The pull-down resistor must have much bigger value than the voltage divider's overall value. <br>
It's important because we have to pull down the voltage of ADC pin to 0V when no buttons pressed (to avoid the "floating" state of ADC input),
but we don't want to calculate the with pull-down resistor as part of the voltage divider.


### Most used functions
###### Initialize
```
void init(int adcPin, int buttonCount);

/*
 *  Initialite the ButtonHandler object
 *  Parameters:
 *    adcPin:       The pin of arduino what is used to read status of the buttons
 *    buttonCount:  The number of attached buttons
 */
```

###### Read state of buttons
```
int getPressed();

/*
 *  Returns the ID of pressed button (ids starts from 1)
 *  Valid ID range: [1..buttonCount]
 *  or returns NOTHING_PRESSED if no button pressed currently.
 */
```


### Full set of functions [can be found in API.md](https://github.com/bbkbarbar/Arduino-ButtonHandler-library/blob/master/API.md)


### ToDo:
- [ ] Try out to override the value of MAX_BUTTON_COUNT macro.
