#include <iostream>
#include "cola.h"
#include "dominio.h"

using namespace std;

// Devuelve true si la cola está vacía (cabeza == nullptr), false en caso contrario.
// Simple chequeo del puntero cabeza.
bool colaIsEmpty(const Cola& cola) {

    if (cola.primero == nullptr) {
        return true;
    }
    return false;

}

// Inserta un nodo al final de la cola.
// Si la cola está vacía, cabeza pasa a ser el nuevo nodo.
// Si no, recorre con un puntero auxiliar hasta el último y engancha el nuevo al final.
void colaQueue(Cola& cola, Pasajero* pas) {
    if (cola.primero == nullptr) {
        cola.primero = pas;
        cola.ultimo = pas;
        pas->sig = nullptr;

    }else {
        cola.ultimo->sig = pas;
        pas->sig = nullptr;
        cola.ultimo = pas;
    }

}

// Extrae (y devuelve) el primer elemento de la cola.
// Si está vacía, retorna nullptr. Si no, mueve cabeza al siguiente y retorna el viejo primero.
Pasajero* colaDequeue(Cola& cola) {
    if (cola.primero == nullptr) {
        return nullptr;
    }
    Pasajero* reco= cola.primero;
    cola.primero = cola.primero->sig;

    //Cola vacia
    if (cola.primero == nullptr) {
        cola.ultimo = nullptr;
    }

    return reco;
}

// RECURSIVA
// Imprime la cola en orden de cabeza hacia el final.
// Caso base: cabeza == nullptr (corta). Caso recursivo: imprime actual y llama con cabeza->sig.
void colaPrintRec(const Pasajero* cabeza) {
    if (cabeza == nullptr) {
        return;
    }

    cout << "  " << cabeza->nombre << ", " << cabeza->id << ", " << cabeza->nroVuelo << endl;

    colaPrintRec(cabeza->sig);
}

void colaPrintRec(const Cola& cola) {
    colaPrintRec(cola.primero);
}


// RECURSIVA
// Libera recursivamente todos los nodos de la cola.
// Guarda el siguiente, borra el actual y continúa con el resto hasta nullptr.
void colaClearRec(Pasajero*& cabeza) {
    if (cabeza == nullptr) {
        return;
    }
    Pasajero* siguiente = cabeza->sig;  // guardo el siguiente
    delete cabeza;                      // libero el nodo actual
    cabeza = nullptr;

    colaClearRec(siguiente);
}

void colaClearRec(Cola& cola) {
    colaClearRec(cola.primero);
    cola.ultimo = nullptr;
}

// RECURSIVA
// Calcula el tamaño de la cola contando nodos.
// Caso base: nullptr → 0. Caso recursivo: 1 + tamaño del resto (cabeza->sig).
int colaSizeRec( const Pasajero* cabeza) {

    if (cabeza == nullptr) {
        return 0;
    }

    return 1 + colaSizeRec(cabeza->sig);
}

int colaSizeRec(const Cola& cola) {
    return colaSizeRec(cola.primero);
}

// RECURSIVA
// Busca el primer nodo cuyo id coincida con el buscado.
// Caso base: nullptr → no encontrado. Si coincide en el actual, lo devuelve; si no, busca en el resto.
Pasajero* colaSearchRec(Pasajero* cabeza, int id) {
    if (cabeza == nullptr) {
        return nullptr; // no lo encontró, cola vacía o llegamos al final
    }

    if (cabeza->id == id) {
        return cabeza; // encontrado
    }

    // caso recursivo: buscar en el resto de la lista
    return colaSearchRec(cabeza->sig, id);
}

Pasajero* colaSearchRec(const Cola& cola, int id) {
    return colaSearchRec(cola.primero, id);
}
