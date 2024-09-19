#include <HID-Project.h>

const int pinA = A0;
const int pinLed = LED_BUILTIN;
const uint16_t KEY_MSCTLR = 0x29F;

void setup() {
  pinMode(pinA, INPUT_PULLUP);
  pinMode(pinLed, OUTPUT);

  Consumer.begin();
}

void loop() {
  if (!digitalRead(pinA)) {
    digitalWrite(pinLed, HIGH);

    Consumer.press(KEY_MSCTLR);
    Consumer.releaseAll();

    // Simple debounce
    delay(120);
    digitalWrite(pinLed, LOW);
  }
}