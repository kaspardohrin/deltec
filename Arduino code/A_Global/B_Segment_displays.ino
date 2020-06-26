// Initiate new 7 segment object
TM1637Display display_left(SEGMENT_CLK, SEGMENT_1_DIN);
TM1637Display display_right(SEGMENT_CLK, SEGMENT_2_DIN);

/** o _ _ _
 * _ _ _ _
*/
const uint8_t EYE_0[] = {
	SEG_A | SEG_B | SEG_F | SEG_G,
	0x00,
	0x00,
  0x00
};
/** _ o _ _
 * _ _ _ _
*/
const uint8_t EYE_1[] = {
  0x00,
	SEG_A | SEG_B | SEG_F | SEG_G,
	0x00,
  0x00
};
/** _ _ o _
 * _ _ _ _
*/
const uint8_t EYE_2[] = {
	0x00,
	0x00,
	SEG_A | SEG_B | SEG_F | SEG_G,
  0x00
};
/** _ _ _ o
 * _ _ _ _
*/
const uint8_t EYE_3[] = {
	0x00,
	0x00,
  0x00,
	SEG_A | SEG_B | SEG_F | SEG_G
};
/** |- - - _
 * _ o _ _
*/
const uint8_t EYE_4[] = {
	SEG_A | SEG_F,
	SEG_A | SEG_C | SEG_D | SEG_E | SEG_G,
	SEG_A,
  0x00
};
/** _ - - -|
 * _ _ o _
*/
const uint8_t EYE_5[] = {
  0x00,
	SEG_A,
	SEG_A | SEG_C | SEG_D | SEG_E | SEG_G,
  SEG_A | SEG_B
};
/** _ _ _ _
 * _ - _ _
*/
const uint8_t EYE_6[] = {
	0x00,
	SEG_G,
	0x00,
  0x00
};
/** _ _ _ _
 * _ _ - _
*/
const uint8_t EYE_7[] = {
  0x00,
	0x00,
	SEG_G,
  0x00
};
/** _ [ ] _
*/
const uint8_t EYE_8[] = {
	0x00,
	SEG_A | SEG_D | SEG_E | SEG_F,
	SEG_A | SEG_B | SEG_C | SEG_D,
  0x00
};

// Loading effects eyes
/** _ - _ _
 * _ _ _ _
*/
const uint8_t EYE_LOAD_1[] = {
	0x00,
	SEG_A,
	0x00,
  0x00
};
/** _ _ - _
 * _ _ _ _
*/
const uint8_t EYE_LOAD_2[] = {
	0x00,
	0x00,
	SEG_A,
  0x00
};
/** _ _ | _
 * _ _ _ _
*/
const uint8_t EYE_LOAD_3[] = {
	0x00,
	0x00,
	SEG_B,
  0x00
};
/** _ _ _ _
 * _ _ | _
*/
const uint8_t EYE_LOAD_4[] = {
	0x00,
	0x00,
	SEG_C,
  0x00
};
/** _ _ _ _
 * _ _ - _
*/
const uint8_t EYE_LOAD_5[] = {
	0x00,
	0x00,
	SEG_D,
  0x00
};
/** _ _ _ _
 * _ - _ _
*/
const uint8_t EYE_LOAD_6[] = {
	0x00,
	SEG_D,
	0x00,
  0x00
};
/** _ _ _ _
 * _ | _ _
*/
const uint8_t EYE_LOAD_7[] = {
	0x00,
	SEG_E,
	0x00,
  0x00
};
/** _ | _ _
 * _ _ _ _
*/
const uint8_t EYE_LOAD_8[] = {
	0x00,
	SEG_F,
	0x00,
  0x00
};

/**
 * Set the animation on the eyes
 * @param eyeAnimation Enum representing the animation
 */
void setEyeType(EyeType eyeAnimation) {
  // Save latest animation state
  if (eyeAnimation != BLINK) {
    nextIdleMovementEyes = eyeAnimation;
  }
  // Each eye module has a different amount of possible effects
  switch (eyeModuleVersion)
  {
  case RGB:
    setEyeTypeModule1(eyeAnimation);
    break;
  case SEGMENT:
    setEyeTypeModule2(eyeAnimation);
    break;
  case MATRIX:
    setEyeTypeModule3(eyeAnimation);
    break;
  }
}
void setEyeTypeModule1(EyeType eyeAnimation) {

}
void setEyeTypeModule2(EyeType eyeAnimation) {
  display_left.clear();
  display_right.clear();
  switch (eyeAnimation) {
    case NORMAL:
      // Eye normal
      display_left.setSegments(EYE_1);
      display_right.setSegments(EYE_2);
      break;
    case HAPPY:
      // look happy
      display_left.setSegments(EYE_6);
      display_right.setSegments(EYE_7);
      break;
    case ANGRY:
      // look angry
      display_left.setSegments(EYE_5);
      display_right.setSegments(EYE_4);
      break;
    case LEFT:
      // look left
      display_left.setSegments(EYE_0);
      display_right.setSegments(EYE_0);
      break;
    case RIGHT:
      // look right
      display_left.setSegments(EYE_3);
      display_right.setSegments(EYE_3);
      break;
    case CROSS:
      // look cross
      display_left.setSegments(EYE_3);
      display_right.setSegments(EYE_0);
      break;
    case SURPRISED:
      // look surprised
      display_left.setSegments(EYE_8);
      display_right.setSegments(EYE_8);
      break;
    case BLINK:
      // look blink
      display_left.setSegments(EYE_6);
      display_right.setSegments(EYE_7);
      break;
    default:
      break;
  }
}
void setEyeTypeModule3(EyeType eyeAnimation) {

}

