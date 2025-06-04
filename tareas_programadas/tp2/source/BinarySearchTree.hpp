/*
 Credits
 Based on: Prof. Arturo Camacho, Universidad de Costa Rica
 Modified by: Prof. Allan Berrocal, Universidad de Costa Rica
 */

#pragma once
#include <cstddef>

template <typename DataType>
class BSTree;

template <typename DataType>
class BSTreeNode {
 public:
  friend class BSTree<DataType>;

  BSTreeNode() = default;

  BSTreeNode(const DataType &value, BSTreeNode<DataType> *parent = nullptr,
             BSTreeNode<DataType> *left = nullptr,
             BSTreeNode<DataType> *right = nullptr);

  ~BSTreeNode();

  DataType getKey() const;

  BSTreeNode<DataType> *getParent() const;

  BSTreeNode<DataType> *getLeft() const;

  BSTreeNode<DataType> *getRight() const;

  void setParent(BSTreeNode<DataType> *parent);

  void setLeft(BSTreeNode<DataType> *left);

  void setRight(BSTreeNode<DataType> *right);

 private:
  DataType key;

  BSTreeNode<DataType> *parent = nullptr;

  BSTreeNode<DataType> *left = nullptr;

  BSTreeNode<DataType> *right = nullptr;
};

// Implementación de BSTreeNode
template <typename DataType>
BSTreeNode<DataType>::BSTreeNode(const DataType &value, BSTreeNode<DataType> *parent,
                                   BSTreeNode<DataType> *left, BSTreeNode<DataType> *right)
    : key(value), parent(parent), left(left), right(right) {}

template <typename DataType>
BSTreeNode<DataType>::~BSTreeNode() {}

template <typename DataType>
DataType BSTreeNode<DataType>::getKey() const {
  return key;
}

template <typename DataType>
BSTreeNode<DataType> *BSTreeNode<DataType>::getParent() const {
  return parent;
}

template <typename DataType>
BSTreeNode<DataType> *BSTreeNode<DataType>::getLeft() const {
  return left;
}

template <typename DataType>
BSTreeNode<DataType> *BSTreeNode<DataType>::getRight() const {
  return right;
}

template <typename DataType>
void BSTreeNode<DataType>::setParent(BSTreeNode<DataType>* parent) {
    this->parent = parent;
}

template <typename DataType>
void BSTreeNode<DataType>::setLeft(BSTreeNode<DataType>* left) {
    this->left = left;
}

template <typename DataType>
void BSTreeNode<DataType>::setRight(BSTreeNode<DataType>* right) {
    this->right = right;
}

template <typename DataType>
class BSTree {
 public:
  BSTree();

  ~BSTree() {};

  void insert(const DataType &value);

  void remove(const DataType &value);

  void inorderWalk(BSTreeNode<DataType> *rootOfSubtree) const;

  void preorderWalk(BSTreeNode<DataType> *rootOfSubtree) const;

  void postorderWalk(BSTreeNode<DataType> *rootOfSubtree) const;

  BSTreeNode<DataType> *search(const BSTreeNode<DataType> *rootOfSubtree,
                               const DataType &value) const;

  BSTreeNode<DataType> *getMinimum(
      const BSTreeNode<DataType> *rootOfSubtree) const;

  BSTreeNode<DataType> *getMaximum(
      const BSTreeNode<DataType> *rootOfSubtree) const;

  BSTreeNode<DataType> *getSuccessor(const BSTreeNode<DataType> *node) const;

  BSTreeNode<DataType> *getRoot() const;

  void fastInsert(size_t n);
  
 private:
  BSTreeNode<DataType> *root;
  void buildBalanced(DataType left, DataType right);
};

// Implementación de BSTree

template <typename DataType>
BSTree<DataType>::BSTree() : root(nullptr) {}

