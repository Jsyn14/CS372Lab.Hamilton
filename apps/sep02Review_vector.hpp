//In The Stanadard Template Library

#include <vector>
#include <iostream>

int main() {
    std::vector<int> v1, v2, v3;
v1.push_back(10);
v1.push_back(20);
std::cout << "v1: ";
for (auto& v : v1) {
    std::cout << v << " ";

}
std::cout << std::endl;
std::cout << std::endl;
} 