# ButtonHandler - Full set of functions

##### Initialize

```
void init(int adcPin, int buttonCount);

/*
 *  Initialite the ButtonHandler object
 *  Parameters:
 *    adcPin:       The pin of arduino what is used to read status of the buttons
 *    buttonCount:  The number of attached buttons
 */
```

##### Read buttons

```
int getPressed();

/*
 *  Returns the ID of pressed button (ids starts from 1)
 *  Valid ID range: [1..buttonCount]
 *  or returns NOTHING_PRESSED if no button pressed currently.
 */
```

##### Read status of a specified button
```
int isPressed(unsigned short btnId);

/*
 *  Check that the specified button (by buttonID) is pressed currently or not.
 *  Valid ID range: [1..buttonCount]
 *  Returns: 1 (true) or
 *           0 (false)
 */
```

##### Other status -related functions
```
int isPressedAny();

/*
 *  Check that any button is pressed currently or not.
 *  Returns: 1 (true) or
 *           0 (false)
 */
```

```
int isReleasedAll();

/*
 *  Check that all buttons is released currently or not.
 *  Returns: 1 (true) or
 *           0 (false)
 */
```

##### Additional / debug functions
```
String getBoundaryValues();

/*
 *  Returns a String to show the border values
 *  what had been calculated to separate the ADC values of different buttons.
 */
```

```
void setDebugMode(unsigned char status);

/*
 *  Enable or disable debud mode.
 *  In debug mode the current ADC values
 *  will be continously shown in serial output.
 *  Parameter:
 *    status: 1 (enable)
 *            0 (disable)
 */
```
