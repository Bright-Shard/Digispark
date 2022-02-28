/*
 *
 *  MacOS Parrot by BrightShard
 *  It uses Spotlight to open a terminal and then cURLs parrot.live to show a
 *  cute, dancing parrot
 *
 */

#include "DigiKeyPlus.h"
DigiKeyPlus keyboard;

// The actual keyboard attack
void script() {
  keyboard.MacSpotlight("Terminal"); // Open the terminal
  keyboard.Type("curl parrot.live"); // cURL parrot.live
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
