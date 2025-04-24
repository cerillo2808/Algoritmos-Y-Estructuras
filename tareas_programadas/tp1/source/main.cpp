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

    // Crear una copias de los arreglos
    uint32_t* copia_mil = copiarArreglo(mil, 1000);
    uint32_t* copia_diezMil = copiarArreglo(diezMil, 10000);
    uint32_t* copia_cienMil = copiarArreglo(cienMil, 100000);
    uint32_t* copia_unMillon = copiarArreglo(unMillon, 1000000);

    // Ordenar por selección
    ordenador.ordenamientoPorSeleccion(copia_mil, 1000);
    ordenador.ordenamientoPorSeleccion(copia_diezMil, 10000);
    ordenador.ordenamientoPorSeleccion(copia_cienMil, 100000);
    ordenador.ordenamientoPorSeleccion(copia_unMillon, 1000000);

    // Liberar la memoria
    delete[] mil;
    delete[] diezMil;
    delete[] cienMil;
    delete[] unMillon;
    delete[] copia_mil;
    delete[] copia_diezMil;
    delete[] copia_cienMil;
    delete[] copia_unMillon;     

    return 0;
}