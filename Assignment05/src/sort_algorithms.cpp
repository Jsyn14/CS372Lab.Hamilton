#include "sort_algorithms.hpp"
#include <utility>

namespace sorts {

template <typename T>
static int partition_vec(std::vector<T>& a, int low, int high) {
    int mid = low + (high - low) / 2;
    if (a[mid] < a[low]) std::swap(a[mid], a[low]);
    if (a[high] < a[low]) std::swap(a[high], a[low]);
    if (a[mid] < a[high]) std::swap(a[mid], a[high]);
    const T& pivot = a[high];

    int i = low;
    for (int j = low; j < high; ++j) {
        if (a[j] < pivot) { std::swap(a[i], a[j]); ++i; }
    }
    std::swap(a[i], a[high]);
    return i;
}

template <typename T>
void quicksort(std::vector<T>& a) {
    if (a.empty()) return;
    std::vector<std::pair<int,int>> st;
    st.emplace_back(0, static_cast<int>(a.size()) - 1);
    while (!st.empty()) {
        auto [l, r] = st.back(); st.pop_back();
        while (l < r) {
            int p = partition_vec(a, l, r);
            if (p - l < r - p) {
                if (p + 1 < r) st.emplace_back(p + 1, r);
                r = p - 1;
            } else {
                if (l < p - 1) st.emplace_back(l, p - 1);
                l = p + 1;
            }
        }
    }
}

// Explicit template instantiation for int (our benchmark type)
template void quicksort<int>(std::vector<int>&);

} // namespace sorts
