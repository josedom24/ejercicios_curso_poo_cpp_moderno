#include <iostream>

class FuncionBase {
public:
    // Operador virtual: actúa como interfaz polimórfica
    virtual int operator()(int x) const {
        return x;  // identidad
    }

    virtual ~FuncionBase() = default; // Destructor virtual para herencia segura
};

// Clase derivada: duplica el valor
class FuncionDoble : public FuncionBase {
public:
    int operator()(int x) const override {
        return x * 2;
    }
};

// Clase derivada: eleva al cuadrado
class FuncionCuadrado : public FuncionBase {
public:
    int operator()(int x) const override {
        return x * x;
    }
};

// Función que usa polimorfismo dinámico
void ejecutarFuncion(const FuncionBase& f, int valor) {
    std::cout << "f(" << valor << ") = " << f(valor) << "\n";
}

int main() {
    FuncionBase identidad;
    FuncionDoble doble;
    FuncionCuadrado cuadrado;

    ejecutarFuncion(identidad, 5);  // f(5) = 5
    ejecutarFuncion(doble, 5);      // f(5) = 10
    ejecutarFuncion(cuadrado, 5);   // f(5) = 25
}