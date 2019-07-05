char n;

void setup() {
  Serial.begin(9600);
  for (char i = 2; i < 6; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  while (Serial.available() > 0) {
    n = Serial.read();
    if (isDigit(n)) {
      n -= '0';
      for (char i = 0; i < 4; i++)
        digitalWrite(i + 2, (n >> i) & 1u);
    }
  }
  delay(10);
}
