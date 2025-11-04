#include <iostream>
#include <utility>

class Registro {
public:
    Registro() = default;                    // Constructor por defecto
    ~Registro() = default;                   // Destructor por defecto

    Registro(const Registro&) = delete;      // No copiable
    Registro& operator=(const Registro&) = delete;

    Registro(Registro&&) noexcept = default; // Movible
    Registro& operator=(Registro&&) noexcept = default;
};

int main() {
    Registro r1;
    Registro r2 = std::move(r1);  // Movimiento permitido
    std::cout << "Fin del programa\n";
}