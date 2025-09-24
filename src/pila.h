
#ifndef AEROPUERTO_PP2_PILA_H
#define AEROPUERTO_PP2_PILA_H

#include "dominio.h"

using namespace std;

enum TipoAccion {AGREGAR,PROCESAR};

struct Accion {
    TipoAccion tipo;
    Pasajero* pasajero;
    Accion* sig;
};

struct Pila {
    Accion* tope = nullptr;
};

bool isEmpty(const Pila& p);

void push(Pila& cabeza,TipoAccion tipo ,Pasajero* pas);

Accion* pop(Pila& p);

void printPilaRec(const Accion* cabeza);
void printPilaRec(const Pila& p);

void clearRec(Accion*& cabeza);
void clearRec(Pila& p);

int sizeRec(const Accion* cabeza);
int sizeRec(const Pila& p);

Pasajero* searchRec(const Accion* cabeza, int id);
Pasajero* searchRec(const Pila& p, int id);

#endif //AEROPUERTO_PP2_PILA_H