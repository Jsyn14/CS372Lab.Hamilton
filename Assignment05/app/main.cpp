#include <algorithm>
#include <chrono>
#include <iostream>
#include <limits>
#include <random>
#include <string>
#include <vector>
#include "sort_algorithms.hpp"

using Clock = std::chrono::high_resolution_clock;

struct Algo {
    const char* name;
    void (*fn)(std::vector<int>&);
    bool is_n2;
};

static long long time_ms(std::vector<int> data, void(*fn)(std::vector<int>&)) {
    auto start = Clock::now();
    fn(data);
    auto end = Clock::now();
    return std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
}

int main() {
    std::vector<int> sizes = {10, 50, 100, 500, 1000, 5000, 10000, 50000, 100000, 250000};

    const Algo algos[] = {
        {"bubble",    sorts::bubble_sort<int>,    true},
        {"selection", sorts::selection_sort<int>, true},
        {"insertion", sorts::insertion_sort<int>, true},
        {"quicksort", sorts::quicksort<int>,      false}
    };

    std::mt19937 rng(42);
    std::uniform_int_distribution<int> dist(std::numeric_limits<int>::min(), std::numeric_limits<int>::max());

    std::cout << "size,algorithm,milliseconds\n";
    for (int n : sizes) {
        std::vector<int> base(n);
        for (int i = 0; i < n; ++i) base[i] = dist(rng);

        for (const auto& a : algos) {
            if (a.is_n2 && n > 100000) { // keep lab machines happy; adjust or remove if required
                std::cout << n << "," << a.name << ",\n";
                continue;
            }
            auto data = base;
            long long ms = time_ms(std::move(data), a.fn);
            std::cout << n << "," << a.name << "," << ms << "\n";
        }
    }
    return 0;
}
