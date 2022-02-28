/*
  DigiKeyPlus.h - Shortcut commands built on top of DigiKeyboard.h
  Created by BrightShard, 2022
*/

#include "Arduino.h"
#include "DigiKeyPlus.h"
#include "DigiKeyboard.h"

DigiKeyPlus::DigiKeyPlus(){}

// General Shortcuts -----------------------------------------------------------
void DigiKeyPlus::Init(int slowFactor, int buttonPin, void (*script)())
{
  _script = (*script); // Store the script
  _slowFactor = slowFactor; // Store slowFactor
  _buttonPin = buttonPin; // Store button pin

  pinMode(1, OUTPUT); // LED is output
  pinMode(_buttonPin, INPUT); // Button is input

  // Init keyboard
  DigiKeyboard.update();
  DigiKeyboard.sendKeyStroke(0);
  DigiKeyboard.delay(500 * _slowFactor);

  digitalWrite(_buttonPin, HIGH); // Give button power
  digitalWrite(1, HIGH); // Turn LED on, showing the attack is ready
  _canRun = true; // Store that the attack is ready to run
}
void DigiKeyPlus::Update()
{
  DigiKeyboard.update(); // Keep keyboard online
  // If a button is being used, run the button handler
  if(_buttonPin != -1) {
    // If the button is being pressed, run the attack
    if (digitalRead(_buttonPin) == 0 && _canRun == true) {
      digitalWrite(1, LOW); // Turn off LED, showing the script is running
      _canRun = false; // Script is running and shouldn't be launched again
      _script(); // Run the attack
      DigiKeyboard.delay(500 * _slowFactor); // Delay between attacks for stability
      digitalWrite(1, HIGH); // Turn on LED, showing the script can be run
      _canRun = true; // Script has run and it's OK to launch it again
    }
  } else {
    _script(); // Run the attack
    DigiKeyboard.delay(5000 * _slowFactor);
  }
}
void DigiKeyPlus::Append(const char* text)
{
  DigiKeyboard.print(text);
}
void DigiKeyPlus::Append(char text)
{
  DigiKeyboard.print(text);
}
void DigiKeyPlus::Type(const char* text)
{
  DigiKeyboard.println(text);
}
void DigiKeyPlus::Type(char text)
{
  DigiKeyboard.println(text);
}
void DigiKeyPlus::Type(byte key, byte modifier)
{
  DigiKeyboard.sendKeyStroke(key, modifier);
}
void DigiKeyPlus::Type(byte key)
{
  DigiKeyboard.sendKeyStroke(key);
}
void DigiKeyPlus::Wait(int time)
{
  DigiKeyboard.delay(time * _slowFactor);
}
void DigiKeyPlus::VolumeUp()
{
  for(int x = 0; x <= 10; x++) // Loop 10 times
  {
    DigiKeyboard.sendKeyStroke(VOLUME_UP); // Turn volume up
    DigiKeyboard.delay(10 * _slowFactor); // Be nice to the computer :)
  }
}
void DigiKeyPlus::VolumeDown()
{
  for(int x = 0; x <= 10; x++) // Loop 10 times
  {
    DigiKeyboard.sendKeyStroke(VOLUME_DOWN); // Turn volume down
    DigiKeyboard.delay(10 * _slowFactor); // Be nice to the computer :)
  }
}




// MacOS Shortcuts -------------------------------------------------------------
void DigiKeyPlus::MacSpotlight(String query)
{
  DigiKeyboard.sendKeyStroke(KEY_SPACE, CMD_LEFT); // Open Spotlight
  DigiKeyboard.delay(300 * _slowFactor); // Wait for it to appear
  DigiKeyboard.println(query); // Type the query and hit enter
  DigiKeyboard.delay(1500 * _slowFactor); // Wait for the app to open
}



// Windows Shortcuts -----------------------------------------------------------
void DigiKeyPlus::WinRun(String command)
{
  DigiKeyboard.sendKeyStroke(KEY_R, WIN_LEFT); // Open run menu
  DigiKeyboard.delay(300 * _slowFactor); // Wait for it to appear
  DigiKeyboard.println(command); // Type the command and hit enter
  DigiKeyboard.delay(1500 * _slowFactor); // Wait for the app to open
}
