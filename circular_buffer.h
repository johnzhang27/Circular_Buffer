#ifndef _CIRCULARBUFFER_H_
#define _CIRCULARBUFFER_H_

#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <set>
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
// Circualr buffer is like a 1st add 1st out stack.
template<typename T> class CircularBuffer
{
    private:
        vector<T> *buf;
        // This is a smart pointer function I found online, it can 
        // directly allocate space from memory(not sure).
        /* unique_ptr<T[]> buf_; */
        unsigned int numElements;
    public:
        // Constructor
        CircularBuffer(size_t size);
        // Destructor
        ~CircularBuffer();
        // Check if the circular buffer is full or not.
        bool isFull();
        // Check if the circualr buffer is empty or not.
        bool isEmpty();
        // "Push to stack", add elements to the buffer.
        int Push(T element);
        // Cout how many elements are in the circular buffer currently.
        int numElements();
        // "Pop out elements", remove the 1st added element from the circular buffer.
        T Pop();
        // This will return the pointer of nth element. If empty then NULL.
        void Peek(int)
        // Check the total capacity of the circular buffer.
        int Capacity();

};
#endif