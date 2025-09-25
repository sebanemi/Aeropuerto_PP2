//
// Created by matiasmeneclier on 23/9/2025.
//
#include "dominio.h"
#include <iostream>

#ifndef AEROPUERTO_PP2_COLA_H
#define AEROPUERTO_PP2_COLA_H

using namespace std;

struct Cola {
    Pasajero* primero = nullptr;
    Pasajero* ultimo = nullptr;
};

bool colaIsEmpty(const Cola& cola);

void colaQueue(Cola& cola, Pasajero* pas);

void colaQueueFront(Cola& cola, Pasajero* pas);

Pasajero* colaDequeue(Cola& cola);

Pasajero* colaDequeueBack(Cola& cola);

// RECURSIVA
void colaPrintRec(const Pasajero* cabeza);
void colaPrintRec(const Cola& cola);

// RECURSIVA
void colaClearRec(Pasajero*& cabeza);
void colaClearRec(Cola& cola);

// RECURSIVA
int colaSize(const Pasajero* cabeza);
int colaSizeRec(const Cola& cola);

// RECURSIVA
Pasajero* colaSearchRec(Pasajero* cabeza, int id);
Pasajero* colaSearchRec(const Cola& cola, int id);

#endif //AEROPUERTO_PP2_COLA_H