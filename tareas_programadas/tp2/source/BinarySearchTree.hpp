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
/**
 * @brief Constructor de un nodo del árbol de búsqueda binaria.
 */
template <typename DataType>
BSTreeNode<DataType>::BSTreeNode(const DataType &value, BSTreeNode<DataType> *parent,
                                   BSTreeNode<DataType> *left, BSTreeNode<DataType> *right)
    : key(value), parent(parent), left(left), right(right) {}

/**
 * @brief Destructor de un nodo del árbol de búsqueda binaria.
 */
template <typename DataType>
BSTreeNode<DataType>::~BSTreeNode() {}

/**
 * @brief Getter para la key del nodo.
 */
template <typename DataType>
DataType BSTreeNode<DataType>::getKey() const {
  return key;
}

/**
 * @brief Getter para el padre del nodo.
 */
template <typename DataType>
BSTreeNode<DataType> *BSTreeNode<DataType>::getParent() const {
  return parent;
}

/**
 * @brief Getter para el hijo izquierdo del nodo.
 */
template <typename DataType>
BSTreeNode<DataType> *BSTreeNode<DataType>::getLeft() const {
  return left;
}

/**
 * @brief Getter para el hijo derecho del nodo.
 */
template <typename DataType>
BSTreeNode<DataType> *BSTreeNode<DataType>::getRight() const {
  return right;
}

/**
 * @brief Setter para el padre del nodo.
 */
template <typename DataType>
void BSTreeNode<DataType>::setParent(BSTreeNode<DataType>* parent) {
    this->parent = parent;
}

/**
 * @brief Setter para el hijo izquierdo del nodo.
 */
template <typename DataType>
void BSTreeNode<DataType>::setLeft(BSTreeNode<DataType>* left) {
    this->left = left;
}

/**
 * @brief Setter para el hijo derecho del nodo.
 */
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
  void buildBalanced(std::make_signed_t<DataType> left, std::make_signed_t<DataType> right);
};

// Implementación de BSTree
/**
 * @brief Constructor del árbol de búsqueda binaria.
 * Inicializa a root como nullptr.
 */
template <typename DataType>
BSTree<DataType>::BSTree() : root(nullptr) {}

/**
 * @brief inserta un nuevo nodo con el @param value
 * Revisa si el árbol está vacío, en caso de que sí, crea a la raíz.
 * Recorre el árbol para encontrar la posición adecuada.
 * Si el valor es menor que el nodo actual, se inserta a la izquierda.
 * Si el valor es mayor, se inserta a la derecha.
 * Por defecto, si el valor es igual, se inserta a la derecha.
 */
template <typename DataType>
void BSTree<DataType>::insert(const DataType &value) {
  BSTreeNode<DataType> *newNode = new BSTreeNode<DataType>(value);
  if (root == nullptr) {
    // Árbol vacío, el nuevo nodo se convierte en la raíz
    root = newNode;
    return;
  }

  BSTreeNode<DataType> *current = root;
  BSTreeNode<DataType> *parent = nullptr;

  // Recorre el árbol para encontrar la posición correcta
  while (current != nullptr) {
    parent = current;
    if (value < current->getKey()) {
      current = current->getLeft();
    } else {
      current = current->getRight();
    }
  }

  // Inserta el nuevo nodo como hijo del nodo padre encontrado
  newNode->setParent(parent);
  if (value < parent->getKey()) {
    parent->setLeft(newNode);
  } else {
    parent->setRight(newNode);
  }
}

/**
 * @brief Elimina un nodo con el valor @param value del árbol.
 * Busca el nodo a eliminar.
 * Revisa si el nodo a eliminar es una hoja, tiene un solo hijo o tiene dos hijos.
 * En caso de ser una hoja, simplemente se elimina.
 * Si tiene un solo hijo, se conecta el hijo al padre del nodo a eliminar.
 * Si tiene dos hijos, se busca el sucesor (el mínimo del subárbol derecho),
 * se elimina el sucesor y se reemplaza el valor del nodo a eliminar con el del sucesor.
 * Si el nodo a eliminar es la raíz y no tiene hijos, se establece la raíz como nullptr.
 */
