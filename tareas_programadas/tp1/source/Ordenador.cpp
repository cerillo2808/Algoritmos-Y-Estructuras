// Copyright [2025] <Liqing Yosery Zheng Lu>

#include <iostream>
#include <chrono>
#include <stack>
#include <cstdint>
#include "Ordenador.hpp"

/**
 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por selección.
 * Escoge el elemento más pequeño y lo coloca en la posición i.
 * @param A El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void Ordenador::ordenamientoPorSeleccion(uint32_t *A, uint32_t n) const {
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
        // swap(A[i], A[m]);
        uint32_t *temp = new uint32_t(A[i]);
        A[i] = A[m];
        A[m] = *temp;
        delete temp;
    }

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

    std::cout << "Ordenamiento por seleccion. Tamaño: " << n << std::endl;

    estaOrdenado(A, n, "Ordenamiento por seleccion");
    // Imprimir el tiempo de ejecución
    std::cout << duracion << " microsegundos" << std::endl;
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por inserción.
 * Inserta los elementos en su posición correcta.
 * @param A El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void Ordenador::ordenamientoPorInserccion(uint32_t *A, uint32_t n) const {
    // Empieza a contar la duración
    auto inicio = std::chrono::high_resolution_clock::now();

    // Recorre el arreglo A
    // i es 1 porque el elemento A[0] como es uno sólo, ya está ordenado
    for (uint32_t i = 1; i < n; i++) {
        // key es el elemento a insertar
        uint32_t *key = new uint32_t(A[i]);
        int j = i - 1;

        // Mueve los elementos mayores que key una posición adelante
        while (j >= 0 && A[j] > *key) {
            A[j + 1] = A[j];
            j--;
        }

        // Inserta key en su posición correcta
        A[j + 1] = *key;
        delete key;
    }

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración enmicrosegundos
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

    std::cout << "Ordenamiento por inserción. Tamaño: " << n << std::endl;

    estaOrdenado(A, n, "Ordenamiento por inserción");
    std::cout << duracion << " microsegundos" << std::endl;
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por mezcla.
 * Divide el arreglo en dos mitades, ordena cada mitad y luego mezcla las dos mitades.
 * @param A El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void Ordenador::ordenamientoPorMezcla(uint32_t *A, uint32_t n) const {
    // Iniciar el cronómetro
    auto inicio = std::chrono::high_resolution_clock::now();

    // Método que separa las dos mitades y llama a otro método para mezclar
    mergeSort(A, 0, n - 1);

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();

    // Calcular la duración enmicrosegundos
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();
    // Imprimir el tiempo de ejecución
    std::cout << "Ordenamiento por mezcla. Tamaño: " << n << std::endl;

    estaOrdenado(A, n, "Ordenamiento por mezcla");
    std::cout << duracion << " microsegundos" << std::endl;
}

/**
 * @brief Mezcla dos subarreglos de un arreglo dado.
 * Sabe que los subarreglos están ordenados, por lo que los mezcla en orden.
 * @details Este método es parte del algoritmo de ordenamiento por mezcla (Merge Sort).
 * @param A El arreglo a mezclar.
 * @param p El índice inicial del primer subarreglo.
 * @param q El índice final del primer subarreglo y el índice inicial del segundo subarreglo.
 * @param r El índice final del segundo subarreglo.
 */
void Ordenador::merge(uint32_t *A, uint32_t p, uint32_t q, uint32_t r) const {
    // Tamaño de la sublista izquierda
    uint32_t nL = q - p + 1;
    // Tamaño de la sublista derecha
    uint32_t nR = r - q;

    // Crear subarreglos temporales
    uint32_t *L = new uint32_t[nL];
    uint32_t *R = new uint32_t[nR];

    // Copiar datos a los subarreglos
    for (uint32_t i = 0; i < nL; i++) {
        L[i] = A[p + i];
    }
    for (uint32_t j = 0; j < nR; j++) {
        R[j] = A[q + 1 + j];
    }

    // Mezclar los subarreglos en A[p..r]
    uint32_t i = 0, j = 0, k = p;
    while (i < nL && j < nR) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar los elementos restantes de L[], si los hay
    while (i < nL) {
        A[k] = L[i];
        i++;
        k++;
    }

    // Copiar los elementos restantes de R[], si los hay
    while (j < nR) {
        A[k] = R[j];
        j++;
        k++;
    }

    // Liberar memoria de los subarreglos
    delete[] L;
    delete[] R;
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por mezcla (Merge Sort).
 * Divide el arreglo en dos mitades, ordena cada mitad y luego mezcla las dos mitades.
 * Este método es recursivo.
 * @details Este método es parte del algoritmo de ordenamiento por mezcla (Merge Sort).
 * @param A El arreglo a ordenar.
 * @param p El índice inicial del subarreglo a ordenar.
 * @param r El índice final del subarreglo a ordenar.
 */
void Ordenador::mergeSort(uint32_t *A, uint32_t p, uint32_t r) const {
    if (p < r) {
        // Encuentra el punto medio
        uint32_t q = p + (r - p) / 2;

        // Ordenar recursivamente las dos mitades
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);

        // Combinar las dos mitades ordenadas
        merge(A, p, q, r);
    }
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por montículos (Heap Sort).
 * Construye un montículo máximo y luego extrae los elementos en orden.
 * Aplica maxHeapify para mantener la propiedad del montículo.
 * @param A El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void Ordenador::ordenamientoPorMonticulos(uint32_t *A, uint32_t n) const {
    // Iniciar el cronómetro
    auto inicio = std::chrono::high_resolution_clock::now();

    // Construir el heap máximo
    buildMaxHeap(A, n);

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        // Mover la raíz actual al final
        // swap(A[0], A[i]);
        uint32_t *temp = new uint32_t(A[0]);
        A[0] = A[i];
        A[i] = *temp;
        delete temp;

        // Aplicar maxHeapify al heap reducido para asegurar que se mantenga la propiedad del heap
        maxHeapify(A, i, 0);
    }

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();

    // Calcular la duración enmicrosegundos
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

    // Imprimir el tiempo de ejecución
    std::cout << "Ordenamiento por montículos. Tamaño: " << n << std::endl;

    estaOrdenado(A, n, "Ordenamiento por montículos");
    std::cout << duracion << " microsegundos" << std::endl;
}

