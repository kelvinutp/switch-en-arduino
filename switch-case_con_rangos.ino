int a;
void setup() {
  Serial.begin(9600);
  pinMode(3, OUTPUT);
  pinMode(8, INPUT);
  pinMode(7, OUTPUT);

}

void loop() {
  digitalWrite(7, HIGH);
  delayMicroseconds(10);
  digitalWrite(7, LOW);
  a = map(pulseIn(8, HIGH), 270, 1700, 4, 30);
  switch (a)
  {
    case 0 ... 20:
      analogWrite(3, 255);
      break;
    case 21 ... 25:
      analogWrite(3, 100);
      break;
    case 26...29:
      analogWrite(3, 50);
      break;
    case 30:
      analogWrite(3, 0);
      break;
  }
  delay(100);
}