void eyeBlink() {
  // start blink
  if (intervalBlink != 200) {
    // Blink animation
    setEyeType(BLINK);
    intervalBlink = 200;
  }
  // Open eyes
  else {
    setEyeType(nextIdleMovementEyes);
    // Set blink interval for next blink
    intervalBlink = (random(10,15)*1000);
  }
}

void idleMovementEyes() {
  setEyeType(nextIdleMovementEyes);
  if (nextIdleMovementEyes != NORMAL) {
    // The next idle movement will be normal eyes if it was different this time
    nextIdleMovementEyes = NORMAL;
  } else {
    // Next idle movement will be random
    uint8_t randomNumber = floor(random(1, 6));
    switch (randomNumber)
    {
    case 1:
      nextIdleMovementEyes = HAPPY;
      break;
    case 2:
      nextIdleMovementEyes = ANGRY;
      break;
    case 3:
      nextIdleMovementEyes = LEFT;
      break;
    case 4:
      nextIdleMovementEyes = RIGHT;
      break;
    case 5:
      nextIdleMovementEyes = CROSS;
      break;
    case 6:
      nextIdleMovementEyes = SURPRISED;
      break;
    }
  }
  // Next idle movement interval will be between 5 and 15 seconds
  intervalIdleEyes = (random(2,5)*1000);
}

void WiFiLoadAnimation() {
  // Each eye module has a different amount of possible effects
  switch (eyeModuleVersion)
  {
  case RGB:
    loadAnimationModule1();
    break;
  case SEGMENT:
    loadAnimationModule2();
    break;
  case MATRIX:
    loadAnimationModule3();
    break;
  }
}
// Wifi load animation for RGB eye module
void loadAnimationModule1() {
  switch (loadingBar) {
    case 0:
      // RGB led loading
      break;
    case 1:
      // RGB led loading
      break;
    case 2:
      // RGB led loading
      break;
    case 3:
      // RGB led loading
      break;
    case 4:
      // RGB led loading
      break;
    case 5:
      // RGB led loading
      break;
    case 6:
      // RGB led loading
      break;
    case 7:
      // RGB led loading
      break;
  }
}
// Wifi load animation for 7 segment eye module
void loadAnimationModule2() {
  switch (loadingBar) {
    case 0:
      display_left.setSegments(EYE_LOAD_1);
      display_right.setSegments(EYE_LOAD_1);
      break;
    case 1:
      display_left.setSegments(EYE_LOAD_2);
      display_right.setSegments(EYE_LOAD_2);
      break;
    case 2:
      display_left.setSegments(EYE_LOAD_3);
      display_right.setSegments(EYE_LOAD_3);
      break;
    case 3:
      display_left.setSegments(EYE_LOAD_4);
      display_right.setSegments(EYE_LOAD_4);
      break;
    case 4:
      display_left.setSegments(EYE_LOAD_5);
      display_right.setSegments(EYE_LOAD_5);
      break;
    case 5:
      display_left.setSegments(EYE_LOAD_6);
      display_right.setSegments(EYE_LOAD_6);
      break;
    case 6:
      display_left.setSegments(EYE_LOAD_7);
      display_right.setSegments(EYE_LOAD_7);
      break;
    case 7:
      display_left.setSegments(EYE_LOAD_8);
      display_right.setSegments(EYE_LOAD_8);
      break;
  }
}
// Wifi load animation for 8x8 matrix eye module
void loadAnimationModule3() {
  switch (loadingBar) {
    case 0:
      // Matrix loading animation
      break;
    case 1:
      // Matrix loading animation
      break;
    case 2:
      // Matrix loading animation
      break;
    case 3:
      // Matrix loading animation
      break;
    case 4:
      // Matrix loading animation
      break;
    case 5:
      // Matrix loading animation
      break;
    case 6:
      // Matrix loading animation
      break;
    case 7:
      // Matrix loading animation
      break;
  }
}