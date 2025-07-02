// Copyright [2025] <Liqing Yosery Zheng Lu>

#include <vector>
#include <cstdint>
#include <string>

#pragma once

class operador {
    public:
    /**
     * @brief Implementa el algoritmo de Floyd-Warshall para encontrar los caminos más cortos entre todas las ciudades.
     * 
     * @param matriz Matriz de adyacencia que representa el grafo de las ciudades.
     * @param matrizPadres Matriz que almacena los padres de cada nodo en el camino más corto.
     */
    void FloydWarshall(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres);

    /**
     * @brief Convierte una cadena a minúsculas.
     * 
     * @param str Cadena a convertir.
     * @return std::string Cadena convertida a minúsculas.
     */
    static std::string toLowercase(const std::string& str);

    /**
     * @brief Ejecuta la acción uno del menú.
     * Esta acción permite al usuario encontrar la ciudad o ciudades más efectivas para colocar mayor capacidad de equipo.
     * La ciudad más efectiva es aquella cuya suma de distancias a todas las demás ciudades es mínima.
     * Si no hay un camino a alguna ciudad, esa ciudad no es considerada válida.
     * Si hay más de una ciudad que reúne esta condición, se listan todos los nombres.
     * 
     * @param matriz Matriz de adyacencia que representa el grafo de las ciudades.
     * @param nombres Vector que almacena los nombres de las ciudades.
     */
    void accionUno(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::string>& nombres);

    /**
     * @brief Ejecuta la acción dos del menú.
     * Esta acción permite al usuario encontrar la ciudad más efectiva para despachar mayor capacidad de equipo hacia una ciudad específica, de manera que el tiempo total de viajes sea mínimo.
     * Muestra el nombre de la ciudad y el valor del tiempo correspondiente.
     * Si hay más de una ciudad que reúne esta condición, se listan todos los nombres.
     * @param matriz Matriz de adyacencia que representa el grafo de las ciudades.
     * @param matrizPadres Matriz que almacena los padres de cada nodo en el camino más corto.
     * @param nombres Vector que almacena los nombres de las ciudades.
     * @return int Retorna 0 si la acción se ejecuta correctamente, -1 si hay un error al seleccionar la ciudad.
     */
    int accionDos(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombres);

    /**
     * @brief Ejecuta la acción tres del menú.
     * Esta acción permite al usuario encontrar el par de ciudades más distantes entre sí, indicando el tiempo de viaje entre ambas y la ruta que se debe seguir para llegar de una ciudad a la otra.
     * Si hay más de un par de ciudades que reúne esta condición, se listan todos los nombres.
     * @param matriz Matriz de adyacencia que representa el grafo de las ciudades.
     * @param matrizPadres Matriz que almacena los padres de cada nodo en el camino más corto.
     * @param nombres Vector que almacena los nombres de las ciudades.
     */
    void accionTres(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombres);

    /**
     * @brief Ejecuta la acción cuatro del menú.
     * Esta acción permite al usuario encontrar el par de ciudades menos distantes entre sí, indicando el tiempo de viaje entre ambas y la ruta que se debe seguir para llegar de una ciudad a la otra.
     * Si hay más de un par de ciudades que reúne esta condición, se listan todos los nombres.
     * @param matriz Matriz de adyacencia que representa el grafo de las ciudades.
     * @param matrizPadres Matriz que almacena los padres de cada nodo en el camino más corto.
     * @param nombres Vector que almacena los nombres de las ciudades.
     */
    void accionCuatro(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombres);

    /**
     * @brief Ejecuta la acción cinco del menú.
     * Esta acción produce una lista de todas las ciudades ordenadas por el tiempo de viaje promedio desde cada ciudad hasta todas las demás.
     * Muestra el nombre de la ciudad y el tiempo promedio de viaje de dicha ciudad hasta todas las demás.
     * @param matriz Matriz de adyacencia que representa el grafo de las ciudades.
     * @param matrizPadres Matriz que almacena los padres de cada nodo en el camino más corto.
     * @param nombres Vector que almacena los nombres de las ciudades.
     */
    void accionCinco(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::string>& nombres);

    /**
     * @brief Carga un archivo CSV y almacena los datos en la matriz.
     * 
     * @param nombreArchivo Nombre del archivo CSV a cargar.
     * @param matriz Matriz donde se almacenarán los datos del archivo.
     */
    void cargarCSV(const std::string& nombreArchivo, std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombreCiudad);
};
