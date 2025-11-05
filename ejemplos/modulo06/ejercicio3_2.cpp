#include <iostream>

// Clase base (no abstracta)
class Figura {
public:
    virtual void dibujar() const {
        std::cout << "Dibujando una figura genérica\n";
    }

    virtual ~Figura() = default;
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
    return c;  // Se permite, pero se produce "object slicing"
}

int main() {
    std::cout << "== Ejemplo con devolución por valor ==\n";
    Figura f = crearFiguraPorValor();  // Se copia solo la parte base
    f.dibujar();  // Muestra: "Dibujando una figura genérica"

    return 0;
}