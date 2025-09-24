cmake_minimum_required(VERSION 4.0)
project(Aeropuerto_PP2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Aeropuerto_PP2
        src/dominio.h
        src/pila.h
        src/pila.cpp
        src/dominio.cpp
        src/utils.h
        src/menu.h
        src/menu.cpp
        src/main.cpp
        src/cola.cpp
        src/cola.h
        src/utils.cpp
)
