// Copyright [2025] <Liqing Yosery Zheng Lu>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>
#include <chrono>
#include <filesystem>
#include <limits>
#include <algorithm>
#include <iomanip>

#include "menu.hpp"
#include "operador.hpp"

const uint64_t UINT64_MAXIMO = std::numeric_limits<uint64_t>::max();

int menu::run() {
    while (true) {
        while (true) {
            displayArchivo();

            char opcion = pedirArchivo();

            if (opcion == 'X') {
                // Si se seleccionó salir, termina el programa
                return 0;
            }

            // Es un 0 si no se ocupa correr Floyd-Warshall, es un 0 si ocupa correrlo
            // Si no hay un archivo válido, es un -1
            int condicion = handleArchivo(opcion);
            if (condicion < 0) {
                continue;
            } else {
                break;
            }
        }

        while (true) {
            displayMenu();

            char opcion = pedirAccion();

            if (opcion == 'X') {
                break;
            }
        }
    }
}

void menu::displayArchivo() {
    std::cout << "Elija el archivo CSV que contiene el grafo a consultar:" << std::endl;
    std::cout << "[1] input_small.csv" << std::endl;
    std::cout << "[2] input_medium.csv" << std::endl;
    std::cout << "[3] input_large.csv" << std::endl;
    std::cout << "[4] Ingrese uno personalizado." << std::endl;
    std::cout << "[X] Salir." << std::endl;
}

void menu::displayMenu() {
    std::cout << "Seleccione una opción:" << std::endl;
    std::cout << "[1] Ciudad(es) más efectiva(s) para colocar mayor capacidad de equipo." << std::endl;
    /* 
    Encontrar el nombre de la ciudad donde es más efectivo colocar mayor capacidad de equipo de
    manera que si se necesita repartir equipo ubicado en este centro hacia todos los demás, se tenga
    que invertir la menor cantidad de tiempo total de viajes. Muestre el nombre de la ciudad y
    el valor de tiempo correspondiente. Si hay más de una ciudad que reúne esta condición, liste
    todos los nombres..
    */
    std::cout << "[2] Ciudad más efectiva para despachar mayor capacidad de equipo." << std::endl;
    /*
    Dada una ciudad x, encuentre la ciudad y desde la cual es mejor despachar equipo de apoyo
    o suministros hacia la ciudad x para que llegue lo más pronto posible en caso de que ocurra
    una emergencia en la ciudad x. Muestre el nombre de la ciudad y así como el valor del tiempo
    y la ruta que se debe seguir para llegar de la ciudad y a la x. Si hay más de una ciudad que
    reúne esta condición, liste todos los nombres.
    */
    std::cout << "[3] Par de ciudades más distantes." << std::endl;
    /*
    Encontrar el par de ciudades (x, y) que están más distantes la una de la otra e indicar el
    tiempo de viaje entre ambas así como la ruta que se debe seguir para llegar de la ciudad x a
    la y. Si hay más de una ciudad que reúne esta condición, liste todos los nombres.
    */
    std::cout << "[4] Par de ciudades menos distantes." << std::endl;
    /*
    Encontrar el par (x, y) de ciudades que están menos distantes la una de la otra siempre que
    x̸ = y e indicar el tiempo de viaje entre ambas así como la ruta que se debe seguir para llegar
    de la ciudad x a la y. Si hay más de una ciudad que reúne esta condición, liste todos los
    nombres.
    */
    std::cout << "[5] Ciudades ordenadas por tiempo de viaje promedio." << std::endl;
    /*
    Producir una lista de todas las ciudades en orden creciente según el tiempo de viaje promedio
    desde esa ciudad hasta todas las demás ciudades. Muestre el nombre de la ciudad así como
    el tiempo promedio de viaje de dicha ciudad hasta todas las demás.
    */
    std::cout << "[X] Regresar." << std::endl;
    /*
    Regresar al menú de selección de archivo.
    */
}

char menu::pedirArchivo() {
    // El cero significa que no se ha seleccionado una opción válida
    char opcion = '0';
    while (true) {
        std::cin >> opcion;
        opcion = std::toupper(opcion);

        if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == '4' || opcion == 'X') {
            break;
        } else {
            std::cout << "Opción inválida. Intente de nuevo." << std::endl;
            displayArchivo();
        }
    }
    return opcion;
}

