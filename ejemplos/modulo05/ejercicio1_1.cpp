#include <iostream>
#include <vector>

int main() {
    std::vector<int> a{1, 2, 3};
    std::vector<int> b = a;  // Constructor de copia (copia profunda)

    a[1] = 99;  // Modificamos solo 'a'

    std::cout << "a: ";
    for (int v : a) std::cout << v << " ";  // 1 99 3
    std::cout << "\n";

    std::cout << "b: ";
    for (int v : b) std::cout << v << " ";  // 1 2 3
    std::cout << "\n";
}