#include "RBTree.h"

// Construtor do nó
template <typename T>
Node<T>::Node(T data) : data(data) {
    parent = nullptr; // Inicializa o ponteiro para o pai como nulo
    left = nullptr; // Inicializa o ponteiro para o filho à esquerda como nulo
    right = nullptr; // Inicializa o ponteiro para o filho à direita como nulo
    color = RED;  // Inicializa a cor do nó como RED por padrão
}

// Construtor da classe RBTree que inicializa a árvore com um nó TNULL
template <typename T>
RBTree<T>::RBTree() {
    TNULL = new Node<T>(T());  // Cria um novo nó TNULL com valor padrão de T
    TNULL->color = BLACK;  // Define a cor de TNULL como BLACK
    root = TNULL;  // Inicializa a raiz como o nó TNULL
}

// Inicializa um nó TNULL com dados nulos e cor preta
template <typename T>
void RBTree<T>::initializeNULLNode(Node<T>* node, Node<T>* parent) {
    node->data = T();  // Dados nulos para o nó TNULL
    node->parent = parent;  // Define o pai do nó TNULL
    node->left = nullptr;  // O nó TNULL não tem filho à esquerda
    node->right = nullptr;  // O nó TNULL não tem filho à direita
    node->color = BLACK;  // A cor do nó TNULL é BLACK
}

// Função auxiliar para percurso preOrder da árvore
template <typename T>
void RBTree<T>::preOrderHelper(Node<T>* node) {
    if (node != TNULL) {  // Se o nó não for o TNULL
        std::cout << node->data << " ";  // Imprime os dados do nó
        preOrderHelper(node->left);  // Percorre a subárvore à esquerda
        preOrderHelper(node->right);  // Percorre a subárvore à direita
    }
}

// Função auxiliar para percurso inOrder da árvore
template <typename T>
void RBTree<T>::inOrderHelper(Node<T>* node) {
    if (node != TNULL) {  // Se o nó não for o TNULL
        inOrderHelper(node->left);  // Percorre a subárvore à esquerda
        std::cout << node->data << " ";  // Imprime os dados do nó
        inOrderHelper(node->right);  // Percorre a subárvore à direita
    }
}

// Função auxiliar para percurso postOrder da árvore
template <typename T>
void RBTree<T>::postOrderHelper(Node<T>* node) {
    if (node != TNULL) {  // Se o nó não for o TNULL
        postOrderHelper(node->left);  // Percorre a subárvore à esquerda
        postOrderHelper(node->right);  // Percorre a subárvore à direita
        std::cout << node->data << " ";  // Imprime os dados do nó
    }
}

// Função auxiliar para buscar uma chave na árvore
template <typename T>
Node<T>* RBTree<T>::searchTreeHelper(Node<T>* node, T key) {
    if (node == TNULL || key == node->data) {
        return node;  // Se o nó é TNULL ou contém a chave procurada, retorna o nó
    }
    if (key < node->data) {  // Se a chave procurada é menor que a chave do nó atual
        return searchTreeHelper(node->left, key);  // Busca na subárvore esquerda
    }
    return searchTreeHelper(node->right, key);  // Busca na subárvore direita
}

// Função auxiliar para balancear a árvore após a inserção de um novo nó
template <typename T>
void RBTree<T>::balanceInsert(Node<T>* k) {
    Node<T>* u;  // Nó tio (uncle)
    while (k->parent->color == RED) {  // Enquanto o pai do nó k for vermelho
        if (k->parent == k->parent->parent->right) {  // Se o pai de k é o filho direito do avô
            u = k->parent->parent->left;  // O tio é o filho esquerdo do avô
            if (u->color == RED) {  // Se o tio é vermelho
                u->color = BLACK;  // O tio vira preto
                k->parent->color = BLACK;  // O pai de k vira preto
                k->parent->parent->color = RED;  // O avô de k vira vermelho
                k = k->parent->parent;  // Atualiza k para o avô
            } else {  // Se o tio é preto
                if (k == k->parent->left) {  // Se k é o filho esquerdo do pai
                    k = k->parent;  // Atualiza k para o pai
                    rightRotate(k);  // Realiza rotação à direita
                }
                k->parent->color = BLACK;  // O pai de k vira preto
                k->parent->parent->color = RED;  // O avô de k vira vermelho
                leftRotate(k->parent->parent);  // Realiza rotação à esquerda
            }
        } else {  // Se o pai de k é o filho esquerdo do avô
            u = k->parent->parent->right;  // O tio é o filho direito do avô
            if (u->color == RED) {  // Se o tio é vermelho
                u->color = BLACK;  // O tio vira preto
                k->parent->color = BLACK;  // O pai de k vira preto
                k->parent->parent->color = RED;  // O avô de k vira vermelho
                k = k->parent->parent;  // Atualiza k para o avô
            } else {  // Se o tio é preto
                if (k == k->parent->right) {  // Se k é o filho direito do pai
                    k = k->parent;  // Atualiza k para o pai
                    leftRotate(k);  // Realiza rotação à esquerda
                }
                k->parent->color = BLACK;  // O pai de k vira preto
                k->parent->parent->color = RED;  // O avô de k vira vermelho
                rightRotate(k->parent->parent);  // Realiza rotação à direita
            }
        }
        if (k == root) {  // Se k é a raiz
            break;  // Interrompe o loop
        }
    }
    root->color = BLACK;  // A raiz é sempre preta
}

