//
// Created by seban on 22/9/2025.
//
#include "dominio.h"
#include <iostream>

#ifndef AEROPUERTO_PP2_PILA_H
#define AEROPUERTO_PP2_PILA_H

using namespace std;

bool isEmpty(Pasajero* cabeza);

void push(Pasajero*& cabeza, Pasajero* pas);

Pasajero* pop(Pasajero*& cabeza);

void printPilaRec(Pasajero* cabeza);

void clearRec(Pasajero*& cabeza);

int sizeRec(Pasajero* cabeza);

Pasajero* searchRec(Pasajero* cabeza, int id);

#endif //AEROPUERTO_PP2_PILA_H