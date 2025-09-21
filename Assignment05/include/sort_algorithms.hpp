#ifndef SORT_ALGORITHMS_HPP
#define SORT_ALGORITHMS_HPP

#include <vector>

namespace sorts {

template <typename T>
void bubble_sort(std::vector<T>& a) {
    bool swapped;
    for (size_t i = 0; i + 1 < a.size(); ++i) {
        swapped = false;
        for (size_t j = 0; j + 1 < a.size() - i; ++j) {
            if (a[j+1] < a[j]) { std::swap(a[j], a[j+1]); swapped = true; }
        }
        if (!swapped) break;
    }
}

template <typename T>
void selection_sort(std::vector<T>& a) {
    for (size_t i = 0; i + 1 < a.size(); ++i) {
        size_t minIdx = i;
        for (size_t j = i + 1; j < a.size(); ++j)
            if (a[j] < a[minIdx]) minIdx = j;
        if (minIdx != i) std::swap(a[i], a[minIdx]);
    }
}

template <typename T>
void insertion_sort(std::vector<T>& a) {
    for (size_t i = 1; i < a.size(); ++i) {
        T key = a[i];
        size_t j = i;
        while (j > 0 && key < a[j-1]) { a[j] = a[j-1]; --j; }
        a[j] = key;
    }
}

// Quicksort API
template <typename T>
void quicksort(std::vector<T>& a);

} // namespace sorts

#endif // SORT_ALGORITHMS_HPP
