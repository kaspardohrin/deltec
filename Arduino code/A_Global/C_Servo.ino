// New servo instance
Servo tailServo;

/** List of idle movements
 * 0 = Straight resting position
 * 1 = 45* left
 * 2 = 45* right
 * 3 = 90* down left
 * 4 = 90* down right
 * 5 = Happy mode <- Temporaraly stops idle movement and resumes on effect end
 */

// Array with usable tail positions in degrees
uint16_t tailPositions[] = {90, 45, 135, 0, 180};  // Preselected tail angles
uint8_t wiggleCount = 0;                            // Amount of wiggles done
bool wiggling = false;                             // Is the tail currently wiggling

/**
 * Select next idle movement and set servo position to that.
 */
void idleMovementTail() {
  if (wiggling) {
    // Happy mode
    wiggleTail();
  } else if (idleTail) {
    // Set sail to angle
    tailServo.write(tailPositions[nextIdleMovementTail]);
    selectNextTailIdleMovevent();
  }
}

void selectNextTailIdleMovevent() {
  if (nextIdleMovementTail != 0) {
    // The next idle movement will be straight tail if it was different this time
    nextIdleMovementTail = 0;
    // This will stay for a short time
    intervalIdleTail = 1000;
  } else {
    // Next idle movement will a random static angle
    nextIdleMovementTail = random(1, 4);
    // Next idle movement interval will be random
    intervalIdleTail = (random(10,20)*1000);
  }
}

void wiggleTail() {
  wiggling = true;
  intervalIdleTail = 100;
  // wiggle tail animation X times
  if (wiggleCount <= 8) {
    // Is tail going left
    if ((wiggleCount % 2) == 0) {
      tailServo.write(70);
    }
    // or right
    else {
      tailServo.write(100);
    }
    wiggleCount ++;
  } else {
    // Tail wiggle done start idle movement again
    wiggleCount = 0;
    wiggling = false;
    tailServo.write(90);
    selectNextTailIdleMovevent();
  }
}
