#include "circular_buffer.h"

// This is the constructor
template <typename T>
CircularBuffer<T>::CircularBuffer(size_t size){
    assert(size > 0);
    // I used a vector structure to simulate the buffer structure.
    // However if this is not how we want to store data, we could do:
    /*
    explicit circular_buffer(size_t size) :
	buf_(std::unique_ptr<T[]>(new T[size])),
	max_size_(size)
    {   
	    //empty constructor
    }
    */
    *buf = new vector<T>[size];
    // Zero at this point because no element in the buffer.
    numElements = 0;
    this->size = size;
    this->head = 0;
    this->tail = 0;
    this->elements_index = 0;
    this->full = false;
}
// This is the destructor
template <typename T>
CircularBuffer<T>::~CircularBuffer(){
    delete[] *buf;
}
// Add element to our structure
template <typename T>
int CircularBuffer<T>:: Write(T element){
    if(isFull()){
        // Do reset or what, I dont know.
    }
    else{
        *buf[head] = element;
        head=(head+1) % size;
        if(head == tail){
            full = true;
        }
    }

}
template <typename T>
T CircularBuffer<T>::Read(){
    if(isEmpty()){
        // No element to read.
    }
    else{
        read = *buf[tail];
        tail=(tail+1) % size;
        full = false;
    }

}
// This function is for checking whether the buffer is full or not.
template <typename T>
bool CircularBuffer<T>::isFull(){
    return full;
}
template <typename T>
bool CircularBuffer<T>::isEmpty(){
    bool temp = false;
    if(head == tail)&&(full != true){
        temp = true;
    }
    return temp;
}
