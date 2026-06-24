#ifndef DYNAMIC_ARRAY
#define DYNAMIC_ARRAY
#include "DynamicArray.h"
#include <iostream>



class DynamicArray {

    private:
        int *data;
        int size;
        int capacity;


        // Helper
        void resize() {
        int *temp = new int[size * 2];
        for(int i = 0 ; i < size; i++) {
            temp[i] = data[i];
        }
        delete[] data;
        data = temp;
        capacity = (capacity * 2);
       }

       

    public:
        enum Result {
            SUCCESS,
            OUT_OF_BOUNDS,
            NOT_FOUND
    };


    // Constructors
    DynamicArray() 
        : size(0), capacity(2), data(new int[2])  {  
    }
    
    DynamicArray(int initialCapacity) 
        : size(0),  capacity(initialCapacity), data(new int[initialCapacity]) {
    }

    DynamicArray(const DynamicArray& orgArray) 
        : size(orgArray.size), capacity(orgArray.capacity)
    { 
        data = new int[capacity];
        for(int i = 0; i < size; i++) {
            data[i] = orgArray.data[i];
        }
    }

    // Destructor  
    ~DynamicArray() {
       delete[] data;
    }




    void append(int value) {
        if(size >= capacity) {
            resize();
        }

        data[size] = value;
        size++;
    }

    void append(const DynamicArray& other) {
        while(capacity - size <= other.size) {
            resize();
        }
        for(int i = size; i < other.size + size; i++) {
            data[size + i] = other.data[i];
        }
    }


    Result insert(int index, int value) {
        if(index >= size){
            return OUT_OF_BOUNDS;
        }
       
        if(capacity == size) {
            resize();
        }


        // [10] []  []  [] 
        // 0    1   2   3
        
        for(int i = index + 1 ; i <= size ; i++) {
            data[i] = data[i - 1];
        }

        data[index] = value;
        size = size + 1;
        return SUCCESS;
    }

    Result remove(int index) {
        return SUCCESS;
    }

    Result find(int value, int& outIndex) {
         return SUCCESS;
    }

    void print() {
        for(int i = 0; i < size; i++) {
            std::cout <<data[i]<<  std::endl;
        }
    }

};



#endif