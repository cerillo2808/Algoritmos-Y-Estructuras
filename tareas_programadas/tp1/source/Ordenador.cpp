#include <iostream>
#include <chrono>
#include "Ordenador.hpp"



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