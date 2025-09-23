//
// Created by seban on 22/9/2025.
//

#include<string>

#ifndef AEROPUERTO_PP2_DOMINIO_H
#define AEROPUERTO_PP2_DOMINIO_H

using namespace std;

//Estructura para la cola (Pasajeros pendientes) y pila (cambios revertidos)
struct Pasajero {
    string nombre;
    int id;
    string nroVuelo;
    Pasajero* sig;
};

#endif //AEROPUERTO_PP2_DOMINIO_H