#ifndef _CIRCULARBUFFER_H_
#define _CIRCULARBUFFER_H_

#include <vector>
#include <iostream>
#include <algorithm>
#include <fstream>
#include <utility> 
#include <cassert>
#include <string>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/ioctl.h>
#include <unistd.h>
#include <string.h>
#include <time.h>

using namespace std;
// It has to be power of 2 but since I don't know what is the required size
// So I put 64 here because my Arduino board is 64 KB.
#define BufferSize = 64
#include "circular_buffer.cpp"
// Circualr buffer is like a 1st add 1st out stack.
template<typename T> class CircularBuffer
{
    public:
        // Constructor
        CircularBuffer(unsigned int size);
        // Destructor
        ~CircularBuffer();
        // Check if the circular buffer is full or not.
        bool isFull();
        // Check if the circualr buffer is empty or not.
        bool isEmpty();
        // "Push to stack", add elements to the buffer.
        int Write(T element);
        // Cout how many elements are in the circular buffer currently.
        int numElements();
        // "Pop out elements", remove the 1st added element from the circular buffer.
        T Read();
        // This will return the pointer of nth element. If empty then NULL.
        /*int Peek(int nth_element);*/
        // Check the total capacity of the circular buffer or the remaining capacity.
        size_t Capacity();
        // Check the available size of the circular buffer.
        size_t RemainingSize();
        // Reset the buffer to empty state.
        void Reset();
    private:
        vector<T> *buf;
        // This is a smart pointer function I found online, it can 
        // directly allocate space from memory(not sure).
        /* unique_ptr<T[]> buf_; */
        unsigned int head, tail, num_Elements, size;
        bool full;
        T read;

};
#endif