#pragma once

template <typename T>
struct Node
{
    T data;
    Node* ptrNext;
    Node* ptrPrev;
};

namespace LinkedList
{

    template<typename T>
    Node<T>* newNode(T data);

    template<typename T>
    void addElementEnd(Node<T>** list, T data);

    template<typename T>
    void showNode(Node<T>* list);

    template<typename T>
    void swapValue(Node<T>* node1, Node<T>* node2);
    
    void randomList(Node<int>** list, int amount);

    template<typename T>
    Node<T>* duplicateList(Node<T>* list);
}
