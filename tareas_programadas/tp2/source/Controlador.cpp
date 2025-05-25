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
    // TODO: Arreglo random de un millón de elementos. (Insertar)
    // TODO: Areglo random de diez mil elementos. (Eliminar)
    // TODO: Arreglo random de diez mil elementos. (Buscar)
    // TODO: Arreglo ordenado de un millón de elementos. (Insertar)

    // TODO: Lista enlazada insertar un millón de nodos random.
    // TODO: Lista enlazada buscar diez mil elementos random. Tomar tiempo.
    // TODO: Lista enlazada eliminar diez mil elementos random. Tomar tiempo.
    // TODO: Lista enlazada insertar llaves 0, 1, ..., 999999 (un millón de nodos).
    // TODO: Lista enlazada ordenada, buscar diez mil elementos random. Tomar tiempo
    // TODO: Lista enlazada ordenada, eliminar diez mil elementos random. Tomar tiempo.

    // TODO: Árbol búsqueda binaria insertar un millón de nodos random.
    // TODO: Árbol búsqueda binaria buscar diez mil elementos random. Tomar tiempo.
    // TODO: Árbol búsqueda binaria eliminar diez mil elementos random. Tomar tiempo.
    // TODO: Árbol búsqueda binaria insertar llaves 0, 1, ..., 999999 (un millón de nodos).
    // TODO: Árbol búsqueda binaria ordenado, buscar diez mil elementos random. Tomar tiempo.
    // TODO: Árbol búsqueda binaria ordenado, eliminar diez mil elementos random. Tomar tiempo.

    // TODO: Árbol rojinegro insertar un millón de nodos random.
    // TODO: Árbol rojinegro buscar diez mil elementos random. Tomar tiempo.
    // TODO: Árbol rojinegro eliminar diez mil elementos random. Tomar tiempo.
    // TODO: Árbol rojinegro insertar llaves 0, 1, ..., 999999 (un millón de nodos).
    // TODO: Árbol rojinegro ordenado, buscar diez mil elementos random. Tomar tiempo.
    // TODO: Árbol rojinegro ordenado, eliminar diez mil elementos random. Tomar tiempo.

    // TODO: Hash table insertar un millón de nodos random.
    // TODO: Hash table buscar diez mil elementos random. Tomar tiempo.
    // TODO: Hash table eliminar diez mil elementos random. Tomar tiempo.
    // TODO: Hash table insertar llaves 0, 1, ..., 999999 (un millón de nodos).
    // TODO: Hash table ordenado, buscar diez mil elementos random. Tomar tiempo.
    // TODO: Hash table ordenado, eliminar diez mil elementos random. Tomar tiempo.
    

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
    // Los números van de 0 a 3 millones, sin incluir el último
    std::uniform_int_distribution<uint32_t> distribucion(0, 2999999);

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