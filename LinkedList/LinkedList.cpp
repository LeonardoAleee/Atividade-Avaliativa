#include "LinkedList.h"
#include <iostream>
#include <chrono>
#include <random>

// Cria um novo nó com o dado fornecido
template<typename T>
Node<T>* LinkedList::newNode(T data)
{
    Node<T>* temp = new Node<T>;
    temp->data = data;
    temp->ptrNext = nullptr;
    temp->ptrPrev = nullptr;
    return temp;
}

// Adiciona um elemento no final da lista
template<typename T>
void LinkedList::addElementEnd(Node<T>** list, T data)
{
    Node<T>* temp = LinkedList::newNode(data);
    if (*list == nullptr) // Lista vazia
    {
        *list = temp;
    }
    else
    {
        Node<T>* current = *list;
        while (current->ptrNext != nullptr) // Percorre até o final da lista
        {
            current = current->ptrNext;
        }
        current->ptrNext = temp; // Adiciona o novo nó ao final
        temp->ptrPrev = current;
    }
}

// Exibe os elementos da lista
template<typename T>
void LinkedList::showNode(Node<T>* list)
{
    if (list == nullptr)
    {
        std::cout << "Lista inv�lida" << std::endl;
    }
    else if (list->ptrPrev != nullptr)
    {
        std::cout << "Estamos no meio da lista" << std::endl;
    }
    else
    {
        std::cout << "Elementos: ";
        Node<T>* current = list;
        while (current != nullptr) // Percorre a lista inteira
        {
            std::cout << current->data << " "; // Imprime todos os elementos
            current = current->ptrNext;
        }
        std::cout << std::endl;
    }
}

// Troca os valores de dois nós
template<typename T>
void LinkedList::swapValue(Node<T>* node1, Node<T>* node2)
{
    T temp = node1->data;
    node1->data = node2->data;
    node2->data = temp;
}

// Gera uma lista com elementos aleatórios
void LinkedList::randomList(Node<int>** list, int amount)
{
    if (amount == 0) return;

    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 100); // Distribuição uniforme de números inteiros no intervalo [1, 100]

    for (int count = 0; count < amount; count++)
    {
        LinkedList::addElementEnd(list, dis(gen));
    }
}

// Duplica uma lista
template<typename T>
Node<T>* LinkedList::duplicateList(Node<T>* list)
{
    Node<T>* temp = list;
    Node<T>* newList = nullptr;
    while (temp != nullptr) // Percorre a lista original
    {
        LinkedList::addElementEnd(&newList, temp->data); // Adiciona cada elemento à nova lista
        temp = temp->ptrNext;
    }
    return newList;
}

// Instâncias explícitas para int
template Node<int>* LinkedList::newNode(int);
template void LinkedList::addElementEnd(Node<int>**, int);
template void LinkedList::showNode(Node<int>*);
template void LinkedList::swapValue(Node<int>*, Node<int>*);
template Node<int>* LinkedList::duplicateList(Node<int>*);

// Instâncias explícitas para float
template Node<float>* LinkedList::newNode(float);
template void LinkedList::addElementEnd(Node<float>**, float);
template void LinkedList::showNode(Node<float>*);
template void LinkedList::swapValue(Node<float>*, Node<float>*);
template Node<float>* LinkedList::duplicateList(Node<float>*);

// Instâncias explícitas para char
template Node<char>* LinkedList::newNode(char);
template void LinkedList::addElementEnd(Node<char>**, char);
template void LinkedList::showNode(Node<char>*);
template void LinkedList::swapValue(Node<char>*, Node<char>*);
template Node<char>* LinkedList::duplicateList(Node<char>*);

// Instâncias explícitas para double
template Node<double>* LinkedList::newNode(double);
template void LinkedList::addElementEnd(Node<double>**, double);
template void LinkedList::showNode(Node<double>*);
template void LinkedList::swapValue(Node<double>*, Node<double>*);
template Node<double>* LinkedList::duplicateList(Node<double>*);


// Instanciações explícitas para tipos de treeNode<T>
template void LinkedList::addElementEnd(Node<treeNode<int>*>**, treeNode<int>*);
template void LinkedList::addElementEnd(Node<treeNode<double>*>**, treeNode<double>*);
template void LinkedList::addElementEnd(Node<treeNode<float>*>**, treeNode<float>*);
