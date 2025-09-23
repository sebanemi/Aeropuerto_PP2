#include <iostream>
#include "pila.h"
#include "dominio.h"

using namespace std;

// Devuelve true si la cola está vacía (cabeza == nullptr), false en caso contrario.
// Simple chequeo del puntero cabeza.
bool colaIsEmpty(Pasajero* cabeza) {

    if (cabeza == nullptr) {
        return true;
    }
    return false;

}

// Inserta un nodo al final de la cola.
// Si la cola está vacía, cabeza pasa a ser el nuevo nodo.
// Si no, recorre con un puntero auxiliar hasta el último y engancha el nuevo al final.
void colaPush(Pasajero*& cabeza, Pasajero* pas) {
    if (cabeza == nullptr) {
        cabeza = pas;
        pas->sig = nullptr;

    }else {
        Pasajero* reco = cabeza;
        while (reco->sig != nullptr) {
reco = reco->sig;
        }
        reco->sig = pas;
    }

}

// Extrae (y devuelve) el primer elemento de la cola.
// Si está vacía, retorna nullptr. Si no, mueve cabeza al siguiente y retorna el viejo primero.
Pasajero* colaPop(Pasajero*& cabeza) {
if (cabeza == nullptr) {
    return nullptr;
}
    Pasajero* reco= cabeza;
cabeza = cabeza->sig;

    return reco;
}

// RECURSIVA
// Imprime la cola en orden de cabeza hacia el final.
// Caso base: cabeza == nullptr (corta). Caso recursivo: imprime actual y llama con cabeza->sig.
void colaPrintRec(Pasajero* cabeza) {
    if (cabeza == nullptr) {
        return;
    }

    cout << "  " << cabeza->nombre << ", " << cabeza->id << ", " << cabeza->nroVuelo << endl;

    colaPrintRec(cabeza->sig);
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

// RECURSIVA
// Calcula el tamaño de la cola contando nodos.
// Caso base: nullptr → 0. Caso recursivo: 1 + tamaño del resto (cabeza->sig).
int colaSizeRec(Pasajero* cabeza) {

    if (cabeza == nullptr) {
        return 0;
    }

    return 1 + sizeRec(cabeza->sig);
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
