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
    uint32_t* millonRandom;

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
     * Este método utiliza la biblioteca <random> para generar números aleatorios en el rango [0, 1000000).
     * @param n El tamaño del arreglo a generar.
     * @return Un puntero al arreglo generado.
     */
    uint32_t* generarArregloAleatorio(uint32_t n);

    /**
     * @brief Copia un arreglo de enteros sin signo de 32 bits.
     * Este método crea una copia de un arreglo dado y devuelve un puntero al nuevo arreglo.
     * @param A El arreglo a copiar.
     * @param n El tamaño del arreglo a copiar.
     * @return Un puntero al nuevo arreglo copiado.
     */
    uint32_t* copiarArreglo(uint32_t *A, uint32_t n);

    /**
     * @brief Inicializa los arreglos de enteros sin signo de 32 bits.
     * Este método genera arreglos aleatorios de diferentes tamaños (1000, 10000, 100000 y 1000000).
     * Usa el método generarArregloAleatorio para crear los arreglos y los almacena en los punteros correspondientes.
     */
    void iniciarArreglos();

    void insertarEnListaEnlazadaRandom(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n);
    void buscarEnListaEnlazadaRandom(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n);
    void eliminarEnListaEnlazadaRandom(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n);

    void insertarEnListaEnlazadaOrdenada(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n);
    void buscarEnListaEnlazadaOrdenada(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n);
    void eliminarEnListaEnlazadaOrdenada(SLList<uint32_t>& lista, uint32_t* arreglo, uint32_t n);
};