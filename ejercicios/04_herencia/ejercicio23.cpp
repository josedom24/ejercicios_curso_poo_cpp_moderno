#include <iostream>

class Animal {
public:
    virtual void hacerSonido() const {
        std::cout << "Sonido genérico de animal.\n";
    }

    virtual ~Animal() = default;
};

class Leon : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Ruge el león.\n";
    }

    void cazar() const {
        std::cout << "El león está cazando.\n";
    }
};

class Elefante : public Animal {
public:
    void hacerSonido() const override {
        std::cout << "Barrita el elefante.\n";
    }

    void banarse() const {
        std::cout << "El elefante se baña.\n";
    }
};

class Mono : public Animal {
public:
    // No sobrescribe hacerSonido()
    void columpiarse() const {
        std::cout << "El mono se columpia.\n";
    }
};

int main() {
    Leon leon;
    Elefante elefante;
    Mono mono;

    // --- Conversión implícita de Derivada& a Base& ---
    Animal& refAnimal1 = leon;
    Animal& refAnimal2 = elefante;
    Animal& refAnimal3 = mono;

    // Acceso solo a métodos declarados en la clase base
    refAnimal1.hacerSonido(); // Llama a Leon::hacerSonido()
    refAnimal2.hacerSonido(); // Llama a Elefante::hacerSonido()
    refAnimal3.hacerSonido(); // Llama a Animal::hacerSonido() (no sobrescrito)

    // No se puede acceder a métodos propios de las derivadas:
    // refAnimal1.cazar();       // Error de compilación
    // refAnimal2.banarse();     // Error de compilación
    // refAnimal3.columpiarse(); // Error de compilación

    std::cout << "Demostración de conversiones implícitas y polimorfismo dinámico completada.\n";
    return 0;
}
