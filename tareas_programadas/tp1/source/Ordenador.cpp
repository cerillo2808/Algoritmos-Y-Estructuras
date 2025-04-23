#include <iostream>
#include <chrono>
#include "Ordenador.hpp"

void Ordenador::ordenamientoPorSeleccion(uint32_t *A, uint32_t n) const{
    // va escogiendo el elemento más pequeño y poniéndolo en la posición i
    // recorre el arreglo A
    for (int i = 0; i < n - 1; i++) {
        // m es el índice del elemento mínimo
        int m = i;
        // busca el elemento mínimo en el resto del arreglo
        for (int j = i + 1; j < n; j++) {
            if (A[j] < A[m]) {
                m = j;
            }
        }
        // intercambia el elemento mínimo con el elemento i
        std::swap(A[i], A[m]);
    }
    std::cout << "Ordenamiento por seleccion: " << std::endl;
    imprimirArreglo(A, n);
    estaOrdenado(A, n, "Ordenamiento por seleccion");
}

void Ordenador::imprimirArreglo(uint32_t *A, uint32_t n) const{
    for (uint32_t i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

bool Ordenador::estaOrdenado(uint32_t *A, uint32_t n, const char* nombre) const{
    for (uint32_t i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            std::cout << nombre << " no ordenó." << std::endl;
            return false;
        }
    }
    std::cout << nombre << " ordenó bien." << std::endl;
    return true;
}