#include <string>
#include "dominio.h"
#include "cola.h"

using namespace std;

#ifndef AEROPUERTO_PP2_UTILS_H
#define AEROPUERTO_PP2_UTILS_H

/*
 * Lee el archivo preset (pasajeros_preset.txt), crea un nuevo Pasajero usando la funcion de dominio.cpp y lo encola usando la función que
 * armó mati
 */

bool cargarPasajerosEnCola(string filename, Cola& cola);

bool validarId(int id);

bool validarNroVuelo(string nroVuelo);

bool colaSearchBoolean(Pasajero* cabeza, int id);

#endif //AEROPUERTO_PP2_UTILS_H