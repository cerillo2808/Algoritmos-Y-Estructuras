/*
 Credits
 Based on: Prof. Arturo Camacho, Universidad de Costa Rica
 Modified by: Prof. Allan Berrocal, Universidad de Costa Rica
*/

#pragma once

enum colors { RED, BLACK };

template <typename DataType>
class RBTree;

template <typename DataType>
class RBTreeNode {
 public:
  friend class RBTree<DataType>;

  RBTreeNode() = default;

  RBTreeNode(const DataType &value, RBTreeNode<DataType> *parent = nullptr,
             RBTreeNode<DataType> *left = nullptr,
             RBTreeNode<DataType> *right = nullptr, enum colors c = RED);

  ~RBTreeNode();

  DataType getKey() const;

  RBTreeNode<DataType> *getParent() const;

  RBTreeNode<DataType> *getLeft() const;

  RBTreeNode<DataType> *getRight() const;

  void setKey(DataType key);

  void setParent(RBTreeNode<DataType> *parent);

  void setLeft(RBTreeNode<DataType> *left);

  void setRight(RBTreeNode<DataType> *right);

 private:
  DataType key;

  RBTreeNode<DataType> *parent;

  RBTreeNode<DataType> *left;

  RBTreeNode<DataType> *right;

  enum colors color;
};

// Implementación de RBTreeNode
/**
 * @brief Constructor de un nodo del árbol rojinegro
 */
template <typename DataType>
RBTreeNode<DataType>::RBTreeNode(const DataType &value, RBTreeNode<DataType> *parent,
                                   RBTreeNode<DataType> *left, RBTreeNode<DataType> *right, enum colors c)
    : key(value), parent(parent), left(left), right(right), color(c) {}

/**
 * @brief Destructor de un nodo del árbol rojinegro
 */
template <typename DataType>
RBTreeNode<DataType>::~RBTreeNode() {}

/**
 * @brief Getter para la clave del nodo
 */
template <typename DataType>
DataType RBTreeNode<DataType>::getKey() const {
  return key;
}

/**
 * @brief Getter para el padre del nodo
 */
template <typename DataType>
RBTreeNode<DataType> *RBTreeNode<DataType>::getParent() const {
  return parent;
}

/**
 * @brief Getter para el hijo izquierdo del nodo
 */
template <typename DataType>
RBTreeNode<DataType> *RBTreeNode<DataType>::getLeft() const {
  return left;
}

/**
 * @brief Getter para el hijo derecho del nodo
 */
template <typename DataType>
RBTreeNode<DataType> *RBTreeNode<DataType>::getRight() const {
  return right;
}

/**
 * @brief Setter para la clave del nodo
 */
template <typename DataType>
void RBTreeNode<DataType>::setKey(DataType key) {
  this->key = key;
}

/**
 * @brief Setter para el padre del nodo
 */
template <typename DataType>
void RBTreeNode<DataType>::setParent(RBTreeNode<DataType> *parent) {
  this->parent = parent;
}

/**
 * @brief Setter para el hijo izquierdo del nodo
 */
template <typename DataType>
void RBTreeNode<DataType>::setLeft(RBTreeNode<DataType> *left) {
  this->left = left;
}

/**
 * @brief Setter para el hijo derecho del nodo
 */
template <typename DataType>
void RBTreeNode<DataType>::setRight(RBTreeNode<DataType> *right) {
  this->right = right;
}

template <typename DataType>
class RBTree {
 public:
  RBTree();

  ~RBTree();

  void insert(const DataType &value);

  void remove(const DataType &value);

  RBTreeNode<DataType> *search(const RBTreeNode<DataType> *rootOfSubtree,
                               const DataType &value) const;

  RBTreeNode<DataType> *getMinimum(
      const RBTreeNode<DataType> *rootOfSubtree) const;

  RBTreeNode<DataType> *getMaximum(
      const RBTreeNode<DataType> *rootOfSubtree) const;

  RBTreeNode<DataType> *getSuccessor(const RBTreeNode<DataType> *node) const;

