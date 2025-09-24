#include <fstream>
#include <sstream>
#include <cctype>
#include "utils.h"
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
bool cargarPasajerosEnCola(string filename, Pasajero*& first, Pasajero*& last) {
    ifstream file(filename);
    if (!file.is_open()) return false;

    string linea;
    while (getline(file, linea)) {
        if (linea.empty()) continue;

        stringstream ss(linea);
        string nombre, idStr, nroVuelo;
        if (!getline(ss, nombre, ',')) continue;
        if (!getline(ss, idStr, ',')) continue;
        if (!getline(ss, nroVuelo, ',')) continue;

        int id = stoi(idStr);
        Pasajero* nuevo = crearNuevoPasajero(nombre, id, nroVuelo);
        colaPush(first, nuevo);
        last = nuevo;
    }

    file.close();
    return true;
}

// Devuelve true si el id es válido (positivo); false en caso contrario.
bool validarId(int id) {
    return id > 0;
}

// Devuelve true si el nroVuelo no está vacío y contiene al menos un dígito.
bool validarNroVuelo(string nroVuelo) {
    if (nroVuelo.empty()) return false;
    for (char c : nroVuelo) if (isdigit(static_cast<unsigned char>(c))) return true;
    return false;
}
