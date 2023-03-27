#include <iostream>
#include "Array.h"

using namespace mySTL;

int main() {
    // Create an array of integers with size 5
    Array<int, 5> arr;

    // Fill the array with some values
    for (size_t i = 0; i < arr.Size(); ++i) {
        arr[i] = i * 2;
    }

    // Print out the array
    for (size_t i = 0; i < arr.Size(); ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    // Modify the array using the Data() method
    int* dataPtr = arr.Data();
    for (size_t i = 0; i < arr.Size(); ++i) {
        *(dataPtr + i) = i * 3;
    }

    // Print out the modified array
    for (size_t i = 0; i < arr.Size(); ++i) {
        std::cout << "arr[" << i << "] = " << arr[i] << std::endl;
    }

    return 0;
}