// Copyright [2025] <Liqing Yosery Zheng Lu>

#pragma once
#include <cstdint>
#include <chrono>
#include "BinarySearchTree.hpp"
#include "ChainedHashTable.hpp"
#include "DoublyLinkedList.hpp"
#include "RedBlackTree.hpp"
#include "SinglyLinkedList.hpp"

class Controlador {
    private:
    /**
     * @brief Arreglos de enteros sin signo de 32 bits.
     * El diezMilEliminar es para almacenar los números que se eliminan.
     * El diezMilBuscar es para almacenar los números que se buscan.
     * El millonRandom es para llenar los árboles y la tabla hash con números aleatorios.
     */
    uint32_t* diezMilEliminar;
    uint32_t* diezMilBuscar;
    uint32_t* millonRandomSinRepetir;
    uint32_t* millonRandomConRepetidos;

    public:
    Controlador() = default;
    ~Controlador() = default;

    /**
     * @brief Ejecuta el controlador.
     * Este método inicia el proceso de generación de arreglos aleatorios y ordenamiento.
     * Llama a generarArregloAleatorio para crear los arreglos y luego llama a los métodos de ordenamiento.
     * Finalmente, libera la memoria de los arreglos generados.
     */
    void run();

    /**
     * @brief Genera un arreglo de enteros sin signo de 32 bits con números aleatorios.
     * Este método utiliza la biblioteca <random> para generar números aleatorios en el rango [0, 3000000).
     * El arerglo generado puede tener valores repetidos.
     * @param n El tamaño del arreglo a generar.
     * @return Un puntero al arreglo generado.
     */
    uint32_t* generarArregloAleatorioRepetidos(uint32_t n);

    /**
     * @brief Genera un arreglo de enteros sin signo de 32 bits con números aleatorios.
     * Este método genera un arreglo de enteros que van desde 0 hasta 2999999 sin repetidos.
     * Este método utiliza la biblioteca <random> para barajar todos los elementos posibles.
     * Toma los primeros n elementos del universo barajado.
     * El arreglo generado no contiene valores repetidos.
     */
    uint32_t* generarArregloAleatorioSinRepetidos(uint32_t n);

    /**
     * @brief Copia un arreglo de enteros sin signo de 32 bits.
     * Este método crea una copia de un arreglo dado y devuelve un puntero al nuevo arreglo.
     * @param A El arreglo a copiar.
     * @param n El tamaño del arreglo a copiar.
     * @return Un puntero al nuevo arreglo copiado.
     */
    uint32_t* copiarArreglo(uint32_t *A, uint32_t n);

    /**
     * @brief Inserta elementos en una lista enlazada simple.
     * @param lista La lista enlazada simple donde se insertan los elementos.
     * @param arreglo El arreglo de los elementos a insertar.
     * @param n El número de elementos a insertar, o el tamaño del arreglo.
     */
    void insertarEnListaEnlazada(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n);

    /**
     * @brief Busca elementos en una lista enlazada simple.
     * @param lista La lista enlazada simple donde se buscan los elementos.
     * @param arreglo El arreglo de los elementos a buscar.
     * @param n El número de elementos a buscar, o el tamaño del arreglo.
     */
    void buscarEnListaEnlazada(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n);

    /**
     * @brief Elimina elementos de una lista enlazada simple.
     * @param lista La lista enlazada simple de donde se eliminan los elementos.
     * @param arreglo El arreglo de los elementos a eliminar.
     * @param n El número de elementos a eliminar, o el tamaño del arreglo.
     */
    void eliminarEnListaEnlazada(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n);

    /**
     * @brief Realiza operaciones en una lista simplemente enlazada.
     * Este método ejecuta una serie de operaciones de inserción, búsqueda y eliminación
     * en listas simplemente enlazadas, tanto con números aleatorios como con números ordenados.
     */
    void operacionesListaSimplementeEnlazada();

    /**
     * @brief Inserta elementos en un árbol de búsqueda binaria.
     * @param arbol El árbol de búsqueda binaria donde se insertan los elementos.
     * @param arreglo El arreglo de los elementos a insertar.
     * @param n El número de elementos a insertar, o el tamaño del arreglo.
     */
    void insertarEnArbolBusquedaBinaria(BSTree<uint32_t>& arbol, uint32_t* arreglo, uint32_t n);

    /**
     * @brief Busca elementos en un árbol de búsqueda binaria.
     * @param arbol El árbol de búsqueda binaria donde se buscan los elementos.
     * @param arreglo El arreglo de los elementos a buscar.
     * @param n El número de elementos a buscar, o el tamaño del arreglo.
     */
    void buscarEnArbolBusquedaBinaria(BSTree<uint32_t>& arbol, uint32_t* arreglo, uint32_t n);

    /**
     * @brief Elimina elementos en un árbol de búsqueda binaria.
     * @param arbol El árbol de búsqueda binaria donde se buscan los elementos.
     * @param arreglo El arreglo de los elementos a buscar.
     * @param n El número de elementos a buscar, o el tamaño del arreglo.
     */
    void eliminarEnArbolBusquedaBinaria(BSTree<uint32_t>& arbol, uint32_t* arreglo, uint32_t n);

    /**
     * @brief Realiza operaciones en un árbol de búsqueda binaria.
     * Este método ejecuta una serie de operaciones de inserción, búsqueda y eliminación
     * en árboles de búsqueda binaria, tanto con números aleatorios como con números ordenados.
     */
    void operacionesArbolBusquedaBinaria();
};