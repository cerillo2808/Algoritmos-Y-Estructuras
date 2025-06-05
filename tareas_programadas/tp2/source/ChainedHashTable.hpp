/*
 Credits
 Based on: Prof. Arturo Camacho, Universidad de Costa Rica
 Modified by: Prof. Allan Berrocal, Universidad de Costa Rica
 */

#pragma once
#include <cstdint>
#include <vector>

#include "DoublyLinkedList.hpp"

template <typename DataType>

class ChainedHashTable {
 public:
  ChainedHashTable(size_t size);

  // No es necesario liberar memoria, la lista doblemente enlazada se encarga
  ~ChainedHashTable() {};

  void insert(const DataType& value);

  DLListNode<DataType>* search(const DataType& value) const;

  void remove(const DataType& value);

  size_t getSize() const;

  std::vector<DLList<DataType>> getTable() const;

  void setTable(std::vector<DLList<DataType>>);

 private:
  size_t size;

  std::vector<DLList<DataType>> table;
  DLListNode<DataType>* getPointerTo(const DataType& value);
};

// Implementación de tabla hash encadenada
/**
 * @brief Constructor de una tabla hash encadenada
 * @param size Tamaño de la tabla hash
 * Inicializa la tabla con el tamaño especificado y crea una lista doblemente enlazada para cada índice.
 */
template <typename DataType>
ChainedHashTable<DataType>::ChainedHashTable(size_t size)
  : size(size), table(size) {
  }

/**
 * @brief Inserta el valor @param value en la tabla hash encadenada.
 * Calcula el índice usando h(k) = k mód m, m siendo el tamaño de la tabla.
 * Luego, inserta el valor en la lista doblemente enlazada correspondiente a ese índice.
 * No soporta duplicados, si el valor ya existe, no lo inserta.
 */
template <typename DataType>
void ChainedHashTable<DataType>::insert(const DataType& value) {
  size_t index = static_cast<size_t>(value) % size;
  if (table[index].search(value) != nullptr) {
    // Si el valor ya existe, no lo inserta
    return;
  }
  table[index].insert(value);
}

/**
 * @brief Busca el valor @param value en la tabla hash encadenada.
 * Calcula el índice usando h(k) = k mód m, m siendo el tamaño de la tabla.
 * Luego, busca el valor en la lista doblemente enlazada correspondiente a ese índice.
 * @return Un puntero al nodo que contiene el valor, o nullptr si no se encuentra.
 */
template <typename DataType>
DLListNode<DataType>* ChainedHashTable<DataType>::search(const DataType& value) const {
  size_t index = static_cast<size_t>(value) % size;
  return table[index].search(value);
}

/**
 * @brief Elimina el valor @param value de la tabla hash encadenada.
 * Busca el nodo que contiene el valor y lo elimina de la lista doblemente enlazada correspondiente.
 * Si el nodo no se encuentra, no hace nada.
 */
template <typename DataType>
void ChainedHashTable<DataType>::remove(const DataType& value) {
  DLListNode<DataType>* node = this->getPointerTo(value);
  if (node != nullptr) {
    size_t index = static_cast<size_t>(value) % size;
    // Usa eliminación por puntero, Θ(1)
    table[index].remove(node);
  }
}

/**
 * @brief Getter del tamaño de la tabla hash encadenada.
 */
template <typename DataType>
size_t ChainedHashTable<DataType>::getSize() const {
  return size;
}

/**
 * @brief Getter de la tabla hash encadenada.
 */
template <typename DataType>
std::vector<DLList<DataType>> ChainedHashTable<DataType>::getTable() const {
  return table;
}

/**
 * @brief Setter de la tabla hash encadenada.
 */
template <typename DataType>
void ChainedHashTable<DataType>::setTable(std::vector<DLList<DataType>> newTable) {
  table = std::move(newTable);
  size = table.size();
}

/**
 * @brief Obtiene un puntero al nodo que contiene el valor @param value.
 * Calcula el índice usando h(k) = k mód m, m siendo el tamaño de la tabla.
 * Busca el valor en la lista doblemente enlazada correspondiente a ese índice.
 * @return Un puntero al nodo que contiene el valor, o nullptr si no se encuentra.
 * Esta función es útil para operaciones que requieren acceso directo al nodo, como eliminación.
 */
template <typename DataType>
DLListNode<DataType>* ChainedHashTable<DataType>::getPointerTo(const DataType& value) {
  size_t index = static_cast<size_t>(value) % size;
  return table[index].search(value);
}