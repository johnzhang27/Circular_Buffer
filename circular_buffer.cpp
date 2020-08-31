#include "circular_buffer.h"

// This is the constructor
template <typename T>
CircularBuffer<T>::CircularBuffer(unsigned int size){
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
    buf = new vector<T>[size];
    // Zero at this point because no element in the buffer.
    this->size = size;
    this->head = 0;
    this->tail = 0;
    this->num_Elements = 0;
    this->full = false;
}
// This is the destructor.
template <typename T>
CircularBuffer<T>::~CircularBuffer(){
    delete[] buf;
}
// Add element to our structure
template <typename T>
int CircularBuffer<T>:: Write(T element){
    if(isFull()){
        // Do reset or what, I dont know.
    }
    else{
        buf[head] = element;
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
        read = buf[tail];
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
    if((head == tail)&&(full != true)){
        temp = true;
    }
    return temp;
}
template <typename T>
void CircularBuffer<T>::Reset(){
    head = tail;
    full = false;
}

template <typename T>
size_t CircularBuffer<T>::Capacity(){
    return size;
}

template <typename T>
size_t CircularBuffer<T>::RemainingSize(){
    size_t RemSize = size;
    if(!full){
        if(head >= tail){
            RemSize = head - tail;
        }
        else{
            RemSize = size + head - tail;
        }
    }
    return RemSize;
}
template <typename T>
int CircularBuffer<T>::numElements(){
    int num = static_cast<int>(size);
    if(!full){
        if(head >= tail){
            num = num - (head - tail);
        }
        else{
            num = num - (num + head - tail);
        }
    }
    num_Elements = num;
    return num;
}
/*template <typename T>
int CircularBuffer<T>::Peek(int nth_element){
    int *ret = NULL;
    if(isEmpty() || (nth_element > num_Elements-1)){
        ret = NULL;
    }
    else{
        ret = ((head + nth_element) % size) * size;
    }
    return ret;
}*/