  RBTreeNode<DataType> *getRoot() const;

  RBTreeNode<DataType> *getNil() const;


 private:
  RBTreeNode<DataType> *root;

  RBTreeNode<DataType> *nil;

  void leftRotate(RBTreeNode<DataType> *x);
  void rightRotate(RBTreeNode<DataType> *y);
  void transplant(RBTreeNode<DataType> *u, RBTreeNode<DataType> *v);
  void insertFixup(RBTreeNode<DataType> *z);
  void removeFixup(RBTreeNode<DataType> *x);
  void destroyRecursive(RBTreeNode<DataType>* node);
};

// Implementación de RBTree
/**
 * @brief Constructor de un árbol rojinegro
 * Inicializa el nodo nil y establece la raíz como nil
 * El color del nodo nil es BLACK
 */
template <typename DataType>
RBTree<DataType>::RBTree() {
  nil = new RBTreeNode<DataType>();
  nil->color = BLACK;
  root = nil;
}

/**
 * @brief Destructor del árbol rojinegro
 * Destruye recursivamente todos los nodos del árbol
 * El nodo centinela se elimina al final
 */
template <typename DataType>
RBTree<DataType>::~RBTree() {
  if (root != nil) {
    destroyRecursive(root);
  }
  // El centinela nil se elimina al final
  delete nil;
  root = nullptr;
  nil = nullptr;
}

/**
 * @brief Destruye recursivamente los nodos del árbol
 * @param node El nodo actual a destruir
 * Recorre el árbol en postorden y elimina cada nodo
 * No destruye el nodo centinela nil, ya que es un nodo especial
 */
template <typename DataType>
void RBTree<DataType>::destroyRecursive(RBTreeNode<DataType>* node) {
  if (node == nil) {
    // Es el nodo centinela nil, no se destruye
    return;
  }

  destroyRecursive(node->left);
  destroyRecursive(node->right);
  delete node;
}

/**
 * @brief Inserta @param n en el árbol rojinegro
 * Crea un nuevo nodo con el valor dado, lo inserta en el árbol como un nodo rojo
 * siguiendo el procedimiento estándar de inserción en un árbol binario de búsqueda
 * Luego llama a un proceso de corrección para mantener las propiedades del árbol rojinegro
 * No se permiten duplicados, si el valor ya existe, no se inserta
 */
template <typename DataType>
void RBTree<DataType>::insert(const DataType& value) {
  RBTreeNode<DataType>* z = new RBTreeNode<DataType>(value, nullptr, nil, nil, RED);
  RBTreeNode<DataType>* y = nil;
  RBTreeNode<DataType>* x = root;

  // Encuentra la posición correcta para insertar el nuevo nodo
  while (x != nil) {
    y = x;
    if (z->key < x->key) {
      x = x->left;
    } else {
      x = x->right;
    }
  }

  // Inserta el nuevo nodo
  z->parent = y;
  if (y == nil) {
    // Si el árbol estaba vacío, z se convierte en la raíz
    root = z;

  } else if (z->key < y->key) {
    // Si z es menor que y, se inserta a la izquierda
    y->left = z;

  } else if (z->key > y->key) {
    // Si z es mayor que y, se inserta a la derecha
    y->right = z;
  } else {
    // Si z ya existe, no se inserta (no se permiten duplicados)
    delete z;
    return;
  }

  // Inicializa los hijos izquierdo y derecho de z como nil
  // Establece el color de z como RED
  z->left = nil;
  z->right = nil;
  z->color = RED;

  // Llama al proceso de corrección para mantener las propiedades del árbol rojinegro
  insertFixup(z);
}

/**
 * @brief Elimina @param value con el valor dado del árbol rojinegro
 * Busca el nodo a eliminar, si no se encuentra, no hace nada
 * Si no tiene hijos, simplemente lo elimina
 * Si tiene un hijo, lo reemplaza por su hijo
 * Si tiene dos hijos, encuentra el sucesor (el mínimo del subárbol derecho),
 * lo reemplaza por el nodo a eliminar y elimina el sucesor
 */
