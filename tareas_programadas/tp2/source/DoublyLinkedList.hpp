/*
 Credits
 Based on: Prof. Arturo Camacho, Universidad de Costa Rica
 Modified by: Prof. Allan Berrocal, Universidad de Costa Rica
 */

#pragma once
template <typename DataType>
class DLList;

template <typename DataType>
class DLListNode {
 public:
  friend class DLList<DataType>;

  DLListNode() = default;

  DLListNode(const DataType& value, DLListNode<DataType>* next = nullptr,
             DLListNode<DataType>* prev = nullptr);

  ~DLListNode() {};

  DataType getKey() const;

  DLListNode<DataType>* getPrev() const;

  DLListNode<DataType>* getNext() const;

  void setKey(DataType key);

  void setPrev(DLListNode<DataType>* prev);

  void setNext(DLListNode<DataType>* next);

 private:
  DataType key;

  DLListNode<DataType>* next;

  DLListNode<DataType>* prev;
};

// Implementación de DLListNode
/**
 * @brief Constructor de un nodo de lista doblemente enlazada.
 * @param value El valor a almacenar en el nodo.
 * @param next Puntero al siguiente nodo (por defecto es nullptr).
 * @param prev Puntero al nodo anterior (por defecto es nullptr).
 */
template <typename DataType>
DLListNode<DataType>::DLListNode(const DataType& value, DLListNode<DataType>* next,
                                   DLListNode<DataType>* prev)
    : key(value), next(next), prev(prev) {}

/**
 * @brief Getter para la clave del nodo
 */
template <typename DataType>
DataType DLListNode<DataType>::getKey() const {
  return key;
}

/**
 * @brief Getter para el nodo anterior
 */
template <typename DataType>
DLListNode<DataType>* DLListNode<DataType>::getPrev() const {
  return prev;
}

/**
 * @brief Getter para el nodo siguiente
 */
template <typename DataType>
DLListNode<DataType>* DLListNode<DataType>::getNext() const {
  return next;
}

/**
 * @brief Setter para la clave del nodo
 */
template <typename DataType>
void DLListNode<DataType>::setKey(DataType key) {
  this->key = key;
}

/**
 * @brief Setter para el nodo anterior
 */
template <typename DataType>
void DLListNode<DataType>::setPrev(DLListNode<DataType>* prev) {
  this->prev = prev;
}

/**
 * @brief Setter para el nodo siguiente
 */
template <typename DataType>
void DLListNode<DataType>::setNext(DLListNode<DataType>* next) {
  this->next = next;
}

template <typename DataType>
class DLList {
 public:
  DLList();

  ~DLList();

  void insert(const DataType& value);

  DLListNode<DataType>* search(const DataType& value) const;

  void remove(const DataType& value);

  void remove(DLListNode<DataType>* node);

  DLListNode<DataType>* getNil() const;

 private:
  DLListNode<DataType>* nil;
};

// Implementación de DLList
/**
 * @brief Constructor de una lista doblemente enlazada.
 * Crea un nodo nil que sirve como centinela para facilitar las operaciones de inserción y eliminación.
 */
template <typename DataType>
DLList<DataType>::DLList() {
  nil = new DLListNode<DataType>();
  nil->setNext(nil);
  nil->setPrev(nil);
}

/**
 * @brief Destructor de la lista doblemente enlazada.
 * Elimina todos los nodos de la lista, comenzando desde el nodo nil.
 * El nodo nil se elimina al final.
 */
template <typename DataType>
DLList<DataType>::~DLList() {
  DLListNode<DataType>* current = nil->getNext();
  while (current != nil) {
    DLListNode<DataType>* toDelete = current;
    current = current->getNext();
    delete toDelete;
  }
  delete nil; // Elimina el nodo nil al final
}

/**
 * @brief Inserta un nuevo nodo con @param value al inicio de la lista.
 * Este método crea un nuevo nodo y lo inserta justo después del nodo nil.
 */
template <typename DataType>
void DLList<DataType>::insert(const DataType& value) {
  DLListNode<DataType>* newNode = new DLListNode<DataType>(value, nil->getNext(), nil);
  nil->getNext()->setPrev(newNode);
  nil->setNext(newNode);
}

/**
 * @brief Busca un nodo con @param value en la lista.
 * Este método recorre la lista desde el nodo nil y devuelve el primer nodo que coincide con el valor.
 */
template <typename DataType>
DLListNode<DataType>* DLList<DataType>::search(const DataType& value) const {
  DLListNode<DataType>* current = nil->getNext();
  while (current != nil) {
    if (current->getKey() == value) {
      return current;
    }
    current = current->getNext();
  }
  // Si llegó hasta acá, no encontró el valor
  return nullptr;
}

/**
 * @brief Elimina el primer nodo que contiene @param value de la lista.
 * Si el nodo no existe, no hace nada.
 */
template <typename DataType>
void DLList<DataType>::remove(const DataType& value) {
  // Busca el nodo con el valor especificado
  DLListNode<DataType>* nodeToRemove = search(value);
  if (nodeToRemove) {
    // Si lo encontró, lo elimina
    remove(nodeToRemove);
  }
}

/**
 * @brief Elimina un nodo específico de la lista.
 * Este método desvincula el nodo de la lista y lo elimina de la memoria.
 */
template <typename DataType>
void DLList<DataType>::remove(DLListNode<DataType>* node) {
  if (node == nil) {
    // Si es nil, no se elimina
    return; 
  }
  // Desvincula el nodo de la lista
  node->getPrev()->setNext(node->getNext());
  node->getNext()->setPrev(node->getPrev());
  // Elimina el nodo de la memoria
  delete node;
}

/**
 * @brief Getter para el nodo nil
 */
template <typename DataType>
DLListNode<DataType>* DLList<DataType>::getNil() const {
  return nil;
}