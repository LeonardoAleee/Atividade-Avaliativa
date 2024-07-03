#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <cassert>

// Definição das cores possíveis para os nós da árvore rubro-negra
enum Color { RED, BLACK };

// Estrutura do nó para a árvore rubro-negra
template <typename T>
struct Node {
    T data; // Dados armazenados no nó (a chave do nó)
    Color color; // Cor do nó, que pode ser RED ou BLACK
    Node *left; // Ponteiro para o filho à esquerda do nó
    Node *right; // Ponteiro para o filho à direita do nó
    Node *parent; // Ponteiro para o pai do nó

    // Declaração do construtor do nó
    Node(T data);
};

// Classe que representa a árvore rubro-negra
template <typename T>
class RBTree {
private:
    Node<T>* root;
    Node<T>* TNULL;

    void initializeNULLNode(Node<T>* node, Node<T>* parent);
    void preOrderHelper(Node<T>* node);
    void inOrderHelper(Node<T>* node);
    void postOrderHelper(Node<T>* node);
    Node<T>* searchTreeHelper(Node<T>* node, T key);
    void balanceInsert(Node<T>* k);
    void balanceDelete(Node<T>* x);
    void printHelper(Node<T>* root, std::string indent, bool last);
    void rbTransplant(Node<T>* u, Node<T>* v);
    void deleteNodeHelper(Node<T>* node, T key);

public:
    RBTree();
    void preorder();
    void inorder();
    void postorder();
    Node<T>* searchTree(T k);
    Node<T>* minimum(Node<T>* node);
    Node<T>* maximum(Node<T>* node);
    Node<T>* successor(Node<T>* x);
    Node<T>* predecessor(Node<T>* x);
    void leftRotate(Node<T>* x);
    void rightRotate(Node<T>* x);
    void insert(T key);
    Node<T>* getRoot();
    void deleteNode(T data);
    void printTree();
};

#endif
