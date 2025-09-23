#include<iostream>
#include "dominio.h"

using namespace std;

Pasajero* crearNuevoPasajero(string& nombre, int id, string& nroVuelo) {
    return new Pasajero{nombre, id, nroVuelo, nullptr};
}

void eliminarPasajero(Pasajero*& p) {
    delete p;
    p = nullptr;
}