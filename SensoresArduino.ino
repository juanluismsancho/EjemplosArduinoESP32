#include "DHT.h"

#define DHTTYPE DHT22

int aguaPin = A0;
int humedadPin = A1;

int DHTPIN = 8;

float sensorAgua;
float dhtValue[2] = {0};
float sensorHumedadSuelo;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);
  pinMode(aguaPin, INPUT);
  
  Wire.begin();
  dht.begin();
}

void loop() {
  Serial.println("Nueva lectura");
  sensorHumedadSuelo = analogRead(humedadPin);
  Serial.print("Humedad suelo = " );
  Serial.println(sensorHumedadSuelo);

  sensorAgua = digitalRead(aguaPin);
  Serial.print("Agua = " );
  Serial.println(sensorAgua);

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
