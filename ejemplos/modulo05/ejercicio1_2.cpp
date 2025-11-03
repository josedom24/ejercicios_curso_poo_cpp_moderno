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

    // Constructor con datos iniciales
    BufferSuperficial(std::initializer_list<int> lista)
        : datos(std::make_shared<std::vector<int>>(lista)) {}

    // Constructor de copia (copia superficial)
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
    BufferSuperficial b1{1, 2, 3};
    BufferSuperficial b2 = b1;  // Constructor de copia (comparten datos)
    BufferSuperficial b3;       // Constructor por defecto
    b3 = b1;                    // Asignación por copia (comparten datos)

    std::cout << "== Estado inicial ==\n";
    b1.mostrar();
    b2.mostrar();
    b3.mostrar();

    b1.modificar(1, 99);  // Modifica el recurso compartido

    std::cout << "\n== Después de modificar b1 ==\n";
    b1.mostrar();
    b2.mostrar();  // Se ve afectado
    b3.mostrar();  // También se ve afectado
}
