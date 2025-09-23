#include <iostream>
#include "pila.h"
#include "dominio.h"

using namespace std;

bool isEmpty(Pasajero* cabeza) {
    if (cabeza == nullptr) {
        return true;
    }
    return false;
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

    cout<<"  " <<cabeza->nombre<<", "<<cabeza->id<<", "<<cabeza->nroVuelo<<endl;

}

void clearRec(Pasajero*& cabeza) {
    if (cabeza == nullptr) {
        return;
    }

    Pasajero* siguiente = cabeza->sig;

    clearRec(siguiente);

    eliminarPasajero(cabeza);
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
