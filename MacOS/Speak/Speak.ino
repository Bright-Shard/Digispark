/*
 *
 *  MacOS Speaker by BrightShard
 *  This script turns the volume up, opens the Terminal via Spotlight, 
 *  and then says the provided message
 *
 *  The script automatically waits depending on the length of the message and
 *  then closes the terminal
 *
 */

#include "DigiKeyPlus.h"
DigiKeyPlus keyboard; // Will handle the keyboard attacks
char tempChar; // Used to iterating through PROGMEM chars
// Message is stored in PROGMEM to save RAM
const char msg[] PROGMEM = "Never gonna give you up / Never gonna let y\
ou down / Never gonna run around and desert you / Never gonna make you cry / Never gon\
na say goodbye / Never gonna tell a lie and hurt you";

// The actual keyboard attack
void script() {
  keyboard.VolumeUp(); // Turn up the volume
  keyboard.MacSpotlight("Terminal"); // Open the terminal
  // Type the say command
  keyboard.Append("say \""); // Start the command
  for (byte k = 0; k < strlen_P(msg); k++) {
    tempChar = pgm_read_byte_near(msg + k);
    keyboard.Append(tempChar);
  }
  keyboard.Type("\""); // Close quotes & hit enter
  keyboard.Wait((strlen_P(msg) * 100) + 20); // Wait for message to finish
  keyboard.Type("exit"); // Clear terminal
  keyboard.Wait(50); // Be nice to the computer
  keyboard.Type(KEY_Q, CMD_LEFT); // Close terminal
  keyboard.VolumeDown(); // Reset volume
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
