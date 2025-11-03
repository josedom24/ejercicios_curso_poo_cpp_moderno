#include <iostream>
#include <memory>

class Buffer {
private:
    std::unique_ptr<int[]> datos;
    std::size_t tam;

public:
    // Constructor con tamaño e inicialización
    Buffer(std::size_t n, int valor = 0)
        : datos(std::make_unique<int[]>(n)), tam(n) {
        for (std::size_t i = 0; i < tam; ++i)
            datos[i] = valor;
    }

    // Método de clonación
    std::unique_ptr<Buffer> clone() const {
        auto nuevo = std::make_unique<Buffer>(tam);
        for (std::size_t i = 0; i < tam; ++i)
            nuevo->datos[i] = datos[i];  // Copia profunda
        return nuevo;
    }

    void modificar(std::size_t i, int valor) {
        if (i < tam) datos[i] = valor;
    }

    void mostrar() const {
        for (std::size_t i = 0; i < tam; ++i)
            std::cout << datos[i] << " ";
        std::cout << "\n";
    }
};

int main() {
    Buffer original(3, 5);       // [5, 5, 5]
    auto copia = original.clone(); // Clonación profunda

    original.modificar(1, 99);   // Solo cambia el original

    std::cout << "Original: ";
    original.mostrar();
    std::cout << "Copia:    ";
    copia->mostrar();
}