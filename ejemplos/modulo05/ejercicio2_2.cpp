#include <iostream>
#include <memory>
#include <vector>

class BufferMovil {
private:
    std::unique_ptr<std::vector<int>> datos;

public:
    // Constructor por defecto
    BufferMovil() = default;

    // Constructor con datos iniciales (crea un vector con los valores dados)
    explicit BufferMovil(const std::vector<int>& v)
        : datos(std::make_unique<std::vector<int>>(v)) {}

    // Constructor de movimiento
    BufferMovil(BufferMovil&& other) noexcept
        : datos(std::move(other.datos)) {  // std::move(other.datos) convierte el miembro en rvalue
                                           // y activa el constructor de movimiento de std::unique_ptr,
                                           // transfiriendo la propiedad del puntero.
        std::cout << "Constructor de movimiento\n";
    }

    // Operador de asignación por movimiento
    BufferMovil& operator=(BufferMovil&& other) noexcept {
        if (this != &other) {
            datos = std::move(other.datos);  // Transfiere la propiedad del puntero del objeto origen
                                             // al destino. El origen queda con un puntero nulo.
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
    BufferMovil b1(std::vector<int>{1, 2, 3});  // Crea un objeto con su propio recurso

    // std::move(b1) convierte b1 (un lvalue) en un rvalue,
    // habilitando el constructor de movimiento en lugar del de copia.
    BufferMovil b2 = std::move(b1);  // Se transfiere la propiedad del recurso de b1 a b2
                                     // (sin copiar el std::vector<int>).

    BufferMovil b3;                  // Objeto inicialmente vacío
    b3 = std::move(b2);              // Invoca el operador de asignación por movimiento.
                                     // Transfiere el recurso de b2 a b3; b2 queda vacío.

    std::cout << "b1: "; b1.mostrar();  // (vacío) → b1 perdió su recurso
    std::cout << "b2: "; b2.mostrar();  // (vacío) → b2 también fue movido
    std::cout << "b3: "; b3.mostrar();  // 1 2 3 → ahora b3 posee el recurso original
}
