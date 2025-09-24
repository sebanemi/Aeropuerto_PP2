#include <iostream>
#include "pila.h"
#include "dominio.h"

using namespace std;

bool isEmpty(const Pila& pila) {
    if (pila.tope == nullptr) {
        return true;
    }
    return false;
}

//Lo hago como un addFirst
void push(Pila& pila,TipoAccion tipo ,Pasajero* pas) {
    Accion* a = new Accion{tipo,pas,nullptr};
    pila.tope = a;
}

//Lo hago como un removeFirst
/*
 * Recibe como parametro la cabecera de la pila
 * Devuelve un puntero a pasajero para que se inserte nuevamente en la cola
 *
 */
Accion* pop(Pila& pila) {
    if (pila.tope == nullptr) {
        return nullptr;
    }

    Accion* accion = pila.tope;

    pila.tope = pila.tope->sig;

    return accion;
}

void printPilaRec(const Accion* cabeza) {
    if (cabeza == nullptr) {
        return;
    }

    printPilaRec(cabeza->sig);

    cout << "Accion: " << (cabeza->tipo == AGREGAR ? "AGREGAR" : "PROCESAR")
         << " | Pasajero: " << cabeza->pasajero->nombre
         << ", " << cabeza->pasajero->id
         << ", " << cabeza->pasajero->nroVuelo << endl;
}

void printPilaRec(const Pila& pila) {
    printPilaRec(pila.tope);
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

void clearRec(Pila& pila) {
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

int sizeRec(const Pila& pila) {
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

Pasajero* searchRec(const Pila& pila, int id) {
    return searchRec(pila.tope, id);
}
