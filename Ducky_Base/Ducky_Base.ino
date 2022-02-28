/*
 *
 *  Ducky Base by BrightShard
 *  This is the "base script" that the other DigiSpark
 *  scripts are based off of. Just change the script()
 *  function to change the attack.
 *
 */
#include "DigiKeyPlus.h"
DigiKeyPlus keyboard;

// The actual keyboard attack
void script() {
  keyboard.Type("Hello, world!");
}

void setup() {
  /* Keyboard attack handler:
   *  1 - the slowFactor variable, turn this up on slower machines for more delays & stability
   *  0 - the pin of the pushbutton on the DigiSpark, change it to -1 if there's no button
   *  script - the function of the HID attack
   */
  keyboard.Init(1, 0, script);
}

void loop() {
  keyboard.Update(); // Keep keyboard alive & handle button presses
}
