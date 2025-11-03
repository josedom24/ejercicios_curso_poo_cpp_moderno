#include <iostream>
#include <memory>

class Base {};
class Derivada : public Base {};

int main() {
    // --- Conversión implícita con punteros inteligentes ---
    // std::unique_ptr<Derivada> puede convertirse automáticamente
    // en std::unique_ptr<Base> porque existe una relación de herencia pública.
    std::unique_ptr<Derivada> ptrDerivada = std::make_unique<Derivada>();
    std::unique_ptr<Base> ptrBase = std::move(ptrDerivada); // Conversión implícita

    // --- Conversión implícita con referencias ---
    // Una referencia a un objeto Derivada puede asignarse a una referencia Base
    // sin necesidad de casting explícito.
    Derivada objDerivada;
    Base& refBase = objDerivada; // Conversión implícita

    std::cout << "Conversiones implícitas realizadas correctamente.\n";
    return 0;
}
