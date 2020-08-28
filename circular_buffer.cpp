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
    this->start = 0;
    this->end = 0;
    this->elements = 0;
}
// This is the destructor
template <typename T>
CircularBuffer<T>::~CircularBuffer(){
    delete[] *buf;
}
// Add element to our structure
template <typename T>
int CircularBuffer<T>:: Push(T element){

}
// This function is for checking whether the buffer is full or not.
template <typename T>
bool CircularBuffer<T>::isFull(){
    
}
