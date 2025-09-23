//
// Created by seban on 22/9/2025.
//
#include "dominio.h"
#include <iostream>

#ifndef AEROPUERTO_PP2_PILA_H
#define AEROPUERTO_PP2_PILA_H

using namespace std;

bool isEmpty(Pasajero* cabeza) {
    if (cabeza == nullptr) {
        return true;
    }
}

//Lo hago como un addFirst
/*
 * Recibe como parametro la cabecera de la pila y el objeto pasajero que se removió de la cola
 *
 */
void push(Pasajero*& cabeza, Pasajero* pas) {
    if (cabeza == nullptr) {
        cabeza = pas;
        pas->sig = nullptr;
        return;
    }

    pas->sig = cabeza;
    cabeza = pas;
}

//Lo hago como un removeFirst
/*
 * Recibe como parametro la cabecera de la pila
 * Devuelve un puntero a pasajero para que se inserte nuevamente en la cola
 *
 */
Pasajero* pop(Pasajero*& cabeza) {
    if (cabeza == nullptr) {
        return nullptr;
    }

    Pasajero* pasajero = cabeza;

    cabeza = cabeza->sig;

    return pasajero;
}

void printPilaRec(Pasajero* cabeza) {
    if (cabeza == nullptr) {
        return;
    }

    printPilaRec(cabeza->sig);

    cout<<"  " <<cabeza->nombre<<", "<<cabeza->nroVuelo<<endl;

}

void clearRec(Pasajero*& cabeza) {
    if (cabeza == nullptr) {
        return;
    }

    Pasajero* siguiente = cabeza->sig;

    clearRec(siguiente);

    delete cabeza;

    cabeza = nullptr;
}

int sizeRec(Pasajero* cabeza) {
    //Caso base
    if (cabeza == nullptr) {
        return 0;
    }
    //Caso recursivo
    return 1 + sizeRec(cabeza->sig);
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

#endif //AEROPUERTO_PP2_PILA_H