#include <iostream>

class Animal {
public:
    virtual void comer() const {
        std::cout << "El animal come.\n";
    }
};

class Perro : public Animal {
public:
    // Sobrescribimos el método comer
    void comer() const override {
        std::cout << "El perro come su pienso.\n";
    }

    void ladrar() const {
        std::cout << "El perro ladra.\n";
    }
};

class Gato : public Animal {
public:
    // No sobrescribe comer(), hereda la versión de Animal
    void maullar() const {
        std::cout << "El gato maúlla.\n";
    }
};

int main() {
    Perro p;
    Gato g;

    // --- Conversión implícita de Derivada& a Base& ---
    // Referencias a las derivadas se convierten automáticamente
    // en referencias a la clase base (sin necesidad de casting).
    Animal& refAnimal1 = p;
    Animal& refAnimal2 = g;

    // Ambas referencias solo pueden usar métodos definidos en Animal:
    refAnimal1.comer(); // Llama a Perro::comer() (método sobrescrito)
    refAnimal2.comer(); // Llama a Animal::comer() (no sobrescrito en Gato)

    // No podemos acceder a métodos exclusivos de las derivadas:
    // refAnimal1.ladrar(); // Error: 'ladrar' no está en Animal
    // refAnimal2.maullar(); // Error: 'maullar' no está en Animal

    // Pero si accedemos directamente al objeto derivado, sí:
    p.ladrar(); // Válido: tenemos un Perro
    g.maullar(); // Válido: tenemos un Gato

    std::cout << "Conversiones implícitas con referencias realizadas correctamente.\n";
    return 0;
}