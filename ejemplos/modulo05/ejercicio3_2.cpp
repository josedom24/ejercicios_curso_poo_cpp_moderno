#include <iostream>
#include <string>

class Archivo {
public:
    explicit Archivo(const std::string& nombre) {
        std::cout << "Abriendo archivo: " << nombre << '\n';
    }

    ~Archivo() {
        std::cout << "Cerrando archivo\n";
    }

    // Prohibimos la copia
    Archivo(const Archivo&) = delete;
    Archivo& operator=(const Archivo&) = delete;
};

int main() {
    Archivo a("datos.txt");
    // Archivo b = a;        // Error: constructor de copia eliminado
    // b = a;                // Error: asignación por copia eliminada
}