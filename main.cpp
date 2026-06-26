#include <iostream>
#include "DynamicArray.h"

// Helper function requires scope resolution for the nested enum
void printResult(DynamicArray::Result res) {
    switch (res) {
        case DynamicArray::SUCCESS: std::cout << "SUCCESS" << std::endl; break;
        case DynamicArray::OUT_OF_BOUNDS: std::cout << "OUT_OF_BOUNDS" << std::endl; break;
        case DynamicArray::NOT_FOUND: std::cout << "NOT_FOUND" << std::endl; break;
    }
}

int main() {
    DynamicArray arr;


    arr.append(10);
    arr.append(30);
    arr.append(40);
    
    std::cout << "Initial array: ";
    arr.print();

    // Test 1: Successful insertion
    std::cout << "\n--- Testing insert() ---" << std::endl;
    std::cout << "Inserting 20 at index 1. Result: ";
    printResult(arr.insert(1, 20));
    std::cout << "Array after insert: ";
    arr.print();

    // Test 2: Out of bounds insertion
    std::cout << "Inserting at index 10. Result: ";
    printResult(arr.insert(10, 99));

    // Test 3: Successful removal
    std::cout << "\n--- Testing remove() ---" << std::endl;
    std::cout << "Removing element at index 2 (value 30). Result: ";
    printResult(arr.remove(2));
    std::cout << "Array after removal: ";
    arr.print();

    // Test 4: Out of bounds removal
    std::cout << "Removing at index -1. Result: ";
    printResult(arr.remove(-1));

    // Test 5: Successful find
    std::cout << "\n--- Testing find() ---" << std::endl;
    int index;
    std::cout << "Finding value 40. Result: ";
    
    // Using the scoped enum type for the variable
    DynamicArray::Result findRes = arr.find(40, index);
    printResult(findRes);
    if (findRes == DynamicArray::SUCCESS) {
        std::cout << "Found at index: " << index << std::endl;
    }

    // Test 6: Unsuccessful find
    std::cout << "Finding value 100. Result: ";
    printResult(arr.find(100, index));

    return 0;
}