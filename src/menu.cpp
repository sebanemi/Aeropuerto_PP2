#include "dominio.h"
#include "menu.h"

#include <algorithm>

#include "pila.h"
#include "cola.h"
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
    Cola pasajeros{};
    Pila procesados{};

    int op;
    string nombre;
    string nroVuelo;
    int id;
    Pasajero* p;
    Accion* a;

    do {
        mostrarMenu();
        cin >> op;

        //Falta definir los parametros de las funciones

        switch(op) {
            case 1:
                cargarPasajerosEnCola("data/pasajeros_preset.txt",pasajeros);
                break;
            case 2:
                cout<<"Ingresar nombre: ";
                cin >>nombre;
                cout<<"Ingresar id: ";
                cin>>id;
                cout<<"Ingresar numero de vuelo: ";
                cin>>nroVuelo;

                p = crearNuevoPasajero(nombre, id, nroVuelo);

                colaQueue(pasajeros, p);
                pilaPush(procesados, AGREGAR, p);
                break;
            case 3:
                if (!colaIsEmpty(pasajeros)) {
                    pilaPush(procesados,PROCESAR, colaDequeue(pasajeros));
                }else {
                    cout<<"COLA / PILA VACIA"<<endl;
                }

                break;
            case 4:
                if (!pilaIsEmpty(procesados)) {

                    a = pilaPop(procesados);

                    if (a->tipo == PROCESAR) {
                        p = a->pasajero;
                        colaQueueFront(pasajeros, p);
                    }
                    if (a->tipo == AGREGAR) {
                        a->pasajero = colaDequeue(pasajeros);
                        eliminarPasajero(a->pasajero);
                    }
                    delete a;
                }else {
                    cout<<"COLA / PILA VACIA"<<endl;
                }

                break;
            case 5:
                colaPrintRec(pasajeros);
                break;
            case 6:
                pilaPrintRec(procesados);
                break;
            case 7:
                cout<<"Ingresar ID a buscar: ";
                cin>>id;
                p = pilaSearchRec(procesados,id);
                if (p) {
                    cout<<"  ID: "<<p->id<<endl;
                    cout<<"  Nombre: "<<p->nombre<<endl;
                    cout<<"  Nro vuelo: "<<p->nroVuelo<<endl;
                }else {
                    cout<<"No encontrado"<<endl;
                }
                break;
            case 8:
                colaClearRec(pasajeros);
                pilaClearRec(procesados);
                break;
            case 9:
                cout<<"Size cola: "<<colaSizeRec(pasajeros)<<endl;
                cout<<"Size Pila: "<<pilaSizeRec(procesados)<<endl;
                break;
            case 0:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (op != 0);
}