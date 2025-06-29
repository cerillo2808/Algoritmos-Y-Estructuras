// Copyright [2025] <Liqing Yosery Zheng Lu>

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cstdint>
#include <chrono>
#include <filesystem>

#include "menu.hpp"

int menu::run() {
    // TODO: Wiki help
    std::cout << "Por favor, ingrese el archivo CSV que contiene el grafo a consultar." << std::endl;
    displayArchivo();
    bool correrFloydWarshall = handleArchivo(pedirArchivo());
    // TODO: Pedir csv personalizado
    auto start = std::chrono::high_resolution_clock::now();
    if (correrFloydWarshall) {
        // TODO: Floyd-Warshall
    }
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
    std::cout << "Grafo analizado exitosamente en " << duration << " milisegundos." << std::endl;
    displayMenu(); 
    // TODO: Handle user input
    // TODO: Permitir salir o agregar otro archivo
    // TODO: Menú de ayuda
    return 0;
}

void menu::displayArchivo() {
    std::cout << "Elija el archivo CSV que contiene el grafo a consultar:" << std::endl;
    std::cout << "[1] input_small.csv" << std::endl;
    std::cout << "[2] input_medium.csv" << std::endl;
    std::cout << "[3] input_large.csv" << std::endl;
    std::cout << "[4] Ingrese uno personalizado." << std::endl;
    // TODO: Instrucciones para ingresar un archivo personalizado
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

void menu::cargarCSV(const std::string& nombreArchivo, std::vector<std::vector<uint64_t>>& matriz, std::vector<std::string>& nombreCiudad) {
    std::ifstream archivo(nombreArchivo);
    std::string linea;

    // Verificar si el archivo se abrió correctamente
    if (!archivo.is_open()) {
        std::cerr << "Error al abrir el archivo: " << nombreArchivo << std::endl;
        return;
    }

    // Ignorar la primera línea (encabezados)
    std::getline(archivo, linea);

    // Almacena los datos en una matriz temporal
    size_t max_id = 0;
    std::vector<std::tuple<uint64_t, std::string, uint64_t, std::string, uint64_t>> datos;

    // Leer todos los datos y recolectar nombres e ids
    while (std::getline(archivo, linea)) {
        // Ignorar líneas vacías
        if (linea.empty()) continue;

        std::stringstream ss(linea);
        std::string sourceIdStr, sourceName, targetIdStr, targetName, weightStr;
        if (!std::getline(ss, sourceIdStr, ',')) break;
        if (!std::getline(ss, sourceName, ',')) break;
        if (!std::getline(ss, targetIdStr, ',')) break;
        if (!std::getline(ss, targetName, ',')) break;
        if (!std::getline(ss, weightStr, ',')) break;

        uint64_t sourceId = std::stoull(sourceIdStr);
        uint64_t targetId = std::stoull(targetIdStr);
        uint64_t weight = std::stoull(weightStr);

        // Guardar el máximo id para saber el tamaño de la matriz final
        if (sourceId > max_id) max_id = sourceId;
        if (targetId > max_id) max_id = targetId;

        // Guardar nombres en el vector temporal si es la primera vez que aparecen
        if (sourceId >= nombreCiudad.size()) nombreCiudad.resize(sourceId + 1);
        if (targetId >= nombreCiudad.size()) nombreCiudad.resize(targetId + 1);
        nombreCiudad[sourceId] = sourceName;
        nombreCiudad[targetId] = targetName;

        datos.push_back({sourceId, sourceName, targetId, targetName, weight});
    }

    // Inicializar la matriz con tamaño adecuado (cuadrada)
    matriz.assign(max_id + 1, std::vector<uint64_t>(max_id + 1, 0));

    // Llenar la matriz con los pesos
    for (const auto& d : datos) {
        uint64_t sourceId, targetId, weight;
        std::tie(sourceId, std::ignore, targetId, std::ignore, weight) = d;
        matriz[sourceId][targetId] = weight;

    }
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
            // TODO: Mostrar el wiki
            displayArchivo();
        }
    }
    return opcion;
}

bool menu::handleArchivo(char opcion) {

    if (opcion == 'X') {
        // Sale del menu
        // No corre Floyd-Warshall
        return false;

    } else if (opcion == '1') {
        if (small) {
            std::cout << "El archivo 'input_small.csv' ya ha sido cargado anteriormente." << std::endl;
            return false;
        }
        cargarCSV("files/input_small.csv", small_matriz, small_nombreCiudad);
        small = true;

    } else if (opcion == '2') {
        if (medium) {
            std::cout << "El archivo 'input_medium.csv' ya ha sido cargado anteriormente." << std::endl;
            return false;
        }
        cargarCSV("files/input_medium.csv", medium_matriz, medium_nombreCiudad);
        medium = true;

    } else if (opcion == '3') {
        if (large) {
            std::cout << "El archivo 'input_large.csv' ya ha sido cargado anteriormente." << std::endl;
            return false;
        }
        cargarCSV("files/input_large.csv", large_matriz, large_nombreCiudad);
        large = true;

    } else if (opcion == '4') {
        std::string nombreArchivo;
        while (true) {
            std::cout << "Por favor, ingrese el nombre del archivo CSV personalizado (con extensión .csv) o 'X' para regresar: ";
            std::cin >> nombreArchivo;
            if (nombreArchivo == "X" || nombreArchivo == "x") {
                return false; // Regresa al menú anterior
            }
            if (!std::filesystem::exists(nombreArchivo)) {
                std::cerr << "El archivo no existe. Intente de nuevo." << std::endl;
            } else {
                cargarCSV(nombreArchivo, personalized_matriz, personalized_nombreCiudad);
                break;
            }
        }
    }

    // Indica que no ha sido cargado anteriormente y ocupa Floyd-Warshall
    return true;
}