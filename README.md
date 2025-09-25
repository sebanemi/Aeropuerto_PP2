 TP Pilas y Colas  

Este proyecto implementa un sistema de gestión de **pasajeros** utilizando **estructuras dinámicas** en C++: **Cola** (queue) y **Pila** (stack).  
El objetivo es practicar el uso de listas enlazadas, recursividad y operaciones básicas de memoria dinámica.

---

Funcionalidades principales

El programa presenta un **menú interactivo** con las siguientes opciones:

1. **Cargar datos preset**  
   Lee un archivo (`data/pasajeros_preset.txt`) con pasajeros predefinidos (nombre, ID y número de vuelo) y los encola automáticamente.  

2. **Encolar evento manual**  
   Permite ingresar un pasajero manualmente:  
   - Nombre (se admite con espacios).  
   - ID (validación: no se permiten IDs duplicados).  
   - Número de vuelo.  
   Luego, lo agrega al final de la cola y registra la acción en la pila.  

3. **Procesar siguiente**  
   - Saca el primer pasajero de la cola (`dequeue`).  
   - Guarda la acción en la pila (para permitir deshacer).  

4. **Deshacer última acción**  
   - Si fue un **PROCESAR**, vuelve a encolarlo al frente.  
   - Si fue un **AGREGAR**, lo elimina de la cola.  

5. **Mostrar Cola (recursivo)**  
   Muestra todos los pasajeros en orden de llegada.  

6. **Mostrar Pila (recursivo)**  
   Muestra todas las acciones realizadas (AGREGAR/PROCESAR).  

7. **Buscar en Cola/Pila (recursivo)**  
   Permite buscar un pasajero por ID, tanto en la cola como en la pila.  

8. **Vaciar estructuras (recursivo)**  
   Libera todos los pasajeros y acciones de memoria.  

9. **Estadísticas (recursivo)**  
   Muestra el tamaño de la cola y la pila.  

0. **Salir**  
   Limpia memoria y termina el programa.  

---

Estructura del proyecto

```
TP-Pilas-Colas/
├── data/
│   └── pasajeros_preset.txt    # Datos iniciales de prueba
├── dominio.h / dominio.cpp     # Definición y creación/eliminación de Pasajero
├── cola.h / cola.cpp           # Implementación de la Cola (queue)
├── pila.h / pila.cpp           # Implementación de la Pila (stack)
├── utils.h / utils.cpp         # Funciones auxiliares (validaciones, carga desde archivo, búsqueda booleana)
├── menu.h / menu.cpp           # Lógica del menú principal
├── main.cpp                    # Punto de entrada al programa
└── README.md                   # Este archivo
```

---

 Uso

### 1. Compilar
En consola (Linux/Mac):
```bash
g++ main.cpp menu.cpp cola.cpp pila.cpp utils.cpp dominio.cpp -o tp_pilas_colas
```

En Windows (MinGW):
```bash
g++ main.cpp menu.cpp cola.cpp pila.cpp utils.cpp dominio.cpp -o tp_pilas_colas.exe
```

### 2. Ejecutar
```bash
./tp_pilas_colas
```

---

Ejemplo de ejecución

```
=== TP Pilas y Colas ===
1) Cargar datos preset
2) Encolar evento manual
3) Procesar siguiente (dequeue + push accion)
4) Deshacer ultima accion (pop + revertir)
5) Mostrar Cola (recursivo)
6) Mostrar Pila (recursivo)
7) Buscar en Cola/Pila (recursivo)
8) Vaciar estructuras (recursivo)
9) Estadisticas (size recursivo)
0) Salir
Opcion: 2

Ingresar nombre: Juan Perez
Ingresar id: 123
Ingresar numero de vuelo: AR0450
```

Salida:
```
Pasajero agregado con éxito.
```

---

Conceptos que se practican

- **Cola (FIFO)**: primero en entrar, primero en salir.  
- **Pila (LIFO)**: último en entrar, primero en salir.  
- **Recursividad**: impresión, búsqueda, tamaño, liberación de memoria.  
- **Memoria dinámica**: creación y destrucción de nodos con `new` y `delete`.  
- **Validaciones**: evitar IDs duplicados, entradas vacías, etc.  

---

 Autores / Créditos

Trabajo Práctico de *Paradigmas de la programación 2* – Facultad de Ingeniería del Ejército.  
Desarrollado por: * Sebastián Nemi y Matías Meneclier*
