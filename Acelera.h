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

#ifndef Acelera_h
#define Acelera_h

#include<SPI.h>
#include<Arduino.h>

class Acelera {

public:
    int CS, x, y, z;
    char POWER_CTL, DATA_FORMAT, DATAX0, DATAX1, DATAY0, DATAY1, DATAZ0, DATAZ1;
    char valores[10];
    SPIClass SPI;

    Acelera();
    int valorX(void);
    int valorY(void);
    int valorZ(void);

private:
    void escribeRegistro(char direccionRegistro, char valor);
    void leeRegistro(char direccionRegistro, int numBytes, char * valores);
};

#endif /* defined(Acelera_h) */