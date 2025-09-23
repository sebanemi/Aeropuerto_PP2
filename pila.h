//
// Created by seban on 22/9/2025.
//
#include <iostream>

#ifndef AEROPUERTO_PP2_PILA_H
#define AEROPUERTO_PP2_PILA_H

#include "dominio.h"

using namespace std;

struct Pila {
    Pasajero* tope = nullptr;
};

bool isEmpty(Pila p);

void push(Pila& cabeza, Pasajero* pas);

Pasajero* pop(Pila& p);

void printPilaRec(Pila p);

void clearRec(Pila& p);

int sizeRec(Pila p);

Pasajero* searchRec(Pasajero* cabeza, int id);

#endif //AEROPUERTO_PP2_PILA_H