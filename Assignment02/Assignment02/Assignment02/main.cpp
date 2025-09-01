#include <iostream>
#include <chrono>
#include <iomanip>
#include "MyVector.hpp"
using namespace std;

template <class Vec>
void bench(const char* label) {
    cout << "Benchmarking " << label << "\n";
    for (int n = 2; n <= 4096; n *= 2) {
        Vec v;
        auto t0 = chrono::steady_clock::now();
        for (int i = 0; i < n; ++i) v.push_back(i);
        auto t1 = chrono::steady_clock::now();
        double ms = chrono::duration<double, milli>(t1 - t0).count();
        cout << "N=" << setw(4) << n << "  time=" << fixed << setprecision(4) << ms << " ms\n";
    }
    cout << "\n";
}

int main() {
    bench<Vector>("Base (for-loop copy, ×2 growth)");
    bench<VectorCopy>("std::copy (×2 growth)");
    bench<VectorGrow4>("start=128, ×4 growth");
    return 0;
}