/**
 * @brief Mantiene la propiedad del montículo máximo.
 * Este método se utiliza para mantener la propiedad del montículo máximo en un arreglo.
 * @details Este método es parte del algoritmo de ordenamiento por montículos (Heap Sort).
 * @param A El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 * @param i El índice del nodo a verificar.
 */
void Ordenador::maxHeapify(uint32_t *A, uint32_t n, uint32_t i) const {
    // Inicializar el nodo más grande como la raíz
    uint32_t largest = i;
    // Calcular los índices de los hijos izquierdo y derecho
    uint32_t left = 2 * i + 1;
    uint32_t right = 2 * i + 2;

    // Si el hijo izquierdo es más grande que la raíz
    if (left < n && A[left] > A[largest]) {
        largest = left;
    }

    // Si el hijo derecho es más grande que el más grande hasta ahora
    if (right < n && A[right] > A[largest]) {
        largest = right;
    }

    // Si el más grande no es la raíz
    if (largest != i) {
        std::swap(A[i], A[largest]);
        // Recursivamente aplicar maxHeapify al subárbol afectado
        maxHeapify(A, n, largest);
    }
}

/**
 * @brief Construye un montículo máximo a partir de un arreglo.
 * Este método se utiliza para construir un montículo máximo a partir de un arreglo dado.
 * @details Este método es parte del algoritmo de ordenamiento por montículos (Heap Sort).
 * @param A El arreglo a convertir en montículo máximo.
 * @param n El tamaño del arreglo.
 */
void Ordenador::buildMaxHeap(uint32_t *A, uint32_t n) const {
    // Construir el heap máximo desde el último nodo padre hasta la raíz
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, n, i);
    }
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento rápido (Quick Sort).
 * Este método implementa el algoritmo de ordenamiento rápido (Quick Sort) para ordenar un arreglo de enteros sin signo de 32 bits.
 * Llama a la función recursiva quickSort.
 * @param A El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void Ordenador::ordenamientoRapido(uint32_t *A, uint32_t n) const {
    // Iniciar el cronómetro
    auto inicio = std::chrono::high_resolution_clock::now();

    // Llamar a la función recursiva quickSort
    quickSort(A, 0, n - 1);

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();

    // Calcular la duración en microsegundos
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

    // Imprimir el tiempo de ejecución
    std::cout << "Ordenamiento rápido. Tamaño: " << n << std::endl;

    estaOrdenado(A, n, "Ordenamiento rápido");
    std::cout << duracion << " microsegundos" << std::endl;
}

/**
 * @brief Particiona un arreglo para el algoritmo de ordenamiento rápido.
 * Este método particiona un arreglo de enteros sin signo de 32 bits para el algoritmo de ordenamiento rápido (Quick Sort).
 * Se selecciona un pivote y reorganiza el arreglo de manera que los elementos menores que el pivote estén a la izquierda y los mayores a la derecha.
 * El pivote se elige como el mediano de tres elementos (el primero, el medio y el último).
 * @details Este método es parte del algoritmo de ordenamiento rápido (Quick Sort).
 * @param A El arreglo a particionar.
 * @param p El índice inicial del subarreglo a particionar.
 * @param r El índice final del subarreglo a particionar.
 * @return El índice del pivote después de la partición.
 */
