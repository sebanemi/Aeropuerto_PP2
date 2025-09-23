#include <iostream>

#include "dominio.h"
#include "pila.h"

using namespace std;

int main() {
    Pila stack{};
    Pasajero* pas = crearNuevoPasajero("seba",1,"123A");
    Pasajero* pa2 = crearNuevoPasajero("juan",2,"123A");
    Pasajero* pa3 = crearNuevoPasajero("pedro",3,"123A");

    push(stack, pas);
    push(stack, pa2);
    push(stack, pa3);

    printPilaRec(stack);


    cout<<"POPING:"<<endl;
    pop(stack);
    printPilaRec(stack);

    cout<<"SIZE:"<<sizeRec(stack)<<endl;

    clearRec(stack);

    return 0;
}