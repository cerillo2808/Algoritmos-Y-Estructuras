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

    /*
    // Ordenar por montículos
    // Crear una copias de los arreglos
    uint32_t* copia_mil_heap = copiarArreglo(mil, 1000);
    uint32_t* copia_diezMil_heap = copiarArreglo(diezMil, 10000);
    uint32_t* copia_cienMil_heap = copiarArreglo(cienMil, 100000);
    uint32_t* copia_unMillon_heap = copiarArreglo(unMillon, 1000000);
    ordenador.ordenamientoPorMonticulos(copia_mil_heap, 1000);
    ordenador.ordenamientoPorMonticulos(copia_diezMil_heap, 10000);
    ordenador.ordenamientoPorMonticulos(copia_cienMil_heap, 100000);
    ordenador.ordenamientoPorMonticulos(copia_unMillon_heap, 1000000);
    */

    /*
    // Ordenar por rápido
    // Crear una copias de los arreglos
    uint32_t* copia_mil_quick = copiarArreglo(mil, 1000);
    uint32_t* copia_diezMil_quick = copiarArreglo(diezMil, 10000);
    uint32_t* copia_cienMil_quick = copiarArreglo(cienMil, 100000);
    uint32_t* copia_unMillon_quick = copiarArreglo(unMillon, 1000000);
    ordenador.ordenamientoRapido(copia_mil_quick, 1000);
    ordenador.ordenamientoRapido(copia_diezMil_quick, 10000);
    ordenador.ordenamientoRapido(copia_cienMil_quick, 100000);
    ordenador.ordenamientoRapido(copia_unMillon_quick, 1000000);
    */

    // Ordenar por residuos
    // Crear una copias de los arreglos
    uint32_t* copia_mil_residuos = copiarArreglo(mil, 1000);
    uint32_t* copia_diezMil_residuos = copiarArreglo(diezMil, 10000);
    uint32_t* copia_cienMil_residuos = copiarArreglo(cienMil, 100000);
    uint32_t* copia_unMillon_residuos = copiarArreglo(unMillon, 1000000);
    ordenador.ordenamientoPorResiduos(copia_mil_residuos, 1000);
    ordenador.ordenamientoPorResiduos(copia_diezMil_residuos, 10000);
    ordenador.ordenamientoPorResiduos(copia_cienMil_residuos, 100000);
    ordenador.ordenamientoPorResiduos(copia_unMillon_residuos, 1000000);
    
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
    /*     
    delete[] copia_mil_heap;
    delete[] copia_diezMil_heap;
    delete[] copia_cienMil_heap;
    delete[] copia_unMillon_heap;
    delete[] copia_mil_quick;
    delete[] copia_diezMil_quick;
    delete[] copia_cienMil_quick;
    delete[] copia_unMillon_quick;
    */
    delete[] copia_mil_residuos;
    delete[] copia_diezMil_residuos;
    delete[] copia_cienMil_residuos;
    delete[] copia_unMillon_residuos;

    return 0;
}