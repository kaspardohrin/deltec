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
      webSocket.sendTXT(0, "false");
      setEyeType(0);
    } else {
      Serial.println("Turned on idle animation for eyes");
      idleEyes = true;
      webSocket.sendTXT(0, "true");
    }
  } else if (recievedString == "idle_tail_toggle") {
    if (idleEyes) {
      Serial.println("Turned off idle animation for tail");
      idleTail = false;
      webSocket.sendTXT(0, "false");
      tailServo.write(tailPositions[0]);
    } else {
      Serial.println("Turned on idle animation for tail");
      idleTail = true;
      webSocket.sendTXT(0, "true");
    }
  }

  // Animation change
  else if (recievedString == "wiggle") {
    // Wiggle tail
    Serial.println("Wiggling");
    wiggleTail();
  } else if (recievedString == "eyes_normal") {
    // Happy eyes
    Serial.println("Normal eyes");
    setEyeType(0);
    intervalIdleEyes = 10000;
  } else if (recievedString == "eyes_left") {
    // Happy eyes
    Serial.println("Left eyes");
    setEyeType(1);
    intervalIdleEyes = 10000;
  } else if (recievedString == "eyes_right") {
    // Happy eyes
    Serial.println("Right eyes");
    setEyeType(2);
    intervalIdleEyes = 10000;
  } else if (recievedString == "eyes_down") {
    // Happy eyes
    Serial.println("Down eyes");
    setEyeType(3);
    intervalIdleEyes = 10000;
  } else if (recievedString == "eyes_cross") {
    // Happy eyes
    Serial.println("Cross eyes");
    setEyeType(4);
    intervalIdleEyes = 10000;
  } else if (recievedString == "eyes_happy") {
    // Happy eyes
    Serial.println("Happy eyes");
    setEyeType(5);
    intervalIdleEyes = 10000;
  } else if (recievedString == "eyes_surprised") {
    // Happy eyes
    Serial.println("Surprised eyes");
    setEyeType(6);
    intervalIdleEyes = 10000;
  }
}

