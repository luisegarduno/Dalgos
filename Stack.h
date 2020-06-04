//
// Created by Luis on 6/4/2020.
//

#ifndef DATASTRUCTURES_STACK_H
#define DATASTRUCTURES_STACK_H

#include <iostream>
#include "Node.h"
#include "LinkedList.h"

using std::cout;
using std::endl;

class OUT_OF_BOUNDS{
public:
    const char * what() {
        return "OUT OF BOUNDS";
    }
};

template<class T>
class Stack{
private:
    LinkedList<T> stackData;
    T top;
    size_t stackSize;

public:
    Stack();
    T pop();
    T peek();
    void push(T);
    bool isEmpty();

    T topValue();
    size_t sizeOfStack();
};

template<class T>
Stack<T>::Stack(): stackSize(0){
}

template<class T>
T Stack<T>::pop(){
    T returnValue;
    if(!isEmpty()) {
        returnValue = stackData.popFirstNode();
        if(stackData.head != 0){
            top = stackData.head->getData();
        }
        return returnValue;
    }                             // returns stored data1
    return returnValue;
}

template<class T>
void Stack<T>::push(T x){
    stackData.pushToFront(x);
    top = x;                           // pushes element onto DSLinkedList
    stackSize++;
}

template<class T>
T Stack<T>::peek(){                           // returns tail of data linked list
    try {
        return this->stackData.getAt(this->stackData.getListSize() - 1);
    } catch (OUT_OF_BOUNDS) {
        throw OUT_OF_BOUNDS();
    }
}

template<class T>
T Stack<T>::topValue(){
    return top;
}

template<class T>
size_t Stack<T>::sizeOfStack(){
    return stackSize;
}

template<class T>
bool Stack<T>::isEmpty(){                 // checks to see if DSLinkedList is empty
    return ( (this->stackData.head == nullptr) ? true : false);
}

#endif //DATASTRUCTURES_STACK_H
