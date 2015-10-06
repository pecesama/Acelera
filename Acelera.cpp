// Acelera 1.0 library for arduino
// Read X, Y and Z from a ADXL345 3-axis accelerometer
//
// Pedro Santana 02Jun2014
// http://www.pecesama.com/
//
// This file is free software; provided as is, with no warranty of any kind.
// In no event shall the author be liable for any claim, damages or other liability.
//
// Code based on the Sparkfun ADXL345 quickstart guide.

#include "Acelera.h"

Acelera::Acelera() {
    CS=10; //Asignar al pin 10.
    POWER_CTL = 0x2D;	//Power Control Register
    DATA_FORMAT = 0x31;
    DATAX0 = 0x32;	//X-Axis Data 0
    DATAX1 = 0x33;	//X-Axis Data 1
    DATAY0 = 0x34;	//Y-Axis Data 0
    DATAY1 = 0x35;	//Y-Axis Data 1
    DATAZ0 = 0x36;	//Z-Axis Data 0
    DATAZ1 = 0x37;	//Z-Axis Data 1
    SPI.begin();
    SPI.setDataMode(SPI_MODE3);
    pinMode(CS, OUTPUT);
    digitalWrite(CS, HIGH);
    escribeRegistro(DATA_FORMAT, 0x01);
    escribeRegistro(POWER_CTL, 0x08);
}

int Acelera::valorX(void) {
    leeRegistro(DATAX0, 6, valores);
    x = ((int)valores[1]<<8)|(int)valores[0];
    return x;
}

int Acelera::valorY(void) {
    leeRegistro(DATAX0, 6, valores);
    y = ((int)valores[3]<<8)|(int)valores[2];
    return y;
}

int Acelera::valorZ(void) {
    leeRegistro(DATAX0, 6, valores);
    z = ((int)valores[5]<<8)|(int)valores[4];
    return z;
}

void Acelera::escribeRegistro(char direccionRegistro, char valor) {
    digitalWrite(CS, LOW);
    SPI.transfer(direccionRegistro);
    SPI.transfer(valor);
    digitalWrite(CS, HIGH);
}

void Acelera::leeRegistro(char direccionRegistro, int numBytes, char * valores) {
    char direccion = 0x80 | direccionRegistro;
    if(numBytes > 1)direccion = direccion | 0x40;
    digitalWrite(CS, LOW);
    SPI.transfer(direccion);
    for(int i=0; i<numBytes; i++) {
        valores[i] = SPI.transfer(0x00);
    }
    digitalWrite(CS, HIGH);
}