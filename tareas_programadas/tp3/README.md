# Descripción

El Sistema Nacional de Tipificación de Emergencias Potenciales (SiNTiEmPo) administra una red de centros de atención distribuidos en distintas ciudades. Estas ciudades están conectadas por rutas cuyo tiempo promedio de viaje es conocido. En este proyecto se modela dicha red como un grafo dirigido ponderado y se implementa un sistema capaz de responder diversas consultas estratégicas, tales como la ubicación óptima para almacenar suministros, las rutas más cortas entre centros, y el ordenamiento de ciudades según eficiencia de conexión. Se hace uso del algoritmo de Floyd-Warshall para calcular todos los caminos más cortos entre pares de ciudades y se justifica su selección por su eficiencia y aplicabilidad a grafos densos con pesos positivos.

# Manual de compilación

1. Clonar el repositorio.
2. Abrir una terminal y navegar al directorio [tareas_programadas/tp3](../tp3/).
3. Ejecutar el comando `make` en la terminal para compilar el programa. Esto generará el ejecutable correspondiente en la carpeta `bin`.
4. Para ejecutar el programa, utilizar el comando `./bin/main`.
5. Seguir las instrucciones que aparecen en pantalla para interactuar con el programa.


# Manual de uso

Al iniciar el programa, se presenta un menú principal donde se puede elegir el archivo que contiene el grafo a analizar. Para seleccionar una opción, basta con ingresar el número correspondiente en la consola.

- Opciones 1, 2 y 3 permiten elegir entre archivos de prueba predefinidos.
- La opción 4 permite cargar un grafo personalizado ingresando la ruta completa al archivo `.csv`.

Para salir del programa desde el menú principal, se puede ingresar la letra `X`.

Luego de seleccionar y procesar el archivo, se accede a un menú secundario con las diferentes acciones disponibles. Allí también se elige la opción deseada ingresando el número correspondiente. 

En el caso de la opción 2 (identificar desde qué ciudad debe despacharse equipo hacia una ciudad específica para que llegue en el menor tiempo posible), se debe ingresar la ciudad de destino. Puede seleccionarse por número o por nombre, sin distinción de mayúsculas o minúsculas.

Para regresar del menú secundario al menú principal, se puede ingresar la letra `X`.
