
#include <iostream>
#include <chrono>
#include <vector>
#include "MyVector.hpp"

using namespace std;
using namespace std::chrono;

// Function to time vector operations
template<typename VectorType>
void timeVectorOperations(const string& vectorName) {
    cout << "\n=== Testing " << vectorName << " ===" << endl;
    cout << "Size\tTime (ms)" << endl;
    
    for (int exp = 1; exp <= 12; ++exp) {
        int size = 1 << exp; // Powers of 2: 2, 4, 8, 16, ...
        
        VectorType v;
        
        auto start = high_resolution_clock::now();
        
        for (int i = 0; i < size; ++i) {
            v.push_back(i);
        }
        
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<microseconds>(end - start);
        
        cout << size << "\t" << duration.count() / 1000.0 << endl;
    }
}

int main() {
    cout << "Vector Performance Comparison" << endl;
    cout << "============================" << endl;
    
    // Test base Vector class
    timeVectorOperations<Vector>("Base Vector (for-loop copy)");
    
    // Test VectorCopy class
    timeVectorOperations<VectorCopy>("VectorCopy (STL copy)");
    
    // Test VectorGrow4 class
    timeVectorOperations<VectorGrow4>("VectorGrow4 (start 128, grow x4)");
    
    return 0;
}
