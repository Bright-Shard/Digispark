/*
 *
 *  MacOS Wallpaper Changer by BrightShard
 *  It opens the terminal with Spotlight, downloads an image, and sets that as the wallpaper
 *  The default changed wallpaper is Handsome Squidward, although the URL can be changed to a different one
 *
*/

#include "DigiKeyboard.h"
int btnPressed = 1; // Track if btn is pressed
int canRun = true; // Track if script is running or not
const char* url = "https://cdn.wallpapersafari.com/69/4/j0JeYp.jpg"; // URL of wallpaper to set
int slowFactor = 1; // Turn this up for slow computers

// The actual keyboard attack
void script() {
  DigiKeyboard.sendKeyStroke(KEY_SPACE, MOD_GUI_LEFT); // Open spotlight
  DigiKeyboard.delay(300 * slowFactor); // Wait for it to appear
  DigiKeyboard.println("Terminal"); // Search for the terminal app
  DigiKeyboard.delay(2000 * slowFactor); // Wait for terminal to open
  DigiKeyboard.print("cd /tmp; curl -o wallpaper "); // Move to /tmp and download the wallpaper
  DigiKeyboard.println(url); // Add URL
  DigiKeyboard.delay(3000 * slowFactor); // Wait for the image to download
  DigiKeyboard.println("osascript -e 'tell application \"Finder\" to set the desktop picture to POSIX file \"/tmp/wallpaper\"'"); // Set wallpaper
  DigiKeyboard.delay(2000 * slowFactor); // In case we have a slow one
  DigiKeyboard.println("exit"); // Exit terminal
  DigiKeyboard.delay(200 * slowFactor); // In case we have a slow one
  DigiKeyboard.sendKeyStroke(KEY_Q, MOD_GUI_LEFT); // Quit the terminal app
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
