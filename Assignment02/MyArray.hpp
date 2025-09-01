
#pragma once
#include <cstddef>
#include <stdexcept>

template<typename T, size_t N>
class Array {
private:
    T data[N];
    size_t _size;

public:
    Array() : _size(N) {}
    
    explicit Array(size_t size) : _size(size) {
        if (size > N) {
            throw std::out_of_range("Size exceeds array capacity");
        }
    }
    
    // Array index operator
    T& operator[](size_t index) {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
    
    const T& operator[](size_t index) const {
        if (index >= _size) {
            throw std::out_of_range("Index out of bounds");
        }
        return data[index];
    }
    
    // Size and capacity methods
    size_t size() const { return _size; }
    size_t capacity() const { return N; }
    
    // Iterator support (basic)
    T* begin() { return data; }
    T* end() { return data + _size; }
    const T* begin() const { return data; }
    const T* end() const { return data + _size; }
    
    // Fill array with value
    void fill(const T& value) {
        for (size_t i = 0; i < _size; ++i) {
            data[i] = value;
        }
    }
};