template <typename DataType>
void BSTree<DataType>::remove(const DataType &value) {
  // Busca la nodo a eliminar
  BSTreeNode<DataType> *nodeToRemove = search(root, value);

  if (nodeToRemove == nullptr) {
    // Si no se encuentra el nodo, no se hace nada
    return;
  }

  if (nodeToRemove->getLeft() == nullptr && nodeToRemove->getRight() == nullptr) {
    // Caso 1: Nodo hoja
    if (nodeToRemove->getParent() == nullptr) {
      // Si el nodo a eliminar es la raíz y es una hoja, se establece la raíz como nullptr
      root = nullptr;

    } else if (nodeToRemove->getParent()->getLeft() == nodeToRemove) {
      // Si es el hijo izquierdo del padre, se establece el hijo izquierdo del padre como nullptr
      nodeToRemove->getParent()->setLeft(nullptr);

    } else {
      // Si es el hijo derecho del padre, se establece el hijo derecho del padre como nullptr
      nodeToRemove->getParent()->setRight(nullptr);
    }

    // Caso 2: Nodo con un solo hijo
  } else if (nodeToRemove->getLeft() == nullptr || nodeToRemove->getRight() == nullptr) {
    // Busca el hijo del nodo a eliminar
    BSTreeNode<DataType> *child = (nodeToRemove->getLeft() != nullptr) ? nodeToRemove->getLeft() : nodeToRemove->getRight();
    
    if (nodeToRemove->getParent() == nullptr) {
      // Si el nodo a eliminar es la raíz y tiene un hijo, se actualiza la raíz
      child->setParent(nullptr);

    } else if (nodeToRemove->getParent()->getLeft() == nodeToRemove) {
      // Si es el hijo izquierdo del padre, se conecta el hijo al padre del nodo a eliminar
      nodeToRemove->getParent()->setLeft(child);

    } else {
      // Si es el hijo derecho del padre, se conecta el hijo al padre del nodo a eliminar
      nodeToRemove->getParent()->setRight(child);

    }
    // Actualiza el padre del hijo para que apunte al padre del nodo a eliminar
    child->setParent(nodeToRemove->getParent());

  } else {
    // Caso 3: Nodo con dos hijos
    // Encuentra el sucesor (el mínimo del subárbol derecho)
    BSTreeNode<DataType> *successor = getSuccessor(nodeToRemove);
    // Intercambiar claves
    nodeToRemove->key = successor->getKey();

    // Eliminar el sucesor físicamente (que tendrá a lo sumo un hijo)
    if (successor->getParent()->getLeft() == successor) {
      // Si el sucesor es el hijo izquierdo del padre, se conecta el hijo derecho del sucesor al padre del sucesor
      successor->getParent()->setLeft(successor->getRight());
      // Si el sucesor tiene un hijo derecho, se actualiza su padre
      if (successor->getRight()) successor->getRight()->setParent(successor->getParent());
    } else {
      // Si el sucesor es el hijo derecho del padre, se conecta el hijo derecho del sucesor al padre del sucesor
      successor->getParent()->setRight(successor->getRight());
      // Si el sucesor tiene un hijo derecho, se actualiza su padre
      if (successor->getRight()) successor->getRight()->setParent(successor->getParent());
    }

    delete successor;
    return;
  }

  delete nodeToRemove;
}

/**
 * @brief Recorre el árbol en inorden e imprime los valores de los nodos.
 */
template <typename DataType>
void BSTree<DataType>::inorderWalk(BSTreeNode<DataType> *rootOfSubtree) const {
  if (rootOfSubtree != nullptr) {
    inorderWalk(rootOfSubtree->getLeft());
    std::cout << rootOfSubtree->getKey() << " ";
    inorderWalk(rootOfSubtree->getRight());
  }
}

/**
 * @brief Recorre el árbol en preorden e imprime los valores de los nodos.
 */
template <typename DataType>
void BSTree<DataType>::preorderWalk(BSTreeNode<DataType> *rootOfSubtree) const {
  if (rootOfSubtree != nullptr) {
    std::cout << rootOfSubtree->getKey() << " ";
    preorderWalk(rootOfSubtree->getLeft());
    preorderWalk(rootOfSubtree->getRight());
  }
}

/**
 * @brief Recorre el árbol en postorden e imprime los valores de los nodos.
 */
template <typename DataType>
void BSTree<DataType>::postorderWalk(BSTreeNode<DataType> *rootOfSubtree) const {
  if (rootOfSubtree != nullptr) {
    postorderWalk(rootOfSubtree->getLeft());
    postorderWalk(rootOfSubtree->getRight());
    std::cout << rootOfSubtree->getKey() << " ";
  }
}

/**
 * @brief Busca un nodo con el valor @param value en el subárbol
 * @param rootOfSubtree es la raíz del subárbol en donde se busca
 * @return un puntero al nodo encontrado o nullptr si no está en el subárbol
 * Recorre el árbol comparando el valor del nodo actual con el valor buscado.
 * Si el valor es igual, retorna el nodo actual.
 * Si el valor es menor, se busca en el subárbol izquierdo.
 * Si el valor es mayor, se busca en el subárbol derecho.
 */