template <typename DataType>
void RBTree<DataType>::remove(const DataType& value) {
  // Busca el nodo a eliminar
  RBTreeNode<DataType>* z = search(root, value);
  if (z == nil) {
    // Si no se encuentra el nodo, no se hace nada
    return;
  }

  // Guarda el nodo a eliminar y su color original
  RBTreeNode<DataType>* y = z;
  RBTreeNode<DataType>* x;
  enum colors yOriginalColor = y->color;

  // Caso 1: Nodo a eliminar es una hoja o tiene un solo hijo
  if (z->left == nil) {
    // Reemplaza z con su hijo derecho (puede ser nil)
    x = z->right;
    transplant(z, z->right);

  } else if (z->right == nil) {
    // Si no tiene hijo derecho, se reemplaza por su hijo izquierdo
    x = z->left;
    transplant(z, z->left);

  } else {
    // Caso 2: Nodo a eliminar tiene dos hijos
    // Encuentra el sucesor y (el mínimo del subárbol derecho)
    y = getMinimum(z->right);
    yOriginalColor = y->color;
    x = y->right;
    if (y->parent == z) {
      // Si y es hijo directo de z, se enlaza el hijo de y con y
      x->parent = y;
    } else {
      // Reemplaza y por su hijo derecho
      transplant(y, y->right);
      y->right = z->right;
      y->right->parent = y;
    }

    // Reemplaza el nodo a eliminar con el sucesor
    transplant(z, y);
    y->left = z->left;
    y->left->parent = y;
    y->color = z->color;
  }

  if (yOriginalColor == BLACK) {
    // Si el color original del nodo eliminado era BLACK, se debe hacer un proceso de corrección
    removeFixup(x);
  }

  delete z;
}

/**
 * @brief Busca un nodo con el valor @param value en el subárbol
 * Recorre el árbol comparando el valor con las claves de los nodos
 * Si encuentra el nodo, lo devuelve; si no, devuelve nil
 * @param rootOfSubtree El nodo raíz del subárbol donde se busca
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::search(const RBTreeNode<DataType>* rootOfSubtree, const DataType& value) const {
  RBTreeNode<DataType>* current = const_cast<RBTreeNode<DataType>*>(rootOfSubtree);
  // Recorre el árbol buscando el valor
  while (current != nil && value != current->key) {
    if (value < current->key) {
      // Si el valor es menor, busca en el subárbol izquierdo
      current = current->left;
    } else {
      // Si el valor es mayor, busca en el subárbol derecho
      current = current->right;
    }
  }
  // Si llega acá es porque encontró el nodo o llegó al nil
  return current;
}

/**
 * @brief Obtiene el nodo con el valor mínimo en el subárbol
 * @param rootOfSubtree es la raíz del subárbol en donde se busca
 * El menor se encuentra en el extremo izquierdo del árbol
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::getMinimum(const RBTreeNode<DataType>* rootOfSubtree) const {
  RBTreeNode<DataType>* current = const_cast<RBTreeNode<DataType>*>(rootOfSubtree);
  // Recorre hacia la izquierda hasta encontrar el nodo más a la izquierda
  while (current->left != nil) {
    current = current->left;
  }
  return current;
}

/**
 * @brief Obtiene el nodo con el valor máximo en el subárbol
 * @param rootOfSubtree es la raíz del subárbol en donde se busca
 * El mayor se encuentra en el extremo derecho del árbol
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::getMaximum(const RBTreeNode<DataType>* rootOfSubtree) const {
  RBTreeNode<DataType>* current = const_cast<RBTreeNode<DataType>*>(rootOfSubtree);
  // Recorre hacia la derecha hasta encontrar el nodo más a la derecha
  while (current->right != nil) {
    current = current->right;
  }
  return current;
}

/**
 * @brief Obtiene el sucesor de @param node
 * El sucesor es el nodo con el valor más pequeño en el subárbol derecho del nodo dado.
 * Si no tiene subárbol derecho, recorre hacia arriba hasta encontrar un nodo que sea el hijo izquierdo de su padre.
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::getSuccessor(const RBTreeNode<DataType>* node) const {

  RBTreeNode<DataType>* n = const_cast<RBTreeNode<DataType>*>(node);
  if (n->right != nil) {
    // Si tiene subárbol derecho, el sucesor es el mínimo del subárbol derecho
    return getMinimum(n->right);
  }
  // Si no tiene subárbol derecho, recorre hacia arriba
  RBTreeNode<DataType>* y = n->parent;
  while (y != nil && n == y->right) {
    // Sigue subiendo hasta encontrar un nodo que sea el hijo izquierdo de su padre
    n = y;
    y = y->parent;
  }
  return y;
}

/**
 * @brief Getter de la raíz del árbol rojinegro
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::getRoot() const {
  return root;
}

/**
 * @brief Getter del nodo nil
 */
