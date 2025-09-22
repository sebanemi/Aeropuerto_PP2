//
// Created by seban on 22/9/2025.
//
#include "dominio.h"

#ifndef AEROPUERTO_PP2_PILA_H
#define AEROPUERTO_PP2_PILA_H

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

void printPilaRec() {

}

void clearRec() {

}

int sizeRec() {
    n = 0;
    return n;
}

void searchRec() {

}

#endif //AEROPUERTO_PP2_PILA_H