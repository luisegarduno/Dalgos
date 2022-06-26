/*
 * Dalgos v1.0.0
 * Updated: 2022-06-24
 * --------------------------------------------
 * Created by Luis on 2020-06-04.
 */

#ifndef DS_NODE_H
#define DS_NODE_H

#include <iostream>

template<class T>
class Node{

    private:
        // Each node contains:
        Node<T>* next;          // Node pointer, pointing to the next Node in the list
        Node<T>* previous;      // Node pointer, pointing to the previous node in the list
        T data;                 // Data of type T

    public:
        // Default constructor
        Node();

        // Constructor with data value passed into it
        explicit Node(T);

        Node(const Node<T>&);

        // Copy constructor
        Node(const Node<T>&,Node<T>*,Node<T>*);

        // Set functions used to re/define Node variables
        void setData(T*);
        void setNextNode(Node<T>*);
        void setPreviousNode(Node<T>*);

        // Get functions used to return Node variables
        T* getData();
        Node<T>* getNextNode();
        Node<T>* getPreviousNode();

        // Node destructor
        ~Node();
};

// Default constructor : initializes Node
template<class T>
Node<T>::Node() : next(nullptr), previous(nullptr){
}

// parameter "aValue" of type T is used to declare data value
template<class T>
Node<T>::Node(T aValue) :  next(nullptr), previous(nullptr), data(aValue){
}

template<class T>
Node<T>::Node(const Node<T>& data2) : next(nullptr), previous(nullptr), data(data2.data){
}


template<class T>
Node<T>::Node(const Node<T>& aData, Node<T>* aNext, Node<T>* aPrevious) :
        data(aData.data), next(aNext), previous(aPrevious){
}

// Set current node data equal to x
template<class T>
void Node<T>::setData(T* x){
    this->data = *x;
}

// Get current node data
template<class T>
T* Node<T>::getData(){
    return &data;
}

// Set the next node in the list using parameter "setNext" of type Node<T>*
template<class T>
void Node<T>::setNextNode(Node<T>* setNext){
    this->next = setNext;
}

// Set the previous node in the list using parameter "setPrev" of type Node<T>*
template<class T>
void Node<T>::setPreviousNode(Node<T>* setPrev){
    this->previous = setPrev;
}

// get" or return the next node in the list
template<class T>
Node<T>* Node<T>::getNextNode(){
    return this->next;
}

// Used to "get" or return the previous node in the list
template<class T>
Node<T>* Node<T>::getPreviousNode(){
    return this->previous;
}

// Default Node destructor
template<class T>
Node<T>::~Node<T>()= default;

#endif //DS_NODE_H
