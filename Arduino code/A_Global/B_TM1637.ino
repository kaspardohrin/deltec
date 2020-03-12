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

/** _ _ _ _
 * _ o _ _
*/
const uint8_t EYE_4[] = {
	0x00,
	SEG_C | SEG_D | SEG_E | SEG_G,
	0x00,
  0x00
};
/** _ _ _ _
 * _ _ o _
*/
const uint8_t EYE_5[] = {
  0x00,
	0x00,
	SEG_C | SEG_D | SEG_E | SEG_G,
  0x00
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
  // start blink
  if (intervalBlink != 200) {
    // Blink animation
    setEyeType(5);
    intervalBlink = 200;
  } 
  // Open eyes
  else {
    setEyeType(nextIdleMovementEyes);
    intervalBlink = (random(7,15)*1000);
  }  
}

void idleMovementEyes() {
  setEyeType(nextIdleMovementEyes);
  if (nextIdleMovementEyes != 0) {
    // The next idle movement will be normal eyes if it was different this time
    nextIdleMovementEyes = 0;
  } else {
    // Next idle movement will be random
    nextIdleMovementEyes = random(1, 6);
  }
  // Next idle movement interval will be between 5 and 15 seconds
  intervalIdleEyes = (random(2,5)*1000);
}