void move() {
  // Do we need to change the state of the motors
  if (moveDirection != moveDirectionPrevious) {
    switch (moveDirection) {
      case IDLE:
        Serial.println("Idle");
        digitalWrite(LEFT_MOTOR_RELAY_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_RELAY_PIN, HIGH);
        // Movement is done
        driving = false;
        break;
      case FORWARD:
        Serial.println("Forward");
        digitalWrite(LEFT_MOTOR_RELAY_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_RELAY_PIN, LOW);
        break;
      case LEFT:
        Serial.println("Left");
        digitalWrite(LEFT_MOTOR_RELAY_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_RELAY_PIN, LOW);
        break;
      case RIGHT:
        Serial.println("Right");
        digitalWrite(LEFT_MOTOR_RELAY_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_RELAY_PIN, HIGH);
        break;
    }
  }
  moveDirectionPrevious = moveDirection;
}

// Set how long the next movement should take
void changeMovementDuration(uint16_t duration) {
  intervalMovement = duration;
}