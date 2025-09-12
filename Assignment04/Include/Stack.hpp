#ifndef STACK_HPP
#define STACK_HPP

#include <vector>
#include <stdexcept>

template <typename T>
class Stack {
private:
    std::vector<T> data;

public:
    // Check if the stack is empty
    bool empty() const {
        return data.empty();
    }

    // Return the number of elements
    size_t size() const {
        return data.size();
    }

    // Push an item onto the stack
    void push(const T& item) {
        data.push_back(item);
    }

    // Pop the top item off the stack
    void pop() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        data.pop_back();
    }

    // Access the top item
    T& front() {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Stack is empty");
        }
        return data.back();
    }

    // Traverse the stack and apply a function to each item
    void traverse(void (*visit)(T&)) {
        for (auto it = data.rbegin(); it != data.rend(); ++it) {
            visit(*it);
        }
    }
};

#endif // STACK_HPP