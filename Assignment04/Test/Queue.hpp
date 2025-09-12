#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <list>
#include <stdexcept>

template <typename T>
class Queue {
private:
    std::list<T> data;

public:
    // Check if the queue is empty
    bool empty() const {
        return data.empty();
    }

    // Return the number of elements
    size_t size() const {
        return data.size();
    }

    // Add an item to the back of the queue
    void push(const T& item) {
        data.push_back(item);
    }

    // Remove the item from the front of the queue
    void pop() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        data.pop_front();
    }

    // Access the item at the front
    T& front() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.front();
    }

    const T& front() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.front();
    }

    // Access the item at the back
    T& back() {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.back();
    }

    const T& back() const {
        if (empty()) {
            throw std::out_of_range("Queue is empty");
        }
        return data.back();
    }

    // Traverse the queue and apply a function to each item
    void traverse(void (*visit)(T&)) {
        for (auto& item : data) {
            visit(item);
        }
    }
};

#endif // QUEUE_HPP