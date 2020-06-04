//
// Created by Luis on 6/4/2020.
//

#ifndef DATASTRUCTURES_VECTOR_H
#define DATASTRUCTURES_VECTOR_H

#include <iostream>

template <typename T>
class Vector{
    private:
        T * data;                       // vector element data
        int sizeOfVector;             // vector size
        int capacity;                   // vector capacity
        bool aResize;                   // boolean flag to check if reSize is needed
        void reSize();                  // resizing vector
        bool isSorted;

    public:
        Vector();                     // default constructor
        Vector(int);
        Vector(const Vector&);      // copy constructor

        int getSize();                  // returns size of vector
        int getCapacity();              // returns vector capacity

        void clearVector();             // used to remove all the elements of the vector container
        void printVector();
        void swap(Vector&);           // used to swap the contents between 2 vectors
        void pushBack(const T&);        // push elements into a vector from the back
        void reserve(size_t);
        void assign(size_t,const Vector&);   // assigns new value to the vector elements by replacing old ones

        T& operator[](const int);
        T& operator=(T&);               // copy assignment operator
        Vector& popBack();            // pop/remove/delete's last element from vector
        Vector& operator+=(Vector&);
        Vector operator+(const Vector&) const;

        bool isEmpty() const;
        bool operator==(const Vector&) const;
        bool operator!=(const Vector&) const;

        T& elementIndex(int);

        ~Vector();
};

template <typename T>
Vector<T>::Vector(){                                // Default constructor
    capacity = 5;                                       // initial capacity size
    sizeOfVector = 0;
    this->data = new T[capacity];                       // allocate memory for data
    aResize = false;
}

template <typename T>
Vector<T>::Vector(int numOfElements){
    capacity = 5;
    sizeOfVector = numOfElements;
    if(sizeOfVector > capacity){
        capacity = sizeOfVector;
    }
    this->data = new T[capacity];
}

template<typename T>
Vector<T>::Vector(const Vector<T>& originalVector){
    capacity = originalVector.capacity;               // copy originalVector capacity
    sizeOfVector = originalVector.sizeOfVector;   // copy originalDSVector size
    this->data = new T[capacity];                       // dynamically allocate data

    for(int i = 0; i < capacity; i++){
        this->data[i] = originalVector.data[i];       // copy originalVector data
    }
}

template <typename T>
void Vector<T>::reSize(){
    capacity *= 2;                                      // doubles the capacity
    T * temp = new T[capacity];                         // create temp data array to copy elements

    for(int i = 0;i < sizeOfVector;i++) {
        temp[i] = this->data[i];                        // deep copy data to temp
    }
    delete [] this->data;                               // delete the memory allocated
    this->data = temp;

}

template <typename T>
int Vector<T>::getSize(){
    return sizeOfVector;                              // returns vector size
}

template <typename T>
int Vector<T>::getCapacity(){                         // returns vector capacity
    return capacity;
}

template <typename T>
void Vector<T>::pushBack(const T& anElement){         // add element to back of vector
    if(sizeOfVector == capacity){                     // if capacity is reached, resize
        reSize();
    }

    this->data[sizeOfVector] = anElement;             // add new element as the last vector element
    sizeOfVector += 1;                                // once added, the size of the vector increases by 1
}

template <typename T>
Vector<T>& Vector<T>::popBack(){                    //pop/remove elements from a vector from the back
    T * temps = this->data;                             // create pointer to = this->data
    sizeOfVector -= 1;                                // Since we are removing an element from the Vector, decrease size counter
    this->data = new T[capacity];

    for(int i = 0; i < sizeOfVector; i++){
        this->data[i] = temps[i];
    }

    delete [] temps;                                    // delete temp pointer
    return *this;
}

template <typename T>
void Vector<T>::swap(Vector<T>& bVector){         // used to swap the contents between 2 vectors

    int tempCapacity = capacity;                        // store capacity on stack
    capacity = bVector.getCapacity();                 // replace v1.capacity with v2.capacity
    bVector.capacity = tempCapacity;

    int tempSize = sizeOfVector;
    sizeOfVector = bVector.getSize();               // replace v2.size with temp.size
    bVector.sizeOfVector = tempSize;

    T * tempData = this->data;                          // use tempData to point to data
    this->data = bVector.data;                        // this->data now points to bVector.data
    bVector.data = tempData;                          // bVector now points to tempData
}

template <typename T>
void Vector<T>::reserve(size_t space){
    if(sizeOfVector < int(space)){
        capacity = int(space);
    }
}

template <typename T>
void Vector<T>::clearVector(){                        // used to remove all the elements of the vector container

    delete [] this->data;                               // completely delete all data

    capacity = 5;                                       // re-declare the values of private variables
    sizeOfVector = 0;
    this->data = new T[capacity];
}