// Função auxiliar para imprimir a árvore com a indentação apropriada
template <typename T>
void RBTree<T>::printHelper(Node<T>* root, std::string indent, bool last) {
    if (root != TNULL) {  // Se o nó não for TNULL
        std::cout << indent;  // Imprime a indentação
        if (last) {
            std::cout << "R----";  // Marca o nó como o último filho à direita
            indent += "   ";  // Atualiza a indentação para os filhos
        } else {
            std::cout << "L----";  // Marca o nó como o último filho à esquerda
            indent += "|  ";  // Atualiza a indentação para os filhos
        }
        std::string sColor = root->color ? "BLACK" : "RED";  // Define a cor do nó como BLACK ou RED
        std::cout << root->data << "(" << sColor << ")" << std::endl;  // Imprime os dados e a cor do nó
        printHelper(root->left, indent, false);  // Imprime a subárvore à esquerda
        printHelper(root->right, indent, true);  // Imprime a subárvore à direita
    }
}

// Função pública para iniciar o percurso preOrder da árvore
template <typename T>
void RBTree<T>::preorder() {
    preOrderHelper(this->root);  // Chama a função auxiliar para percurso preOrder
}

// Função pública para iniciar o percurso inOrder da árvore
template <typename T>
void RBTree<T>::inorder() {
    inOrderHelper(this->root);  // Chama a função auxiliar para percurso inOrder
}

// Função pública para iniciar o percurso postOrder da árvore
template <typename T>
void RBTree<T>::postorder() {
    postOrderHelper(this->root);  // Chama a função auxiliar para percurso postOrder
}

// Função pública para buscar uma chave na árvore
template <typename T>
Node<T>* RBTree<T>::searchTree(T k) {
    return searchTreeHelper(this->root, k);  // Chama a função auxiliar para busca
}

// Função pública para encontrar o nó com a menor chave a partir do nó dado
template <typename T>
Node<T>* RBTree<T>::minimum(Node<T>* node) {
    while (node->left != TNULL) {  // Vai para o filho mais à esquerda
        node = node->left;
    }
    return node;  // Retorna o nó com a menor chave
}

// Função pública para encontrar o nó com a maior chave a partir do nó dado
template <typename T>
Node<T>* RBTree<T>::maximum(Node<T>* node) {
    while (node->right != TNULL) {  // Vai para o filho mais à direita
        node = node->right;
    }
    return node;  // Retorna o nó com a maior chave
}

// Função pública para encontrar o sucessor de um nó
template <typename T>
Node<T>* RBTree<T>::successor(Node<T>* x) {
    if (x->right != TNULL) {  // Se x tem um filho direito
        return minimum(x->right);  // O sucessor é o mínimo na subárvore direita
    }
    Node<T>* y = x->parent;  // O sucessor é o mais próximo pai em relação a x
    while (y != TNULL && x == y->right) {  // Move para cima até encontrar um pai que é o filho esquerdo
        x = y;
        y = y->parent;
    }
    return y;  // Retorna o sucessor
}

// Função pública para encontrar o antecessor de um nó
template <typename T>
Node<T>* RBTree<T>::predecessor(Node<T>* x) {
    if (x->left != TNULL) {  // Se x tem um filho esquerdo
        return maximum(x->left);  // O antecessor é o máximo na subárvore esquerda
    }
    Node<T>* y = x->parent;  // O antecessor é o mais próximo pai em relação a x
    while (y != TNULL && x == y->left) {  // Move para cima até encontrar um pai que é o filho direito
        x = y;
        y = y->parent;
    }
    return y;  // Retorna o antecessor
}

