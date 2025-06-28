// Copyright [2025] <Liqing Yosery Zheng Lu>

#pragma once

class menu {
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
};