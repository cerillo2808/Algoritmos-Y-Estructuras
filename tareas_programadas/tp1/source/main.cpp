#include <iostream>
#include <random>
#include <cstdint>
#include "Ordenador.hpp"

uint32_t* copiarArreglo(uint32_t *A, uint32_t n) {
    uint32_t* B = new uint32_t[n];
    for (uint32_t i = 0; i < n; i++) {
        B[i] = A[i];
    }
    return B;
}

uint32_t* generarArregloAleatorio(uint32_t n) {
    uint32_t* arreglo = new uint32_t[n];

    // Configurar el generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    // Los números van de 0 a UINT32_MAX
    std::uniform_int_distribution<uint32_t> distribucion(0, UINT32_MAX);

    // Llenar el arreglo con números aleatorios
    for (uint32_t i = 0; i < n; i++) {
        arreglo[i] = distribucion(gen);
    }

    return arreglo;
}

int main() {
    const Ordenador ordenador;

    // Generar arreglos aleatorios
    uint32_t* mil = generarArregloAleatorio(1000);
    uint32_t* diezMil = generarArregloAleatorio(10000);
    uint32_t* cienMil = generarArregloAleatorio(100000);
    uint32_t* unMillon = generarArregloAleatorio(1000000);

    /*
    // Ordenar por selección
    // Crear una copias de los arreglos
    uint32_t* copia_mil_selection = copiarArreglo(mil, 1000);
    uint32_t* copia_diezMil_selection = copiarArreglo(diezMil, 10000);
    uint32_t* copia_cienMil_selection = copiarArreglo(cienMil, 100000);
    uint32_t* copia_unMillon_selection = copiarArreglo(unMillon, 1000000);
    ordenador.ordenamientoPorSeleccion(copia_mil_selection, 1000);
    ordenador.ordenamientoPorSeleccion(copia_diezMil_selection, 10000);
    ordenador.ordenamientoPorSeleccion(copia_cienMil_selection, 100000);
    ordenador.ordenamientoPorSeleccion(copia_unMillon_selection, 1000000);
    */

    /*
    // Ordenar por inserción
    // Crear una copias de los arreglos
    uint32_t* copia_mil_insertion = copiarArreglo(mil, 1000);
    uint32_t* copia_diezMil_insertion = copiarArreglo(diezMil, 10000);
    uint32_t* copia_cienMil_insertion = copiarArreglo(cienMil, 100000);
    uint32_t* copia_unMillon_insertion = copiarArreglo(unMillon, 1000000);
    ordenador.ordenamientoPorInserccion(copia_mil_insertion, 1000);
    ordenador.ordenamientoPorInserccion(copia_diezMil_insertion, 10000);
    ordenador.ordenamientoPorInserccion(copia_cienMil_insertion, 100000);
    ordenador.ordenamientoPorInserccion(copia_unMillon_insertion, 1000000);
    */

    // Ordenar por mezcla
    // Crear una copias de los arreglos
    uint32_t* copia_mil_merge = copiarArreglo(mil, 1000);
    uint32_t* copia_diezMil_merge = copiarArreglo(diezMil, 10000);
    uint32_t* copia_cienMil_merge = copiarArreglo(cienMil, 100000);
    uint32_t* copia_unMillon_merge = copiarArreglo(unMillon, 1000000);
    ordenador.ordenamientoPorMezcla(copia_mil_merge, 1000);
    ordenador.ordenamientoPorMezcla(copia_diezMil_merge, 10000);
    ordenador.ordenamientoPorMezcla(copia_cienMil_merge, 100000);
    ordenador.ordenamientoPorMezcla(copia_unMillon_merge, 1000000);

    // Liberar la memoria
    delete[] mil;
    delete[] diezMil;
    delete[] cienMil;
    delete[] unMillon;
    /*
    delete[] copia_mil_selection
    delete[] copia_diezMil_selection
    delete[] copia_cienMil_selection
    delete[] copia_unMillon_selection
    delete[] copia_mil_insertion;
    delete[] copia_diezMil_insertion;
    delete[] copia_cienMil_insertion;
    delete[] copia_unMillon_insertion;
    */
   delete[] copia_mil_merge;
   delete[] copia_diezMil_merge;
   delete[] copia_cienMil_merge;
   delete[] copia_unMillon_merge;     

    return 0;
}