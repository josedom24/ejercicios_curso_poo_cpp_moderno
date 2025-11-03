#include <iostream>
#include <memory>

class Animal {
public:
    virtual void comer() const {
        std::cout << "El animal come.\n";
    }

    virtual ~Animal() = default;
};

class Perro : public Animal {
public:
    void comer() const override {
        std::cout << "El perro come su pienso.\n";
    }

    void ladrar() const {
        std::cout << "El perro ladra.\n";
    }
};

class Gato : public Animal {
public:
    // No sobrescribe 'comer', hereda la versión de Animal
    void maullar() const {
        std::cout << "El gato maúlla.\n";
    }
};

int main() {
    // --- Conversión implícita con punteros inteligentes ---
    // std::unique_ptr<Perro> se convierte automáticamente en std::unique_ptr<Animal>
    std::unique_ptr<Perro> ptrPerro = std::make_unique<Perro>();
    std::unique_ptr<Gato> ptrGato = std::make_unique<Gato>();

    std::unique_ptr<Animal> ptrAnimal1 = std::move(ptrPerro); // Conversión implícita
    std::unique_ptr<Animal> ptrAnimal2 = std::move(ptrGato);  // Conversión implícita

    // Ambas llamadas acceden solo a métodos declarados en Animal:
    ptrAnimal1->comer(); // Ejecuta Perro::comer() (sobrescrito)
    ptrAnimal2->comer(); // Ejecuta Animal::comer() (no sobrescrito por Gato)

    // No podemos acceder a los métodos propios de las derivadas:
    // ptrAnimal1->ladrar(); // Error: 'ladrar' no está en Animal
    // ptrAnimal2->maullar(); // Error: 'maullar' no está en Animal

    std::cout << "Conversiones implícitas con punteros inteligentes realizadas correctamente.\n";
    return 0;
}