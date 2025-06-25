// Copyright [2025] <Liqing Yosery Zheng Lu>

#pragma once

class menu {
 public:
  /**
   * @brief Runs the menu and returns an integer value.
   * 
   * @return int Returns 0 on success.
   */
  int run();
  
  /**
   * @brief Displays the menu options to the user.
   */
  void displayMenu();
  
  /**
   * @brief Handles user input and executes the corresponding action.
   */
  void handleInput();
};