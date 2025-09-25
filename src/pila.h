
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

bool pilaIsEmpty(const Pila& p);

void pilaPush(Pila& cabeza,TipoAccion tipo ,Pasajero* pas);

Accion* pilaPop(Pila& p);

void pilaPrintRec(const Accion* cabeza);
void pilaPrintRec(const Pila& p);

void pilaClearRec(Accion*& cabeza);
void pilaClearRec(Pila& p);

int pilaSizeRec(const Accion* cabeza);
int pilaSizeRec(const Pila& p);

Pasajero* pilaSearchRec(const Accion* cabeza, int id);
Pasajero* pilaSearchRec(const Pila& p, int id);

#endif //AEROPUERTO_PP2_PILA_H