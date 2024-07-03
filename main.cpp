#include "RBTree.h"

// Função para testar a inserção de nós na árvore rubro-negra
void testInsert() {
    RBTree bst;

    // Inserções iniciais
    bst.insert(55);  // Insere a chave 55 na árvore
    bst.insert(40);  // Insere a chave 40 na árvore
    bst.insert(65);  // Insere a chave 65 na árvore
    bst.insert(60);  // Insere a chave 60 na árvore
    bst.insert(75);  // Insere a chave 75 na árvore
    bst.insert(57);  // Insere a chave 57 na árvore

    std::cout << "Árvore após inserções iniciais:\n";
    bst.printTree();
    std::cout << std::endl;

    // Inserindo chaves adicionais para testar mais casos
    bst.insert(20);  // Insere a chave 20 na árvore
    bst.insert(30);  // Insere a chave 30 na árvore
    bst.insert(10);  // Insere a chave 10 na árvore
    bst.insert(90);  // Insere a chave 90 na árvore
    bst.insert(80);  // Insere a chave 80 na árvore

    std::cout << "Árvore após inserções adicionais:\n";
    bst.printTree();
    std::cout << std::endl;

    // Inserindo mais chaves para testar casos ainda mais complexos
    bst.insert(85);  // Insere a chave 85 na árvore
    bst.insert(50);  // Insere a chave 50 na árvore
    bst.insert(35);  // Insere a chave 35 na árvore
    bst.insert(5);   // Insere a chave 5 na árvore

    std::cout << "Árvore após inserções mais complexas:\n";
    bst.printTree();
    std::cout << std::endl;
}

// Função para testar a exclusão de nós na árvore rubro-negra
void testDelete() {
    RBTree bst;

    // Inserções iniciais
    bst.insert(55);  // Insere a chave 55 na árvore
    bst.insert(40);  // Insere a chave 40 na árvore
    bst.insert(65);  // Insere a chave 65 na árvore
    bst.insert(60);  // Insere a chave 60 na árvore
    bst.insert(75);  // Insere a chave 75 na árvore
    bst.insert(57);  // Insere a chave 57 na árvore

    // Exclusões iniciais
    bst.deleteNode(40);  // Exclui o nó com a chave 40
    std::cout << "Árvore após excluir 40:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(65);  // Exclui o nó com a chave 65
    std::cout << "Árvore após excluir 65:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(55);  // Exclui o nó com a chave 55
    std::cout << "Árvore após excluir 55:\n";
    bst.printTree();
    std::cout << std::endl;

    // Teste de exclusão de nó inexistente
    bst.deleteNode(999);  // Tenta excluir um nó inexistente
    std::cout << "Árvore após tentar excluir 999 (nó inexistente):\n";
    bst.printTree();
    std::cout << std::endl;

    // Inserções adicionais para testar exclusões mais complexas
    bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(90);
    bst.insert(80);

    bst.deleteNode(20);  // Exclui o nó com a chave 20
    std::cout << "Árvore após excluir 20:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(30);  // Exclui o nó com a chave 30
    std::cout << "Árvore após excluir 30:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(10);  // Exclui o nó com a chave 10
    std::cout << "Árvore após excluir 10:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(90);  // Exclui o nó com a chave 90
    std::cout << "Árvore após excluir 90:\n";
    bst.printTree();
    std::cout << std::endl;

    bst.deleteNode(80);  // Exclui o nó com a chave 80
    std::cout << "Árvore após excluir 80:\n";
    bst.printTree();
    std::cout << std::endl;
}

// Função para testar a busca de nós na árvore rubro-negra
void testSearch() {
    RBTree bst;

    // Inserções iniciais
    bst.insert(55);
    bst.insert(40);
    bst.insert(65);
    bst.insert(60);
    bst.insert(75);
    bst.insert(57);

    // Buscas iniciais
    Node* result = bst.searchTree(65);
    std::cout << "Busca 65: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(40);
    std::cout << "Busca 40: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(75);
    std::cout << "Busca 75: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(999);  // Busca uma chave inexistente
    std::cout << "Busca 999: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    // Inserções adicionais para testar buscas mais complexas
    bst.insert(20);
    bst.insert(30);
    bst.insert(10);
    bst.insert(90);
    bst.insert(80);

    result = bst.searchTree(20);
    std::cout << "Busca 20: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(30);
    std::cout << "Busca 30: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(10);
    std::cout << "Busca 10: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(90);
    std::cout << "Busca 90: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(80);
    std::cout << "Busca 80: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    // Buscando chaves não existentes para verificar comportamento
    result = bst.searchTree(1);  // Busca uma chave inexistente
    std::cout << "Busca 1: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(100);  // Busca uma chave inexistente
    std::cout << "Busca 100: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    result = bst.searchTree(50);  // Busca uma chave inexistente
    std::cout << "Busca 50: " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");

    // Teste de busca em árvore vazia
    RBTree emptyTree;
    result = emptyTree.searchTree(1);
    std::cout << "Busca em árvore vazia (1): " << (result != nullptr ? "Encontrado\n" : "Não Encontrado\n");
}

int main() {
    testInsert();  // Executa os testes de inserção
    testDelete();  // Executa os testes de exclusão
    testSearch();  // Executa os testes de busca
    return 0;
}
