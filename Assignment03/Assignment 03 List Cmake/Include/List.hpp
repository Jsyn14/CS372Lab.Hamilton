#pragma once
#include <cstddef>
#include <utility>
#include "List.hpp"

// Bag<T>
// - Multiset-like container: insert values, remove ONE matching value,
//   query membership, count duplicates, check size/empty, clear.
// - Backing store is your singly-linked List<T> from lecture (copy/move-ready).

template <typename T>
class Bag {
public:
    Bag() = default;
    Bag(const Bag&) = default;
    Bag(Bag&&) noexcept = default;
    Bag& operator=(const Bag&) = default;
    Bag& operator=(Bag&&) noexcept = default;
    ~Bag() = default;

    // Insert a value (one occurrence)
    void insert(const T& value)            { chain_.push_back(value); }
    void insert(T&& value)                 { chain_.push_back(std::move(value)); }

    // Remove ONE matching value, if present
    bool remove(const T& value)            { return chain_.remove_one(value); }

    // Queries
    bool        empty() const noexcept     { return chain_.empty(); }
    std::size_t size()  const noexcept     { return chain_.size(); }

    void clear() noexcept                  { chain_.clear(); }

    bool contains(const T& value) const {
        for (auto it = chain_.begin(); it != chain_.end(); ++it)
            if (*it == value) return true;
        return false;
    }

    std::size_t count(const T& value) const {
        std::size_t c = 0;
        for (auto it = chain_.begin(); it != chain_.end(); ++it)
            if (*it == value) ++c;
        return c;
    }

private:
    List<T> chain_;
};