template <typename DataType>
void BSTree<DataType>::insert(const DataType &value) {
  BSTreeNode<DataType> *newNode = new BSTreeNode<DataType>(value);
  if (root == nullptr) {
    root = newNode;
    return;
  }

  BSTreeNode<DataType> *current = root;
  BSTreeNode<DataType> *parent = nullptr;

  while (current != nullptr) {
    parent = current;
    if (value < current->getKey()) {
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }

  newNode->setParent(parent);
  if (value < parent->getKey()) {
    parent->setLeft(newNode);
  } else {
    parent->setRight(newNode);
  }
}

template <typename DataType>
void BSTree<DataType>::remove(const DataType &value) {
  BSTreeNode<DataType> *nodeToRemove = search(root, value);
  if (nodeToRemove == nullptr) {
    return; // El valor no se encuentra en el árbol
  }

  if (nodeToRemove->getLeft() == nullptr && nodeToRemove->getRight() == nullptr) {
    // Caso 1: Nodo hoja
    if (nodeToRemove->getParent() == nullptr) {
      root = nullptr; // Árbol vacío
    } else if (nodeToRemove->getParent()->getLeft() == nodeToRemove) {
      nodeToRemove->getParent()->setLeft(nullptr);
    } else {
      nodeToRemove->getParent()->setRight(nullptr);
    }
  } else if (nodeToRemove->getLeft() == nullptr || nodeToRemove->getRight() == nullptr) {
    // Caso 2: Nodo con un solo hijo
    BSTreeNode<DataType> *child = (nodeToRemove->getLeft() != nullptr) ? nodeToRemove->getLeft() : nodeToRemove->getRight();
    if (nodeToRemove->getParent() == nullptr) {
      root = child; // Actualizar la raíz del árbol
      child->setParent(nullptr);
    } else if (nodeToRemove->getParent()->getLeft() == nodeToRemove) {
      nodeToRemove->getParent()->setLeft(child);
    } else {
      nodeToRemove->getParent()->setRight(child);
    }
    child->setParent(nodeToRemove->getParent());
  } else {
    // Caso 3: Nodo con dos hijos
    BSTreeNode<DataType> *successor = getSuccessor(nodeToRemove);
    DataType successorValue = successor->getKey();
    remove(successorValue); // Eliminar el sucesor
    nodeToRemove->key = successorValue; // Reemplazar el valor del nodo a eliminar
  }

  delete nodeToRemove;
}

template <typename DataType>
void BSTree<DataType>::inorderWalk(BSTreeNode<DataType> *rootOfSubtree) const {
  if (rootOfSubtree != nullptr) {
    inorderWalk(rootOfSubtree->getLeft());
    std::cout << rootOfSubtree->getKey() << " ";
    inorderWalk(rootOfSubtree->getRight());
  }
}

template <typename DataType>
void BSTree<DataType>::preorderWalk(BSTreeNode<DataType> *rootOfSubtree) const {
  if (rootOfSubtree != nullptr) {
    std::cout << rootOfSubtree->getKey() << " ";
    preorderWalk(rootOfSubtree->getLeft());
    preorderWalk(rootOfSubtree->getRight());
  }
}

template <typename DataType>
void BSTree<DataType>::postorderWalk(BSTreeNode<DataType> *rootOfSubtree) const {
  if (rootOfSubtree != nullptr) {
    postorderWalk(rootOfSubtree->getLeft());
    postorderWalk(rootOfSubtree->getRight());
    std::cout << rootOfSubtree->getKey() << " ";
  }
}

template <typename DataType>
BSTreeNode<DataType> *BSTree<DataType>::search(const BSTreeNode<DataType> *rootOfSubtree,
                                                  const DataType &value) const {
  BSTreeNode<DataType> *current = rootOfSubtree;
  while (current != nullptr) {
    if (value == current->getKey()) {
      return const_cast<BSTreeNode<DataType> *>(current);
    } else if (value < current->getKey()) {
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }
  return nullptr; // No se encontró el valor
}

template <typename DataType>
BSTreeNode<DataType> *BSTree<DataType>::getMinimum(
    const BSTreeNode<DataType> *rootOfSubtree) const {
  if (rootOfSubtree == nullptr) {
    return nullptr;
  }
  const BSTreeNode<DataType> *current = rootOfSubtree;
  while (current->getLeft() != nullptr) {
    current = current->getLeft();
  }
  return const_cast<BSTreeNode<DataType> *>(current);
}

template <typename DataType>
BSTreeNode<DataType> *BSTree<DataType>::getMaximum(
    const BSTreeNode<DataType> *rootOfSubtree) const {
  if (rootOfSubtree == nullptr) {
    return nullptr;
  }
  const BSTreeNode<DataType> *current = rootOfSubtree;
  while (current->getRight() != nullptr) {
    current = current->getRight();
  }
  return const_cast<BSTreeNode<DataType> *>(current);
}

template <typename DataType>
BSTreeNode<DataType> *BSTree<DataType>::getSuccessor(
    const BSTreeNode<DataType> *node) const {
  if (node->getRight() != nullptr) {
    return getMinimum(node->getRight());
  }

  BSTreeNode<DataType> *current = node->getParent();
  while (current != nullptr && node == current->getRight()) {
    node = current;
    current = current->getParent();
  }
  return current; // Puede ser nullptr si no hay sucesor
}

template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::getRoot() const {
    return root;
}

template <typename DataType>
void BSTree<DataType>::fastInsert(size_t n) {
  if (n == 0) return;
  buildBalanced(0, static_cast<DataType>(n - 1));
}

template <typename DataType>
void BSTree<DataType>::buildBalanced(DataType left, DataType right) {
  if (left > right) return;
  DataType mid = left + (right - left) / 2;
  insert(mid);  // inserta el valor medio
  buildBalanced(left, mid - 1);   // lado izquierdo
  buildBalanced(mid + 1, right);  // lado derecho
}