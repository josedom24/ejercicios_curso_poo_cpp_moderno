#include <iostream>
#include <string>

// Clase plantilla genérica
// Esta versión se aplica a todos los tipos excepto 'bool'
template <typename T>
class Registro {
private:
    T valor;  // Valor almacenado de tipo genérico

public:
    // Constructor que inicializa el valor
    Registro(const T& v) : valor(v) {}

    // Método genérico para mostrar el valor almacenado
    void mostrar() const {
        std::cout << "Valor almacenado: " << valor << '\n';
    }
};

// Especialización total de la plantilla para el tipo bool
// Se define un comportamiento distinto para valores lógicos
template <>
class Registro<bool> {
private:
    bool valor;  // Valor lógico almacenado

public:
    // Constructor que inicializa el valor booleano
    Registro(bool v) : valor(v) {}

    // Método especializado que muestra un mensaje más expresivo
    void mostrar() const {
        if (valor)
            std::cout << "Valor lógico: verdadero\n";
        else
            std::cout << "Valor lógico: falso\n";
    }
};

int main() {
    // Instancia genérica con tipo int
    Registro<int> r1(42);
    r1.mostrar();  // Usa la versión genérica

    // Instancia genérica con tipo double
    Registro<double> r2(3.14);
    r2.mostrar();  // Usa la versión genérica

    // Instancia genérica con tipo std::string
    Registro<std::string> r3("Hola");
    r3.mostrar();  // Usa la versión genérica

    // Instancia especializada con tipo bool
    Registro<bool> r4(true);
    r4.mostrar();  // Usa la versión especializada

    Registro<bool> r5(false);
    r5.mostrar();  // Usa la versión especializada

    return 0;
}
