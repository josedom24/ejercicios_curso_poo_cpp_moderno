#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

int main() {
    std::vector<std::string> frutas{
        "cereza", "manzana", "banana", "arándano", "kiwi"
    };

    // 1. Buscar la primera cadena con más de 5 caracteres
    auto it1 = std::find_if(frutas.begin(), frutas.end(),
                            [](const std::string& s) {
                                return s.size() > 5;
                            });

    if (it1 != frutas.end())
        std::cout << "Primera fruta con más de 5 caracteres: " << *it1 << "\n";
    else
        std::cout << "No hay frutas con más de 5 caracteres.\n";

    // 2. Buscar la primera cadena que empieza por 'b'
    auto it2 = std::find_if(frutas.begin(), frutas.end(),
                            [](const std::string& s) {
                                return !s.empty() && s[0] == 'b';
                            });

    if (it2 != frutas.end())
        std::cout << "Primera fruta que empieza por 'b': " << *it2 << "\n";
    else
        std::cout << "No hay frutas que empiecen por 'b'.\n";

    return 0;
}
