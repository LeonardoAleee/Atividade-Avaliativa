#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>
#include <cassert>

// Definição das cores possíveis para os nós da árvore rubro-negra
enum Color { RED, BLACK };

// Estrutura do nó para a árvore rubro-negra
struct Node {
    int data; // Dados armazenados no nó (a chave do nó)
    Color color; // Cor do nó, que pode ser RED ou BLACK
    Node *left; // Pnteiro para o filho à esquerda do nó
    Node *right; // Ponteiro para o filho à direita do nó
    Node *parent; // Ponteiro para o pai do nó

    // Declaração do construtor do nó
    Node(int data);
};

// Classe que representa a árvore rubro-negra
class RBTree {
private:
    Node* root;
    Node* TNULL;

    void initializeNULLNode(Node* node, Node* parent);
    void preOrderHelper(Node* node);
    void inOrderHelper(Node* node);
    void postOrderHelper(Node* node);
    Node* searchTreeHelper(Node* node, int key);
    void balanceInsert(Node* k);
    void balanceDelete(Node* x);
    void printHelper(Node* root, std::string indent, bool last);
    void rbTransplant(Node* u, Node* v);
    void deleteNodeHelper(Node* node, int key);

public:
    RBTree();
    void preorder();
    void inorder();
    void postorder();
    Node* searchTree(int k);
    Node* minimum(Node* node);
    Node* maximum(Node* node);
    Node* successor(Node* x);
    Node* predecessor(Node* x);
    void leftRotate(Node* x);
    void rightRotate(Node* x);
    void insert(int key);
    Node* getRoot();
    void deleteNode(int data);
    void printTree();
};

#endif
