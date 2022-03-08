#include "DHT.h"

#define DHTTYPE DHT22

int DHTPIN = 13;

float dhtValue[2] = {0};

DHT dht(DHTPIN, DHTTYPE);

void setup() {

  Serial.begin(115200);
  
  Wire.begin();
  dht.begin();

}

void loop() {
  
  Serial.println("Nueva lectura");

  dht.readTempAndHumidity(dhtValue);
  Serial.print("Humedad: ");
  Serial.print(dhtValue[0]);
  Serial.print(" %\t");
  Serial.print("Temperatura: ");
  Serial.print(dhtValue[1]);
  Serial.println(" *C");
  
  Serial.println("---------------------");
  delay(5000);

}
