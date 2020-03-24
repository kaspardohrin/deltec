void move() {
  // Do we need to change the state of the motors
  if (moveDirection != moveDirectionPrevious) {
    moveDirectionPrevious = moveDirection;
    switch (moveDirection) {
      case IDLE:
        digitalWrite(LEFT_MOTOR_RELAY_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_RELAY_PIN, HIGH);
        // Movement is done
        driving = false;
        break;
      case FORWARD:
        digitalWrite(LEFT_MOTOR_RELAY_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_RELAY_PIN, LOW);
        break;
      case LEFT:
        digitalWrite(LEFT_MOTOR_RELAY_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_RELAY_PIN, LOW);
        break;
      case RIGHT:
        digitalWrite(LEFT_MOTOR_RELAY_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_RELAY_PIN, HIGH);
        break;
      default:
        digitalWrite(LEFT_MOTOR_RELAY_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_RELAY_PIN, HIGH);
        break;
    }
  }
}

// Set how long the next movement should take
void changeMovementDuration(uint16_t duration) {
  intervalMovement = duration;
}