// Função pública para realizar uma rotação à esquerda no nó x
template <typename T>
void RBTree<T>::leftRotate(Node<T>* x) {
    Node<T>* y = x->right;  // O filho direito de x se tornará o novo pai
    x->right = y->left;  // O filho esquerdo de y se tornará o filho direito de x
    if (y->left != TNULL) {  // Se y tem um filho esquerdo
        y->left->parent = x;  // Atualiza o pai do filho esquerdo de y para x
    }
    y->parent = x->parent;  // Atualiza o pai de y para o pai de x
    if (x->parent == nullptr) {  // Se x é a raiz
        this->root = y;  // A nova raiz é y
    } else if (x == x->parent->left) {  // Se x é o filho esquerdo do pai
        x->parent->left = y;  // Atualiza o filho esquerdo do pai para y
    } else {  // Se x é o filho direito do pai
        x->parent->right = y;  // Atualiza o filho direito do pai para y
    }
    y->left = x;  // Atualiza o filho esquerdo de y para x
    x->parent = y;  // Atualiza o pai de x para y
}

// Função pública para realizar uma rotação à direita no nó x
template <typename T>
void RBTree<T>::rightRotate(Node<T>* x) {
    Node<T>* y = x->left;  // O filho esquerdo de x se tornará o novo pai
    x->left = y->right;  // O filho direito de y se tornará o filho esquerdo de x
    if (y->right != TNULL) {  // Se y tem um filho direito
        y->right->parent = x;  // Atualiza o pai do filho direito de y para x
    }
    y->parent = x->parent;  // Atualiza o pai de y para o pai de x
    if (x->parent == nullptr) {  // Se x é a raiz
        this->root = y;  // A nova raiz é y
    } else if (x == x->parent->right) {  // Se x é o filho direito do pai
        x->parent->right = y;  // Atualiza o filho direito do pai para y
    } else {  // Se x é o filho esquerdo do pai
        x->parent->left = y;  // Atualiza o filho esquerdo do pai para y
    }
    y->right = x;  // Atualiza o filho direito de y para x
    x->parent = y;  // Atualiza o pai de x para y
}

// Função pública para inserir uma nova chave na árvore
template <typename T>
void RBTree<T>::insert(T key) {
    Node<T>* node = new Node<T>(key);  // Cria um novo nó com a chave fornecida
    node->parent = nullptr;  // Inicializa o pai do nó como nulo
    node->data = key;  // Define os dados do nó como a chave fornecida
    node->left = TNULL;  // Inicializa o filho esquerdo como TNULL
    node->right = TNULL;  // Inicializa o filho direito como TNULL
    node->color = RED;  // A nova chave é inicialmente vermelha

    Node<T>* y = nullptr;  // Nó pai do novo nó
    Node<T>* x = this->root;  // Inicia a busca a partir da raiz

    while (x != TNULL) {  // Enquanto x não for TNULL
        y = x;  // Atualiza y para x
        if (node->data < x->data) {  // Se a nova chave é menor que a chave de x
            x = x->left;  // Move para o filho esquerdo
        } else {
            x = x->right;  // Move para o filho direito
        }
    }

    node->parent = y;  // Define o pai do novo nó
    if (y == nullptr) {  // Se a árvore estava vazia
        root = node;  // O novo nó se torna a raiz
    } else if (node->data < y->data) {  // Se a nova chave é menor que a chave do pai
        y->left = node;  // O novo nó é o filho esquerdo
    } else {
        y->right = node;  // O novo nó é o filho direito
    }

    if (node->parent == nullptr) {  // Se o novo nó é a raiz
        node->color = BLACK;  // A raiz é sempre preta
        return;  // Retorna sem precisar balancear
    }

    balanceInsert(node);  // Balanceia a árvore após a inserção
}

// Função pública para obter a raiz da árvore
template <typename T>
Node<T>* RBTree<T>::getRoot() {
    return this->root;  // Retorna a raiz da árvore
}

// Função pública para excluir um nó com a chave fornecida
template <typename T>
void RBTree<T>::deleteNode(T data) {
    deleteNodeHelper(this->root, data);  // Chama a função auxiliar para exclusão
}

// Função pública para imprimir a árvore
template <typename T>
void RBTree<T>::printTree() {
    if (root) {  // Se a árvore não está vazia
        printHelper(this->root, "", true);  // Chama a função auxiliar para impressão
    }
}

