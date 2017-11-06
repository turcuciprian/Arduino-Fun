const int pinUsed = 3;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(citesteTempInCelsius());
  delay(1000);
}

float citesteTempInCelsius(){
  float temperaturaMEdiata = 0;
  float sumaTemperatura;
  for(int i = 0;i<10;i++){
    int reading = analogRead(pinUsed);
    float voltage = reading * 5.0;
    voltage /= 1024.0;
    float temperaturaCelsius = (voltage - 0.5)*100;
    sumaTemperatura = sumaTemperatura + temperaturaCelsius;
  }
  // ERROR AT COUNT -- not declared in scope
  return sumaTemperatura/ (float)count;
}

