#include <iostream>
#include <memory>
#include <vector>

// Clase base abstracta
class Figura {
protected:
    std::string color;

public:
    Figura(const std::string& c = "negro") : color(c) {}

    virtual void dibujar() const = 0;  // Método virtual puro
    virtual ~Figura() = default;

    void mostrarColor() const {
        std::cout << "Color: " << color << "\n";
    }
};

// Clases derivadas concretas
class Circulo : public Figura {
public:
    using Figura::Figura;  // Hereda constructor

    void dibujar() const override {
        std::cout << "Dibujando un círculo (" << color << ")\n";
    }
};

class Rectangulo : public Figura {
public:
    using Figura::Figura;

    void dibujar() const override {
        std::cout << "Dibujando un rectángulo (" << color << ")\n";
    }
};

int main() {
    std::vector<std::unique_ptr<Figura>> figuras;

    figuras.push_back(std::make_unique<Circulo>("rojo"));
    figuras.push_back(std::make_unique<Rectangulo>("azul"));

    for (const auto& figura : figuras) {
        figura->dibujar();      // Llamada polimórfica
        figura->mostrarColor(); // Método común a todas las figuras
    }
}