// Função auxiliar para balancear a árvore após a exclusão de um nó
template <typename T>
void RBTree<T>::balanceDelete(Node<T>* x) {
    Node<T>* s;  // Nó irmão
    while (x != root && x->color == BLACK) {  // Enquanto x não for a raiz e sua cor for BLACK
        if (x == x->parent->left) {  // Se x é o filho esquerdo do pai
            s = x->parent->right;  // O irmão é o filho direito do pai
            if (s->color == RED) {  // Se o irmão é vermelho
                s->color = BLACK;  // O irmão vira preto
                x->parent->color = RED;  // O pai de x vira vermelho
                leftRotate(x->parent);  // Realiza rotação à esquerda
                s = x->parent->right;  // Atualiza o irmão
            }
            // Se ambos os filhos do irmão são pretos
            if (s->left->color == BLACK && s->right->color == BLACK) {
                s->color = RED;  // O irmão vira vermelho
                x = x->parent;  // Atualiza x para o pai
            } else {
                if (s->right->color == BLACK) {  // Se o filho direito do irmão é preto
                    s->left->color = BLACK;  // O filho esquerdo do irmão vira preto
                    s->color = RED;  // O irmão vira vermelho
                    rightRotate(s);  // Realiza rotação à direita
                    s = x->parent->right;  // Atualiza o irmão
                }
                s->color = x->parent->color;  // O irmão recebe a cor do pai de x
                x->parent->color = BLACK;  // O pai de x vira preto
                s->right->color = BLACK;  // O filho direito do irmão vira preto
                leftRotate(x->parent);  // Realiza rotação à esquerda
                x = root;  // Atualiza x para a raiz
            }
        } else {  // Se x é o filho direito do pai
            s = x->parent->left;  // O irmão é o filho esquerdo do pai
            if (s->color == RED) {  // Se o irmão é vermelho
                s->color = BLACK;  // O irmão vira preto
                x->parent->color = RED;  // O pai de x vira vermelho
                rightRotate(x->parent);  // Realiza rotação à direita
                s = x->parent->left;  // Atualiza o irmão
            }
            // Se ambos os filhos do irmão são pretos
            if (s->right->color == BLACK && s->left->color == BLACK) {
                s->color = RED;  // O irmão vira vermelho
                x = x->parent;  // Atualiza x para o pai
            } else {
                if (s->left->color == BLACK) {  // Se o filho esquerdo do irmão é preto
                    s->right->color = BLACK;  // O filho direito do irmão vira preto
                    s->color = RED;  // O irmão vira vermelho
                    leftRotate(s);  // Realiza rotação à esquerda
                    s = x->parent->left;  // Atualiza o irmão
                }
                s->color = x->parent->color;  // O irmão recebe a cor do pai de x
                x->parent->color = BLACK;  // O pai de x vira preto
                s->left->color = BLACK;  // O filho esquerdo do irmão vira preto
                rightRotate(x->parent);  // Realiza rotação à direita
                x = root;  // Atualiza x para a raiz
            }
        }
    }
    x->color = BLACK;  // O nó x vira preto após o balanceamento
}

// Função auxiliar para substituir um nó u por um nó v
template <typename T>
void RBTree<T>::rbTransplant(Node<T>* u, Node<T>* v) {
    if (u->parent == nullptr) {  // Se u é a raiz
        root = v;  // v se torna a nova raiz
    } else if (u == u->parent->left) {  // Se u é o filho esquerdo do pai
        u->parent->left = v;  // v se torna o novo filho esquerdo
    } else {  // Se u é o filho direito do pai
        u->parent->right = v;  // v se torna o novo filho direito
    }
    v->parent = u->parent;  // Atualiza o pai de v
}

