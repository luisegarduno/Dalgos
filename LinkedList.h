//
// Created by Luis on 6/4/2020.
//

#ifndef DATASTRUCTURES_LINKEDLIST_H
#define DATASTRUCTURES_LINKEDLIST_H

#include "Node.h"
#include <iomanip>
#include <fstream>
#include <climits>
#include <iostream>

using std::cout;
using std::endl;
using std::fstream;

template<class T>
class LinkedList{

    Node<T> * head;
    Node<T> * tail;
    Node<T> * iterator;

    int size{};                           // Size of Linked List

    private:
        void remove(Node<T>*);        // Remove node

    public:
        LinkedList();
        explicit LinkedList(T);
        LinkedList(const LinkedList<T>&);

        void print();                   // print all values in Linked List
        void printMatrix(int);          // prints matrix
        void printGraph_ToFile(fstream&);
        void printMatrix_ToFile(fstream&,int);

        void clear();                   // Clears the Linked List, also used to destruct memory from heap
        void append(T);                 // add node to Linked List
        void removeAt(int);             // remove specific index value (passed in parameter)
        void popLastNode();

        T getAt(T);                     // returns element at specific index
        LinkedList<T>& operator=(const LinkedList<T>&);

        bool operator!=(const LinkedList<T>&) const;
        int getListSize() const;

        // Custom Iterator

        T& getIterator();               // Custom iterator functions
        T& getNextIterator();
        void resetIterator();
        void iterateForward();
        bool iteratorIsValid();

        void setLinkedList_head(Node<T> *);
        void setLinkedList_tail(Node<T> *);
        void setLinkedList_iterator(Node<T> *);

        Node<T> * getLinkedList_head();
        Node<T> * getLinkedList_tail();
        Node<T> * getLinkedList_iterator();

        ~LinkedList();
};

template<class T>               // Default constructor
LinkedList<T>::LinkedList(): head(nullptr), tail(nullptr), iterator(nullptr), size(0){
}

template<class T>
LinkedList<T>::LinkedList(T x) {
    head = new Node<T>(x);
    size++;

}

template<class T>
LinkedList<T>::LinkedList(const LinkedList<T>& originalLinkedList){

    if(originalLinkedList.head == nullptr){       // if original Linked List is empty
        head = tail = nullptr;                    // head is = to nullptr
    }

    else{
        Node<T>* aCurrent = originalLinkedList.head;
        head = tail = nullptr;
        auto count = 0;

        while(aCurrent != nullptr){
            auto* newNode = new Node<T>();
            newNode->setPreviousNode(nullptr);
            newNode->setNextNode(nullptr);
            newNode->setData(aCurrent->getData());

            if(count == 0){
                head = tail = newNode;
            }
            else {
                tail->setNextNode(newNode);
                newNode->setPreviousNode(tail);
                tail = tail->getNextNode();
            }
            ++count;
            aCurrent = aCurrent->getNextNode();
        }
    }
}

template<class T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T>& v2LinkedList) {
    if(this != &v2LinkedList){

        if(v2LinkedList.head == nullptr){
            head = tail = nullptr;
        }

        else {
            this->clear();

            Node<T>* newHead;
            Node<T>* newTail;

            newHead = v2LinkedList.getLinkedList_head();
            newTail = v2LinkedList.getLinkedList_tail();

            setLinkedList_head(newHead);
            Node<T>* temp;

            while(newHead != nullptr){
                temp = new Node<T>(newHead->getData());
                newTail->setNextNode(temp);
                newTail = newTail->getNextNode();
                newHead = newHead->getNextNode();
            }
        }
    }

    return *this;
}

template<class T>
void LinkedList<T>::append(T x){
    auto* newNode = new Node<T>(x);

    if(head == nullptr){            // if Linked List is empty
        head = newNode;             // declare new node as the head and tail
        tail = newNode;
    }
    else{
        tail->setNextNode(newNode);             // if linked list contains node already, set the node after the tail = to new node(previously nullptr)
        newNode->setPreviousNode(tail);         // at the end, the previous node prior to declaring new node, is the tail
        tail = newNode;                         // declare new node as the tail
    }
    size++;                                     // increment Linked List Size
}

template<class T>
void LinkedList<T>::resetIterator(){
    this->iterator = this->head;                // set's the iterator Nodeptr to the head of LinkedList
}

