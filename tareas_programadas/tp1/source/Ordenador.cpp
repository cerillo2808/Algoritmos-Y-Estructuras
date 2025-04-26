#include <iostream>
#include <chrono>
#include <stack>
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
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

    std::cout << "Ordenamiento por seleccion. Tamaño: " << n << std::endl;
    
    estaOrdenado(A, n, "Ordenamiento por seleccion");
    // Imprimir el tiempo de ejecución
    std::cout << duracion << " microsegundos" << std::endl;
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
    // Calcular la duración enmicrosegundos
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

    std::cout << "Ordenamiento por inserción. Tamaño: " << n << std::endl;

    estaOrdenado(A, n, "Ordenamiento por inserción");
    std::cout << duracion << "microsegundos" << std::endl;
}

void Ordenador::ordenamientoPorMezcla(uint32_t *A, uint32_t n) const{

    // Divide el arreglo en dos mitades, ordena cada mitad y luego mezcla las dos mitades

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
    std::cout << duracion << "microsegundos" << std::endl;

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

    // Calcular la duración enmicrosegundos
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

    // Imprimir el tiempo de ejecución
    std::cout << "Ordenamiento por montículos. Tamaño: " << n << std::endl;
    
    estaOrdenado(A, n, "Ordenamiento por montículos");
    std::cout << duracion << "microsegundos" << std::endl;
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
    // Iniciar el cronómetro
    auto inicio = std::chrono::high_resolution_clock::now();

    // Llamar a la función quickSort que es recursiva
    quickSort(A, n);

    // Detener el cronómetro
    auto fin = std::chrono::high_resolution_clock::now();

    // Calcular la duración enmicrosegundos
    auto duracion = std::chrono::duration_cast<std::chrono::microseconds>(fin - inicio).count();

    // Imprimir el tiempo de ejecución
    std::cout << "Ordenamiento rápido. Tamaño: " << n << std::endl;
    
    estaOrdenado(A, n, "Ordenamiento rápido");
    std::cout << duracion << "microsegundos" << std::endl;
}

uint32_t Ordenador::partition(uint32_t *A, uint32_t p, uint32_t r) const {
    // Seleccionar el mediano de tres como pivote
    uint32_t mid = p + (r - p) / 2;
    if (A[p] > A[mid]) std::swap(A[p], A[mid]);
    if (A[p] > A[r]) std::swap(A[p], A[r]);
    if (A[mid] > A[r]) std::swap(A[mid], A[r]);

    // El pivote es el elemento medio después de ordenar los tres
    std::swap(A[mid], A[r]);
    uint32_t pivot = A[r];

    int i = p - 1;
    for (uint32_t j = p; j < r; j++) {
        if (A[j] <= pivot) {
            i++;
            std::swap(A[i], A[j]);
        }
    }

    std::swap(A[i + 1], A[r]);
    return i + 1;
}

void Ordenador::quickSort(uint32_t *A, uint32_t n) const {
    if (n <= 1) return; // Si el arreglo tiene 1 o 0 elementos, ya está ordenado

    // Crear una pila para almacenar los límites de los subarreglos
    std::stack<std::pair<uint32_t, uint32_t>> pila;

    // Empujar los límites iniciales del arreglo completo
    pila.push({0, n - 1});

    while (!pila.empty()) {
        // Obtener los límites del subarreglo actual
        uint32_t p = pila.top().first;
        uint32_t r = pila.top().second;
        pila.pop();

        // Particionar el subarreglo y obtener el índice del pivote
        uint32_t q = partition(A, p, r);

        // Empujar los límites de los subarreglos izquierdo y derecho
        if (q > p + 1) { // Subarreglo izquierdo
            pila.push({p, q - 1});
        }
        if (q + 1 < r) { // Subarreglo derecho
            pila.push({q + 1, r});
        }
    }
}

void Ordenador::ordenamientoPorResiduos(uint32_t *A, uint32_t n) const{
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
    std::cout << duracion << "microsegundos" << std::endl;
}

void Ordenador::countingSort(uint32_t *A, uint32_t n, uint32_t exp) const {
    uint32_t *B = new uint32_t[n]; // Arreglo de salida
    uint32_t C[10] = {0};          // Contador para los dígitos (0-9)

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

    delete[] B; // Liberar memoria
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
    std::cout << "Ordenó bien en ";
    return true;
}