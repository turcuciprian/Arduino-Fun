//NewPing Library used
//Library downloaded from here: https://bitbucket.org/teckel12/arduino-new-ping/downloads/
#include <NewPing.h>
const int xTrigPin = 3;//OUTPUT
const int xEchoPin = 2;//INPUT
const int xBuzzPin = 9; // Buzzer

long distancex;
int duration;
NewPing sonar(xTrigPin,xEchoPin,2000);
void setup() {
  pinMode(xTrigPin, OUTPUT);
  pinMode(xEchoPin, INPUT);
//  pinMode(xBuzzPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {  
   int distance = sonar.ping_cm();
  if(distance<15 && distance !=0){
//    Serial.println(distance);  
    pinMode(xBuzzPin, HIGH);
//    digitalWrite(xBuzzPin,HIGH);
    delay(50);// short enough delay to hear the fluctuation
    
  }
  
  pinMode(xBuzzPin, LOW);
 }
