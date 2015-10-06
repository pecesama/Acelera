// Read X, Y and Z from a ADXL345 3-axis accelerometer
// using Pedro Santana's Acelera 1.0 library
//
// Pedro Santana 02Jun2014
// http://www.pecesama.com/
//
// This file is free software; provided as is, with no warranty of any kind.
// In no event shall the author be liable for any claim, damages or other liability.

#include <Acelera.h>
#include <SPI.h>

Acelera acelera;

void setup() {
  Serial.begin(9600);
  Acelera::Acelera();
}

void loop() {
  Serial.print(" X: ");
  Serial.print(acelera.valorX());
  Serial.print(',');
  Serial.print(" Y: ");
  Serial.print(acelera.valorY());
  Serial.print(',');
  Serial.print(" Z: ");
  Serial.println(acelera.valorZ());      
  delay(3000); 
}