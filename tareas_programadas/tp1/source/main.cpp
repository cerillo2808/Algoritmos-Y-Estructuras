#include <iostream>
#include "Ordenador.hpp"

uint32_t* copiarArreglo(uint32_t *A, uint32_t n) {
    uint32_t* B = new uint32_t[n];
    for (uint32_t i = 0; i < n; i++) {
        B[i] = A[i];
    }
    return B;
}

int main() {
    const Ordenador ordenador;

    // TODO: crear arreglos de mil, 10mil, 100mil y 1 millón de elementos
    uint32_t arr[] = {64, 34, 2, 12, 0, 11, 9};

    // Crear una copia del arreglo
    uint32_t* copia = copiarArreglo(arr, 7);

    // TODO: Llamar método de ordenamiento

    // Liberar la memoria de la copia
    delete[] copia;

    return 0;
}