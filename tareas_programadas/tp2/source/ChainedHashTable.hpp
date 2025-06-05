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
};

// Implementación de tabla hash encadenada
template <typename DataType>
ChainedHashTable<DataType>::ChainedHashTable(size_t size)
  : size(size), table(size) {
  }

template <typename DataType>
void ChainedHashTable<DataType>::insert(const DataType& value) {
  size_t index = static_cast<size_t>(value) % size;
  table[index].insert(value);
}

template <typename DataType>
DLListNode<DataType>* ChainedHashTable<DataType>::search(const DataType& value) const {
  size_t index = static_cast<size_t>(value) % size;
  return table[index].search(value);
}

template <typename DataType>
void ChainedHashTable<DataType>::remove(const DataType& value) {
  size_t index = static_cast<size_t>(value) % size;
  table[index].remove(value);
}

template <typename DataType>
size_t ChainedHashTable<DataType>::getSize() const {
  return size;
}

template <typename DataType>
std::vector<DLList<DataType>> ChainedHashTable<DataType>::getTable() const {
  return table;
}

template <typename DataType>
void ChainedHashTable<DataType>::setTable(std::vector<DLList<DataType>> newTable) {
  table = std::move(newTable);
  size = table.size();
}
