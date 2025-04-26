#pragma once
#include "Ordenador.hpp"

class Controlador {
    private:
    uint32_t* mil;
    uint32_t* diezMil;
    uint32_t* cienMil;
    uint32_t* unMillon;

    public:
    Controlador() = default;
    ~Controlador() = default;
    void run();
    uint32_t* generarArregloAleatorio(uint32_t n);
    uint32_t* copiarArreglo(uint32_t *A, uint32_t n);
    void iniciarArreglos();
    void selectionSort(Ordenador ordenador);
    void insertionSort(Ordenador ordenador);
    void mergeSort(Ordenador ordenador);
    void heapSort(Ordenador ordenador);
    void quickSort(Ordenador ordenador);
    void radix(Ordenador ordenador);
};