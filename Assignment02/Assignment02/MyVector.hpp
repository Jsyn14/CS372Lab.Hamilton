#pragma once
#include <cstddef>
#include <algorithm>

// Base vector: start cap=1, double when full; copy with a for-loop
class Vector {
protected:
    int*   data_ = nullptr;
    size_t sz_   = 0;
    size_t cap_  = 0;

    virtual void grow() {
        size_t newCap = (cap_ == 0 ? 1 : cap_ * 2);
        int* newData = new int[newCap];
        for (size_t i = 0; i < sz_; ++i) newData[i] = data_[i]; // manual copy
        delete[] data_;
        data_ = newData;
        cap_  = newCap;
    }

public:
    Vector() = default;
    // Rule of Three
    Vector(const Vector& o) : data_(nullptr), sz_(o.sz_), cap_(o.cap_) {
        if (cap_) { data_ = new int[cap_]; for (size_t i=0;i<sz_;++i) data_[i]=o.data_[i]; }
    }
    Vector& operator=(const Vector& o) {
        if (this==&o) return *this;
        int* nd = (o.cap_ ? new int[o.cap_] : nullptr);
        for (size_t i=0;i<o.sz_;++i) nd[i]=o.data_[i];
        delete[] data_; data_=nd; sz_=o.sz_; cap_=o.cap_; return *this;
    }
    virtual ~Vector() { delete[] data_; }

    void push_back(int v) { if (sz_==cap_) grow(); data_[sz_++] = v; }
    size_t size() const { return sz_; }
    size_t capacity() const { return cap_; }
};

// Derived 1: same doubling but use std::copy (faster copy)
class VectorCopy : public Vector {
protected:
    void grow() override {
        size_t newCap = (cap_ == 0 ? 1 : cap_ * 2);
        int* newData = new int[newCap];
        std::copy(data_, data_ + sz_, newData);
        delete[] data_;
        data_ = newData;
        cap_  = newCap;
    }
};

// Derived 2: start at 128, then grow ×4 (fewer copies, more memory)
class VectorGrow4 : public Vector {
protected:
    void grow() override {
        size_t newCap = (cap_ == 0 ? 128 : cap_ * 4);
        int* newData = new int[newCap];
        for (size_t i = 0; i < sz_; ++i) newData[i] = data_[i];
        delete[] data_;
        data_ = newData;
        cap_  = newCap;
    }
};
