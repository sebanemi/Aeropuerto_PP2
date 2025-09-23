#include <iostream>

#include "dominio.h"
#include "pila.h"

using namespace std;

int main() {
    Pasajero* stack = nullptr;
    Pasajero* pas = new Pasajero;
    pas->sig = nullptr;
    pas->nombre = "seba";
    pas->id = 1;
    pas->nroVuelo = "123A";
    push(stack, pas);

    printPilaRec(stack);

    clearRec(stack);

    return 0;
}