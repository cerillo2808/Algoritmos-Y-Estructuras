// Copyright [2025] <Liqing Yosery Zheng Lu>

#include <iostream>
#include <random>
#include <vector>
#include <algorithm>
#include "BinarySearchTree.hpp"
#include "ChainedHashTable.hpp"
#include "RedBlackTree.hpp"
#include "SinglyLinkedList.hpp"
#include "Controlador.hpp"

void Controlador::run() {

    // Generar arreglos aleatorios
    millonRandomSinRepetir = generarArregloAleatorioSinRepetidos(1000000);
    millonRandomConRepetidos = generarArregloAleatorioRepetidos(1000000);
    diezMilEliminar = generarArregloAleatorioRepetidos(10000);
    diezMilBuscar = generarArregloAleatorioRepetidos(10000);

    operacionesListaSimplementeEnlazada();
    operacionesArbolBusquedaBinaria();
    operacionesArbolRojinegro();
    operacionesTablaHashEncadenada();

    // Liberar la memoria
    delete [] millonRandomSinRepetir;
    delete [] millonRandomConRepetidos;
    delete [] diezMilEliminar;
    delete [] diezMilBuscar;
}

uint32_t* Controlador::copiarArreglo(uint32_t *A, uint32_t n) {
    uint32_t* B = new uint32_t[n];
    for (uint32_t i = 0; i < n; i++) {
        B[i] = A[i];
    }
    return B;
}

