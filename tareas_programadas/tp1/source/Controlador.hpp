// Copyright [2025] <Liqing Yosery Zheng Lu>

#pragma once
#include "Ordenador.hpp"

class Controlador {
    private:
    /**
     * @brief Arreglos de enteros sin signo de 32 bits.
     * Estos arreglos se utilizan para almacenar los números aleatorios generados.
     */
    uint32_t* mil;
    uint32_t* diezMil;
    uint32_t* cienMil;
    uint32_t* unMillon;

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

    /**
     * @brief Ordena los arreglos de diferentes tamaños utilizando el método de ordenamiento por selección.
     * Este método crea copias de los arreglos generados y los ordena utilizando el método de ordenamiento por selección.
     * Al ginalizar, libera la memoria de las copias.
     * @param ordenador El objeto Ordenador que contiene los métodos de ordenamiento.
     */
    void selectionSort(Ordenador ordenador);

    /**
     * @brief Ordena los arreglos de diferentes tamaños utilizando el método de ordenamiento por inserción.
     * Este método crea copias de los arreglos generados y los ordena utilizando el método de ordenamiento por inserción.
     * Al finalizar, libera la memoria de las copias.
     * @param ordenador El objeto Ordenador que contiene los métodos de ordenamiento.
     */
    void insertionSort(Ordenador ordenador);

    /**
     * @brief Ordena los arreglos de diferentes tamaños utilizando el método de ordenamiento por mezcla.
     * Este método crea copias de los arreglos generados y los ordena utilizando el método de ordenamiento por mezcla.
     * Al finalizar, libera la memoria de las copias.
     * @param ordenador El objeto Ordenador que contiene los métodos de ordenamiento.
     */
    void mergeSort(Ordenador ordenador);

    /**
     * @brief Ordena los arreglos de diferentes tamaños utilizando el método de ordenamiento por montículos.
     * Este método crea copias de los arreglos generados y los ordena utilizando el método de ordenamiento por montículos.
     * Al finalizar, libera la memoria de las copias.
     * @param ordenador El objeto Ordenador que contiene los métodos de ordenamiento.
     */
    void heapSort(Ordenador ordenador);

    /**
     * @brief Ordena los arreglos de diferentes tamaños utilizando el método de ordenamiento rápido.
     * Este método crea copias de los arreglos generados y los ordena utilizando el método de ordenamiento rápido.
     * Al finalizar, libera la memoria de las copias.
     * @param ordenador El objeto Ordenador que contiene los métodos de ordenamiento.
     */
    void quickSort(Ordenador ordenador);

    /**
     * @brief Ordena los arreglos de diferentes tamaños utilizando el método de ordenamiento por residuos.
     * Este método crea copias de los arreglos generados y los ordena utilizando el método de ordenamiento por residuos.
     * Al finalizar, libera la memoria de las copias.
     * @param ordenador El objeto Ordenador que contiene los métodos de ordenamiento.
     */
    void radix(Ordenador ordenador);
};