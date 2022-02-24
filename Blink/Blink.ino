/*
 *
 * Blink by BrightShard
 * Makes the second LED on the DigiSpark blink, just to make sure the DigiSpark
 * is working
 *
 */

void setup() {
  // initialize the digital pin as an output.
  pinMode(1, OUTPUT); //LED on Model A  or Pro
}

void loop() {
  digitalWrite(1, HIGH);
  delay(1000);               // wait for a second
  digitalWrite(1, LOW);
  delay(1000);               // wait for a second
}
