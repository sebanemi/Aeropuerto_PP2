#include <iostream>
#include "pila.h"
#include "dominio.h"

using namespace std;

bool pilaIsEmpty(const Pila& pila) {
    if (pila.tope == nullptr) {
        return true;
    }
    return false;
}

void pilaPush(Pila& pila,TipoAccion tipo ,Pasajero* pas) {
    Accion* a = new Accion{tipo,pas,nullptr};
    a->sig = pila.tope;
    pila.tope = a;
}

Accion* pilaPop(Pila& pila) {
    if (pila.tope == nullptr) {
        return nullptr;
    }

    Accion* accion = pila.tope;

    pila.tope = pila.tope->sig;

    return accion;
}

void pilaPrintRec(const Accion* cabeza) {
    if (cabeza == nullptr) {
        return;
    }

    pilaPrintRec(cabeza->sig);

    cout << "Accion: " << (cabeza->tipo == AGREGAR ? "AGREGAR" : "PROCESAR")
         << " | Pasajero: " << cabeza->pasajero->nombre
         << ", " << cabeza->pasajero->id
         << ", " << cabeza->pasajero->nroVuelo << endl;
}

void pilaPrintRec(const Pila& pila) {
    pilaPrintRec(pila.tope);
}

void clearRec(Accion*& cabeza) {
    if (cabeza == nullptr) {
        return;
    }

    Accion* siguiente = cabeza->sig;

    clearRec(siguiente);

    delete cabeza;
    cabeza = nullptr;
}

void pilaClearRec(Pila& pila) {
    clearRec(pila.tope);
}

int sizeRec(const Accion* cabeza) {
    //Caso base
    if (cabeza == nullptr) {
        return 0;
    }
    //Caso recursivo
    return 1 + sizeRec(cabeza->sig);
}

int pilaSizeRec(const Pila& pila) {
    return sizeRec(pila.tope);
}

Pasajero* searchRec(const Accion* cabeza, int id) {
    if (cabeza == nullptr) {
        return nullptr;
    }

    if (cabeza->pasajero->id == id) {
        return cabeza->pasajero;
    }

    return searchRec(cabeza->sig, id);
}

Pasajero* pilaSearchRec(const Pila& pila, int id) {
    return searchRec(pila.tope, id);
}
