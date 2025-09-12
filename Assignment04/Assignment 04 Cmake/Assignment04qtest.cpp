//
// File:   listtest.cpp
// Author: Jayson Hamilton
// Assisted by: Copilot
// Purpose:
// Demonstrate the use of the Queue class as part of Assignment04.
//

#include <iostream>
#include "Queue.hpp"

// Helper function to print each item in the queue
void printItem(int &item) {
    std::cout << item << " ";
}

int main() {
    Queue<int> aQueueOfIntegers;

    // Check if the queue is initially empty
    if (aQueueOfIntegers.empty()) {
        std::cout << "Yep, the new queue is empty." << std::endl;
    }

    // Push integers 3 to 0 into the queue
    for (int i = 3; i >= 0; i--) {
        aQueueOfIntegers.push(i);
    }

    // Traverse and print the queue contents
    std::cout << "Queue contents after push: ";
    aQueueOfIntegers.traverse(printItem);
    std::cout << std::endl;

    // Pop three elements, printing the back before each pop
    std::cout << "Popping three elements (showing back before each pop): ";
    for (int i = 0; i < 3; i++) {
        int datum = aQueueOfIntegers.back();
        std::cout << datum << " ";
        aQueueOfIntegers.pop();
    }
    std::cout << std::endl;

    // If queue is not empty, print remaining contents
    if (!aQueueOfIntegers.empty()) {
        std::cout << "Remaining queue contents: ";
        aQueueOfIntegers.traverse(printItem);
        std::cout << std::endl;
    }

    // Push a new value and show final state
    aQueueOfIntegers.push(42);
    std::cout << "Queue after pushing 42: ";
    aQueueOfIntegers.traverse(printItem);
    std::cout << std::endl;

    return 0;
}