template <typename DataType>
RBTreeNode<DataType>* RBTree<DataType>::getNil() const {
  return nil;
}

/**
 * @brief Realiza una rotación a la izquierda en el nodo @param x
 * Mueve el nodo @param x hacia abajo y su hijo derecho hacia arriba.
 */
template <typename DataType>
void RBTree<DataType>::leftRotate(RBTreeNode<DataType> *x) {
  RBTreeNode<DataType> *y = x->right;
  x->right = y->left;
  if (y->left != nil) {
    // Si y tiene un hijo izquierdo, lo actualiza
    y->left->parent = x;
  }
  y->parent = x->parent;
  if (x->parent == nil) {
    // Si x es la raíz, y se convierte en la nueva raíz
    root = y;
  } else if (x == x->parent->left) {
    // Si x es el hijo izquierdo de su padre, y se convierte en el hijo izquierdo
    x->parent->left = y;
  } else {
    // Si x es el hijo derecho de su padre, y se convierte en el hijo derecho
    x->parent->right = y;
  }
  y->left = x;
  x->parent = y;
}

/**
 * @brief Realiza una rotación a la derecha en el nodo @param y
 * Mueve el nodo @param y hacia abajo y su hijo izquierdo hacia arriba.
 */
template <typename DataType>
void RBTree<DataType>::rightRotate(RBTreeNode<DataType> *y) {
  RBTreeNode<DataType> *x = y->left;
  y->left = x->right;
  if (x->right != nil) {
    // Si x tiene un hijo derecho, lo actualiza
    x->right->parent = y;
  }
  x->parent = y->parent;
  if (y->parent == nil) {
    // Si y es la raíz, x se convierte en la nueva raíz
    root = x;
  } else if (y == y->parent->right) {
    // Si y es el hijo derecho de su padre, x se convierte en el hijo derecho
    y->parent->right = x;
  } else {
    // Si y es el hijo izquierdo de su padre, x se convierte en el hijo izquierdo
    y->parent->left = x;
  }
  x->right = y;
  y->parent = x;
}

/**
 * @brief Transplanta el nodo @param u con el nodo @param v
 * Reemplaza el nodo @param u por el nodo @param v en el árbol.
 */
template <typename DataType>
void RBTree<DataType>::transplant(RBTreeNode<DataType> *u, RBTreeNode<DataType> *v) {
  if (u->parent == nil) {
    // Si u es la raíz, v se convierte en la nueva raíz
    root = v;
  } else if (u == u->parent->left) {
    // Si u es el hijo izquierdo de su padre, v se convierte en el hijo izquierdo
    u->parent->left = v;
  } else {
    // Si u es el hijo derecho de su padre, v se convierte en el hijo derecho
    u->parent->right = v;
  }
  v->parent = u->parent;
}

/**
 * @brief Corrige el árbol rojinegro después de una inserción
 * Asegura que las propiedades del árbol rojinegro se mantengan después de insertar un nuevo nodo.
 */
