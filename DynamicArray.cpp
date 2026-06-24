#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
#include "DynamicArray.h"

class DynamicArray {

    private:
    int *data;
    int size;
    int capacity;


    public:
        enum Result {
            SUCCESS,
            OUT_OF_BOUNDS,
            NOT_FOUND
        };

    DynamicArray() 
        : size(0), capacity(1)  {
        }
    
    
    DynamicArray(int initialCapacity) 
        : capacity(initialCapacity) {
    }

    DynamicArray() {

    }

    // destrcutor  
    ~DynamicArray() {
        delete[];
    }

    void append(int value) {

    }

    void append(const DynamicArray& other) {

    }


    Result insert(int index, int value) {

    }

    Result remove(int index) {

    }

    Result find(int value, int& outIndex)
};



#endif