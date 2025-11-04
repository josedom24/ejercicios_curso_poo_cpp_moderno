#include <iostream>
#include <utility> // std::move
#include <vector>

int main() {
    std::vector<int> origen = {1, 2, 3, 4, 5};
    std::vector<int> destino = std::move(origen);  // Se transfiere el contenido

    std::cout << "Tamaño de origen: " << origen.size() << "\n";
    std::cout << "Tamaño de destino: " << destino.size() << "\n";
}