int menu::handleArchivo(char opcion) {
    if (opcion == '1') {
        archivoEscogido = 1;
        if (small) {
            std::cout << "El archivo 'input_small.csv' ya ha sido cargado anteriormente." << std::endl;
            return 0;
        }
        auto start = std::chrono::high_resolution_clock::now();
        operador_instancia.cargarCSV("files/input_small.csv", small_matriz, small_matriz_padres, small_nombreCiudad);
        operador_instancia.FloydWarshall(small_matriz, small_matriz_padres);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Grafo analizado exitosamente en " << duration << " milisegundos." << std::endl;
        small = true;

    } else if (opcion == '2') {
        archivoEscogido = 2;
        if (medium) {
            std::cout << "El archivo 'input_medium.csv' ya ha sido cargado anteriormente." << std::endl;
            return 0;
        }
        auto start = std::chrono::high_resolution_clock::now();
        operador_instancia.cargarCSV("files/input_medium.csv", medium_matriz, medium_matriz_padres, medium_nombreCiudad);
        operador_instancia.FloydWarshall(medium_matriz, medium_matriz_padres);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Grafo analizado exitosamente en " << duration << " milisegundos." << std::endl;
        medium = true;

    } else if (opcion == '3') {
        archivoEscogido = 3;
        if (large) {
            std::cout << "El archivo 'input_large.csv' ya ha sido cargado anteriormente." << std::endl;
            return 0;
        }
        auto start = std::chrono::high_resolution_clock::now();
        operador_instancia.cargarCSV("files/input_large.csv", large_matriz, large_matriz_padres, large_nombreCiudad);
        operador_instancia.FloydWarshall(large_matriz, large_matriz_padres);
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Grafo analizado exitosamente en " << duration << " milisegundos." << std::endl;
        large = true;

    } else if (opcion == '4') {
        archivoEscogido = 4;
        std::string nombreArchivo;
        while (true) {
            std::cout << "Por favor, ingrese el nombre del archivo CSV personalizado (con extensión .csv) o 'X' para regresar: ";
            std::cin >> nombreArchivo;
            if (nombreArchivo == "X" || nombreArchivo == "x") {
                // Regresa al menú anterior
                return -1;
            }
            if (!std::filesystem::exists(nombreArchivo)) {
                std::cerr << "El archivo no existe. Intente de nuevo." << std::endl;
            } else {
                auto start = std::chrono::high_resolution_clock::now();
                operador_instancia.cargarCSV(nombreArchivo, personalized_matriz, personalized_matriz_padres, personalized_nombreCiudad);
                operador_instancia.FloydWarshall(personalized_matriz, personalized_matriz_padres);
                auto end = std::chrono::high_resolution_clock::now();
                auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
                std::cout << "Grafo analizado exitosamente en " << duration << " milisegundos." << std::endl;
                break;
            }
        }
    }

    // Indica que no ha sido cargado anteriormente y ocupa Floyd-Warshall
    return 1;
}

char menu::pedirAccion() {
    char opcion = '0';
    while (true) {
        std::cin >> opcion;
        opcion = std::toupper(opcion);

        if (opcion == '1' || opcion == '2' || opcion == '3' || opcion == '4' || opcion == '5' || opcion == 'X') {
            break;
        } else {
            std::cout << "Opción inválida. Intente de nuevo." << std::endl;
            displayMenu();
        }
    }
    return opcion;
}

int menu::handleAccion(char opcion) {
    if (opcion == '1') {
        // Obtener las matrices correspondientes al archivo escogido
        auto* matriz = getMatriz(archivoEscogido);
        auto* nombres = getNombreCiudad(archivoEscogido);

        if (!matriz || !nombres) {
            std::cout << "Error: No se ha cargado ningún grafo." << std::endl;
            return 1;
        }

        operador_instancia.accionUno(*matriz, *nombres);

    } else if (opcion == '2') {
        // Obtener las matrices correspondientes al archivo escogido
        auto* matriz = getMatriz(archivoEscogido);
        auto* matrizPadres = getMatrizPadres(archivoEscogido);
        auto* nombres = getNombreCiudad(archivoEscogido);

        if (!matriz || !matrizPadres || !nombres) {
            std::cout << "Error: No se ha cargado ningún grafo." << std::endl;
            return 1;
        }

        return operador_instancia.accionDos(*matriz, *matrizPadres, *nombres);

    } else if (opcion == '3') {
        // Obtener las matrices correspondientes al archivo escogido
        auto* matriz = getMatriz(archivoEscogido);
        auto* matrizPadres = getMatrizPadres(archivoEscogido);
        auto* nombres = getNombreCiudad(archivoEscogido);

        if (!matriz || !matrizPadres || !nombres) {
            std::cout << "Error: No se ha cargado ningún grafo." << std::endl;
            return 1;
        }

        operador_instancia.accionTres(*matriz, *matrizPadres, *nombres);

    } else if (opcion == '4') {
        // Obtener las matrices correspondientes al archivo escogido
        auto* matriz = getMatriz(archivoEscogido);
        auto* matrizPadres = getMatrizPadres(archivoEscogido);
        auto* nombres = getNombreCiudad(archivoEscogido);

        if (!matriz || !matrizPadres || !nombres) {
            std::cout << "Error: No se ha cargado ningún grafo." << std::endl;
            return 1;
        }

        operador_instancia.accionCuatro(*matriz, *matrizPadres, *nombres);

    } else if (opcion == '5') {
        // Obtener las matrices correspondientes al archivo escogido
        auto* matriz = getMatriz(archivoEscogido);
        auto* nombres = getNombreCiudad(archivoEscogido);

        if (!matriz || !nombres) {
            std::cout << "Error: No se ha cargado ningún grafo." << std::endl;
            return 1;
        }

        operador_instancia.accionCinco(*matriz, *nombres);
    }

    // Indica que puede preguntar por otra acción
    return 1;
}

std::vector<std::vector<uint64_t>>* menu::getMatriz(int opcion) {
    switch (opcion) {
        case 1:
            return &small_matriz;
        case 2:
            return &medium_matriz;
        case 3:
            return &large_matriz;
        case 4:
            return &personalized_matriz;
        default:
            return nullptr;
    }
}

std::vector<std::vector<uint64_t>>* menu::getMatrizPadres(int opcion) {
    switch (opcion) {
        case 1:
            return &small_matriz_padres;
        case 2:
            return &medium_matriz_padres;
        case 3:
            return &large_matriz_padres;
        case 4:
            return &personalized_matriz_padres;
        default:
            return nullptr;
    }
}

std::vector<std::string>* menu::getNombreCiudad(int opcion) {
    switch (opcion) {
        case 1:
            return &small_nombreCiudad;
        case 2:
            return &medium_nombreCiudad;
        case 3:
            return &large_nombreCiudad;
        case 4:
            return &personalized_nombreCiudad;
        default:
            return nullptr;
    }
}
