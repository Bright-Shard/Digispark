# DigiSpark Scripts
A few HID attacks with the DigiSpark board. My scripts are a bit different than most, in that they use a button to run. Just plug a 2-pin button into GND and P0. When the (second) red LED turns on on the DigiSpark, press the button to launch the attack. Once the red light turns on again, the attack has completed and can be run again the same way.

All of the attacks are based on the `Ducky_Base` script, and a little information/documentation is in the `Ducky_Base.ino` file if you wish to make your own.

These attacks are also just pranks, since I can run those without getting into (too) much trouble.

## Why use a button?
Often times I've had stability issues with the actual USB rubber ducky, and I prefer having a button to launch the attack from the start as well as relaunch it if it fails the first time.
