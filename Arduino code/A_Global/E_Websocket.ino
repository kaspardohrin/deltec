// Change what it should do based on recieved instruction via websocket
void handleRecieved(String recievedString) {
  Serial.println(recievedString);

  // Movement
  if (recievedString == "forward") {
    // Move forward
    Serial.println("Moving forward");
    moveDirection = FORWARD;
    driving = true;
  } else if (recievedString == "left") {
    // Move left
    Serial.println("Moving left");
    moveDirection = LEFT;
    driving = true;
  } else if (recievedString == "right") {
    // Move left
    Serial.println("Moving right");
    moveDirection = RIGHT;
    driving = true;
  }

  // Idle toggle
  else if (recievedString == "idle_eyes_toggle") {
    if (idleEyes) {
      Serial.println("Turned off idle animation for eyes");
      idleEyes = false;
      setEyeType(0);
    } else {
      Serial.println("Turned on idle animation for eyes");
      idleEyes = true;
    }
  } else if (recievedString == "idle_tail_toggle") {
    if (idleEyes) {
      Serial.println("Turned off idle animation for tail");
      idleTail = false;
      tailServo.write(tailPositions[0]);
    } else {
      Serial.println("Turned on idle animation for tail");
      idleTail = true;
    }
  }

  // Animation change
  else if (recievedString == "wiggle") {
    // Wiggle tail
    Serial.println("Wiggling");
    wiggleTail();
  } else if (recievedString == "eyes_happy") {
    // Happy eyes
    Serial.println("Happy eyes");
    setEyeType(5);
    intervalIdleEyes = 10000;
  }
}