template <typename T>
void Vector<T>::assign(size_t newX,const Vector<T>& assignElement){    // assigns new value to the vector elements by replacing old ones
    delete [] this->data;               // delete data from HEAP

    if(newX >= size_t(capacity)){
        capacity = newX;
        sizeOfVector = newX;
    }

    if(newX < size_t(sizeOfVector)){
        sizeOfVector = newX;
    }

    this->data = new T[capacity];       // assign capacity, size, data

    for(int i = 0; i < sizeOfVector; i++){
        this->data[i] = assignElement.data[i];
    }
}

template <typename T>
T& Vector<T>::operator=(T& v2){
    if(this != nullptr){
        delete [] data;
        this->capacity = v2.getCapacity();           // declare capacity = parameters capacity
        sizeOfVector = v2.getSize();               // declare sizeOfDsVector = parameters size
        this->data = new T[capacity];                // dynamically allocate data

        for(int i = 0;i < sizeOfVector; i++) {
            this->data[i] = v2.data[i];      // copy elements to new data array
        }
    }

    return *this;
}

template <typename T>
Vector<T> Vector<T>::operator+(const Vector<T>& aVector) const{
    Vector<T> tempVector;                             // create the vector we will be returning
    tempVector.sizeOfVector = getSize() + aVector.getSize();
    tempVector.capacity = tempVector.getSize();

    T * tempData = this->data;                          // temporarily copy data
    this->data = new T[tempVector.getCapacity()];       // allocate memory for data on heap

    for(int i = 0; i < this->data.getSize(); i++){
        this->data[i] = tempData->data[i];              // iteratively add v1 data to new data
    }

    for(int j = 0; j < aVector.getSize(); j++){
        this->data[j + tempData->getSize()] = aVector.data[j];    // continue adding data starting from where
    }                                                               // last element index number

    tempVector.data = this->data;
    this->data = tempData;

    delete [] tempData;
    return tempVector;
}

template <typename T>
Vector<T>& Vector<T>::operator+=(Vector<T>& v2){
    T * temp = this->data;                               // copy data temporarily to the heap


    this->data = new T[sizeOfVector + v2.getSize()];   // allocate memory for data on HEAP

    for(int i = 0; i < sizeOfVector; i++){
        this->data[i] = temp[i];                         // iteratively add v1 data elements to new data
    }

    for(int j = 0;j < v2.getSize(); j++){
        this->data[j + sizeOfVector] = v2.data[j];     // iteratively add v2 data elements to new data
    }

    capacity += v2.getCapacity();                        // capacity = capacity + aVector.getCapacity
    sizeOfVector += v2.getSize();

    delete [] temp;                                      // deallocate temp memory
    return *this;
}

template <typename T>
bool Vector<T>::operator==(const Vector& aVector)const{
    if(this->getCapacity() != aVector.getCapacity()){
        return false;
    }
    if(this->getSize() != aVector.getSize()){                 // if sizes do not match return false
        return false;
    }
    for (int i = 0;i < aVector.getSize(); i++) {
        if(this->data[i] != aVector.data[i]){
            return false;
        }
    }
    return true;                                                // if everything matches return true
}

template <typename T>
bool Vector<T>::operator!=(const Vector<T>& aVector) const{
    if(this->getCapacity() != aVector.getCapacity()){         // if capacities do not match return true
        return true;
    }
    if(this->getSize() != aVector.getSize()){
        return true;
    }
    for (int i = 0;i < aVector.getSize(); i++) {
        if(this->data[i] != aVector.data[i]){                 // if any data element's don't match
            return true;                                        // return true
        }
    }
    return false;                                               // if everything matches, return false
}

template <typename T>
bool Vector<T>::isEmpty() const{
    return sizeOfVector == 0;
    // if the size of the vector is >= 0 return false
}

template <typename T>
T& Vector<T>::operator[](const int indexLocation){
    //if(indexLocation < 0 || indexLocation > capacity - 1){      // if statement to check location exists
    //return -1;
    //}
    return *(this->data + indexLocation);                       // return element from Vector
}

template <typename T>
T& Vector<T>::elementIndex(int elementNumber){
    return this->data[elementNumber];
}

template <typename T>
void Vector<T>::printVector(){
    for(int i = 0; i < getSize(); i++){                         // returns every element in Vector
        if(i < (getSize() - 1)){
            std::cout << this->data[i] << " | ";
        }
        else{
            std::cout << this->data[i] << std::endl;            // once the end is reached, newline
        }
    }
}

template <typename T>
Vector<T>::~Vector(){
    if(this->data != nullptr){
        delete [] this->data;                                   // deallocate memory from heap
    }
}

#endif //DATASTRUCTURES_VECTOR_H
