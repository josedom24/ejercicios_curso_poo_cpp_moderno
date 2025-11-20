#include <algorithm>
#include <array>
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v = {4, 1, 3, 2};
    std::array<int, 4> a = {8, 5, 7, 6};

    std::sort(v.begin(), v.end());
    std::sort(a.begin(), a.end());

    std::transform(v.begin(), v.end(), v.begin(), [](int x){ return x * 2; });
    std::transform(a.begin(), a.end(), a.begin(), [](int x){ return x * 2; });

    for (int x : v) std::cout << x << " ";  // 2 4 6 8
    std::cout << '\n';
    for (int x : a) std::cout << x << " ";  // 10 12 14 16
}