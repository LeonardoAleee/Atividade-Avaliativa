#include "RBTree.h"

void testInsert() {
    RBTree<int> bst;

    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    std::cout << "Árvore após inserções iniciais:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(90);
    bst.insert(80);

    std::cout << "Árvore após inserções adicionais:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.insert(85);
    bst.insert(50);
    bst.insert(35);
    bst.insert(5);

    std::cout << "Árvore após inserções mais complexas:\n";
    bst.printTree();
    std::cout << std::endl;
}

void testDelete() {
    RBTree<int> bst;

    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    bst.deleteNode(40);
    std::cout << "Árvore após excluir 40:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(65);
    std::cout << "Árvore após excluir 65:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(55);
    std::cout << "Árvore após excluir 55:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(999);
    std::cout << "Árvore após tentar excluir 999 (nó inexistente):\n";
    bst.printTree();
    std::cout << std::endl;

    bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(90);
    bst.insert(80);

    bst.deleteNode(20);
    std::cout << "Árvore após excluir 20:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(30);
    std::cout << "Árvore após excluir 30:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(10);
    std::cout << "Árvore após excluir 10:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(90);
    std::cout << "Árvore após excluir 90:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(80);
    std::cout << "Árvore após excluir 80:\n";
    bst.printTree();
    std::cout << std::endl;
}

void testSearch() {
    RBTree<int> bst;

    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    Node<int>* result = bst.searchTree(65);
    std::cout << "Busca 65: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(40);
    std::cout << "Busca 40: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(75);
    std::cout << "Busca 75: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(999);
    std::cout << "Busca 999: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(90);
    bst.insert(80);

    result = bst.searchTree(20);
    std::cout << "Busca 20: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(30);
    std::cout << "Busca 30: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(10);
    std::cout << "Busca 10: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(90);
    std::cout << "Busca 90: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(80);
    std::cout << "Busca 80: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(1);
    std::cout << "Busca 1: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(100);
    std::cout << "Busca 100: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(50);
    std::cout << "Busca 50: " << (result != bst.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");

    RBTree<int> emptyTree;
    result = emptyTree.searchTree(1);
    std::cout << "Busca em árvore vazia (1): " << (result != emptyTree.getTNULL() ? "Encontrado\n" : "Não Encontrado\n");
}



void testValidation() {
    RBTree<int> bst;

    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    std::cout << "Validação da árvore: " << (bst.validateRBTree() ? "Válida\n" : "Inválida\n");

    bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(90);
    bst.insert(80);

    std::cout << "Validação após mais inserções: " << (bst.validateRBTree() ? "Válida\n" : "Inválida\n");
}

void testHeight() {
    RBTree<int> bst;

    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    std::cout << "Altura da árvore: " << bst.height() << std::endl;

    bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(90);
    bst.insert(80);

    std::cout << "Altura após mais inserções: " << bst.height() << std::endl;
}

void testMinimum() {
    RBTree<int> bst;

    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    Node<int>* minNode = bst.minimum(bst.getRoot());
    std::cout << "Mínimo da árvore: " << minNode->data << std::endl;

    bst.insert(20);
    bst.insert(30);
    bst.insert(10);

    minNode = bst.minimum(bst.getRoot());
    std::cout << "Mínimo da árvore após inserções adicionais: " << minNode->data << std::endl;
}

void testInorder() {
    RBTree<int> bst;

    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    std::cout << "Percurso em ordem simétrica (inorder): ";
    bst.inorder();
    std::cout << std::endl;
}

void testMaximum() {
    RBTree<int> bst;

    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    Node<int>* maxNode = bst.maximum(bst.getRoot());
    std::cout << "Máximo da árvore: " << maxNode->data << std::endl;

    bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(90);
    bst.insert(80);

    maxNode = bst.maximum(bst.getRoot());
    std::cout << "Máximo da árvore após inserções adicionais: " << maxNode->data << std::endl;
}


int main() {
    testInsert();  // Executa os testes de inserção
    testDelete();  // Executa os testes de exclusão
    testSearch();  // Executa os testes de busca
    testValidation();  // Executa os testes de validação
    testHeight();  // Executa os testes de altura
    testMinimum();  // Executa os testes para encontrar o nó mínimo
    testInorder();  // Executa os testes para percurso em ordem simétrica (inorder)
    testMaximum();  // Executa os testes para encontrar o nó máximo
    return 0;
}
