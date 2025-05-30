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
    millonRandom = generarArregloAleatorio(1000000);
    diezMilEliminar = generarArregloAleatorio(10000);
    diezMilBuscar = generarArregloAleatorio(10000);

    // Lista enlazada orden random
    SLList<uint32_t> listaRandom;

    // Insertar un millón de nodos random.
    std::cout << "Insertando en lista random" << std::endl;
    insertarEnListaEnlazada(listaRandom, millonRandom, 1000000);

    // Lista enlazada buscar diez mil elementos random. Tomar tiempo.
    std::cout << "Buscando en lista random" << std::endl;
    buscarEnListaEnlazada(listaRandom, diezMilBuscar, 10000);

    // Lista enlazada eliminar diez mil elementos random. Tomar tiempo.
    std::cout << "Eliminando en lista random" << std::endl;
    eliminarEnListaEnlazada(listaRandom, diezMilEliminar, 10000);

    // Lista enlazada insertar llaves 0, 1, ..., 999999 (un millón de nodos).
    std::cout << "Insertando en lista ordenada" << std::endl;
    SLList<uint32_t> listaOrdenada;
    for (uint32_t i = 0; i < 1000000; i++) {
        listaOrdenada.insert(i);
    }

    // Lista enlazada ordenada, buscar diez mil elementos random. Tomar tiempo
    std::cout << "Buscando en lista ordenada" << std::endl;
    buscarEnListaEnlazada(listaOrdenada, diezMilBuscar, 10000);

    // Lista enlazada ordenada, eliminar diez mil elementos random. Tomar tiempo.
    std::cout << "Eliminando en lista ordenada" << std::endl;
    eliminarEnListaEnlazada(listaOrdenada, diezMilEliminar, 10000);

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
    delete [] millonRandom;
    delete [] diezMilEliminar;
    delete [] diezMilBuscar;
    std::cout << "Fin del programa." << std::endl;
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
    millonRandom = generarArregloAleatorio(1000000);
    diezMilEliminar = generarArregloAleatorio(10000);
    diezMilBuscar = generarArregloAleatorio(10000);
}

void Controlador::insertarEnListaEnlazada(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n) {
    for (uint32_t i = 0; i < n; i++) {
        lista.insert(arreglo[i]);
    }

}

void Controlador::buscarEnListaEnlazada(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n) {
    auto inicio = std::chrono::high_resolution_clock::now();
    for (uint32_t i = 0; i < n; i++) {
        lista.search(arreglo[i]);
    }
    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
    
    std::cout << "Duración buscar en lista enlazada: " << duracion << " microsegundos" << std::endl;
}

void Controlador::eliminarEnListaEnlazada(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n) {
    auto inicio = std::chrono::high_resolution_clock::now();
    for (uint32_t i = 0; i < n; i++) {
        lista.remove(arreglo[i]);
    }
    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
    
    std::cout << "Duración eliminar en lista enlazada: " << duracion << " microsegundos" << std::endl;
}
