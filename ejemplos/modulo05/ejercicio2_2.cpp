#include <iostream>
#include <memory>
#include <vector>

class BufferMovil {
private:
    std::unique_ptr<std::vector<int>> datos;

public:
    // Constructor por defecto
    BufferMovil() = default;

    // Constructor con datos iniciales
    explicit BufferMovil(const std::vector<int>& v)
        : datos(std::make_unique<std::vector<int>>(v)) {}

    // Constructor de movimiento
    BufferMovil(BufferMovil&& other) noexcept
        : datos(std::move(other.datos)) {
        std::cout << "Constructor de movimiento\n";
    }

    // Operador de asignación por movimiento
    BufferMovil& operator=(BufferMovil&& other) noexcept {
        if (this != &other) {
            datos = std::move(other.datos);
            std::cout << "Asignación por movimiento\n";
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
    BufferMovil b1(std::vector<int>{1, 2, 3});
    BufferMovil b2 = std::move(b1);  // Invoca el constructor de movimiento
    BufferMovil b3;
    b3 = std::move(b2);              // Invoca el operador de asignación por movimiento

    std::cout << "b1: "; b1.mostrar();  // (vacío)
    std::cout << "b2: "; b2.mostrar();  // (vacío)
    std::cout << "b3: "; b3.mostrar();  // 1 2 3
}