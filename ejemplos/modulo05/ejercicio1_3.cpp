#include <iostream>
#include <memory>
#include <vector>

class BufferProfundo {
private:
    std::unique_ptr<std::vector<int>> datos;

public:
    // Constructor con datos iniciales
    BufferProfundo(std::initializer_list<int> lista)
        : datos(std::make_unique<std::vector<int>>(lista)) {}

    // Constructor de copia (copia profunda)
    BufferProfundo(const BufferProfundo& other)
        : datos(std::make_unique<std::vector<int>>(*other.datos)) {
        std::cout << "Constructor de copia (profunda)\n";
    }

    // Operador de asignación por copia (copia profunda)
    BufferProfundo& operator=(const BufferProfundo& other) {
        if (this != &other) {
            datos = std::make_unique<std::vector<int>>(*other.datos);
            std::cout << "Asignación por copia (profunda)\n";
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
    BufferProfundo b1{1, 2, 3};
    BufferProfundo b2 = b1;  // Constructor de copia (duplica datos)
    BufferProfundo b3{4, 5, 6};
    b3 = b1;                 // Asignación por copia (duplica datos)

    std::cout << "== Estado inicial ==\n";
    b1.mostrar();
    b2.mostrar();
    b3.mostrar();

    b1.modificar(1, 99);  // Modifica solo su copia

    std::cout << "\n== Después de modificar b1 ==\n";
    b1.mostrar();
    b2.mostrar();  // No se ve afectado
    b3.mostrar();  // No se ve afectado
}