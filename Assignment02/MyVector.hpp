
#pragma once
#include <cstddef>
#include <stdexcept>
#include <algorithm>

class Vector {
protected:
    int* data;
    size_t _size;
    size_t _capacity;

    virtual void grow() {
        size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
        int* new_data = new int[new_capacity];
        
        // Use for-loop copying (base implementation)
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = data[i];
        }
        
        delete[] data;
        data = new_data;
        _capacity = new_capacity;
    }

public:
    Vector() : data(nullptr), _size(0), _capacity(0) {}
    
    virtual ~Vector() {
        delete[] data;
    }
    
    // Copy constructor
    Vector(const Vector& other) : data(nullptr), _size(0), _capacity(0) {
        if (other._size > 0) {
            _capacity = other._capacity;
            data = new int[_capacity];
            _size = other._size;
            for (size_t i = 0; i < _size; ++i) {
                data[i] = other.data[i];
            }
        }
    }
    
    // Assignment operator
    Vector& operator=(const Vector& other) {
        if (this != &other) {
            delete[] data;
            data = nullptr;
            _size = 0;
            _capacity = 0;
            
            if (other._size > 0) {
                _capacity = other._capacity;
                data = new int[_capacity];
                _size = other._size;
                for (size_t i = 0; i < _size; ++i) {
                    data[i] = other.data[i];
                }
            }
        }
        return *this;
    }
    
    void push_back(int value) {
        if (_size >= _capacity) {
            grow();
        }
        data[_size++] = value;
    }
    
    size_t size() const { return _size; }
    size_t capacity() const { return _capacity; }
    
    int& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
    
    const int& operator[](size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
};

class VectorCopy : public Vector {
protected:
    void grow() override {
        size_t new_capacity = (_capacity == 0) ? 1 : _capacity * 2;
        int* new_data = new int[new_capacity];
        
        // Use STL copy algorithm
        std::copy(data, data + _size, new_data);
        
        delete[] data;
        data = new_data;
        _capacity = new_capacity;
    }
};

class VectorGrow4 : public Vector {
protected:
    void grow() override {
        size_t new_capacity;
        if (_capacity == 0) {
            new_capacity = 128; // Start with 128
        } else {
            new_capacity = _capacity * 4; // Grow by factor of 4
        }
        
        int* new_data = new int[new_capacity];
        
        // Use for-loop copying
        for (size_t i = 0; i < _size; ++i) {
            new_data[i] = data[i];
        }
        
        delete[] data;
        data = new_data;
        _capacity = new_capacity;
    }
};
