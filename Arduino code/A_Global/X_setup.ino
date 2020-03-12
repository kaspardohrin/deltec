void setup() {
  Serial.begin(115200);
  Serial.println(F("Starting setup"));

  // TM1637 7 Segment setup
  display_left.setBrightness(0x0f);
  display_right.setBrightness(0x0f);
  display_left.clear();
  display_right.clear();

  // Servo setup
  if (!tailServo.attached()) {
		tailServo.setPeriodHertz(50); // standard 50 hz servo
		tailServo.attach(SERVO_PIN, 1000, 2000); // Attach the servo after it has been detatched
	}
  tailServo.write(0);
}