#include "DynamicArray.h"
#include <cstdlib>
#include <iostream>

using namespace std;

// Private Helper
void DynamicArray::resize()
{
    int newCapacity = capacity * 2;
    int* temp = new int[newCapacity];

    for (int i = 0; i < size; i++)
    {
        temp[i] = data[i];
    }

    delete[] data;

    data = temp;
    capacity = newCapacity;
}


// Constructors
DynamicArray::DynamicArray()
    : data(new int[2]), size(0), capacity(2)
{
}

DynamicArray::DynamicArray(int initialCapacity)
    : data(new int[initialCapacity > 0 ? initialCapacity : 2]),
      size(0),
      capacity(initialCapacity > 0 ? initialCapacity : 2)
{
}

DynamicArray::DynamicArray(const DynamicArray& orgArray)
    : data(new int[orgArray.capacity]), size(orgArray.size), capacity(orgArray.capacity)
{
    for (int i = 0; i < size; i++)
    {
        data[i] = orgArray.data[i];
    }
}


// Destructor
DynamicArray::~DynamicArray()
{
    delete[] data;
}

// // Public Functions
void DynamicArray::append(int value)
{
    if (size >= capacity)
    {
        resize();
    }

    data[size] = value;
    size++;
}



void DynamicArray::append(const DynamicArray& other)
{
    while (capacity < size + other.size)
    {
        resize();
    }

    for (int i = 0; i < other.size; i++)
    {
        data[size + i] = other.data[i];
    }

    size += other.size;
}

DynamicArray::Result DynamicArray::insert(int index, int value)
{
    if (index < 0 || index > size)
    {
        return OUT_OF_BOUNDS;
    }

    if (size == capacity)
    {
        resize();
    }

    for (int i = size; i > index; i--)
    {
        data[i] = data[i - 1];
    }

    data[index] = value;
    size++;

    return SUCCESS;
}

DynamicArray::Result DynamicArray::remove(int index)
{
    if (index < 0 || index >= size)
    {
        return OUT_OF_BOUNDS;
    }

    for (int i = index; i < size - 1; i++)
    {
        data[i] = data[i + 1];
    }

    data[size - 1] = 0;
    size--;

    return SUCCESS;
}

DynamicArray::Result DynamicArray::find(int value, int& outIndex) const
{
    for (int i = 0; i < size; i++)
    {
        if (data[i] == value)
        {
            outIndex = i;
            return SUCCESS;
        }
    }

    return NOT_FOUND;
}

void DynamicArray::print() const
{
    cout << "[";
    for (int i = 0; i < size; i++)
    {
        cout << data[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }

    cout << "]" << endl;
}


int& DynamicArray::getAt(int index)
{
    if (index < 0 || index >= size)
    {
        cerr << "error" << endl;
        exit(1);
    }

    return data[index];
}
