# Descripción

El presente trabajo aborda la comparación entre los tiempos de ejecución teóricos y reales de diversos algoritmos de ordenamiento. Con el objetivo de evaluar cómo se ajustan las predicciones teóricas a mediciones prácticas, se generaron arreglos aleatorios de 1 000, 10 000, 100 000 y 1 000 000 y se midió
el tiempo de ejecución promedio en tres corridas mediante la biblioteca chrono.

### Algoritmos programados en C++
- Selection Sort
- Insertion Sort
- Merge Sort (mezcla)
- Heapsort (montículos)
- Quicksort (rápido)
- Radix Sort (residuos)

# Manual de compilación
El proyecto incluye su propio Makefile, por lo que se tiene que dirigir al directorio `../tareas_programadas/tp1` y ejecutar el siguiente comando:
````
make
````

Después, para correr el programa, use el comando_
````
./bin/main
`````

En caso de que quiera terminar de manera abrupta el programa, puede usar la combinación de teclas  `Control+C`.

# Resultados
los métodos cuadráticos (selección e inserción) crecen según lo esperado
con complejidad 𝑂(𝑛^2), mientras que los algoritmos 𝑂(𝑛 log 𝑛)
(mezcla, montículos y rápido) requieren tamaños superiores a
10^6 para evidenciar plenamente su ventaja. El ordenamiento por
residuos, con complejidad 𝑂(𝑑 (𝑛+𝑘)), demostró ser el más rápido
en los rangos analizados.