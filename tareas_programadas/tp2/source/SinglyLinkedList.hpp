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
/**
 * @brief Constructor de un nodo de la lista enlazada simple.
 * Inicializa el nodo con una clave nula y el siguiente nodo como nullptr.
 */
template <typename DataType>
SLListNode<DataType>::SLListNode() : key(), next(nullptr) {}

/**
 * @brief Constructor de un nodo de la lista enlazada simple.
 * @param value El valor a almacenar en el nodo.
 * @param next El siguiente nodo en la lista (por defecto es nullptr).
 */
template <typename DataType>
SLListNode<DataType>::SLListNode(const DataType& value, SLListNode<DataType>* next)
  : key(value), next(next) {}

/**
 * @brief Destructor de un nodo de la lista enlazada simple.
 */
template <typename DataType>
SLListNode<DataType>::~SLListNode() {}

/**
 * @brief Getter para la key del nodo.
 */
template <typename DataType>
DataType SLListNode<DataType>::getKey() const {
  return key;
}

/**
 * @brief Getter para el siguiente nodo en la lista.
 */
template <typename DataType>
SLListNode<DataType>* SLListNode<DataType>::getNext() const {
  return next;
}

/**
 * @brief Setter para la key del nodo.
 */
template <typename DataType>
void SLListNode<DataType>::setKey(DataType key) {
  this->key = key;
}

/**
 * @brief Setter para el siguiente nodo en la lista.
 */
template <typename DataType>
void SLListNode<DataType>::setNext(SLListNode<DataType>* newNode) {
  next = newNode;
}

template <typename DataType>
class SLList {
 public:
  SLList();

  ~SLList();

  void insert(const DataType& value);

  SLListNode<DataType>* search(const DataType& value) const;

  void remove(const DataType& value);

  SLListNode<DataType>* getNil() const;

 private:
  SLListNode<DataType>* nil;

};

// Implementación de SLList
/**
 * @brief Constructor de la lista enlazada simple. Inicializa el nodo centinela.
 */
template <typename DataType>
SLList<DataType>::SLList() {
  nil = new SLListNode<DataType>();
  nil->setNext(nullptr);
}

/**
 * @brief Destructor de la lista enlazada simple. Elimina todos los nodos.
 * Recorre la lista desde el nodo centinela y elimina cada nodo hasta llegar al final.
 */
template <typename DataType>
SLList<DataType>::~SLList() {
  SLListNode<DataType>* actual = nil->getNext();
  SLListNode<DataType>* siguiente;

  // Recorre la lista y elimina cada nodo
  while (actual != nullptr) {
    siguiente = actual->getNext();
    delete actual;
    actual = siguiente;
  }
  // Elimina el nodo centinela
  delete nil;
}

/**
 * @brief Inserta un nuevo nodo con @param value al inicio de la lista.
 * Si la lista no está vacía, agrega el nuevo nodo al inicio de la lista.
 */
template <typename DataType>
void SLList<DataType>::insert(const DataType& value) {
  SLListNode<DataType>* nuevo = new SLListNode<DataType>(value);
  nuevo->setNext(nil->getNext());
  // Se inserta después del nodo centinela
  nil->setNext(nuevo);
}

/**
 * @brief Busca un nodo con el valor @param value en la lista.
 * Recorre la lista desde nil hasta encontrar el nodo con la misma clave.
 * Si llega al final de la lista sin encontrar el valor, retorna nullptr.
 */
template <typename DataType>
SLListNode<DataType>* SLList<DataType>::search(const DataType& value) const {

  SLListNode<DataType>* actual = nil->getNext();
  // Se empieza buscando después de la centinela
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

/**
 * @brief Elimina todos los nodos con el valor @param value de la lista.
 * Recorre la lista desde nil hasta encontrar el nodo con la misma clave.
 * Si lo encuentra, lo elimina y actualiza el puntero del nodo anterior.
 * Sigue recorriendo la lista hasta el final para eliminar todos los nodos con ese valor.
 */
template <typename DataType>
void SLList<DataType>::remove(const DataType& value) {

  if (!nil) {
    // Si la lista está vacía, no hay nada que eliminar
    return;
  }

  SLListNode<DataType>* anterior = nil;
  SLListNode<DataType>* actual = nil->getNext();

  // Se empieza buscando después de la centinela
  // Recorre la lista hasta el final
  while (actual != nullptr) {
    if (actual->getKey() == value) {
      // Si se encuentra el nodo a eliminar, se actualiza el puntero del nodo anterior
      anterior->setNext(actual->getNext());
      delete actual;
      // Se mantiene para seguir recorriendo la lista
      actual = anterior->getNext();
    } else {
      // Si no se encuentra el nodo a eliminar, se avanza al siguiente nodo
      anterior = actual;
      actual = actual->getNext();
    }
  }
}

/**
 * @brief Getter para nil de la lista.
 */
template <typename DataType>
SLListNode<DataType>* SLList<DataType>::getNil() const {
  return nil;
}
