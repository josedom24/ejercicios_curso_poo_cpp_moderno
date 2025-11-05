#include <iostream>
#include <vector>
#include <string>

// Plantilla genérica (para cualquier tipo simple)
template <typename T>
class Contenedor {
private:
    T valor;

public:
    Contenedor(T v) : valor(v) {}

    void mostrar() const {
        std::cout << "Elemento único: " << valor << '\n';
    }
};

// Especialización parcial para std::vector<T>
template <typename T>
class Contenedor<std::vector<T>> {
private:
    std::vector<T> valores;

public:
    Contenedor(const std::vector<T>& v) : valores(v) {}

    void mostrar() const {
        std::cout << "Colección de elementos (" << valores.size() << "): ";
        for (const auto& e : valores)
            std::cout << e << " ";
        std::cout << '\n';
    }
};

int main() {
    Contenedor<int> c1(42);                          // versión genérica
    Contenedor<std::string> c2("Hola");              // versión genérica
    Contenedor<std::vector<int>> c3({1, 2, 3, 4});   // especialización parcial
    Contenedor<std::vector<std::string>> c4({"uno", "dos", "tres"}); // especialización parcial

    c1.mostrar();
    c2.mostrar();
    c3.mostrar();
    c4.mostrar();

    return 0;
}