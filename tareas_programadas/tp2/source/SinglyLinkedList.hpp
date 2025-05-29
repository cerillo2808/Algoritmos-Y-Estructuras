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
  SLList() = default;

  ~SLList() {};

  void insert(const DataType& value);

  SLListNode<DataType>* search(const DataType& value) const;

  void remove(const DataType& value);

  SLListNode<DataType>* getNil() const;
  
 private:
  SLListNode<DataType>* nil;

};

// Implementación de SLList
template <typename DataType>
void SLList<DataType>::insert(const DataType& value) {
  //TODO
}

template <typename DataType>
SLListNode<DataType>* SLList<DataType>::search(const DataType& value) const {
  //TODO
  return nullptr;
}

template <typename DataType>
void SLList<DataType>::remove(const DataType& value) {
  //TODO
}

template <typename DataType>
SLListNode<DataType>* SLList<DataType>::getNil() const {
  return nil;
}