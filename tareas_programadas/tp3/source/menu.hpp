// Copyright [2025] <Liqing Yosery Zheng Lu>

#pragma once

#include <vector>
#include <cstdint>
#include <string>

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
};
