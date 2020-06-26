// Change what it should do based on recieved instruction via websocket
void handleRecieved(String recievedString) {
  Serial.println(recievedString);
  // Movement
  if (recievedString == "move_forward") {
    // Move forward
    Serial.println("Moving forward");
    moveDirection = FORWARD;
    driving = true;
  } else if (recievedString == "move_backward") {
    // Move left
    Serial.println("Moving backward");
    moveDirection = BACKWARD;
    driving = true;
  } else if (recievedString == "move_left") {
    // Move left
    Serial.println("Moving left");
    moveDirection = TURNLEFT;
    driving = true;
  } else if (recievedString == "move_right") {
    // Move left
    Serial.println("Moving right");
    moveDirection = TURNRIGHT;
    driving = true;
  }

  // Idle toggle
  else if (recievedString == "eyes_1_random") {
    updateEyeModuleType(RGB);
    idleEyes = true;
    Serial.println("Turned on idle animation for eyes");
    // webSocket.sendTXT(0, "true");
  } else if (recievedString == "eyes_2_random") {
    updateEyeModuleType(SEGMENT);
    idleEyes = true;
    Serial.println("Turned on idle animation for eyes");
    // webSocket.sendTXT(0, "true");
  } else if (recievedString == "eyes_3_random") {
    updateEyeModuleType(MATRIX);
    idleEyes = true;
    Serial.println("Turned on idle animation for eyes");
    // webSocket.sendTXT(0, "true");
  }
  
  // Eyes option 0 (RGB led)
  else if (recievedString == "eyes_1_red") {
    // Eyes red
    updateEyeModuleType(RGB);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes red");
    setEyeType(ANGRY);
  } else if (recievedString == "eyes_1_green") {
    // Eyes green
    updateEyeModuleType(RGB);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes green");
    setEyeType(NORMAL);
  } else if (recievedString == "eyes_1_blue") {
    // Eyes blue
    updateEyeModuleType(RGB);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes blue");
    setEyeType(SURPRISED);
  }

  // Eyes option 2 (7 segment modules)
  else if (recievedString == "eyes_2_normal") {
    // Eyes normal
    updateEyeModuleType(SEGMENT);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes normal");
    setEyeType(NORMAL);
  } else if (recievedString == "eyes_2_happy") {
    // Eyes happy
    updateEyeModuleType(SEGMENT);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes happy");
    setEyeType(HAPPY);
  } else if (recievedString == "eyes_2_angry") {
    // Eyes angry
    updateEyeModuleType(SEGMENT);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes angry");
    setEyeType(ANGRY);
  } else if (recievedString == "eyes_2_left") {
    // Eyes left
    updateEyeModuleType(SEGMENT);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes left");
    setEyeType(LEFT);
  } else if (recievedString == "eyes_2_right") {
    // Eyes right
    updateEyeModuleType(SEGMENT);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes right");
    setEyeType(RIGHT);
  } else if (recievedString == "eyes_2_cross") {
    // Eyes cross
    updateEyeModuleType(SEGMENT);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes cross");
    setEyeType(CROSS);
  } else if (recievedString == "eyes_2_surprised") {
    // Eyes surprised
    updateEyeModuleType(SEGMENT);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes surprised");
    setEyeType(SURPRISED);
  }

  // Eyes option 3 (8x8 matrix)
  else if (recievedString == "eyes_3_normal") {
    // Eyes normal
    updateEyeModuleType(MATRIX);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes normal");
    setEyeType(NORMAL);
  } else if (recievedString == "eyes_3_happy") {
    // Eyes happy
    updateEyeModuleType(MATRIX);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes happy");
    setEyeType(HAPPY);
  } else if (recievedString == "eyes_3_angry") {
    // Eyes angry
    updateEyeModuleType(MATRIX);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes angry");
    setEyeType(ANGRY);
  } else if (recievedString == "eyes_3_left") {
    // Eyes left
    updateEyeModuleType(MATRIX);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes left");
    setEyeType(LEFT);
  } else if (recievedString == "eyes_3_right") {
    // Eyes right
    updateEyeModuleType(MATRIX);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes right");
    setEyeType(RIGHT);
  } else if (recievedString == "eyes_3_cross") {
    // Eyes cross
    updateEyeModuleType(MATRIX);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes cross");
    setEyeType(CROSS);
  } else if (recievedString == "eyes_3_surprised") {
    // Eyes surprised
    updateEyeModuleType(MATRIX);
    idleEyes = false;
    intervalIdleEyes = 10000;
    Serial.println("Eyes surprised");
    setEyeType(SURPRISED);
  }

  // Move phone up and down
  else if (recievedString == "phone_up") {
    Serial.println("Moving phone up");
    phoneUp();
  } else if (recievedString == "phone_down") {
    Serial.println("Moving phone down");
    phoneDown();
  }

  // else if (recievedString == "idle_tail_toggle") {             <-- tail code depricated in V2
  //   if (idleEyes) {
  //     Serial.println("Turned off idle animation for tail");
  //     idleTail = false;
  //     webSocket.sendTXT(0, "false");
  //     tailServo.write(tailPositions[0]);
  //   } else {
  //     Serial.println("Turned on idle animation for tail");
  //     idleTail = true;
  //     webSocket.sendTXT(0, "true");
  //   }
  // }

  // Animation change
  // else if (recievedString == "wiggle") {                       <-- tail code depricated in V2
  //   // Wiggle tail
  //   Serial.println("Wiggling");
  //   wiggleTail();
  // }
}

void updateEyeModuleType(EyeModule eyeModuleType) {
  if (eyeModuleVersion != eyeModuleType) {
    eyeModuleVersion = eyeModuleType;
    Serial.println("Eye module type changed");
  }
}

