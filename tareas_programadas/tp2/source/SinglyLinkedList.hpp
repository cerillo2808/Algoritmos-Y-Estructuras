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

/**
 * @brief Inserta un nuevo nodo con el valor dado al inicio de la lista.
 * Crea un nuevo nodo y lo convierte en el nuevo nil si la lista está vacía.
 * Si la lista no está vacía, agrega el nuevo nodo al inicio de la lista.
 * @param value El valor a insertar en la lista.
 */
template <typename DataType>
void SLList<DataType>::insert(const DataType& value) {
  SLListNode<DataType>* nuevoNodo = new SLListNode<DataType>(value, nullptr);
  if (nil == nullptr) {
    // Si la lista está vacía, nil es el nuevo nodo
    nil = nuevoNodo;
  } else {
    // Si la lista no está vacía, el nuevo nodo se vuelve nil y apunta al antiguo nil
    SLListNode<DataType>* temp = nil;
    nil = nuevoNodo;
    nil->setNext(temp);
  }
}

/**
 * @brief Busca un nodo con el valor dado en la lista.
 * Recorre la lista desde nil hasta encontrar el nodo con la misma clave.
 * Si llega al final de la lista sin encontrar el valor, retorna nullptr.
 * @param value El valor a buscar en la lista.
 */
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

/**
 * @brief Elimina el primer nodo con el valor dado de la lista.
 * Si el nodo a eliminar es nil, se actualiza nil al siguiente nodo.
 * Si no se encuentra el nodo, no se hace nada.
 * @param value El valor del nodo a eliminar de la lista.
 */
template <typename DataType>
void SLList<DataType>::remove(const DataType& value) {

  if (nil == nullptr){
    // La lista está vacía, no hay nada que eliminar
    return;
  }

  // Se empieza buscando desde nil
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

/**
 * @brief Getter para nil de la lista.
 */
template <typename DataType>
SLListNode<DataType>* SLList<DataType>::getNil() const {
  return nil;
}
