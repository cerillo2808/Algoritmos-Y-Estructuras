// Copyright [2025] <Liqing Yosery Zheng Lu>

#pragma once

#include <vector>
#include <cstdint>

#include "operador.hpp"

class menu {

 private:

  /**
   * @brief Indica si se ha cargado algún archivo CSV.
   */
    bool small = false;
    bool medium = false;
    bool large = false;

    operador operador_instancia;

  /**
   * @brief Indica el archivo escogido por el usuario.
   * Es 1 si se ha escogido input_small.csv,
   * Es 2 si se ha escogido input_medium.csv,
   * Es 3 si se ha escogido input_large.csv,
   * Es 4 si se ha escogido un archivo personalizado.
   */
    int archivoEscogido = 0;

  /**
  * @brief Matriz que almacena los tiempos de viaje entre las ciudades de input_small.csv.
  */
 std::vector<std::vector<uint64_t>> small_matriz;

   /**
  * @brief Matriz padres input_small.csv.
  */
 std::vector<std::vector<uint64_t>> small_matriz_padres;

  /**
    * @brief Vector que almacena los nombres de las ciudades de input_small.csv.
    */
 std::vector<std::string> small_nombreCiudad;

  /**
   * @brief Matriz que almacena los tiempos de viaje entre las ciudades de input_medium.csv.
   */
  std::vector<std::vector<uint64_t>> medium_matriz;

  /**
   * @brief Matriz padres input_medium.csv.
   */
  std::vector<std::vector<uint64_t>> medium_matriz_padres;

  /**
   * @brief Vector que almacena los nombres de las ciudades de input_medium.csv.
   */
  std::vector<std::string> medium_nombreCiudad;

  /**
   * @brief Matriz que almacena los tiempos de viaje entre las ciudades de input_large.csv.
   */
  std::vector<std::vector<uint64_t>> large_matriz;

  /**
   * @brief Matriz padres input_large.csv.
   */
  std::vector<std::vector<uint64_t>> large_matriz_padres;

  /**
   * @brief Vector que almacena los nombres de las ciudades de input_large.csv.
   */
  std::vector<std::string> large_nombreCiudad;

  /**
   * @brief Matriz que almacena los tiempos de viaje entre las ciudades de input personalizado.
   */
  std::vector<std::vector<uint64_t>> personalized_matriz;

  /**
   * @brief Matriz padres input personalizado.
   */
  std::vector<std::vector<uint64_t>> personalized_matriz_padres;

  /**
   * @brief Vector que almacena los nombres de las ciudades de input personalizado.
   */
  std::vector<std::string> personalized_nombreCiudad;


 public:

  /**
   * @brief Ejecuta el menú y retorna un valor entero.
   * 
   * @return int Retorna 0 en caso de éxito.
   */
  int run();

  /**
   * @brief Muestra las opciones de archivo al usuario.
   */
  void displayArchivo();

  /**
   * @brief Muestra las opciones del menú al usuario.
   */
  void displayMenu();
  
  /**
   * @brief Maneja la entrada del usuario y ejecuta la acción correspondiente.
   */
  void handleInput();

  /**
   * @brief Carga un archivo CSV y almacena los datos en la matriz.
   * 
   * @param nombreArchivo Nombre del archivo CSV a cargar.
   * @param matriz Matriz donde se almacenarán los datos del archivo.
   */
  void cargarCSV(const std::string& nombreArchivo, std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombreCiudad);

  /**
   * @brief Pide al usuario que seleccione un archivo CSV.
   * @return char Retorna la opción seleccionada por el usuario.
   */
  char pedirArchivo();

  /**
   * @brief Pide al usuario que seleccione una acción del menú.
   * @return char Retorna la opción seleccionada por el usuario.
   */
  char pedirAccion();

  /**
   * @brief Maneja la selección del archivo por parte del usuario.
   * @return Retorna false si el archivo ha sido cargado anteriormente, true si no.
   * Sirve para indicar si se debe correr el algoritmo de Floyd-Warshall.
   * @param opcion Opción seleccionada por el usuario.
   */
  int handleArchivo(char opcion);

  /**
   * @brief Maneja la acción seleccionada por el usuario.
   * 
   * @param opcion Opción seleccionada por el usuario.
   */
  int handleAccion(char opcion);

  /**
 * @brief Devuelve un puntero a la matriz correspondiente según la opción seleccionada.
 * 
 * @param opcion Opción que indica qué matriz retornar (1=small, 2=medium, 3=large, 4=personalized).
 * @return std::vector<std::vector<uint64_t>>* Puntero a la matriz correspondiente, nullptr si la opción es inválida.
 */
std::vector<std::vector<uint64_t>>* getMatriz(int opcion);

/**
 * @brief Devuelve un puntero a la matriz de padres correspondiente según la opción seleccionada.
 * 
 * @param opcion Opción que indica qué matriz de padres retornar (1=small, 2=medium, 3=large, 4=personalized).
 * @return std::vector<std::vector<uint64_t>>* Puntero a la matriz de padres correspondiente, nullptr si la opción es inválida.
 */
std::vector<std::vector<uint64_t>>* getMatrizPadres(int opcion);

/**
 * @brief Devuelve un puntero al vector de nombres de ciudades correspondiente según la opción seleccionada.
 * 
 * @param opcion Opción que indica qué vector retornar (1=small, 2=medium, 3=large, 4=personalized).
 * @return std::vector<std::string>* Puntero al vector de nombres correspondiente, nullptr si la opción es inválida.
 */
std::vector<std::string>* getNombreCiudad(int opcion);

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
void accionCinco(std::vector<std::vector<uint64_t>>& matriz, std::vector<std::vector<uint64_t>>& matrizPadres, std::vector<std::string>& nombres);

/**
 * @brief Convierte una cadena a minúsculas.
 * 
 * @param str Cadena a convertir.
 * @return std::string Cadena convertida a minúsculas.
 */
  static std::string toLowercase(const std::string& str);

};