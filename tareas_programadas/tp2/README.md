# Descripción
Este proyecto consiste en comparar el tiempo de ejecución de las operaciones de búsqueda y eliminación en distintas estructuras de datos: lista simplemente enlazada, árbol binario de búsqueda, árbol rojinegro y tabla de dispersión con encadenamiento. El objetivo es analizar cómo varía el rendimiento dependiendo del orden de los datos (ordenados vs. aleatorios) y de la estructura utilizada. Se mide el tiempo de ejecución promedio en tres corridas mediante la biblioteca chrono.

### Algoritmos programados en C++
- Lista simplemente enlazada
- Lista doblemente enlazada
- Árbol de búsqueda binaria
- Árbol rojinegro
- Tabla de dispersión

# Manual de compilación
El proyecto incluye su propio Makefile, por lo que se tiene que dirigir al directorio `../tareas_programadas/tp2` y ejecutar el siguiente comando:
````
make
````

Después, para correr el programa, use el comando:
````
./bin/main
`````

En caso de que quiera terminar de manera abrupta el programa, puede usar la combinación de teclas  `Control+C`.

# Resultados
Con el objetivo de evaluar cómo se ajustan las predicciones teóricas a mediciones prácticas, se implementaron en C++ cinco estructuras: lista simplemente enlazada, lista doblemente enlazada, árbol de búsqueda binaria, árbol rojinegro, y una tabla de dispersión. Para ello se generaron arreglos aleatorios, uno de $1\,000\,000$ con elementos no repetidos, otro también de $1\,000\,000$ pero con elementos repetidos, y dos $10\,000$, uno para buscar y otro para eliminar. Se midió el tiempo de ejecución promedio en tres corridas mediante la biblioteca \texttt{chrono}. Los resultados evidencian que el rendimiento práctico de las estructuras depende no solo de su diseño teórico, sino también del patrón de los datos con que se alimentan. En particular, el árbol binario de búsqueda mostró una caída significativa en su eficiencia al insertar elementos ordenados, debido a la degeneración estructural hacia una forma lineal. El árbol rojinegro, por su parte, se mantuvo eficiente en ambos escenarios, aunque se observaron ligeras diferencias atribuibles a la complejidad de los casos internos del balanceo. En la tabla de dispersión, el orden de los datos también impactó el rendimiento debido a la función hash utilizada, la cual generó agrupamientos no deseados cuando los datos seguían una progresión regular. En cambio, en las listas enlazadas, las diferencias entre los casos ordenados y aleatorios fueron mínimas, aunque se identificaron patrones que podrían ser optimizados. Se concluye que factores como el orden de inserción, la función hash elegida y la implementación concreta pueden tener un impacto sustancial en el comportamiento real de las estructuras de datos.