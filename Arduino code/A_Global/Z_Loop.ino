void loop() {
  /** Available calls:
   * wiggleTail(); <- single time action
   * updateBody(); <- main update caller
   * move() <- move the robot in a direction
   */
  updateBody();
  webSocket.loop();
}

void updateBody() {
  currentMillis = millis(); // Get current time
  if (idleEyes) {
    // Update eye animation
    if (currentMillis - previousMillisIdleEyes >= intervalIdleEyes) {
      previousMillisIdleEyes = currentMillis;
      idleMovementEyes();
    }
  }

  // Update tail motion
  // if (currentMillis - previousMillisIdleTail >= intervalIdleTail) {      <-- tail code depricated in V2
  //   previousMillisIdleTail = currentMillis;
  //   idleMovementTail();
  // }

  // Update eye blink
  if (currentMillis - previousMillisBlink >= intervalBlink) {
    previousMillisBlink = currentMillis;
    eyeBlink();
  }
  
  if (driving) {
    // Keep moving as long as the move is active
    if (currentMillis - previousMillisMovement >= intervalMovement) {
      previousMillisMovement = currentMillis;
      move();
      moveDirection = IDLE;
    }
  }
}