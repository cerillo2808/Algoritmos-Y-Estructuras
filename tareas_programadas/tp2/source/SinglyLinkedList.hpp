/*
 Credits
 Based on: Prof. Arturo Camacho, Universidad de Costa Rica
 Modified by: Prof. Allan Berrocal, Universidad de Costa Rica
*/

#pragma once
template <typename DataType>
class SLList;

template <typename DataType>
class SLListNode {
 public:
  friend class SLList<DataType>;

  SLListNode();

  SLListNode(const DataType& value, SLListNode<DataType>* next = nullptr);

  ~SLListNode();

  DataType getKey() const;

  SLListNode<DataType>* getNext() const;

  void setKey(DataType key);

  void setNext(SLListNode<DataType>* newNode);

 private:
  DataType key;

  SLListNode<DataType>* next;
};

// Implementación de SLListNode
template <typename DataType>
SLListNode<DataType>::SLListNode() : key(), next(nullptr) {}

template <typename DataType>
SLListNode<DataType>::SLListNode(const DataType& value, SLListNode<DataType>* next)
  : key(value), next(next) {}

template <typename DataType>
SLListNode<DataType>::~SLListNode() {}

template <typename DataType>
DataType SLListNode<DataType>::getKey() const {
  return key;
}

template <typename DataType>
SLListNode<DataType>* SLListNode<DataType>::getNext() const {
  return next;
}

template <typename DataType>
void SLListNode<DataType>::setKey(DataType key) {
  this->key = key;
}

template <typename DataType>
void SLListNode<DataType>::setNext(SLListNode<DataType>* newNode) {
  next = newNode;
}

template <typename DataType>
class SLList {
 public:
  SLList();

  ~SLList() {};

  void insert(const DataType& value);

  SLListNode<DataType>* search(const DataType& value) const;

  void remove(const DataType& value);

  SLListNode<DataType>* getNil() const;

 private:
  SLListNode<DataType>* nil;

};

// Implementación de SLList
/**
 * @brief Constructor de la lista enlazada simple. Inicializa nil a nullptr.
 */
template <typename DataType>
SLList<DataType>::SLList() : nil(nullptr) {}

template <typename DataType>
void SLList<DataType>::insert(const DataType& value) {
  SLListNode<DataType>* nuevoNodo = new SLListNode<DataType>(value, nullptr);
  if (nil == nullptr) {
    // Si la lista está vacía, nil es el nuevo nodo
    nil = nuevoNodo;
  } else {
    // Si la lista no está vacía, buscamos el último nodo
    SLListNode<DataType>* anterior = nil;
    while (anterior->getNext() != nullptr) {
      anterior = anterior->getNext();
    }
    anterior->setNext(nuevoNodo);
  }
}

template <typename DataType>
SLListNode<DataType>* SLList<DataType>::search(const DataType& value) const {
  SLListNode<DataType>* actual = nil;
  // Se empieza buscando desde la cabeza
  while (actual != nullptr) {
    if (actual->getKey() == value) {
      return actual;
    }
    // Se avanza al siguiente nodo
    actual = actual->getNext();
  }
  // Si llega hasta acá, no se encontró el valor
  return nullptr;
}

template <typename DataType>
void SLList<DataType>::remove(const DataType& value) {

  if (nil == nullptr){
    // La lista está vacía, no hay nada que eliminar
    return;
  }

  SLListNode<DataType>* actual = nil;

  // Verificar si el nodo a eliminar es nil
  if (nil->getKey() == value) {
    // Se actualiza nil al siguiente nodo
    nil = nil->getNext();
    // Liberar memoria del nodo eliminado
    delete actual; 
    return;
  }

  // Se ocupa una referencia al nodo anterior porque hay que modificar su siguiente
  SLListNode<DataType>* anterior = nullptr;

  // Se busca el nodo a eliminar
  while (actual != nullptr && actual->getKey() != value) {
    anterior = actual;
    actual = actual->getNext();
  }

  // Si se encontró el nodo
  if (actual != nullptr) {
    // Se salta el nodo a eliminar
    anterior->setNext(actual->getNext());
    // Liberar memoria del nodo eliminado
    delete actual;
  }
}

template <typename DataType>
SLListNode<DataType>* SLList<DataType>::getNil() const {
  return nil;
}
