#include <iostream>
#include <memory>

class Registro {
private:
    std::unique_ptr<int[]> datos;
    size_t tamaño;

public:
    Registro(size_t n)
        : datos(std::make_unique<int[]>(n)), tamaño(n) {
        std::cout << "Registro creado con " << n << " elementos\n";
    }

    ~Registro() = default;                   // Destructor por defecto

    Registro(const Registro&) = delete;      // No copiable
    Registro& operator=(const Registro&) = delete;

    Registro(Registro&&) noexcept = default; // Movible
    Registro& operator=(Registro&&) noexcept = default;
};

int main() {
    Registro r1(5);
    Registro r2 = std::move(r1);  // Movimiento permitido
    std::cout << "Fin del programa\n";
}
