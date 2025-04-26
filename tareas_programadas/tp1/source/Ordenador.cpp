#include <iostream>
#include <chrono>
#include "Ordenador.hpp"

void Ordenador::ordenamientoPorSeleccion(uint32_t *A, uint32_t n) const{
    // Va escogiendo el elemento más pequeño y poniéndolo en la posición i

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
        std::swap(A[i], A[m]);
    }

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

    std::cout << "Ordenamiento por seleccion. Tamaño: " << n << std::endl;
    
    estaOrdenado(A, n, "Ordenamiento por seleccion");
    // Imprimir el tiempo de ejecución
    std::cout << duracion << " milisegundos" << std::endl;
}

void Ordenador::ordenamientoPorInserccion(uint32_t *A, uint32_t n) const {

    // Inserta los elementos en su posición correcta

    // Empieza a contar la duración
    auto inicio = std::chrono::high_resolution_clock::now();

    // Recorre el arreglo A
    // i es 1 porque el elemento A[0] como es uno sólo, ya está ordenado
    for (uint32_t i = 1; i < n; i++) {
        // key es el elemento a insertar
        uint32_t key = A[i];
        int j = i - 1;

        // Mueve los elementos mayores que key una posición adelante
        while (j >= 0 && A[j] > key) {
            A[j + 1] = A[j];
            j--;
        }

        // Inserta key en su posición correcta
        A[j + 1] = key;
    }

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();
    // Calcular la duración en milisegundos
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

    std::cout << "Ordenamiento por inserción. Tamaño: " << n << std::endl;

    estaOrdenado(A, n, "Ordenamiento por inserción");
    std::cout << "Tiempo de ejecución: " << duracion << " milisegundos" << std::endl;
}

void Ordenador::ordenamientoPorMezcla(uint32_t *A, uint32_t n) const{

    // Divide el arreglo en dos mitades, ordena cada mitad y luego mezcla las dos mitades

    // Iniciar el cronómetro
    auto inicio = std::chrono::high_resolution_clock::now();

    // Método que separa las dos mitades y llama a otro método para mezclar
    mergeSort(A, 0, n - 1);

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();

    // Calcular la duración en milisegundos
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();
    // Imprimir el tiempo de ejecución
    std::cout << "Ordenamiento por mezcla. Tamaño: " << n << std::endl;

    estaOrdenado(A, n, "Ordenamiento por mezcla");
    std::cout << "Tiempo de ejecución: " << duracion << " milisegundos" << std::endl;

}

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

void Ordenador::mergeSort(uint32_t *A, uint32_t p, uint32_t r) const {
    if (p < r) {
        uint32_t q = p + (r - p) / 2; // Punto medio

        // Ordenar recursivamente las dos mitades
        mergeSort(A, p, q);
        mergeSort(A, q + 1, r);

        // Combinar las dos mitades ordenadas
        merge(A, p, q, r);
    }
}

void Ordenador::ordenamientoPorMonticulos(uint32_t *A, uint32_t n) const{
    // Iniciar el cronómetro
    auto inicio = std::chrono::high_resolution_clock::now();

    // Construir el heap máximo
    buildMaxHeap(A, n);

    // Extraer elementos del heap uno por uno
    for (int i = n - 1; i > 0; i--) {
        std::swap(A[0], A[i]); // Mover la raíz actual al final
        maxHeapify(A, i, 0); // Aplicar maxHeapify al heap reducido para asegurar que se mantenga la propiedad del heap
    }

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();

    // Calcular la duración en milisegundos
    auto duracion = std::chrono::duration_cast<std::chrono::milliseconds>(fin - inicio).count();

    // Imprimir el tiempo de ejecución
    std::cout << "Ordenamiento por montículos. Tamaño: " << n << std::endl;
    
    estaOrdenado(A, n, "Ordenamiento por montículos");
    std::cout << "Tiempo de ejecución: " << duracion << " milisegundos" << std::endl;
}

void Ordenador::maxHeapify(uint32_t *A, uint32_t n, uint32_t i) const {
    uint32_t largest = i; // Inicializar el nodo más grande como la raíz
    uint32_t left = 2 * i + 1; // Hijo izquierdo
    uint32_t right = 2 * i + 2; // Hijo derecho

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
        std::swap(A[i], A[largest]); // Intercambiar
        maxHeapify(A, n, largest); // Recursivamente aplicar maxHeapify
    }
}

void Ordenador::buildMaxHeap(uint32_t *A, uint32_t n) const {
    // Construir el heap máximo desde el último nodo padre hasta la raíz
    for (int i = n / 2 - 1; i >= 0; i--) {
        maxHeapify(A, n, i);
    }
}

void Ordenador::ordenamientoRapido(uint32_t *A, uint32_t n) const{
    //TODO
}
void Ordenador::ordenamientoPorResiduos(uint32_t *A, uint32_t n) const{
    //TODO
}

void Ordenador::imprimirArreglo(uint32_t *A, uint32_t n) const{
    for (uint32_t i = 0; i < n; i++) {
        std::cout << A[i] << " ";
    }
    std::cout << std::endl;
}

bool Ordenador::estaOrdenado(uint32_t *A, uint32_t n, const char* nombre) const{
    for (uint32_t i = 1; i < n; i++) {
        if (A[i] < A[i - 1]) {
            std::cout << "No ordenó en " << std::endl;
            return false;
        }
    }
    std::cout << "Ordenó bien en " << std::endl;
    return true;
}