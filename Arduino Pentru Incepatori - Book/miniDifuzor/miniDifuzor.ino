//Arduino Board Used: Arduino Nano
//using D3 (pin 3) for the i/o of the buzzer

const int pinNr = 3;
void setup() {
  pinMode(pinNr,OUTPUT);
}
void loop() {
  for(int i = 0; i<4000;i++){
    tone(pinNr,i);
    delay(2);// short enough delay to hear the fluctuation
  }
  for(int i = 4000; i>0;i--){
    tone(pinNr,i);
    delay(2);// short enough delay to hear the fluctuation
  }
}
