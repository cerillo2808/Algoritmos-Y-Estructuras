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
            // TODO: Wiki help

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
            // TODO: Wiki help

            displayMenu();

            char opcion = pedirAccion();

            if (opcion == 'X') {
                break;
            }

            // Si es un 0 si ocupa volver a seleccionar el archivo.
            // Es un 1 si ocupa volver a preguntar por una acción.
            int condicion = handleAccion(opcion);
            if (condicion < 0) {
                // TODO: Manejar error
            } else {
                continue;
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

void menu::cargarCSV(const std::string& nombreArchivo, std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombreCiudad) {
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
    matriz.assign(max_id + 1, std::vector<uint64_t>(max_id + 1, UINT64_MAXIMO));
    matrizPadres.assign(max_id + 1, std::vector<uint64_t>(max_id + 1, UINT64_MAXIMO));

    // Configurar condiciones iniciales
    for (size_t i = 0; i <= max_id; ++i) {
        matriz[i][i] = 0;      // peso 0 en la diagonal
    }

    // Llenar la matriz con los pesos
    for (const auto& d : datos) {
        uint64_t sourceId, targetId, weight;
        std::tie(sourceId, std::ignore, targetId, std::ignore, weight) = d;
        matriz[sourceId][targetId] = weight;
        matrizPadres[sourceId][targetId] = static_cast<int64_t>(sourceId);
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

int menu::handleArchivo(char opcion) {

    if (opcion == '1') {
        archivoEscogido = 1;
        if (small) {
            std::cout << "El archivo 'input_small.csv' ya ha sido cargado anteriormente." << std::endl;
            return 0;
        }
        auto start = std::chrono::high_resolution_clock::now();
        cargarCSV("files/input_small.csv", small_matriz, small_matriz_padres, small_nombreCiudad);
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
        cargarCSV("files/input_medium.csv", medium_matriz, medium_matriz_padres, medium_nombreCiudad);
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
        cargarCSV("files/input_large.csv", large_matriz, large_matriz_padres, large_nombreCiudad);
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
                cargarCSV(nombreArchivo, personalized_matriz, personalized_matriz_padres, personalized_nombreCiudad);
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
        
        accionUno(*matriz, *nombres);

    } else if (opcion == '2') {
        // Obtener las matrices correspondientes al archivo escogido
        auto* matriz = getMatriz(archivoEscogido);
        auto* matrizPadres = getMatrizPadres(archivoEscogido);
        auto* nombres = getNombreCiudad(archivoEscogido);
        
        if (!matriz || !matrizPadres || !nombres) {
            std::cout << "Error: No se ha cargado ningún grafo." << std::endl;
            return 1;
        }

        return accionDos(*matriz, *matrizPadres, *nombres);

    } else if (opcion == '3') {
        // Obtener las matrices correspondientes al archivo escogido
        auto* matriz = getMatriz(archivoEscogido);
        auto* matrizPadres = getMatrizPadres(archivoEscogido);
        auto* nombres = getNombreCiudad(archivoEscogido);
        
        if (!matriz || !matrizPadres || !nombres) {
            std::cout << "Error: No se ha cargado ningún grafo." << std::endl;
            return 1;
        }

        accionTres(*matriz, *matrizPadres, *nombres);

    } else if (opcion == '4') {
        // Obtener las matrices correspondientes al archivo escogido
        auto* matriz = getMatriz(archivoEscogido);
        auto* matrizPadres = getMatrizPadres(archivoEscogido);
        auto* nombres = getNombreCiudad(archivoEscogido);
        
        if (!matriz || !matrizPadres || !nombres) {
            std::cout << "Error: No se ha cargado ningún grafo." << std::endl;
            return 1;
        }

        accionCuatro(*matriz, *matrizPadres, *nombres);

    } else if (opcion == '5') {
        // Obtener las matrices correspondientes al archivo escogido
        auto* matriz = getMatriz(archivoEscogido);
        auto* matrizPadres = getMatrizPadres(archivoEscogido);
        auto* nombres = getNombreCiudad(archivoEscogido);
        
        if (!matriz || !matrizPadres || !nombres) {
            std::cout << "Error: No se ha cargado ningún grafo." << std::endl;
            return 1;
        }

        accionCinco(*matriz, *matrizPadres, *nombres);
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

void menu::accionUno(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::string>& nombres) {
    size_t n = matriz.size();
    uint64_t sumaMinima = UINT64_MAXIMO;
    std::vector<size_t> ciudadesOptimas;
    
    // Para cada ciudad i, calcular la suma de distancias a todas las demás ciudades
    for (size_t i = 0; i < n; ++i) {
        uint64_t suma = 0;
        bool esValida = true;
        
        for (size_t j = 0; j < n; ++j) {
            if (i != j) {
                if ((matriz)[i][j] == UINT64_MAXIMO) {
                    // Si no hay camino a alguna ciudad, esta ciudad no es válida
                    esValida = false;
                    break;
                }
                suma += (matriz)[i][j];
            }
        }
        
        if (esValida) {
            if (suma < sumaMinima) {
                sumaMinima = suma;
                ciudadesOptimas.clear();
                ciudadesOptimas.push_back(i);
            } else if (suma == sumaMinima) {
                ciudadesOptimas.push_back(i);
            }
        }
    }
    
    // Mostrar resultados
    if (ciudadesOptimas.empty()) {
        std::cout << "No se encontraron ciudades válidas (sin conexión a todas las demás)." << std::endl;
    } else {
        std::cout << "Ciudad(es) más efectiva(s) para colocar mayor capacidad de equipo:" << std::endl;
        for (size_t ciudad : ciudadesOptimas) {
            std::cout << "- " << (nombres)[ciudad] << std::endl;
        }
        std::cout << "Tiempo total mínimo: " << sumaMinima << " unidades." << std::endl;
    }

}

std::string menu::toLowercase(const std::string& str) {
    std::string result = str;
    std::transform(result.begin(), result.end(), result.begin(), ::tolower);
    return result;
}

int menu::accionDos(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombres) {
    size_t n = matriz.size();
        
    // Mostrar ciudades disponibles
    std::cout << "Ciudades disponibles:" << std::endl;
    for (size_t i = 0; i < n; ++i) {
        if (!(nombres)[i].empty()) {
            std::cout << "[" << i << "] " << (nombres)[i] << std::endl;
        }
    }
    
    // Pedir al usuario que seleccione la ciudad destino
    size_t ciudadDestino;
    std::cout << "Ingrese el número de la ciudad destino o el nombre: ";
    std::string input;
    std::cin.ignore(); // Limpiar el buffer
    std::getline(std::cin, input);
    
    // Verificar si es un número o un nombre
    bool encontrada = false;
    if (std::all_of(input.begin(), input.end(), ::isdigit)) {
        // Es un número
        ciudadDestino = std::stoull(input);
        if (ciudadDestino < n && !(nombres)[ciudadDestino].empty()) {
            encontrada = true;
        }
    } else {
        // Es un nombre, buscar en el vector de nombres
        std::string inputLower = toLowercase(input);
        for (size_t i = 0; i < n; ++i) {
            if (!(nombres)[i].empty() && toLowercase((nombres)[i]) == input) {
                ciudadDestino = i;
                encontrada = true;
                break;
            }
        }
    }

    if (!encontrada) {
        std::cout << "Ciudad destino inválida o no encontrada." << std::endl;
        return 1;
    }
    
    // Encontrar la mejor ciudad origen (menor tiempo a la ciudad destino)
    uint64_t tiempoMinimo = UINT64_MAXIMO;
    std::vector<size_t> mejoresOrigenes;
    
    for (size_t y = 0; y < n; ++y) {
        if (y != ciudadDestino && !(nombres)[y].empty()) {
            uint64_t tiempo = (matriz)[y][ciudadDestino];
            if (tiempo != UINT64_MAXIMO) {
                if (tiempo < tiempoMinimo) {
                    tiempoMinimo = tiempo;
                    mejoresOrigenes.clear();
                    mejoresOrigenes.push_back(y);
                } else if (tiempo == tiempoMinimo) {
                    mejoresOrigenes.push_back(y);
                }
            }
        }
    }
    
    // Mostrar resultados
    if (mejoresOrigenes.empty()) {
        std::cout << "No se encontraron ciudades válidas para despachar hacia " << (nombres)[ciudadDestino] << "." << std::endl;
    } else {
        std::cout << "Mejor(es) ciudad(es) para despachar hacia " << (nombres)[ciudadDestino] << ":" << std::endl;
        
        for (size_t origen : mejoresOrigenes) {
            std::cout << "- " << (nombres)[origen] << std::endl;
            std::cout << "  Tiempo: " << tiempoMinimo << " unidades" << std::endl;
            
            // Reconstruir y mostrar la ruta
            std::vector<size_t> ruta;
            size_t actual = ciudadDestino;
            ruta.push_back(actual);
            
            while (actual != origen) {
                uint64_t predecesor = (matrizPadres)[origen][actual];
                if (predecesor == UINT64_MAXIMO) {
                    // No hay ruta válida
                    break;
                }
                actual = predecesor;
                ruta.push_back(actual);
            }
            
            // Invertir la ruta para mostrarla de origen a destino
            std::reverse(ruta.begin(), ruta.end());
            
            std::cout << "  Ruta: ";
            for (size_t i = 0; i < ruta.size(); ++i) {
                std::cout << (nombres)[ruta[i]];
                if (i < ruta.size() - 1) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl << std::endl;
        }
    }
    return 0;
}

void menu::accionTres(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombres) {
    size_t n = matriz.size();
    uint64_t distanciaMaxima = 0;
    std::vector<std::pair<size_t, size_t>> paresMaximos;
    
    // Buscar la distancia máxima entre todos los pares de ciudades
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i != j && !nombres[i].empty() && !nombres[j].empty()) {
                uint64_t distancia = matriz[i][j];
                if (distancia != UINT64_MAXIMO) {
                    if (distancia > distanciaMaxima) {
                        distanciaMaxima = distancia;
                        paresMaximos.clear();
                        paresMaximos.push_back({i, j});
                    } else if (distancia == distanciaMaxima) {
                        paresMaximos.push_back({i, j});
                    }
                }
            }
        }
    }
    
    // Mostrar resultados
    if (paresMaximos.empty()) {
        std::cout << "No se encontraron pares de ciudades conectadas." << std::endl;
    } else {
        std::cout << "Par(es) de ciudades más distantes:" << std::endl;
        std::cout << "Distancia máxima: " << distanciaMaxima << " unidades" << std::endl << std::endl;
        
        for (const auto& par : paresMaximos) {
            size_t origen = par.first;
            size_t destino = par.second;
            
            std::cout << "De " << nombres[origen] << " a " << nombres[destino] << std::endl;
            std::cout << "Tiempo de viaje: " << distanciaMaxima << " unidades" << std::endl;
            
            // Reconstruir y mostrar la ruta
            std::vector<size_t> ruta;
            size_t actual = destino;
            ruta.push_back(actual);
            
            while (actual != origen) {
                uint64_t predecesor = matrizPadres[origen][actual];
                if (predecesor == UINT64_MAXIMO) {
                    // No hay ruta válida (aunque esto no debería pasar si encontramos la distancia)
                    break;
                }
                actual = predecesor;
                ruta.push_back(actual);
            }
            
            // Invertir la ruta para mostrarla de origen a destino
            std::reverse(ruta.begin(), ruta.end());
            
            std::cout << "Ruta: ";
            for (size_t i = 0; i < ruta.size(); ++i) {
                std::cout << nombres[ruta[i]];
                if (i < ruta.size() - 1) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl << std::endl;
        }
    }

}

void menu::accionCuatro(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombres) {
    size_t n = matriz.size();
    uint64_t distanciaMinima = UINT64_MAXIMO;
    std::vector<std::pair<size_t, size_t>> paresMinimos;
    
    // Buscar la distancia mínima entre todos los pares de ciudades (excluyendo 0 y ∞)
    for (size_t i = 0; i < n; ++i) {
        for (size_t j = 0; j < n; ++j) {
            if (i != j && !nombres[i].empty() && !nombres[j].empty()) {
                uint64_t distancia = matriz[i][j];
                // Buscar mínimo > 0 y != UINT64_MAXIMO
                if (distancia != UINT64_MAXIMO && distancia > 0) {
                    if (distancia < distanciaMinima) {
                        distanciaMinima = distancia;
                        paresMinimos.clear();
                        paresMinimos.push_back({i, j});
                    } else if (distancia == distanciaMinima) {
                        paresMinimos.push_back({i, j});
                    }
                }
            }
        }
    }
    
    // Mostrar resultados
    if (paresMinimos.empty()) {
        std::cout << "No se encontraron pares de ciudades conectadas." << std::endl;
    } else {
        std::cout << "Par(es) de ciudades menos distantes:" << std::endl;
        std::cout << "Distancia mínima: " << distanciaMinima << " unidades" << std::endl << std::endl;
        
        for (const auto& par : paresMinimos) {
            size_t origen = par.first;
            size_t destino = par.second;
            
            std::cout << "De " << nombres[origen] << " a " << nombres[destino] << std::endl;
            std::cout << "Tiempo de viaje: " << distanciaMinima << " unidades" << std::endl;
            
            // Reconstruir y mostrar la ruta
            std::vector<size_t> ruta;
            size_t actual = destino;
            ruta.push_back(actual);
            
            while (actual != origen) {
                uint64_t predecesor = matrizPadres[origen][actual];
                if (predecesor == UINT64_MAXIMO) {
                    // No hay ruta válida (aunque esto no debería pasar si encontramos la distancia)
                    break;
                }
                actual = predecesor;
                ruta.push_back(actual);
            }
            
            // Invertir la ruta para mostrarla de origen a destino
            std::reverse(ruta.begin(), ruta.end());
            
            std::cout << "Ruta: ";
            for (size_t i = 0; i < ruta.size(); ++i) {
                std::cout << nombres[ruta[i]];
                if (i < ruta.size() - 1) {
                    std::cout << " -> ";
                }
            }
            std::cout << std::endl << std::endl;
        }
    }
}

void menu::accionCinco(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombres) {
    size_t n = matriz.size();
    std::vector<std::pair<double, size_t>> ciudadesPromedio; // <promedio, índice de ciudad>
    
    // Para cada ciudad, calcular el tiempo promedio hacia todas las demás ciudades
    for (size_t i = 0; i < n; ++i) {
        if (!nombres[i].empty()) {
            uint64_t suma = 0;
            size_t ciudadesValidas = 0;
            bool esValida = true;
            
            for (size_t j = 0; j < n; ++j) {
                if (i != j && !nombres[j].empty()) {
                    uint64_t distancia = matriz[i][j];
                    if (distancia == UINT64_MAXIMO) {
                        // Si no hay camino a alguna ciudad, esta ciudad no es válida
                        esValida = false;
                        break;
                    }
                    suma += distancia;
                    ciudadesValidas++;
                }
            }
            
            if (esValida && ciudadesValidas > 0) {
                double promedio = static_cast<double>(suma) / ciudadesValidas;
                ciudadesPromedio.push_back({promedio, i});
            }
        }
    }
    
    // Ordenar por tiempo promedio (orden creciente)
    std::sort(ciudadesPromedio.begin(), ciudadesPromedio.end());
    
    // Mostrar resultados
    if (ciudadesPromedio.empty()) {
        std::cout << "No se encontraron ciudades válidas (sin conexión a todas las demás)." << std::endl;
    } else {
        std::cout << "Ciudades ordenadas por tiempo de viaje promedio (orden creciente):" << std::endl;
        std::cout << std::endl;
        
        for (size_t pos = 0; pos < ciudadesPromedio.size(); ++pos) {
            double promedio = ciudadesPromedio[pos].first;
            size_t ciudadIndice = ciudadesPromedio[pos].second;
            
            std::cout << (pos + 1) << ". " << nombres[ciudadIndice] << std::endl;
            std::cout << "   Tiempo promedio de viaje: " << std::fixed << std::setprecision(2) << promedio << " unidades" << std::endl;
            std::cout << std::endl;
        }
    }
}