template <typename DataType>
BSTreeNode<DataType> *BSTree<DataType>::search(const BSTreeNode<DataType> *rootOfSubtree,
                                                  const DataType &value) const {
  BSTreeNode<DataType> *current = const_cast<BSTreeNode<DataType> *>(rootOfSubtree);
  // Recorre el árbol
  while (current != nullptr) {
    if (value == current->getKey()) {
      // Si es igual, retorna el nodo
      return const_cast<BSTreeNode<DataType> *>(current);

    } else if (value < current->getKey()) {
      // Si es menor, busca en el subárbol izquierdo
      current = current->getLeft();

    } else {
      // Si es mayor, busca en el subárbol derecho
      current = current->getRight();
    }
  }
  // Si llega acá es porque no se encontró el valor
  return nullptr;
}

/**
 * @brief Obtiene el nodo con el valor mínimo en el subárbol
 * @param rootOfSubtree es la raíz del subárbol en donde se busca
 * El menor se encuentra en el extremo izquierdo del subárbol
 */
template <typename DataType>
BSTreeNode<DataType> *BSTree<DataType>::getMinimum(
    const BSTreeNode<DataType> *rootOfSubtree) const {
  if (rootOfSubtree == nullptr) {
    // Si el subárbol es nulo, no hay mínimo
    return nullptr;
  }
  const BSTreeNode<DataType> *current = rootOfSubtree;
  while (current->getLeft() != nullptr) {
    // Recorre hacia la izquierda hasta encontrar el nodo más a la izquierda
    current = current->getLeft();
  }
  return const_cast<BSTreeNode<DataType> *>(current);
}

/**
 * @brief Obtiene el nodo con el valor máximoel subárbol
 * @param rootOfSubtree es la raíz del subárbol en donde se busca
 * El mayor ncuentra en el extremo derecho del árbol
 */
template <typename DataType>
BSTreeNode<DataType> *BSTree<DataType>::getMaximum(
    const BSTreeNode<DataType> *rootOfSubtree) const {
  if (rootOfSubtree == nullptr) {
    // Si el subárbol es nulo, no hay máximo
    return nullptr;
  }
  const BSTreeNode<DataType> *current = rootOfSubtree;
  while (current->getRight() != nullptr) {
    // Recorre hacia la derecha hasta encontrar el nodo más a la derecha
    current = current->getRight();
  }
  return const_cast<BSTreeNode<DataType> *>(current);
}

/**
 * @brief Obtiene el sucesor de @param node
 * El sucesor es el nodo con el valor más pequeño en el subárbol derecho del nodo dado.
 * Si el nodo no tiene un subárbol derecho, se busca hacia arriba en el árbol
 * hasta encontrar un nodo que sea el hijo izquierdo de su padre.
 */
template <typename DataType>
BSTreeNode<DataType> *BSTree<DataType>::getSuccessor(
    const BSTreeNode<DataType> *node) const {
  if (node->getRight() != nullptr) {
    // Si el nodo tiene un subárbol derecho, el sucesor es el mínimo del subárbol derecho
    return getMinimum(node->getRight());
  }

  BSTreeNode<DataType> *current = node->getParent();
  while (current != nullptr && node == current->getRight()) {
    // Recorre hacia arriba hasta encontrar un nodo que sea el hijo izquierdo de su padre
    node = current;
    current = current->getParent();
  }
  // Si llega acá es porque no hay un sucesor
  return current;
}

/**
 * @brief Getter para la raíz del árbol
 */
template <typename DataType>
BSTreeNode<DataType>* BSTree<DataType>::getRoot() const {
    return root;
}

/**
 * @brief Inserta @param n cantidad de nodos al árbol.
 * Inserta los valores desde 0 hasta n-1 de manera balanceada.
 */
template <typename DataType>
void BSTree<DataType>::fastInsert(size_t n) {
  if (n == 0){
    // Si n es 0, no hay nada que insertar
    return;
  }
  // Utiliza signed para manejar correctamente los índices negativos
  using Signed = std::make_signed_t<DataType>;
  // Llama a la función recursiva para construir el árbol balanceado
  buildBalanced(static_cast<Signed>(0), static_cast<Signed>(n - 1));
}

/**
 * @brief Construye un árbol balanceado insertando valores desde @param left hasta @param right.
 * Divide el rango en dos mitades, inserta el valor del medio y luego construye recursivamente.
 */
template <typename DataType>
void BSTree<DataType>::buildBalanced(std::make_signed_t<DataType> left, std::make_signed_t<DataType> right) {
  if (left > right) {
    // Si el rango es inválido, no hay más nodos que insertar
    return;
  }
  
  // Calcula el valor medio y lo inserta en el árbol
  auto mid = left + (right - left) / 2;
  insert(static_cast<DataType>(mid));

  // Hace lo mismo para las mitades izquierda y derecha
  buildBalanced(left, mid - 1);
  buildBalanced(mid + 1, right);
}