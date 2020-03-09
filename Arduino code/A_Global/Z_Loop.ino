void loop() {
  currentMillis = millis(); // Get current time
  // Should the eye idle animation change
  if (currentMillis - previousMillisIdle >= intervalIdleEye) {
    previousMillisIdle = currentMillis;
    idleMovement();
  }
  // Should the eyes blink
  if (currentMillis - previousMillisBlink >= intervalBlink) {
    previousMillisBlink = currentMillis;
    eyeBlink();
  }
}