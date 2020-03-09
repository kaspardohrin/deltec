#include <TM1637Display.h>

// TM1637 7 Segment Module connection pins
#define SEGMENT_CLK 5
#define SEGMENT_1_DIN 2
#define SEGMENT_2_DIN 4

// Variables for main code
uint16_t intervalBlink = 4000;          // Time between blinks
uint16_t intervalIdleEye = 5000;        // Time between idle movement changes
unsigned long previousMillisBlink = 0;  // Time last blink was done
unsigned long previousMillisIdle = 0;   // Time last idle move was done
unsigned long currentMillis = 0;        // Current time

uint8_t nextIdleMovement = 0;           // Next idle movement to do

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

uint8_t activeMode = 0;