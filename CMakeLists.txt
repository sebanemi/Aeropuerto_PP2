cmake_minimum_required(VERSION 4.0)
project(Aeropuerto_PP2)

set(CMAKE_CXX_STANDARD 20)

add_executable(Aeropuerto_PP2
        dominio.h
        pila.h
        pila.cpp
        dominio.cpp
        utils.h
        menu.h
        menu.cpp
        main.cpp
        cola.cpp
        cola.h
        utils.cpp
)
