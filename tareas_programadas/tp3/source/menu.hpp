// Copyright [2025] <Liqing Yosery Zheng Lu>

#pragma once

#include <vector>
#include <cstdint>

class menu {

 private:

  /**
   * @brief Indica si se ha cargado algún archivo CSV.
   */
 bool small, medium, large = false;

  /**
  * @brief Matriz que almacena los tiempos de viaje entre las ciudades de input_small.csv.
  */
 std::vector<std::vector<uint64_t>> small_matriz;

  /**
    * @brief Vector que almacena los nombres de las ciudades de input_small.csv.
    */
 std::vector<std::string> small_nombreCiudad;

  /**
   * @brief Matriz que almacena los tiempos de viaje entre las ciudades de input_medium.csv.
   */
  std::vector<std::vector<uint64_t>> medium_matriz;

  /**
   * @brief Vector que almacena los nombres de las ciudades de input_medium.csv.
   */
  std::vector<std::string> medium_nombreCiudad;

  /**
   * @brief Matriz que almacena los tiempos de viaje entre las ciudades de input_large.csv.
   */
  std::vector<std::vector<uint64_t>> large_matriz;

  /**
   * @brief Vector que almacena los nombres de las ciudades de input_large.csv.
   */
  std::vector<std::string> large_nombreCiudad;

  /**
   * @brief Matriz que almacena los tiempos de viaje entre las ciudades de input personalizado.
   */
  std::vector<std::vector<uint64_t>> personalized_matriz;

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
  void cargarCSV(const std::string& nombreArchivo, std::vector<std::vector<uint64_t>>& matriz, std::vector<std::string>& nombreCiudad);

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
  bool handleArchivo(char opcion);

  /**
   * @brief Maneja la acción seleccionada por el usuario.
   * 
   * @param opcion Opción seleccionada por el usuario.
   */
  void handleAccion(char opcion);
};