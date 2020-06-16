void move() {
  // Do we need to change the state of the motors
  if (moveDirection != moveDirectionPrevious) {
    moveDirectionPrevious = moveDirection;
    switch (moveDirection) {
      case IDLE:
        digitalWrite(LEFT_MOTOR_FORWARD_PIN, LOW);
        digitalWrite(LEFT_MOTOR_BACKWARD_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_FORWARD_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_BACKWARD_PIN, LOW);
        // Movement is done
        driving = false;
        break;
      case FORWARD:
        digitalWrite(LEFT_MOTOR_FORWARD_PIN, HIGH);
        digitalWrite(LEFT_MOTOR_BACKWARD_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_FORWARD_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_BACKWARD_PIN, LOW);
        break;
      case BACKWARD:
        digitalWrite(LEFT_MOTOR_FORWARD_PIN, LOW);
        digitalWrite(LEFT_MOTOR_BACKWARD_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_FORWARD_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_BACKWARD_PIN, HIGH);
        break;
      case LEFT:
        digitalWrite(LEFT_MOTOR_FORWARD_PIN, LOW);
        digitalWrite(LEFT_MOTOR_BACKWARD_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_FORWARD_PIN, HIGH);
        digitalWrite(RIGHT_MOTOR_BACKWARD_PIN, LOW);
        break;
      case RIGHT:
        digitalWrite(LEFT_MOTOR_FORWARD_PIN, HIGH);
        digitalWrite(LEFT_MOTOR_BACKWARD_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_FORWARD_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_BACKWARD_PIN, HIGH);
        break;
      default:
        digitalWrite(LEFT_MOTOR_FORWARD_PIN, LOW);
        digitalWrite(LEFT_MOTOR_BACKWARD_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_FORWARD_PIN, LOW);
        digitalWrite(RIGHT_MOTOR_BACKWARD_PIN, LOW);
        break;
    }
  }
}

// Set how long the next movement should take
void changeMovementDuration(uint16_t duration) {
  intervalMovement = duration;
}