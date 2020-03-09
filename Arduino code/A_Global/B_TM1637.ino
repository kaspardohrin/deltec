// Code for TM1637 7 segment displays here

// Initiate new 7 segment object
TM1637Display display_left(SEGMENT_CLK, SEGMENT_1_DIN);
TM1637Display display_right(SEGMENT_CLK, SEGMENT_2_DIN);

/**
 * Set the animation on the eyes
 * @param eyeType Number representing the animation
 * 0 = normal
 * 1 = look left
 * 2 = look right
 * 3 = look down
 * 4 = cross
 * 5 = happy
 */
void setEyeType(uint8_t eyeType) {
  display_left.clear();
  display_right.clear();
  switch (eyeType)
  {
  case 0:
    // Eye normal
    display_left.setSegments(EYE_1);
    display_right.setSegments(EYE_2);
    break;
  case 1:
    // look left
    display_left.setSegments(EYE_0);
    display_right.setSegments(EYE_0);
    break;
  case 2:
    // look right
    display_left.setSegments(EYE_3);
    display_right.setSegments(EYE_3);
    break;
  case 3:
    // look down
    display_left.setSegments(EYE_4);
    display_right.setSegments(EYE_5);
    break;
  case 4:
    // look cross
    display_left.setSegments(EYE_3);
    display_right.setSegments(EYE_0);
    break;
  case 5:
    // look happy
    display_left.setSegments(EYE_6);
    display_right.setSegments(EYE_7);
    break;
  case 6:
    // look surprised
    display_left.setSegments(EYE_8);
    display_right.setSegments(EYE_8);
    break;
  default:
    break;
  }
}

void eyeBlink() {
  // new random interval for next blink (between 7 and 15 seconds)
  intervalBlink = (random(7,15)*1000);
  setEyeType(5);
  delay(100);
  setEyeType(nextIdleMovement);
}

void idleMovement() {
  setEyeType(nextIdleMovement);
  if (nextIdleMovement != 0) {
    // The next idle movement will be normal eyes if it was different this time
    nextIdleMovement = 0;
  } else {
    // Next idle movement will be random
    nextIdleMovement = random(1, 6);
  }
  // Next idle movement interval will be between 5 and 15 seconds
  intervalIdleEye = (random(2,5)*1000);
}