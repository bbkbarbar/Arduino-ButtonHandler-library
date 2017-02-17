#include <buttonhandler.h>

#define BTN1  1
#define BTN2  2
#define BTN3  3

ButtonHandler buttons;

void setup() {

  buttons.init(A5, 3);
  Serial.begin(9600);
  delay(300);
  Serial.print(buttons.getBoundaryValues());
  //buttons.setDebugMode(1);
}

int ispressed = 0;

void loop() {

  if(buttons.isPressed(BTN1)){
    if(ispressed != 1){
      digitalWrite(13, HIGH);
      Serial.print("Btn1 pressed\n");
    }
    ispressed = 1;
  }
  else
  if(buttons.isPressed(BTN2)){
    if(ispressed != 2){
      digitalWrite(13, LOW);
      Serial.print("Btn2 pressed\n");
    }
    ispressed = 2;
  }
  else
  if(buttons.isPressed(BTN3)){
    if(ispressed != 3){
      Serial.print("Btn3 pressed\n");
    }
    ispressed = 3;
  }else{
    ispressed = 0;
  }

}
