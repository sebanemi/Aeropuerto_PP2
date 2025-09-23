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

bool isEmpty(const Pila& p);

void push(Pila& cabeza, Pasajero* pas);

Pasajero* pop(Pila& p);

void printPilaRec(const Pila& p);

void clearRec(Pila& p);

int sizeRec(const Pila& p);

Pasajero* searchRec(const Pila& p, int id);

#endif //AEROPUERTO_PP2_PILA_H