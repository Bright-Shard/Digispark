# DigiSpark Scripts
A few HID attacks with the DigiSpark board. In addition, my scripts use the `DigiKeyPlus` library, a custom DigiKeyboard wrapper I wrote. The library automates certain tasks (such as opening the run/spotlight menus and turning up volume) while also adding more keys (like volume or the other arrow keys) to the library. A few commands are also simplified (`println` and `sendKeyStroke` have been combined into `Type`).

Although I'm still working on documentation for `DigiKeyPlus`, all of the scripts I've written here do work and should be pretty straightforward to read (I also added comments to them).

My scripts also use a button to launch the attack, attached to Pin 0. If you don't want to use a button, change the number from 0 to -1 in the scripts (it makes sense when you read the comments). If you don't use a button, the attack simply runs on each `loop()` call, with a 5 second delay between runs.
