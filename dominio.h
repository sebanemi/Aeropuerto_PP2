//
// Created by seban on 22/9/2025.
//

#include<string>

#ifndef AEROPUERTO_PP2_DOMINIO_H
#define AEROPUERTO_PP2_DOMINIO_H

using namespace std;

//Estructura para la cola (Pasajeros pendientes)
struct Pasajero {
    string nombre;
    string nroVuelo;
    Pasajero* sig;
};

//Estructura para la pila (Para pasajero procesados)
struct Chequeo {
    string nroVuelo;
    Chequeo* sig;
};

#endif //AEROPUERTO_PP2_DOMINIO_H