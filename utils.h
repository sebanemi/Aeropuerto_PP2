#include <string>
#include "dominio.h"
#include "pila.h"
//#include "cola.h"

using namespace std;

#ifndef AEROPUERTO_PP2_UTILS_H
#define AEROPUERTO_PP2_UTILS_H

bool cargarPasajerosEnCola(string filename, Pasajero*& first, Pasajero*& last);

bool validarId(int id);

bool validarNroVuelo(string nroVuelo);

#endif //AEROPUERTO_PP2_UTILS_H