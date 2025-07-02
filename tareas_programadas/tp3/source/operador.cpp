// Copyright [2025] <Liqing Yosery Zheng Lu>

#include <vector>
#include <cstdint>
#include <string>
#include <limits>
#include <algorithm>

#include "operador.hpp"

const uint64_t UINT64_MAXIMO = std::numeric_limits<uint64_t>::max();

void operador::FloydWarshall(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres) {
    size_t n = matriz.size();

    // Implementación del algoritmo de Floyd-Warshall
    for (size_t k = 0; k < n; ++k) {
        for (size_t i = 0; i < n; ++i) {
            for (size_t j = 0; j < n; ++j) {
                if (matriz[i][k] != UINT64_MAXIMO && matriz[k][j] != UINT64_MAXIMO &&
                    matriz[i][j] > matriz[i][k] + matriz[k][j]) {
                    matriz[i][j] = matriz[i][k] + matriz[k][j];
                    matrizPadres[i][j] = static_cast<int64_t>(k);
                }
            }
        }
    }
}