uint32_t Ordenador::partition(uint32_t *A, uint32_t p, uint32_t r) const {
    // Seleccionar el mediano de tres como pivote
    uint32_t mid = p + (r - p) / 2;
    if (A[p] > A[mid]) {
        // swap(A[p], A[mid]);
        uint32_t *temp = new uint32_t(A[p]);
        A[p] = A[mid];
        A[mid] = *temp;
        delete temp;
    }
    if (A[p] > A[r]) {
        // swap(A[p], A[r]);
        uint32_t *temp = new uint32_t(A[p]);
        A[p] = A[r];
        A[r] = *temp;
        delete temp;
    }
    if (A[mid] > A[r]) {
        // swap(A[mid], A[r]);
        uint32_t *temp = new uint32_t(A[mid]);
        A[mid] = A[r];
        A[r] = *temp;
        delete temp;
    }

    // El pivote es el elemento medio después de ordenar los tres
    uint32_t *pivot = new uint32_t(A[r]);
    int i = p - 1;
    for (uint32_t j = p; j < r; j++) {
        if (A[j] <= *pivot) {
            i++;
            // swap(A[i], A[j]);
            uint32_t *temp = new uint32_t(A[i]);
            A[i] = A[j];
            A[j] = *temp;
            delete temp;
        }
    }

    // swap(A[i + 1], A[r]);
    uint32_t *temp = new uint32_t(A[i + 1]);
    A[i + 1] = A[r];
    A[r] = *temp;
    delete temp;

    uint32_t pivotIndex = i + 1;
    delete pivot;
    return pivotIndex;
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento rápido (Quick Sort).
 * Este método es recursivo.
 * @details Este método es parte del algoritmo de ordenamiento rápido (Quick Sort).
 * @param A El arreglo a ordenar.
 * @param p El índice inicial del subarreglo a ordenar.
 * @param r El índice final del subarreglo a ordenar.
 */
void Ordenador::quickSort(uint32_t *A, uint32_t p, uint32_t r) const {
    if (p < r) {
        // Particionar el subarreglo y obtener el índice del pivote
        uint32_t q = partition(A, p, r);

        // Ordenar recursivamente las dos mitades
        quickSort(A, p, q - 1);  // Subarreglo izquierdo
        quickSort(A, q + 1, r);  // Subarreglo derecho
    }
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por residuos (Radix Sort).
 * Este método usa el counting sort como subrutina para ordenar los elementos por cada dígito.
 * @param A El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 */
void Ordenador::ordenamientoPorResiduos(uint32_t *A, uint32_t n) const {
    // Iniciar el cronómetro
    auto inicio = std::chrono::high_resolution_clock::now();

    // Encontrar el número máximo para determinar el número de dígitos
    uint32_t maxVal = A[0];
    for (uint32_t i = 1; i < n; i++) {
        if (A[i] > maxVal) {
            maxVal = A[i];
        }
    }

    // Aplicar Counting Sort para cada dígito (posición de los dígitos)
    for (uint64_t exp = 1; maxVal / exp > 0; exp *= 10) {
        countingSort(A, n, exp);
    }

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();

    // Calcular la duración enmicrosegundos
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

    // Imprimir el tiempo de ejecución
    std::cout << "Ordenamiento por residuos. Tamaño: " << n << std::endl;

    estaOrdenado(A, n, "Ordenamiento por residuos");
    std::cout << duracion << " microsegundos" << std::endl;
}

/**
 * @brief Ordena un arreglo utilizando el algoritmo de ordenamiento por residuos (Counting Sort).
 * @details Este método es una subrutina del algoritmo de ordenamiento por residuos (Radix Sort).
 * @param A El arreglo a ordenar.
 * @param n El tamaño del arreglo.
 * @param exp La posición del dígito a ordenar (1, 10, 100, etc.).
 */
void Ordenador::countingSort(uint32_t *A, uint32_t n, uint32_t exp) const {
    // Arreglo de salida
    uint32_t *B = new uint32_t[n];
    // Contador para los dígitos (0-9)
    uint32_t C[10] = {0};

    // Contar las ocurrencias de cada dígito en la posición actual (exp)
    for (uint32_t i = 0; i < n; i++) {
        uint32_t digit = (A[i] / exp) % 10;
        C[digit]++;
    }

    // Calcular las posiciones acumuladas
    for (uint32_t i = 1; i < 10; i++) {
        C[i] += C[i - 1];
    }

    // Construir el arreglo de salida de manera estable
    for (int i = n - 1; i >= 0; i--) {
        uint32_t digit = (A[i] / exp) % 10;
        B[C[digit] - 1] = A[i];
        C[digit]--;
    }

    // Copiar el arreglo ordenado de vuelta a A
    for (uint32_t i = 0; i < n; i++) {
        A[i] = B[i];
    }

    // Liberar memoria del arreglo de salida
    delete[] B;
}

/**
 * @brief Verifica si un arreglo está ordenado.
 * Se usa después de cada ordenamiento para verificar si el arreglo está ordenado correctamente.
 * @param A El arreglo a verificar.
 * @param n El tamaño del arreglo.
 * @param nombre El nombre del algoritmo utilizado para ordenar el arreglo.
 * @return true si el arreglo está ordenado, false en caso contrario.
 */
bool Ordenador::estaOrdenado(uint32_t *A, uint32_t n, const char* nombre) const {
    for (uint32_t i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            std::cout << "No ordenó en " << std::endl;
            return false;
        }
    }
    std::cout << "Ordenó bien en ";
    return true;
}
