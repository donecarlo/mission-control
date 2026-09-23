// This code is applicable for the Adafruit Neokey Trinkey

#include <HID-Project.h>

bool last_switch = true;

const ConsumerKeycode M_CTRL = static_cast<ConsumerKeycode>(0x29F);

void setup() {
  pinMode(PIN_SWITCH, INPUT_PULLDOWN);
  Consumer.begin();
}

void loop() {
  bool curr_switch = digitalRead(PIN_SWITCH);
  if (curr_switch != last_switch) {
    if (curr_switch) {
      Consumer.write(M_CTRL);
    } else {
      // no need to release
    }
    last_switch = curr_switch;
  }
}