uint32_t* Controlador::generarArregloAleatorioRepetidos(uint32_t n) {
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

uint32_t* Controlador::generarArregloAleatorioSinRepetidos(uint32_t n) {
    const uint32_t rango = 3000000; // 0 a 2999999
    std::vector<uint32_t> universo(rango);
    for (uint32_t i = 0; i < rango; ++i) {
        universo[i] = i;
    }

    // Barajar el universo
    std::random_device rd;
    std::mt19937 gen(rd());
    std::shuffle(universo.begin(), universo.end(), gen);

    // Tomar los primeros n elementos
    uint32_t* arreglo = new uint32_t[n];
    for (uint32_t i = 0; i < n; ++i) {
        arreglo[i] = universo[i];
    }
    return arreglo;
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
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
    
    std::cout << duracion << " milisegundos" << std::endl;
}

void Controlador::eliminarEnListaEnlazada(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n) {
    auto inicio = std::chrono::high_resolution_clock::now();
    for (uint32_t i = 0; i < n; i++) {
        lista.remove(arreglo[i]);
    }
    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
    
    std::cout << duracion << " milisegundos" << std::endl;
}

void Controlador::operacionesListaSimplementeEnlazada() {
    // Lista enlazada orden random
    SLList<uint32_t> listaRandom;

    // Insertar un millón de nodos random.
    std::cout << "\nInsertando en lista random" << std::endl;
    insertarEnListaEnlazada(listaRandom, millonRandomConRepetidos, 1000000);

    // Lista enlazada buscar diez mil elementos random. Tomar tiempo.
    std::cout << "Buscando en lista random: ";
    buscarEnListaEnlazada(listaRandom, diezMilBuscar, 10000);

    // Lista enlazada eliminar diez mil elementos random. Tomar tiempo.
    std::cout << "Eliminando en lista random: ";
    eliminarEnListaEnlazada(listaRandom, diezMilEliminar, 10000);

    // Lista enlazada insertar llaves 0, 1, ..., 999999 (un millón de nodos).
    std::cout << "\nInsertando en lista ordenada" << std::endl;
    SLList<uint32_t> listaOrdenada;
    for (uint32_t i = 0; i < 1000000; i++) {
        listaOrdenada.insert(i);
    }

    // Lista enlazada ordenada, buscar diez mil elementos random. Tomar tiempo
    std::cout << "Buscando en lista ordenada: ";
    buscarEnListaEnlazada(listaOrdenada, diezMilBuscar, 10000);

    // Lista enlazada ordenada, eliminar diez mil elementos random. Tomar tiempo.
    std::cout << "Eliminando en lista ordenada: ";
    eliminarEnListaEnlazada(listaOrdenada, diezMilEliminar, 10000);
}

void Controlador::insertarEnArbolBusquedaBinaria(BSTree<uint32_t>& arbol, uint32_t* arreglo, uint32_t n) {
    for (uint32_t i = 0; i < n; i++) {
        arbol.insert(arreglo[i]);
    }
}

void Controlador::buscarEnArbolBusquedaBinaria(BSTree<uint32_t>& arbol, uint32_t* arreglo, uint32_t n) {
    auto inicio = std::chrono::high_resolution_clock::now();
    for (uint32_t i = 0; i < n; i++) {
        arbol.search(arbol.getRoot(), arreglo[i]);
    }
    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
    
    std::cout << duracion << " microsegundos" << std::endl;
}

void Controlador::eliminarEnArbolBusquedaBinaria(BSTree<uint32_t>& arbol, uint32_t* arreglo, uint32_t n) {
    auto inicio = std::chrono::high_resolution_clock::now();
    for (uint32_t i = 0; i < n; i++) {
        arbol.remove(arreglo[i]);
    }
    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
    
    std::cout << duracion << " microsegundos" << std::endl;
}

void Controlador::operacionesArbolBusquedaBinaria() {
    // Árbol búsqueda binaria random
    BSTree<uint32_t> arbolBinarioRandom;

    // Árbol búsqueda binaria insertar un millón de nodos random.
    std::cout << "\nInsertando en arbol binario random" << std::endl;
    insertarEnArbolBusquedaBinaria(arbolBinarioRandom, millonRandomSinRepetir, 1000000);

    // Árbol búsqueda binaria buscar diez mil elementos random. Tomar tiempo.
    std::cout << "Buscando en arbol binario random: ";
    buscarEnArbolBusquedaBinaria(arbolBinarioRandom, diezMilBuscar, 10000);
    
    // Árbol búsqueda binaria eliminar diez mil elementos random. Tomar tiempo.
    std::cout << "Eliminando en arbol binario random: ";
    eliminarEnArbolBusquedaBinaria(arbolBinarioRandom, diezMilEliminar, 10000);

    // Árbol búsqueda binaria ordenada
    BSTree<uint32_t> arbolBinarioOrdenado;

    // Árbol búsqueda binaria insertar llaves 0, 1, ..., 999999 (un millón de nodos).
    std::cout << "\nInsertando en arbol binario ordenado" << std::endl;
    arbolBinarioOrdenado.fastInsert(1000000);

    // Árbol búsqueda binaria ordenado, buscar diez mil elementos random. Tomar tiempo.
    std::cout << "Buscando en arbol binario ordenado: ";
    buscarEnArbolBusquedaBinaria(arbolBinarioOrdenado, diezMilBuscar, 10000);

    // Árbol búsqueda binaria ordenado, eliminar diez mil elementos random. Tomar tiempo.
    std::cout << "Eliminando en arbol binario ordenado: ";
    eliminarEnArbolBusquedaBinaria(arbolBinarioOrdenado, diezMilEliminar, 10000);
}

void Controlador::insertarEnArbolRojinegro(RBTree<uint32_t>& arbol, uint32_t* arreglo, uint32_t n) {
    for (uint32_t i = 0; i < n; i++) {
        arbol.insert(arreglo[i]);
    }
}

void Controlador::buscarEnArbolRojinegro(RBTree<uint32_t>& arbol, uint32_t* arreglo, uint32_t n) {
    auto inicio = std::chrono::high_resolution_clock::now();
    for (uint32_t i = 0; i < n; i++) {
        arbol.search(arbol.getRoot(), arreglo[i]);
    }
    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
    
    std::cout << duracion << " microsegundos" << std::endl;
}

void Controlador::eliminarEnArbolRojinegro(RBTree<uint32_t>& arbol, uint32_t* arreglo, uint32_t n) {
    auto inicio = std::chrono::high_resolution_clock::now();
    for (uint32_t i = 0; i < n; i++) {
        arbol.remove(arreglo[i]);
    }
    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
    
    std::cout << duracion << " microsegundos" << std::endl;
}

void Controlador::operacionesArbolRojinegro() {
    // Árbol rojinegro random
    RBTree<uint32_t> arbolRojinegroRandom;

    // Árbol rojinegro insertar un millón de nodos random.
    std::cout << "\nInsertando en árbol rojinegro random" << std::endl;
    insertarEnArbolRojinegro(arbolRojinegroRandom, millonRandomSinRepetir, 1000000);

    // Árbol rojinegro buscar diez mil elementos random. Tomar tiempo.
    std::cout << "Buscando en árbol rojinegro random: ";
    buscarEnArbolRojinegro(arbolRojinegroRandom, diezMilBuscar, 10000);
    
    // Árbol rojinegro eliminar diez mil elementos random. Tomar tiempo.
    std::cout << "Eliminando en árbol rojinegro random: ";
    eliminarEnArbolRojinegro(arbolRojinegroRandom, diezMilEliminar, 10000);

    // Árbol rojinegro ordenado
    RBTree<uint32_t> arbolRojinegroOrdenado;

    // Árbol rojinegro insertar llaves 0, 1, ..., 999999 (un millón de nodos).
    std::cout << "\nInsertando en árbol rojinegro ordenado" << std::endl;
    for (u_int32_t i = 0; i < 1000000; i++) {
        arbolRojinegroOrdenado.insert(i);
    }

    // Árbol rojinegro ordenado, buscar diez mil elementos random. Tomar tiempo.
    std::cout << "Buscando en árbol rojinegro ordenado: ";
    buscarEnArbolRojinegro(arbolRojinegroOrdenado, diezMilBuscar, 10000);

    // Árbol rojinegro ordenado, eliminar diez mil elementos random. Tomar tiempo.
    std::cout << "Eliminando en árbol rojinegro ordenado: ";
    eliminarEnArbolRojinegro(arbolRojinegroOrdenado, diezMilEliminar, 10000);
}

void Controlador::insertarEnTablaHashEncadenada(ChainedHashTable<uint32_t>& tabla, uint32_t* arreglo, uint32_t n) {
    for (uint32_t i = 0; i < n; i++) {
        tabla.insert(arreglo[i]);
    }
}

void Controlador::buscarEnTablaHashEncadenada(ChainedHashTable<uint32_t>& tabla, uint32_t* arreglo, uint32_t n) {
    auto inicio = std::chrono::high_resolution_clock::now();
    for (uint32_t i = 0; i < n; i++) {
        tabla.search(arreglo[i]);
    }
    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
    
    std::cout << duracion << " microsegundos" << std::endl;
}

void Controlador::eliminarEnTablaHashEncadenada(ChainedHashTable<uint32_t>& tabla, uint32_t* arreglo, uint32_t n) {
    auto inicio = std::chrono::high_resolution_clock::now();
    for (uint32_t i = 0; i < n; i++) {
        tabla.remove(arreglo[i]);
    }
    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
    
    std::cout << duracion << " microsegundos" << std::endl;
}

void Controlador::operacionesTablaHashEncadenada() {
    // Hash table encadenada random
    ChainedHashTable<uint32_t> tablaHashRandom(1000000);

    // Hash table insertar un millón de nodos random.
    std::cout << "\nInsertando en tabla hash random" << std::endl;
    insertarEnTablaHashEncadenada(tablaHashRandom, millonRandomSinRepetir, 1000000);

    // Hash table buscar diez mil elementos random. Tomar tiempo.
    std::cout << "Buscando en tabla hash random: ";
    buscarEnTablaHashEncadenada(tablaHashRandom, diezMilBuscar, 10000);

    // Hash table eliminar diez mil elementos random. Tomar tiempo.
    std::cout << "Eliminando en tabla hash random: ";
    eliminarEnTablaHashEncadenada(tablaHashRandom, diezMilEliminar, 10000);

    // Hash table encadenada ordenada
    ChainedHashTable<uint32_t> tablaHashOrdenada(1000000);

    // Hash table insertar llaves 0, 1, ..., 999999 (un millón de nodos).
    std::cout << "\nInsertando en tabla hash ordenada" << std::endl;
    for (uint32_t i = 0; i < 1000000; i++) {
        tablaHashOrdenada.insert(i);
    }

    // Hash table ordenado, buscar diez mil elementos random. Tomar tiempo.
    std::cout << "Buscando en tabla hash ordenada: ";
    buscarEnTablaHashEncadenada(tablaHashOrdenada, diezMilBuscar, 10000);

    // Hash table ordenado, eliminar diez mil elementos random. Tomar tiempo.
    std::cout << "Eliminando en tabla hash ordenada: ";
    eliminarEnTablaHashEncadenada(tablaHashOrdenada, diezMilEliminar, 10000);
}