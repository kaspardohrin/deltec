#include <TM1637Display.h>
#include <ESP32Servo.h>

// TM1637 7 Segment Module connection pins
#define SEGMENT_1_DIN 15
#define SEGMENT_2_DIN 4
#define SEGMENT_CLK 5
// Servo pin
#define SERVO_PIN 18

// Variables for main code
uint16_t intervalBlink = 4000;          // Time between blinks
uint16_t intervalIdleEyes = 5000;        // Time between idle movement eyes
uint16_t intervalIdleTail = 6000;        // Time between idle movement tail
unsigned long previousMillisBlink = 0;  // Time last blink was done
unsigned long previousMillisIdleEyes = 0;   // Time last idle move was done
unsigned long previousMillisIdleTail = 0;   // Time last idle move was done
unsigned long currentMillis = 0;        // Current time

uint8_t nextIdleMovementEyes = 0;           // Next idle movement to do
uint8_t nextIdleMovementTail = 0;           // Next idle movement to do