// Author: Dr. Lewis
// Modified by: Jayson Hamilton
// Assisted by: Replit & Chat GPT

#include <iostream>
#include <chrono>
#include <vector>
#include <iomanip>
using namespace std;

void moveDisks(int, int, int, int);
void printIt(int, int, int);

int main() {
    const int FROMPEG = 1;
    const int TOPEG   = 3;
    const int TEMPPEG = 2;

    // Match the kinds of sizes shown in your screenshot
    vector<int> sizes = {6, 10, 15, 20, 30, 32, 35};

    cout << "Towers of Hanoi (recursive) timing\n";
    cout << "(move printing disabled for timing)\n\n";

    for (int numdisks : sizes) {
        auto t0 = chrono::steady_clock::now();
        moveDisks(numdisks, FROMPEG, TOPEG, TEMPPEG);
        auto t1 = chrono::steady_clock::now();

        // milliseconds to match the screenshot units
        double elapsed_ms =
            chrono::duration<double, std::milli>(t1 - t0).count();

        // Lines formatted like the screenshot
        cout << "Moved " << numdisks << " pegs from peg "
             << FROMPEG << " to peg " << TOPEG << "\n";
        cout << "Numdisks: " << numdisks << "\n";
        cout << "Elapsed time: " << fixed << setprecision(4)
             << elapsed_ms << " ms\n\n";
    }

    return 0;
}

void moveDisks(int num, int fromPeg, int toPeg, int tempPeg) {
    if (num > 0) {
        moveDisks(num - 1, fromPeg, tempPeg, toPeg);
        printIt(num, fromPeg, toPeg); // intentionally does nothing for timing
        moveDisks(num - 1, tempPeg, toPeg, fromPeg);
    }
}

void printIt(int /*disk*/, int /*fromPeg*/, int /*toPeg*/) {
  
}
