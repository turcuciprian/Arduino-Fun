//NewPing Library used
//Library downloaded from here: https://bitbucket.org/teckel12/arduino-new-ping/downloads/
#include <NewPing.h>


const int trigPin = 3;//OUTPUT
const int echoPin = 2;//INPUT
long distance;
int duration;
NewPing sonar(trigPin,echoPin,200);
void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(trigPin, INPUT);
  Serial.begin(9600);
}
void loop() {  
  Serial.print("Distance:");
  Serial.print(sonar.ping_cm());
  Serial.println(" cm");
}
