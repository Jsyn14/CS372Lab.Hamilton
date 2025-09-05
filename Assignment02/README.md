
# Vector Class Library

A comprehensive C++ class library implementing Vector, Array, and ReceiptBag classes with performance analysis.

## Overview

This project implements a custom Vector class library with the following components:

## 1. Vector Classes (`MyVector.hpp`)
- **Vector**: Base class with power-of-two growth using for-loop copying
- **VectorCopy**: Derived class using STL `copy` algorithm for better performance
- **VectorGrow4**: Derived class starting with capacity 128 and growing by factor of 4

## 2. Array Template Class (`MyArray.hpp`)
- Type-safe wrapper around C++ arrays
- Template parameterized by data type and size
- Provides cohesion with Vector class in the library

## 3. ReceiptBag Class (`ReceiptBag.hpp`)
- Bag ADT with receipt-based removal system
- Insert operations return unique receipts
- Remove operations require valid receipts
