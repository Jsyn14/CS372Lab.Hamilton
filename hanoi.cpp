// Author: Dr. Lewis
// Modified by: Jayson Hamilton
// Assisted by: Replit and ChatGPT

#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
    if (num <= 0) return;
    moveDisks(num - 1, fromPeg, tempPeg, toPeg);
    // (intentionally no printing for timing)
    moveDisks(num - 1, tempPeg, toPeg, fromPeg);
}

int main() {
    constexpr int FROMPEG = 1;
    constexpr int TOPEG   = 3;
    constexpr int TEMPPEG = 2;

    // Test sizes
    const std::vector<int> sizes = {6, 10, 15, 20, 30, 32, 35};

    std::cout << "Towers of Hanoi (recursive) timing\n";
    std::cout << "(move printing disabled for timing)\n\n";

    for (int n : sizes) {
        auto t0 = std::chrono::steady_clock::now();
        moveDisks(n, FROMPEG, TOPEG, TEMPPEG);
        auto t1 = std::chrono::steady_clock::now();

        double elapsed_ms =
            std::chrono::duration<double, std::milli>(t1 - t0).count();

        std::cout << "Moved " << n << " disks from peg "
                  << FROMPEG << " to peg " << TOPEG << "\n";
        std::cout << "Numdisks: " << n << "\n";
        std::cout << "Elapsed time: " << std::fixed << std::setprecision(4)
                  << elapsed_ms << " ms\n\n";
    }
    return 0;
}
