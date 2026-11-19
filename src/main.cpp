#include <Arduino.h>

// Lab 1a - GPIO Input / Output
// Name: Your Name
// Student number: Your Student Number
//
// Goal:
// - LED starts ON
// - Every button press toggles the LED ON/OFF
// - Button uses debounce to avoid false multiple presses

// Pin numbers
const int LED_PIN = 5;
const int BUTTON_PIN = 23;

// LED state: true means ON, false means OFF
bool ledState = true;

// Variables for button debounce
bool lastButtonReading = LOW;
bool stableButtonState = LOW;

unsigned long lastDebounceTime = 0;
const unsigned long debounceDelay = 50;

void setup() {
  // Set LED pin as output
  pinMode(LED_PIN, OUTPUT);

  // Set button pin as input with internal pulldown resistor
  pinMode(BUTTON_PIN, INPUT_PULLDOWN);

  // LED should be ON when ESP32 starts
  digitalWrite(LED_PIN, HIGH);
}

void loop() {
  // Read the current button value
  bool currentButtonReading = digitalRead(BUTTON_PIN);

  // If the button reading changed, reset the debounce timer
  if (currentButtonReading != lastButtonReading) {
    lastDebounceTime = millis();
  }

  // Check if the reading has stayed stable long enough
  if ((millis() - lastDebounceTime) > debounceDelay) {

    // If the stable button state has changed
    if (currentButtonReading != stableButtonState) {
      stableButtonState = currentButtonReading;

      // Only toggle when the button is pressed, not when released
      if (stableButtonState == HIGH) {
        ledState = !ledState;
        digitalWrite(LED_PIN, ledState);
      }
    }
  }

  // Save the current reading for the next loop
  lastButtonReading = currentButtonReading;
}