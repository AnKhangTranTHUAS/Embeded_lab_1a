#include <Arduino.h>
// name: Tran An Khang
// student number: 26090740

#define LED_OUTPUT 23 
#define BUTTON_INPUT 22

void setup(){
  pinMode(LED_OUTPUT, OUTPUT);
  pinMode(BUTTON_INPUT, INPUT_PULLDOWN);
}

void loop() {int buttonStatus = digitalRead(BUTTON_INPUT); //this should be placed after the setup() because the computer doesn't know what is "Button input"
  if(buttonStatus ==  1){
    digitalWrite(LED_OUTPUT, 1);
  }
  else{
    digitalWrite(LED_OUTPUT, 0);
  }
}
// Good Work - Hasnait
