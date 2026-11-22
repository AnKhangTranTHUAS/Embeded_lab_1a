#include <Arduino.h>


#define LED_OUTPUT 23 
#define BUTTON_INPUT 22

void setup(){
  pinMode(LED_OUTPUT, OUTPUT);
  pinMode(BUTTON_INPUT, INPUT_PULLDOWN);
}

void loop() {int buttonStatus = digitalRead(BUTTON_INPUT);
  if(buttonStatus ==  1){
    digitalWrite(LED_OUTPUT, 1);
  }
  else{
    digitalWrite(LED_OUTPUT, 0);
  }
}
