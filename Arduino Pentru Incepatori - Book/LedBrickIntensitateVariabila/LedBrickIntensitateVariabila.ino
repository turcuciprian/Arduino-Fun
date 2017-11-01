//Since I'm using arduino Nano, I will be using pin 9 (D9) for a PWM effect as that is one of the pins in the Arduino nano board that supports PWM
const int pinUsed = 9;
void setup() {
  pinMode(pinUsed,OUTPUT);
}

void loop() {
  for(int i = 0; i<255;i++){
    analogWrite(pinUsed,i);
    delay(2);// small delay means fast pulse rate
  }
  for(int i = 255;i>0;i--){
    analogWrite(pinUsed,i);
    delay(2);// small delay means fast pulse rate
  }

}
