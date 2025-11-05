#include <iostream>

// Clase base abstracta
class Figura {
public:
    virtual void dibujar() const = 0;     // Método virtual puro
    virtual ~Figura() = default;          // Destructor virtual
};

// Clase derivada
class Circulo : public Figura {
public:
    void dibujar() const override {
        std::cout << "Dibujando un Círculo\n";
    }
};

// Función que devuelve un objeto por valor (provoca object slicing)
Figura crearFiguraPorValor() {
    Circulo c;
    return c;  // Se produce "object slicing"
}

int main() {
    std::cout << "== Ejemplo con devolución por valor ==\n";
    Figura f = crearFiguraPorValor();  // Se copia solo la parte base
    f.dibujar();  // Error conceptual: no se llama a Circulo::dibujar()
                  // Se comporta como una Figura “recortada”

    return 0;
}