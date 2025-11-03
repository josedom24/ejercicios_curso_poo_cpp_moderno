#include <iostream>
#include <utility> // std::move

class Registro {
public:
    Registro() { std::cout << "Registro creado\n"; }
    ~Registro() { std::cout << "Registro destruido\n"; }

    Registro(const Registro&) = delete;            // No copiable
    Registro& operator=(const Registro&) = delete;

    Registro(Registro&&) noexcept = default;       // Movible
    Registro& operator=(Registro&&) noexcept = default;
};

int main() {
    Registro r1;                 // Creación normal
    Registro r2 = std::move(r1); // Movimiento permitido

    // Registro r3 = r2;          // Error: copia prohibida
    // r3 = r1;                   // Error: asignación por copia prohibida

    std::cout << "Fin del programa\n";
}