template<class T>
T& LinkedList<T>::getIterator(){
    return *(iterator->getData());              // return iterator node data
}

template<class T>
T& LinkedList<T>::getNextIterator(){            // points to the next node in the LinkedList
    this->iterator = this->iterator->getNextNode();
    return *(iterator->getData());
}

template<class T>
void LinkedList<T>::iterateForward(){
    if(this->iterator != nullptr || this->iterator->getNextNode() != nullptr){
        this->iterator = this->iterator->getNextNode();
    }
}

template<class T>
bool LinkedList<T>::iteratorIsValid(){
    return this->iterator != nullptr;
}

template<class T>
int LinkedList<T>::getListSize() const{
    return size;
}

template<class T>
void LinkedList<T>::removeAt(int index){
    if (index >= size) {                        // if index is greater than Linked List Size
        std::cout << "\nNothing here: (index >= size)" << index << std::endl << std::endl;
    }
    else {
        Node<T>* temp = head;                   // set the head = to temp Current node
        int count = 0;                          // counter

        while (count != index) {
            temp = temp->getNextNode();         // set the iterator node = to the next node
            count++;                            // increment counter until index is reached
        }

        remove(temp);

        size--;                                 // decrement Linked List size
    }
}

template<class T>
void LinkedList<T>::print(){
    if(head == nullptr){
        cout << "Nothing Available" << endl;
    }

    else{
        Node<T>* aCurrent = head;

        while(aCurrent != nullptr){             // cycles & prints all values in linked list
            cout << aCurrent->getData()->getVertexNode_B() << " (";
            cout << aCurrent->getData()->getWeight() << ")";
            aCurrent = aCurrent->getNextNode();
            if(aCurrent != nullptr){
                cout << "--> ";
            }
        }
        cout << endl;
    }
}

template<class T>
void LinkedList<T>::printMatrix(int x){
    if(head == nullptr){
        cout << "Nothing Available" << endl;
    }

    else{
        Node<T>* vertex_Iterator = head;
        int counter = 1;
        int vertexNode_A = stoi(vertex_Iterator->getData()->getVertexNode_A());

        while(vertex_Iterator != nullptr){
            int vertexNode_B = stoi(vertex_Iterator->getData()->getVertexNode_B());

            if(vertexNode_A == vertexNode_B || vertexNode_A == counter){
                if(vertexNode_A == counter){
                    cout << std::setw(4) << std::left << "0";
                    counter++;
                    vertex_Iterator = vertex_Iterator->getNextNode();
                    continue;
                }
            }

            else if(vertexNode_B < counter){
                if(counter > x){
                    counter = vertexNode_A + 1;
                }
            }

            if(vertexNode_B != counter){
                while(vertexNode_A != counter && counter <= x){
                    counter++;
                }
            }

            else if(vertexNode_B == counter){
                if(vertex_Iterator->getData()->getWeight() == INT_MAX){
                    cout << std::setw(4) << std::left << "INF";
                    counter++;
                }
                else if(vertex_Iterator->getData()->getWeight() != INT_MAX) {
                    cout << std::setw(4) << std::left << vertex_Iterator->getData()->getWeight();
                    counter++;
                }

                if(counter > x){
                    break;
                }
            }

            vertex_Iterator = vertex_Iterator->getNextNode();

            if(vertex_Iterator == nullptr){
                while(counter <= x){
                    cout << std::setw(4) << std::left << "0";
                    counter++;
                }
                vertex_Iterator == nullptr;
            }
        }
        cout << endl;
    }
}

template<class T>
void LinkedList<T>::printGraph_ToFile(fstream& fout){
    if(head == nullptr){
        fout << "Nothing Available" << endl;
    }

    else{
        Node<T>* aCurrent = head;

        while(aCurrent != nullptr){             // cycles & prints all values in linked list
            fout << aCurrent->getData()->getVertexNode_B() << " (";
            fout << aCurrent->getData()->getWeight() << ")";
            aCurrent = aCurrent->getNextNode();
            if(aCurrent != nullptr){
                fout << "--> ";
            }
        }
        fout << endl;
    }
}

