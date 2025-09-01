
# Vector Class Library

A comprehensive C++ class library implementing Vector, Array, and ReceiptBag classes with performance analysis.

## Overview

This project implements a custom Vector class library with the following components:

### 1. Vector Classes (`MyVector.hpp`)
- **Vector**: Base class with power-of-two growth using for-loop copying
- **VectorCopy**: Derived class using STL `copy` algorithm for better performance
- **VectorGrow4**: Derived class starting with capacity 128 and growing by factor of 4

### 2. Array Template Class (`MyArray.hpp`)
- Type-safe wrapper around C++ arrays
- Template parameterized by data type and size
- Provides cohesion with Vector class in the library

### 3. ReceiptBag Class (`ReceiptBag.hpp`)
- Bag ADT with receipt-based removal system
- Insert operations return unique receipts
- Remove operations require valid receipts

## Files

- `MyVector.hpp` - Vector class implementations
- `MyArray.hpp` - Array template class
- `ReceiptBag.hpp` - ReceiptBag template class
- `vector_test.cpp` - Google Test unit tests for Vector classes
- `timing_test.cpp` - Performance comparison of Vector implementations
- `array_test.cpp` - Test program for Array class
- `receipt_bag_test.cpp` - Test program for ReceiptBag class
- `Makefile` - Build configuration

## Building

To build all programs:
```bash
make all
```

To build individual programs:
```bash
make vector_test     # Google Test unit tests
make timing_test     # Performance analysis
make array_test      # Array class tests
make receipt_bag_test # ReceiptBag class tests
```

To run all tests:
```bash
make test
```

## Usage

### Vector Classes
```cpp
#include "MyVector.hpp"

Vector v;              // Base vector
VectorCopy vc;         // STL copy version
VectorGrow4 vg;        // Large initial capacity, 4x growth

v.push_back(42);
cout << v.size() << endl;
```

### Array Class
```cpp
#include "MyArray.hpp"

Array<int, 10> arr;    // Array of 10 integers
arr[0] = 42;
arr.fill(0);           // Fill with zeros
```

### ReceiptBag Class
```cpp
#include "ReceiptBag.hpp"

ReceiptBag<string> bag;
int receipt = bag.insert("item");
string item = bag.remove(receipt);
```

## Performance Analysis

The timing test compares three Vector implementations:
1. Base Vector with for-loop copying
2. VectorCopy with STL copy algorithm
3. VectorGrow4 with optimized growth strategy

Run `./timing_test` to see performance differences across different input sizes.

## Design Features

- **Polymorphism**: Uses virtual functions for different growth strategies
- **Template Classes**: Array and ReceiptBag are fully templated
- **Type Safety**: Array class provides bounds checking
- **Memory Management**: Proper RAII with destructors
- **STL Compatibility**: Uses STL algorithms where appropriate

## Requirements

- C++17 compatible compiler (g++, clang++, or MSVC)
- Make build system (optional, manual compilation commands provided)
- Google Test library (optional, only for unit tests)

## Compilation

### Quick Start (without Google Test)
```bash
g++ -std=c++17 -g -Wall timing_test.cpp -o timing_test
g++ -std=c++17 -g -Wall array_test.cpp -o array_test
g++ -std=c++17 -g -Wall receipt_bag_test.cpp -o receipt_bag_test
```

### Using Makefile
```bash
make all    # Compile all programs
make test   # Run all tests
```

See `compile_instructions.md` for detailed setup instructions for different environments.
