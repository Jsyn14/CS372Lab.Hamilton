//
// File:    stacktest.cpp
// Author:  Dr. Adam Lewis
// Modified by: Jayson Hamilton
// Purpose:
// Basic demonstration of the Stack class for Assignment04.
//

#include <iostream>
#include "Stack.hpp"

// Function to display stack contents
void display(int &value) {
    std::cout << value << " ";
}

int main() {
    Stack<int> intStack;

    // Initial state check
    if (intStack.empty()) {
        std::cout << "Stack is currently empty." << std::endl;
    }

    // Push values onto the stack
    for (int i = 0; i < 4; ++i) {
        intStack.push(i);
    }

    std::cout << "Stack after pushing 0 through 3:" << std::endl;
    intStack.traverse(display);
    std::cout << std::endl;

    // Pop and display top values
    std::cout << "Popping top three values:" << std::endl;
    for (int i = 0; i < 3; ++i) {
        std::cout << intStack.front() << " ";
        intStack.pop();
    }
    std::cout << std::endl;

    // Show remaining stack contents
    if (!intStack.empty()) {
        std::cout << "Remaining stack:" << std::endl;
        intStack.traverse(display);
        std::cout << std::endl;
    }

    // Push a new value and display final state
    intStack.push(42);
    std::cout << "Stack after pushing 42:" << std::endl;
    intStack.traverse(display);
    std::cout << std::endl;

    return 0;
}