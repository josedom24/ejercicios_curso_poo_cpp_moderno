#include <iostream>
#include <memory>
#include <utility>

class RecursoAudio {
private:
    std::string nombre;
    std::unique_ptr<int> datos; // Recurso gestionado automáticamente

public:
    // Constructor con nombre y valor inicial
    RecursoAudio(std::string n, int valor)
        : nombre(std::move(n)), datos(std::make_unique<int>(valor)) {
        std::cout << "Constructor: " << nombre << "\n";
    }

    // Constructor de copia (copia profunda)
    RecursoAudio(const RecursoAudio& other)
        : nombre(other.nombre + "_copia"),
          datos(std::make_unique<int>(*other.datos)) {
        std::cout << "Constructor de copia: " << nombre << "\n";
    }

    // Operador de asignación por copia (copia profunda)
    RecursoAudio& operator=(const RecursoAudio& other) {
        if (this != &other) {
            nombre = other.nombre + "_asignada";
            datos = std::make_unique<int>(*other.datos);
            std::cout << "Asignación por copia: " << nombre << "\n";
        }
        return *this;
    }

    // Constructor de movimiento
    RecursoAudio(RecursoAudio&& other) noexcept
        : nombre(std::move(other.nombre)), datos(std::move(other.datos)) {
        std::cout << "Constructor de movimiento: " << nombre << "\n";
    }

    // Operador de asignación por movimiento
    RecursoAudio& operator=(RecursoAudio&& other) noexcept {
        if (this != &other) {
            nombre = std::move(other.nombre);
            datos = std::move(other.datos);
            std::cout << "Asignación por movimiento: " << nombre << "\n";
        }
        return *this;
    }

    void mostrar() const {
        std::cout << "RecursoAudio [" << nombre << "] -> valor: ";
        if (datos)
            std::cout << *datos << "\n";
        else
            std::cout << "(sin recurso)\n";
    }
};

int main() {
    std::cout << "== Creación y copia ==\n";
    RecursoAudio a1("Original", 42);
    RecursoAudio a2 = a1; // Constructor de copia
    RecursoAudio a3("Temporal", 7);
    a3 = a1;              // Asignación por copia

    std::cout << "\n== Movimiento ==\n";
    RecursoAudio a4 = std::move(a1); // Constructor de movimiento
    RecursoAudio a5("Vacio", 0);
    a5 = std::move(a3);              // Asignación por movimiento

    std::cout << "\n== Estado final ==\n";
    a2.mostrar();
    a4.mostrar();
    a5.mostrar();
}