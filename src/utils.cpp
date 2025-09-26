#include <fstream>
#include <sstream>
#include <cctype>
#include "utils.h"

#include <chrono>

#include "cola.h"
#include "dominio.h"
using namespace std;

/*
 * Lee el archivo preset (ej: pasajeros_preset.txt), crea un Pasajero con crearPasajero()
 * y lo encola con colaPush().
 * Recibe punteros a first y last para mantener referencia de la cola.
 */


// Lee filename (lineas: nombre,id,nroVuelo), crea Pasajero y lo encola al final usando colaPush.
// Actualiza first/last según corresponda; devuelve true si pudo abrir y procesar.
bool cargarPasajerosEnCola(string filename, Cola& cola) {
    ifstream myReadFile(filename);
    if (!myReadFile.is_open()) {
        cerr << "No pude abrir: " << filename << endl;
        return false;
    }
    if (!myReadFile.is_open()) return false;

    string linea;
    while (getline(myReadFile, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string nombre, idStr, nroVuelo;
        if (!getline(ss, nombre, ',')) continue;
        if (!getline(ss, idStr, ',')) continue;
        if (!getline(ss, nroVuelo, ',')) continue;

        int id = stoi(idStr);
        Pasajero* nuevo = crearNuevoPasajero(nombre, id, nroVuelo);
        colaQueue(cola, nuevo);
    }

    myReadFile.close();
    return true;
}

// Recorre la cola, si encuentra la id ingresada devuelve true sino devuelve false.
bool colaSearchBoolean(Pasajero* cabeza, int id) {
    if (cabeza == nullptr) {
        return false; // no lo encontró, cola vacía o llegamos al final
    }

    if (cabeza->id == id) {
        return true; // encontrado
    }

    // caso recursivo: buscar en el resto de la lista
    return colaSearchBoolean(cabeza->sig, id);
}

