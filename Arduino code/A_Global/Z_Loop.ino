void loop() {
  /** Available calls:
   * wiggleTail(); <- single time action
   * updateBody(); <- main update caller
   */
  updateBody();
}

void updateBody() {
  currentMillis = millis(); // Get current time
  // Should the eye idle animation change
  if (currentMillis - previousMillisIdleEyes >= intervalIdleEyes) {
    previousMillisIdleEyes = currentMillis;
    idleMovementEyes();
  }
  // Should the eyes blink
  if (currentMillis - previousMillisBlink >= intervalBlink) {
    previousMillisBlink = currentMillis;
    eyeBlink();
    // wiggleTail();
  }
  // Should the tail change idle position
  if (currentMillis - previousMillisIdleTail >= intervalIdleTail) {
    previousMillisIdleTail = currentMillis;
    idleMovementTail();
  }
}