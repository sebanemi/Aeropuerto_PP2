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
    Pila acciones{};

    int op;
    string nombre;
    string nroVuelo;
    int id;
    char caracter_busqueda;
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
                //HACER PARA QUE SE PUEDA HACER CON ESPACIOS (MATI)
                cin >>nombre;
                cout<<"Ingresar id: ";
                //VALIDAR QUE EL ID NO SE ENCUENTRE YA EN LA COLA (MATI)
                cin>>id;
                cout<<"Ingresar numero de vuelo: ";
                cin>>nroVuelo;

                p = crearNuevoPasajero(nombre, id, nroVuelo);

                colaQueue(pasajeros, p);
                pilaPush(acciones, AGREGAR, p);
                break;
            case 3:
                if (!colaIsEmpty(pasajeros)) {
                    pilaPush(acciones,PROCESAR, colaDequeue(pasajeros));
                }else {
                    cout<<"\n COLA VACIA"<<endl;
                }

                break;
            case 4:
                if (!pilaIsEmpty(acciones)) {

                    a = pilaPop(acciones);

                    if (a->tipo == PROCESAR) {
                        p = a->pasajero;
                        colaQueueFront(pasajeros, p);
                    }
                    if (a->tipo == AGREGAR) {
                        a->pasajero = colaDequeueBack(pasajeros);
                        eliminarPasajero(a->pasajero);
                    }
                    delete a;
                }else {
                    cout<<"\n SIN ACCIONES A DESHACER"<<endl;
                }

                break;
            case 5:
                if (!colaIsEmpty(pasajeros)) {
                    colaPrintRec(pasajeros);
                }else {
                    cout<<"\n COLA VACIA"<<endl;
                }
                break;
            case 6:
                if (!pilaIsEmpty(acciones)) {
                    pilaPrintRec(acciones);
                }else {
                    cout<<"\n PILA VACIA"<<endl;
                }
                break;
            case 7:
                cout<<"BUSCAR EN PILA (P) / BUSCAR EN COLA (C):";
                cin>>caracter_busqueda;
                //VALIDAR EL CARACTER PARA QUE SEA P o C (MATI)
                if (caracter_busqueda=='P' || caracter_busqueda=='p') {
                    cout<<"Ingresar ID a buscar: ";
                    cin>>id;
                    p = pilaSearchRec(acciones,id);
                    if (p) {
                        cout<<"  ID: "<<p->id<<endl;
                        cout<<"  Nombre: "<<p->nombre<<endl;
                        cout<<"  Nro vuelo: "<<p->nroVuelo<<endl;
                    }else {
                        cout<<"\n No encontrado en PILA"<<endl;
                    }
                }else {
                    cout<<"Ingresar ID a buscar: ";
                    cin>>id;
                    p = colaSearchRec(pasajeros,id);
                    if (p) {
                        cout<<"  ID: "<<p->id<<endl;
                        cout<<"  Nombre: "<<p->nombre<<endl;
                        cout<<"  Nro vuelo: "<<p->nroVuelo<<endl;
                    }else {
                        cout<<"\n No encontrado en COLA"<<endl;
                    }
                }
                break;
            case 8:
                colaClearRec(pasajeros);
                pilaClearRec(acciones);
                break;
            case 9:
                if (!colaIsEmpty(pasajeros)) {
                    cout<<"\n Size cola: "<<colaSizeRec(pasajeros)<<endl;
                }else {
                    cout<<"\n COLA VACIA"<<endl;
                }
                if (!pilaIsEmpty(acciones)) {
                    cout<<"\n Size Pila: "<<pilaSizeRec(acciones)<<endl;
                }else {
                    cout<<"\n PILA VACIA"<<endl;
                }
                break;
            case 0:
                cout << "Saliendo...\n";
                colaClearRec(pasajeros);
                pilaClearRec(acciones);
                break;
            default:
                cout << "Opcion invalida\n";
        }
    } while (op != 0);
}