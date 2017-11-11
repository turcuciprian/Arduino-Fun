

/* SparkFun TSL2561

 *  */
#include <SparkFunTSL2561.h>
#include <Wire.h>

// Create an SFE_TSL2561 object, here called "light":
SFE_TSL2561 light;
boolean gain;     // Gain setting, 0 = X1, 1 = X16;
unsigned int ms;  // Integration ("shutter") time in milliseconds

void setup() {
  Serial.begin(9600);
  light.begin();

  unsigned char ID;
  if (light.getID(ID))
  {

    //    Serial.print(ID,HEX);

  }
  else
  {
    byte error = light.getError();
    printError(error);
  }
  gain = 0;
  unsigned char time = 2;
  light.setTiming(gain, time, ms);
  light.setPowerUp();

}

void loop() {
  delay(ms);
  unsigned int data0, data1;
  if (light.getData(data0, data1))
  {
    // getData() returned true, communication was successful

    Serial.print("D0: ");
    Serial.print(data0);
    Serial.print(" - D1: ");
    Serial.print(data1);
  }
  double lux;    // Resulting lux value
  boolean good;  // True if neither sensor is saturated
  good = light.getLux(gain, ms, data0, data1, lux);
  Serial.print(" - LUX: ");
  Serial.print(lux);
  Serial.println("");
  Serial.println("---");

}

void printError(byte error)
// If there's an I2C error, this function will
// print out an explanation.
{
  Serial.print("I2C error: ");
  Serial.print(error, DEC);
  Serial.print(", ");

  switch (error)
  {
    case 0:
      Serial.println("success");
      break;
    case 1:
      Serial.println("data too long for transmit buffer");
      break;
    case 2:
      Serial.println("received NACK on address (disconnected?)");
      break;
    case 3:
      Serial.println("received NACK on data");
      break;
    case 4:
      Serial.println("other error");
      break;
    default:
      Serial.println("unknown error");
  }
}