template<class T>
void LinkedList<T>::printMatrix_ToFile(fstream& fout, int x){

    if(head == nullptr){
        fout << "Nothing Available" << endl;
    }

    else{
        Node<T>* vertex_Iterator = head;
        int counter = 1;
        int vertexNode_A = stoi(vertex_Iterator->getData()->getVertexNode_A());

        while(vertex_Iterator != nullptr){
            int vertexNode_B = stoi(vertex_Iterator->getData()->getVertexNode_B());

            if(vertexNode_A == vertexNode_B || vertexNode_A == counter){
                if(vertexNode_A == counter){
                    fout << std::setw(4) << std::left << "0";
                    counter++;
                    vertex_Iterator = vertex_Iterator->getNextNode();
                    continue;
                }
            }

            else if(vertexNode_B < counter){
                if(counter > x){
                    counter = vertexNode_A + 1;
                }
            }

            if(vertexNode_B != counter){
                while(vertexNode_A != counter && counter <= x){
                    counter++;
                }
            }

            else if(vertexNode_B == counter){
                if(vertex_Iterator->getData()->getWeight() == INT_MAX){
                    fout << std::setw(4) << std::left << "INF";
                    counter++;
                }
                else if(vertex_Iterator->getData()->getWeight() != INT_MAX) {
                    fout << std::setw(4) << std::left << vertex_Iterator->getData()->getWeight();
                    counter++;
                }
                if(counter > x){
                    break;
                }
            }

            vertex_Iterator = vertex_Iterator->getNextNode();

            if(vertex_Iterator == nullptr){
                while(counter <= x){
                    fout << std::setw(4) << std::left << "0";
                    counter++;
                }
                vertex_Iterator == nullptr;
            }
        }
        fout << endl;
    }
}

template<class T>
void LinkedList<T>::remove(Node<T>* iteratorNode){
    Node<T>* nextNode = iteratorNode->next;
    Node<T>* previousNode = iteratorNode->previous;

    if (nextNode != nullptr) {
        nextNode->previous = previousNode;
    }
    if (previousNode != nullptr) {
        previousNode->next = nextNode;
    }
    if (iteratorNode == head) {
        head = nextNode;                    // deletes head and new head is declared
    }
    if (iteratorNode == tail) {             // deletes tail
        tail = previousNode;
    }
    delete iteratorNode;

    resetIterator();

}

template<class T>
void LinkedList<T>::popLastNode(){
    remove(tail);

    size--;
}

template<class T>
T LinkedList<T>::getAt(T x){
    if(head == nullptr){
        return -1;
    }
    else{
        Node<T>* aCurrent = head;           // begin at head

        for(int i = 0; i < x; i++){
            aCurrent = aCurrent->next;      // cycle through Linked List
        }

        return aCurrent->data;              // return element from linked list (specified in parameter
    }
}

template<class T>
void LinkedList<T>::clear(){
    Node<T>* c = getLinkedList_head();
    while(c != nullptr){
        c = c->getNextNode();
        delete getLinkedList_head();
        setLinkedList_head(c);
    }
}

template<class T>
void LinkedList<T>::setLinkedList_head(Node<T> * newHead){
    head = newHead;
}

template<class T>
void LinkedList<T>::setLinkedList_tail(Node<T> * newTail){
    tail = newTail;
}

template<class T>
void LinkedList<T>::setLinkedList_iterator(Node<T> * newIterator){
    iterator = newIterator;
}

template<class T>
Node<T> * LinkedList<T>::getLinkedList_head(){
    return head;
}

template<class T>
Node<T> * LinkedList<T>::getLinkedList_tail(){
    return tail;
}

template<class T>
Node<T> * LinkedList<T>::getLinkedList_iterator(){
    return iterator;
}


template<class T>
bool LinkedList<T>::operator!=(const LinkedList<T>& aLinkedList)const {
    if(this->head != aLinkedList.head){
        return true;
    }
    if(this->tail != aLinkedList.tail){
        return true;
    }
    if(this->iterator != aLinkedList.iterator){
        return true;
    }

    if(size != aLinkedList.size){
        return true;
    }
    if(head != nullptr){
        Node<T>* c = head;
        for(int i = 0; i < size; i++){
            if(c == nullptr){
                return false;
            }
            c = c->next;
        }
        return true;
    }

    if(this->iterator != aLinkedList.iterator){
        return true;
    }
    return this->iterator->data != aLinkedList.iterator->data;

}

template<class T>
LinkedList<T>::~LinkedList<T>(){
    clear();                                // call the clear member function to deconstruct elements from HEAP
}

#endif //DATASTRUCTURES_LINKEDLIST_H
