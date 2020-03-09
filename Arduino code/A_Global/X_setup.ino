void setup() {
  Serial.begin(115200);
  Serial.println(F("Starting setup"));

  // TM1637 7 Segment setup
  display_left.setBrightness(0x0f);
  display_right.setBrightness(0x0f);
  display_left.clear();
  display_right.clear();
}