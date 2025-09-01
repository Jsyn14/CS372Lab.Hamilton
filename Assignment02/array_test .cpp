
#include <iostream>
#include "MyArray.hpp"

using namespace std;

int main() {
    cout << "Array Template Class Test" << endl;
    cout << "=========================" << endl;
    
    // Test integer array
    Array<int, 10> intArray;
    cout << "Created Array<int, 10>" << endl;
    cout << "Size: " << intArray.size() << endl;
    cout << "Capacity: " << intArray.capacity() << endl;
    
    // Fill array with values
    for (size_t i = 0; i < intArray.size(); ++i) {
        intArray[i] = i * 2;
    }
    
    cout << "Array contents: ";
    for (size_t i = 0; i < intArray.size(); ++i) {
        cout << intArray[i] << " ";
    }
    cout << endl;
    
    // Test string array
    Array<string, 5> stringArray;
    stringArray[0] = "Hello";
    stringArray[1] = "World";
    stringArray[2] = "From";
    stringArray[3] = "Array";
    stringArray[4] = "Class";
    
    cout << "\nString array contents: ";
    for (size_t i = 0; i < stringArray.size(); ++i) {
        cout << stringArray[i] << " ";
    }
    cout << endl;
    
    // Test fill method
    Array<double, 3> doubleArray;
    doubleArray.fill(3.14);
    cout << "\nDouble array filled with 3.14: ";
    for (size_t i = 0; i < doubleArray.size(); ++i) {
        cout << doubleArray[i] << " ";
    }
    cout << endl;
    
    return 0;
}
