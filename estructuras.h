#pragma once
#define HEADER_H

#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <fstream>
#include <ios>
#include <ctime>
#include <conio.h>

using namespace std; 

typedef struct cliente {
    string nombre; 
    string nombreVuelo;
    float total; 
    int asientos;
};
typedef struct vuelo{
    string nombre; 
    string codigodeVuelo; 
    string horadeSalida; 
    string horadeLlegada; 
    float costos;
    int cant;
};
