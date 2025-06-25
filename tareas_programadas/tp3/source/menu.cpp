// Copyright [2025] <Liqing Yosery Zheng Lu>

#include <iostream>

#include "menu.hpp"

int menu::run() {
    std::cout << "Por favor, ingrese el archivo CSV que contiene el grafo a consultar." << std::endl;
    // TODO: Pedir csv
    std::cout << "Cargando grafo..." << std::endl;
    // TODO: Tomar tiempo de carga
    // TODO: Almacenar grafo
    // TODO: Mostrar mensaje de carga exitosa y tiempo de carga
    std::cout << "Grafo cargado exitosamente en --segundos." << std::endl;
    displayMenu();
    // TODO: Handle user input
    // TODO: Permitir salir o agregar otro archivo
    // TODO: Menú de ayuda
    return 0;
}

void menu::displayMenu() {
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
    std::cout << "[X] Salir." << std::endl;
}