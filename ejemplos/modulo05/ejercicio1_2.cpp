#include <iostream>
#include <memory>
#include <vector>

class BufferSuperficial {
private:
    std::shared_ptr<std::vector<int>> datos;

public:
    // Constructor por defecto
    BufferSuperficial()
        : datos(std::make_shared<std::vector<int>>()) {}

    // Constructor con datos iniciales (por vector)
    explicit BufferSuperficial(const std::vector<int>& v)
        : datos(std::make_shared<std::vector<int>>(v)) {}

    // Constructor de copia (superficial)
    BufferSuperficial(const BufferSuperficial& other)
        : datos(other.datos) {
        std::cout << "Constructor de copia (superficial)\n";
    }

    // Operador de asignación por copia (superficial)
    BufferSuperficial& operator=(const BufferSuperficial& other) {
        if (this != &other) {
            datos = other.datos;
            std::cout << "Asignación por copia (superficial)\n";
        }
        return *this;
    }

    void modificar(size_t i, int valor) {
        if (i < datos->size()) (*datos)[i] = valor;
    }

    void mostrar() const {
        for (int v : *datos) std::cout << v << " ";
        std::cout << "\n";
    }
};

int main() {
    BufferSuperficial b1(std::vector<int>{1, 2, 3});
    BufferSuperficial b2 = b1;
    BufferSuperficial b3;
    b3 = b1;

    std::cout << "== Estado inicial ==\n";
    b1.mostrar();
    b2.mostrar();
    b3.mostrar();

    b1.modificar(1, 99);

    std::cout << "\n== Después de modificar b1 ==\n";
    b1.mostrar();
    b2.mostrar();
    b3.mostrar();
}
