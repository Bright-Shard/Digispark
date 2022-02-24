/*
 *
 * Ducky Base by BrightShard
 * This is the base file for all of my DigiSpark HID attack scripts
 * It initiates DigiKeyboard.h for the keyboard attack, turns on the LED when
 * the attack is ready to launch, and runs the script() function when the
 * button on pin 0 is pressed
 *
 * All delays are multiplied by the slowFactor variable, so if the target is an
 * older/slower computer, turn that variable up for longer delays and more
 * stability.
 *
 */

#include "DigiKeyboard.h"
int btnPressed = 1; // Track if btn is pressed
int canRun = true; // Track if script is running or not
int slowFactor = 1; // Turn this up for slow computers

// The actual keyboard attack
void script() {
  DigiKeyboard.println("Hello, world!");
}

void setup() {
  pinMode(1, OUTPUT); // LED
  pinMode(0, INPUT); // Btn

  DigiKeyboard.update(); // Init keyboard
  DigiKeyboard.sendKeyStroke(0); // Make computer recognize keyboard, needed for older systems
  DigiKeyboard.delay(1000 * slowFactor); // Let computer register keyboard

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
    DigiKeyboard.delay(1000 * slowFactor); // Delay between attacks for stability
    digitalWrite(1, HIGH); // Turn on LED, showing the script can be run
    canRun = true; // Script has run and it's OK to launch it again
  }
}
