//I will use a different pin for this example
//the pin used in the book is pin 13, I will use D11 (pin 11) and gnd for this exercise
const int pinUsed = 11;
void setup() {
  pinMode(pinUsed,OUTPUT);
}

void loop() {
  digitalWrite(pinUsed,HIGH);
  delay(1000);
  digitalWrite(pinUsed,LOW);
  delay(1000);
}
