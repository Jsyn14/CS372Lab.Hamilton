
#pragma once
#include <vector>
#include <stdexcept>
#include <algorithm>

template<typename T>
class ReceiptBag {
private:
    struct Item {
        T data;
        int receipt;
        bool valid;
        
        Item(const T& d, int r) : data(d), receipt(r), valid(true) {}
    };
    
    std::vector<Item> items;
    int next_receipt;

public:
    ReceiptBag() : next_receipt(1) {}
    
    int insert(const T& item) {
        int receipt = next_receipt++;
        items.emplace_back(item, receipt);
        return receipt;
    }
    
    T remove(int receipt) {
        auto it = std::find_if(items.begin(), items.end(),
            [receipt](const Item& item) {
                return item.receipt == receipt && item.valid;
            });
        
        if (it == items.end()) {
            throw std::runtime_error("Invalid receipt");
        }
        
        T data = it->data;
        it->valid = false;
        return data;
    }
    
    bool isValidReceipt(int receipt) const {
        return std::any_of(items.begin(), items.end(),
            [receipt](const Item& item) {
                return item.receipt == receipt && item.valid;
            });
    }
    
    size_t size() const {
        return std::count_if(items.begin(), items.end(),
            [](const Item& item) { return item.valid; });
    }
    
    bool empty() const {
        return size() == 0;
    }
};
