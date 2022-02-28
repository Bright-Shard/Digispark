/*
 *
 *  Windows Parrot by BrightShard
 *  Uses the Run menu to open the Command Prompt, and
 *  then cURLs parrot.live for a cute, dancing parrot
 *
 */
#include "DigiKeyPlus.h"
DigiKeyPlus keyboard;

// The actual keyboard attack
void script() {
  keyboard.WinRun("cmd"); // Open the command prompt
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
