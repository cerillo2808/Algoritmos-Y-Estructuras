#pragma once
#include <cstdint>

/*
Credits
Author: Prof. Arturo Camacho, Universidad de Costa Rica
 
Modified by: Prof. Allan Berrocal, Universidad de Costa Rica
*/

class Ordenador {
    private:
    // Defina aqui los metodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos metodos quiera.
    /**
     * @brief Verifica si un arreglo está ordenado.
     * Este método verifica si un arreglo de enteros sin signo de 32 bits está ordenado en orden ascendente.
     * @return true si el arreglo está ordenado, false en caso contrario.
     */
    bool estaOrdenado(uint32_t *A, uint32_t n, const char* nombre) const;

    /**
     * @brief Intercambia dos elementos en un arreglo.
     * Este método intercambia dos elementos en un arreglo de enteros sin signo de 32 bits.
     * @param A El arreglo en el que se realizará el intercambio.
     * @param i El índice del primer elemento a intercambiar.
     * @param j El índice del segundo elemento a intercambiar.
     */
    void merge(uint32_t *A, uint32_t p, uint32_t q, uint32_t r) const;

    /**
     * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por mezcla.
     * Este método implementa el algoritmo de ordenamiento por mezcla (Merge Sort) para ordenar un arreglo de enteros sin signo de 32 bits.
     * @param A El arreglo a ordenar.
     * @param p El índice inicial del subarreglo a ordenar.
     * @param r El índice final del subarreglo a ordenar.
     */
    void mergeSort(uint32_t *A, uint32_t p, uint32_t r) const;

    /**
     * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por montículos.
     * Este método implementa el algoritmo de ordenamiento por montículos (Heap Sort) para ordenar un arreglo de enteros sin signo de 32 bits.
     * @param A El arreglo a ordenar.
     * @param n El tamaño del arreglo.
     */
    void maxHeapify(uint32_t *A, uint32_t n, uint32_t i) const;

    /**
     * @brief Construye un montículo máximo a partir de un arreglo.
     * Este método construye un montículo máximo a partir de un arreglo de enteros sin signo de 32 bits.
     * @param A El arreglo a convertir en montículo máximo.
     * @param n El tamaño del arreglo.
     */
    void buildMaxHeap(uint32_t *A, uint32_t n) const;

    /**
     * @brief Particiona un arreglo para el algoritmo de ordenamiento rápido.
     * Este método particiona un arreglo de enteros sin signo de 32 bits para el algoritmo de ordenamiento rápido (Quick Sort).
     * @param A El arreglo a particionar.
     * @param p El índice inicial del subarreglo a particionar.
     * @param r El índice final del subarreglo a particionar.
     * @return El índice del pivote después de la partición.
     */
    uint32_t partition(uint32_t *A, uint32_t p, uint32_t r) const;

    /**
     * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento rápido.
     * Este método implementa el algoritmo de ordenamiento rápido (Quick Sort) para ordenar un arreglo de enteros sin signo de 32 bits.
     * @param A El arreglo a ordenar.
     * @param p El índice inicial del subarreglo a ordenar.
     * @param r El índice final del subarreglo a ordenar.
     */
    void quickSort(uint32_t *A, uint32_t n, uint32_t r) const;

    /**
     * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por residuos.
     * Este método implementa el algoritmo de ordenamiento por residuos (Radix Sort) para ordenar un arreglo de enteros sin signo de 32 bits.
     * @param A El arreglo a ordenar.
     * @param n El tamaño del arreglo.
     */
    void countingSort(uint32_t *A, uint32_t n, uint32_t exp) const;

    public:
    Ordenador() = default;
    ~Ordenador() = default;
    /* Nota:
     - Si no planea implementar algunos de los métodos de ordenamiento, no los borre.
     - Simplemente déjelos con el cuerpo vacío para evitar errores de compilación, ya
       que se ejecutará el mismo main para todas las tareas.
     - Recuerde hacer uso de programación defensiva y documentar los métodos con formato Doxygen, por ejemplo.
     - No cambié la firma de los métodos de la clase Ordenador.
     - No lance excepciones para el manejo de errores.
       Ante un error, basta con que el método no modifique el arreglo original y que no cause la caída del programa.
    */ 

    /**
     * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por selección.
     * Este método implementa el algoritmo de ordenamiento por selección (Selection Sort) para ordenar un arreglo de enteros sin signo de 32 bits.
     * @param A El arreglo a ordenar.
     * @param n El tamaño del arreglo.
     */
    void ordenamientoPorSeleccion(uint32_t *A, uint32_t n) const;

    /**
     * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por inserción.
     * Este método implementa el algoritmo de ordenamiento por inserción (Insertion Sort) para ordenar un arreglo de enteros sin signo de 32 bits.
     * @param A El arreglo a ordenar.
     * @param n El tamaño del arreglo.
     */
    void ordenamientoPorInserccion(uint32_t *A, uint32_t n) const;

    /**
     * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por mezcla.
     * Este método llama al método recursivo mergeSort para ordenar un arreglo de enteros sin signo de 32 bits.
     * @param A El arreglo a ordenar.
     * @param n El tamaño del arreglo.
     */
    void ordenamientoPorMezcla(uint32_t *A, uint32_t n) const;

    /**
     * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por montículos.
     * Este método llama al método buildMaxHeap y luego aplica el algoritmo de ordenamiento por montículos (Heap Sort) para ordenar un arreglo de enteros sin signo de 32 bits.
     * Llama al método maxHeapify para mantener la propiedad del montículo.
     * @param A El arreglo a ordenar.
     * @param n El tamaño del arreglo.
     */
    void ordenamientoPorMonticulos(uint32_t *A, uint32_t n) const;

    /**
     * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento rápido.
     * Este método llama al método partition y luego aplica el algoritmo de ordenamiento rápido (Quick Sort) para ordenar un arreglo de enteros sin signo de 32 bits.
     * Llama al método quickSort para realizar la ordenación recursiva.
     * @param A El arreglo a ordenar.
     * @param n El tamaño del arreglo.
     */
    void ordenamientoRapido(uint32_t *A, uint32_t n) const;

    /**
     * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por residuos.
     * Este método llama al método countingSort y luego aplica el algoritmo de ordenamiento por residuos (Radix Sort) para ordenar un arreglo de enteros sin signo de 32 bits.
     * @param A El arreglo a ordenar.
     * @param n El tamaño del arreglo.
     */
    void ordenamientoPorResiduos(uint32_t *A, uint32_t n) const;

    /**
     * @brief Retorna un std::string con los datos de la tarea.
     * 
     * Este método devuelve una cadena de texto que contiene el carné, nombre y tarea.
     * 
     * @return std::string Una cadena de texto con los datos de la tarea.
     */
    constexpr const char* imprimirDatosDeTarea() const {
      return "Carné: C38680, Nombre: Liqing Yosery Zheng Lu, Tarea 1";
    }
};