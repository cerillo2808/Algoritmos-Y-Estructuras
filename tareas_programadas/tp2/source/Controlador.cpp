// Copyright [2025] <Liqing Yosery Zheng Lu>

#include <iostream>
#include <random>
#include "BinarySearchTree.hpp"
#include "ChainedHashTable.hpp"
#include "DoublyLinkedList.hpp"
#include "RedBlackTree.hpp"
#include "SinglyLinkedList.hpp"
#include "Controlador.hpp"

void Controlador::run() {

    // Generar arreglos aleatorios
    iniciarArreglos();

    // TODO: Llamar a los algoritmos

    // Liberar la memoria
    delete[] mil;
    delete[] diezMil;
    delete[] cienMil;
    delete[] unMillon;
}

uint32_t* Controlador::copiarArreglo(uint32_t *A, uint32_t n) {
    uint32_t* B = new uint32_t[n];
    for (uint32_t i = 0; i < n; i++) {
        B[i] = A[i];
    }
    return B;
}

uint32_t* Controlador::generarArregloAleatorio(uint32_t n) {
    uint32_t* arreglo = new uint32_t[n];

    // Configurar el generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    // Los números van de 0 a UINT32_MAX
    // TODO: revisar si el rango de esta tarea es correcto
    std::uniform_int_distribution<uint32_t> distribucion(0, UINT32_MAX);

    // Llenar el arreglo con números aleatorios
    for (uint32_t i = 0; i < n; i++) {
        arreglo[i] = distribucion(gen);
    }

    return arreglo;
}

void Controlador::iniciarArreglos() {
    // TODO: revisar cuántos arreglos se ocupan y de qué tamaño
    mil = generarArregloAleatorio(1000);
    diezMil = generarArregloAleatorio(10000);
    cienMil = generarArregloAleatorio(100000);
    unMillon = generarArregloAleatorio(1000000);
}