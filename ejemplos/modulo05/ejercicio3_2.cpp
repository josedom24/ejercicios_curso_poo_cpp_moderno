#include <iostream>
#include <string>

class Archivo {
public:
    Archivo(const std::string& nombre) {
        std::cout << "Abriendo archivo: " << nombre << '\n';
    }

    // Impedimos la copia y asignación
    Archivo(const Archivo&) = delete;
    Archivo& operator=(const Archivo&) = delete;
};

int main() {
    Archivo a("datos.txt");
    // Archivo b = a;   // Error: copia prohibida
}