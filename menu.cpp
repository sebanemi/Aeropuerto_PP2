#include "dominio.h"
#include "menu.h"
#include "pila.h"
//#include "cola.h"
#include "utils.h"
#include <iostream>

using namespace std;

void mostrarMenu() {
    cout << "\n=== TP Pilas y Colas ===\n"
         << "1) Cargar datos preset\n"
         << "2) Encolar evento manual\n"
         << "3) Procesar siguiente (dequeue + push accion)\n"
         << "4) Deshacer ultima accion (pop + revertir)\n"
         << "5) Mostrar Cola (recursivo)\n"
         << "6) Mostrar Pila (recursivo)\n"
         << "7) Buscar en Cola/Pila (recursivo)\n"
         << "8) Vaciar estructuras (recursivo)\n"
         << "9) Estadisticas (size recursivo)\n"
         << "0) Salir\n"
         << "Opcion: ";
}

void loopMenu() {
    //Cola pasajeros{};
    Pila procesados{};

    int op;

    do {
        mostrarMenu();
        cin >> op;

        //Falta definir los parametros de las funciones

        switch(op) {
            case 1:
                //cargarPasajerosEnCola();
                break;
            case 2:
                //queue();
                break;
            case 3:
                //dequeue();
                //push();
                break;
            case 4:
                //pop();
                break;
            case 5:
                //printCola();
                break;
            case 6:
                printPilaRec(procesados);
                break;
            case 7:
                //buscarRec(); Busca dentro de los procesados
                break;
            case 8:
                //clear();
                //clear();
                break;
            case 9:
                //mostrarStatsCola(); Mostrar el size
                //mostrarStatsPila();
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (op != 0);
}