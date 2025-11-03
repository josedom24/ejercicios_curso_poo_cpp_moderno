#include <iostream>
#include <memory>
#include <vector>

class BufferCompartido {
private:
    std::shared_ptr<std::vector<int>> datos;

public:
    // Constructor con datos iniciales
    BufferCompartido(std::initializer_list<int> lista)
        : datos(std::make_shared<std::vector<int>>(lista)) {}

    // Constructor de movimiento
    BufferCompartido(BufferCompartido&& other) noexcept
        : datos(std::move(other.datos)) {
        std::cout << "Constructor de movimiento (shared)\n";
    }

    // Operador de asignación por movimiento
    BufferCompartido& operator=(BufferCompartido&& other) noexcept {
        if (this != &other) {
            datos = std::move(other.datos);
            std::cout << "Asignación por movimiento (shared)\n";
        }
        return *this;
    }

    void mostrar() const {
        if (!datos || datos->empty()) {
            std::cout << "(vacío)\n";
        } else {
            for (int v : *datos) std::cout << v << " ";
            std::cout << "\n";
        }
    }
};

int main() {
    BufferCompartido a{1, 2, 3};
    BufferCompartido b = std::move(a);  // Mueve la propiedad compartida

    std::cout << "a: "; a.mostrar();  // (vacío)
    std::cout << "b: "; b.mostrar();  // 1 2 3
}