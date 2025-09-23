#include <iostream>
#include "pila.h"
#include "dominio.h"

using namespace std;

bool isEmpty(Pila pila) {
    if (pila.tope == nullptr) {
        return true;
    }
    return false;
}

//Lo hago como un addFirst
/*
 * Recibe como parametro la cabecera de la pila y el objeto pasajero que se removió de la cola
 *
 */
void push(Pila& pila, Pasajero* pas) {
    if (pila.tope == nullptr) {
        pila.tope = pas;
        pas->sig = nullptr;
        return;
    }

    pas->sig = pila.tope;
    pila.tope = pas;
}

//Lo hago como un removeFirst
/*
 * Recibe como parametro la cabecera de la pila
 * Devuelve un puntero a pasajero para que se inserte nuevamente en la cola
 *
 */
Pasajero* pop(Pila& pila) {
    if (pila.tope == nullptr) {
        return nullptr;
    }

    Pasajero* pasajero = pila.tope;

    pila.tope = pila.tope->sig;

    return pasajero;
}

void printPilaRec(Pasajero* cabeza) {
    if (cabeza == nullptr) {
        return;
    }

    printPilaRec(cabeza->sig);

    cout<<"  " <<cabeza->nombre<<", "<<cabeza->id<<", "<<cabeza->nroVuelo<<endl;
}

void printPilaRec(Pila pila) {
    printPilaRec(pila.tope);
}

void clearRec(Pasajero*& cabeza) {
    if (cabeza == nullptr) {
        return;
    }

    Pasajero* siguiente = cabeza->sig;

    clearRec(siguiente);

    eliminarPasajero(cabeza);
}

void clearRec(Pila& pila) {
    clearRec(pila.tope);
}

int sizeRec(Pasajero* cabeza) {
    //Caso base
    if (cabeza == nullptr) {
        return 0;
    }
    //Caso recursivo
    return 1 + sizeRec(cabeza->sig);
}

int sizeRec(Pila pila) {
    return sizeRec(pila.tope);
}

Pasajero* searchRec(Pasajero* cabeza, int id) {
    if (cabeza == nullptr) {
        return nullptr;
    }

    if (cabeza->id == id) {
        return cabeza;
    }

    return searchRec(cabeza->sig, id);
}

Pasajero* searchRec(Pila& pila, int id) {
    return searchRec(pila.tope, id);
}
