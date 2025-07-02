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

};