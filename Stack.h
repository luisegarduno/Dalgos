/*
 * Dalgos v1.0.0
 * Updated: 2022-06-24
 * --------------------------------------------
 * Created by Luis on 2020-06-04.
 */

#ifndef DS_STACK_H
#define DS_STACK_H

#include "Node.h"
#include <iostream>
#include "LinkedList.h"
#include "OUT_OF_BOUNDS.h"

using std::cout;
using std::endl;

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
        if(stackData.getLinkedList_head() != 0){
            top = *(stackData.getLinkedList_head()->getData());
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
    return this->stackData.getLinkedList_head() == nullptr;
}

#endif // DS_STACK_H
