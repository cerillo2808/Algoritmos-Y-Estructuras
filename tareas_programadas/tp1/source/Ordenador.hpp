#pragma once

/*
Credits
Author: Prof. Arturo Camacho, Universidad de Costa Rica
 
Modified by: Prof. Allan Berrocal, Universidad de Costa Rica
*/

class Ordenador {
    private:
    // Defina aqui los metodos auxiliares de los algoritmos de ordenamiento solamente.
    // Puede definir cuantos metodos quiera.
    
    public:
    Ordenador() = default;
    ~Ordenador() = default;
    /* Nota:
     - Si no planea implementar algunos de los métodos de ordenamiento, no los borre.
     - Simplemente déjelos con el cuerpo vacío para evitar errores de compilación, ya
       que se ejecutará el mismo main para todas las tareas.
     - Recuerde hacer uso de programación defensiva y documentar los métodos con formato Doxygen, por ejemplo.
     - No cambié la firma de los métodos de la clase Ordenador.
     - No lance excepciones para el manejo de errores.
       Ante un error, basta con que el método no modifique el arreglo original y que no cause la caída del programa.
    */ 
    void ordenamientoPorSeleccion(int *A, int n) const;
    void ordenamientoPorInserccion(int *A, int n) const;
    void ordenamientoPorMezcla(int *A, int n) const;
    void ordenamientoPorMonticulos(int *A, int n) const;
    void ordenamientoRapido(int *A, int n) const;
    void ordenamientoPorResiduos(int *A, int n) const;

    /**
     * @brief Retorna un std::string con los datos de la tarea.
     * 
     * Este método devuelve una cadena de texto que contiene el carné, nombre y tarea.
     * 
     * @return std::string Una cadena de texto con los datos de la tarea.
     */
    constexpr const char* imprimirDatosDeTarea() const {
      return "Carné: C38680, Nombre: Liqing Yosery Zheng Lu, Tarea 1";
    }
};