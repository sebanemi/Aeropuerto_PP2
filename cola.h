//
// Created by matiasmeneclier on 23/9/2025.
//
#include "dominio.h"
#include <iostream>

#ifndef AEROPUERTO_PP2_COLA_H
#define AEROPUERTO_PP2_COLA_H

using namespace std;

bool colaIsEmpty(Pasajero* cabeza);

void colaPush(Pasajero*& cabeza, Pasajero* pas);

Pasajero* colaPop(Pasajero*& cabeza);

// RECURSIVA
void colaPrintRec(Pasajero* cabeza);

// RECURSIVA
void colaClearRec(Pasajero*& cabeza);

// RECURSIVA
int colaSizeRec(Pasajero* cabeza);

// RECURSIVA
Pasajero* colaSearchRec(Pasajero* cabeza, int id);

#endif //AEROPUERTO_PP2_COLA_H