template <typename DataType>
void RBTree<DataType>::insertFixup(RBTreeNode<DataType> *z) {
  // Mientras el padre sea rojo, se viola la propiedad de que no puede haber dos rojos seguidos
  while (z->parent->color == RED) {
    if (z->parent == z->parent->parent->left) {
      // El padre es hijo izquierdo del abuelo
      // El tío es hijo derecho del abuelo
      RBTreeNode<DataType> *y = z->parent->parent->right;
      if (y->color == RED) {
        // Caso 1: El tío es rojo
        // Cambia el color del padre y del tío
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        // Se sube el problema al abuelo
        z = z->parent->parent;

      } else {
        // Caso 2: z es hijo derecho
        if (z == z->parent->right) {
          // Rotación izquierda para convertirlo en Caso 3
          z = z->parent;
          leftRotate(z);
        }
        // Caso 3: z es hijo izquierdo, rotación derecha
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        rightRotate(z->parent->parent);
      }

    } else {
      // El padre es hijo derecho del abuelo
      // El tío es hijo izquierdo del abuelo
      RBTreeNode<DataType> *y = z->parent->parent->left;
      if (y->color == RED) {
        // Caso 1: El tío es rojo
        // Cambia el color del padre y del tío
        z->parent->color = BLACK;
        y->color = BLACK;
        z->parent->parent->color = RED;
        // Se sube el problema al abuelo
        z = z->parent->parent;

      } else {
        // Caso 2: z es hijo izquierdo
        if (z == z->parent->left) {
          z = z->parent;
          // Rotación derecha para convertirlo en Caso 3
          rightRotate(z);
        }
        // Caso 3: z es hijo derecho, rotación izquierda
        z->parent->color = BLACK;
        z->parent->parent->color = RED;
        leftRotate(z->parent->parent);
      }
    }
  }
  // Asegura que la raíz siempre sea negra
  root->color = BLACK;
}

/**
 * @brief Corrige el árbol rojinegro después de una eliminación
 * Asegura que las propiedades del árbol rojinegro se mantengan después de eliminar un nodo.
 */
template <typename DataType>
void RBTree<DataType>::removeFixup(RBTreeNode<DataType> *x) {
  while (x != root && x->color == BLACK) {
    if (x == x->parent->left) {
      // x es hijo izquierdo
      RBTreeNode<DataType> *w = x->parent->right;

      if (w->color == RED) {
        // Caso 1: Hermano rojo
        // Cambia el color del hermano y del padre
        // Rotación izquierda en el padre
        w->color = BLACK;
        x->parent->color = RED;
        leftRotate(x->parent);
        w = x->parent->right;
      }
      
      if (w->left->color == BLACK && w->right->color == BLACK) {
        // Caso 2: Hermano negro con hijos negros
        // Recolorear y subir el problema al padre
        w->color = RED;
        x = x->parent;

      } else {
        if (w->right->color == BLACK) {
          // Caso 3: Hermano negro, hijo derecho negro, hijo izquierdo rojo
          // Cambio de color y rotación derecha
          w->left->color = BLACK;
          w->color = RED;
          rightRotate(w);
          w = x->parent->right;
        }
        // Caso 4: Hermano negro, hijo derecho rojo
        // Cambio de color y rotación izquierda
        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->right->color = BLACK;
        leftRotate(x->parent);
        x = root;
      }
    } else {
      RBTreeNode<DataType> *w = x->parent->left;
      // x es hijo derecho
      if (w->color == RED) {
        // Caso 1
        w->color = BLACK;
        x->parent->color = RED;
        rightRotate(x->parent);
        w = x->parent->left;
      }
      if (w->right->color == BLACK && w->left->color == BLACK) {
        // Caso 2
        w->color = RED;
        x = x->parent;
      } else {
        if (w->left->color == BLACK) {
          // Caso 3
          w->right->color = BLACK;
          w->color = RED;
          leftRotate(w);
          w = x->parent->left;
        }
        // Caso 4
        w->color = x->parent->color;
        x->parent->color = BLACK;
        w->left->color = BLACK;
        rightRotate(x->parent);
        x = root;
      }
    }
  }
  // Asegura que la raíz siempre sea negra
  x->color = BLACK;
}
