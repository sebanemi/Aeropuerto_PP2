
#include<string>

#include "pila.h"

#ifndef AEROPUERTO_PP2_DOMINIO_H
#define AEROPUERTO_PP2_DOMINIO_H

using namespace std;

struct Pasajero {
    string nombre;
    int id;
    string nroVuelo;
    Pasajero* sig;
};

Pasajero* crearNuevoPasajero(string nombre, int id, string nroVuelo);

void eliminarPasajero(Pasajero*& p);

#endif //AEROPUERTO_PP2_DOMINIO_H