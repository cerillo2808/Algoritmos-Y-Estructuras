#include <iostream>
#include <chrono>
#include "Ordenador.hpp"

void Ordenador::ordenamientoPorSeleccion(uint32_t *A, uint32_t n) const{
    // Va escogiendo el elemento más pequeño y poniéndolo en la posición i

    // Empieza a contar la duración
    auto inicio = std::chrono::high_resolution_clock::now();

    // Recorre el arreglo A
    for (uint32_t i = 0; i < n - 1; i++) {
        // m es el índice del elemento mínimo
        int m = i;
        // Busca el elemento mínimo en el resto del arreglo
        for (u_int32_t j = i + 1; j < n; j++) {
            if (A[j] < A[m]) {
                m = j;
            }
        }
        // Intercambia el elemento mínimo con el elemento i
        std::swap(A[i], A[m]);
    }

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

    std::cout << "Ordenamiento por seleccion. Tamaño: " << n << std::endl;
    
    estaOrdenado(A, n, "Ordenamiento por seleccion");
    // Imprimir el tiempo de ejecución
    std::cout << duracion << " milisegundos" << std::endl;
}

void Ordenador::ordenamientoPorInserccion(uint32_t *A, uint32_t n) const{
    //TODO
}
void Ordenador::ordenamientoPorMezcla(uint32_t *A, uint32_t n) const{
    //TODO
}
void Ordenador::ordenamientoPorMonticulos(uint32_t *A, uint32_t n) const{
    //TODO
}
void Ordenador::ordenamientoRapido(uint32_t *A, uint32_t n) const{
    //TODO
}
void Ordenador::ordenamientoPorResiduos(uint32_t *A, uint32_t n) const{
    //TODO
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
            std::cout << "No ordenó en " << std::endl;
            return false;
        }
    }
    std::cout << "Ordenó bien en " << std::endl;
    return true;
}