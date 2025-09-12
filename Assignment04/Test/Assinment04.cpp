//
// File:    josephus.cpp
// Author:  Dr. Adam Lewis
// Modified by: Jayson Hamilton
// Purpose:
// Solve the Josephus problem using the Queue class.
//

#include <iostream>
#include "Queue.hpp"

int solveJosephus(int numPlayers, int passCount) {
    Queue<int> circle;

    // Initialize the queue with player numbers
    for (int i = 1; i <= numPlayers; ++i) {
        circle.push(i);
    }

    // Simulate the game
    while (circle.size() > 1) {
        for (int i = 0; i < passCount; ++i) {
            int temp = circle.front();
            circle.pop();
            circle.push(temp); // rotate
        }
        // Eliminate the player holding the hot potato
        std::cout << "Eliminated: " << circle.front() << std::endl;
        circle.pop();
    }

    // Return the last remaining player
    return circle.front();
}

int main() {
    int N, M;
    std::cout << "Enter number of players (N): ";
    std::cin >> N;
    std::cout << "Enter number of passes (M): ";
    std::cin >> M;

    int winner = solveJosephus(N, M);
    std::cout << "Winner: Player " << winner << std::endl;

    return 0;
}