// Função auxiliar para excluir um nó da árvore
template <typename T>
void RBTree<T>::deleteNodeHelper(Node<T>* node, T key) {
    Node<T>* z = TNULL;  // Nó a ser excluído
    Node<T>* x;  // Nó substituto
    Node<T>* y;  // Nó para a troca de chaves
    while (node != TNULL) {  // Procura o nó com a chave fornecida
        if (node->data == key) {
            z = node;  // Encontrou o nó a ser excluído
        }
        if (node->data <= key) {
            node = node->right;  // Move para a direita
        } else {
            node = node->left;  // Move para a esquerda
        }
    }
    if (z == TNULL) {  // Se o nó não foi encontrado
        std::cout << "Couldn't find key in the tree" << std::endl;  // Imprime mensagem de erro
        return;  // Retorna sem excluir o nó
    }
    y = z;  // O nó a ser excluído é o nó z
    Color y_original_color = y->color;  // Armazena a cor original de y
    if (z->left == TNULL) {  // Se o nó a ser excluído não tem filho esquerdo
        x = z->right;  // O filho direito de z se torna x
        rbTransplant(z, z->right);  // Substitui z por seu filho direito
    } else if (z->right == TNULL) {  // Se o nó a ser excluído não tem filho direito
        x = z->left;  // O filho esquerdo de z se torna x
        rbTransplant(z, z->left);  // Substitui z por seu filho esquerdo
    } else {  // Se o nó a ser excluído tem dois filhos
        y = minimum(z->right);  // O sucessor de z é o mínimo da subárvore direita
        y_original_color = y->color;  // Armazena a cor original do sucessor
        x = y->right;  // O filho direito do sucessor se torna x
        if (y->parent == z) {  // Se o sucessor é filho direito de z
            x->parent = y;  // Atualiza o pai de x
        } else {  // Se o sucessor não é filho direito de z
            rbTransplant(y, y->right);  // Substitui o sucessor por seu filho direito
            y->right = z->right;  // Atualiza o filho direito do sucessor
            y->right->parent = y;  // Atualiza o pai do filho direito do sucessor
        }
        rbTransplant(z, y);  // Substitui z pelo sucessor
        y->left = z->left;  // Atualiza o filho esquerdo do sucessor
        y->left->parent = y;  // Atualiza o pai do filho esquerdo do sucessor
        y->color = z->color;  // Atualiza a cor do sucessor
    }
    delete z;  // Remove o nó z
    if (y_original_color == BLACK) {  // Se a cor original de y era BLACK
        balanceDelete(x);  // Rebalanceia a árvore
    }
}

// Função pública para validar as propriedades da árvore rubro-negra
template <typename T>
bool RBTree<T>::validateRBTree() {
    if (root->color != BLACK) {
        std::cout << "A raiz não é preta!" << std::endl;
        return false;
    }

    int blackCount = 0;
    Node<T>* node = root;
    while (node != TNULL) {
        if (node->color == BLACK) {
            blackCount++;
        }
        node = node->left;
    }

    return checkRBProperties(root, blackCount, 0);
}

// Função auxiliar para validar as propriedades da árvore rubro-negra
template <typename T>
bool RBTree<T>::validateHelper(Node<T>* node) {
    if (node == TNULL) return true;

    if (node->color == RED) {
        if (node->left->color != BLACK || node->right->color != BLACK) {
            std::cout << "Nó vermelho com filhos não pretos encontrado: " << node->data << std::endl;
            return false;
        }
    }

    if (!validateHelper(node->left) || !validateHelper(node->right)) {
        return false;
    }

    return true;
}

// Função pública para calcular a altura da árvore
template <typename T>
int RBTree<T>::height() {
    return calculateHeight(root);
}

// Função auxiliar para calcular a altura da árvore
template <typename T>
int RBTree<T>::calculateHeight(Node<T>* node) {
    if (node == TNULL) return 0;

    int leftHeight = calculateHeight(node->left);
    int rightHeight = calculateHeight(node->right);

    return std::max(leftHeight, rightHeight) + 1;
}

// Função pública para obter o nó TNULL
template <typename T>
Node<T>* RBTree<T>::getTNULL() {
    return TNULL;
}

// Função auxiliar para verificar a consistência do número de nós pretos
template <typename T>
bool RBTree<T>::checkRBProperties(Node<T>* node, int& blackCount, int pathBlackCount) {
    if (node == TNULL) {
        if (pathBlackCount == blackCount) {
            return true;
        } else {
            std::cout << "Número de nós pretos em um caminho não é consistente!" << std::endl;
            return false;
        }
    }

    if (node->color == RED) {
        if (node->left->color != BLACK || node->right->color != BLACK) {
            std::cout << "Nó vermelho com filhos não pretos encontrado: " << node->data << std::endl;
            return false;
        }
    }

    if (node->color == BLACK) {
        pathBlackCount++;
    }

    if (!checkRBProperties(node->left, blackCount, pathBlackCount)) {
        return false;
    }

    if (!checkRBProperties(node->right, blackCount, pathBlackCount)) {
        return false;
    }

    return true;
}

// Declaração explícita das instâncias do template
template class Node<int>;
template class RBTree<int>;
