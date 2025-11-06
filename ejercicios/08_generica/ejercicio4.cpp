#include <iostream>
#include <optional>

// Función que realiza una división segura usando std::optional.
// Si el denominador es distinto de cero, devuelve el resultado.
// Si el denominador es cero, devuelve std::nullopt (sin valor).
std::optional<double> dividir(int numerador, int denominador) {
    if (denominador == 0) {
        // No es posible dividir por cero, devolvemos "sin valor"
        return std::nullopt;
    }

    // División válida: devolvemos el resultado como double
    return static_cast<double>(numerador) / denominador;
}

int main() {
    int numerador, denominador;

    // Pedir los números al usuario
    std::cout << "Introduce el numerador: ";
    std::cin >> numerador;

    std::cout << "Introduce el denominador: ";
    std::cin >> denominador;

    // Llamar a la función dividir()
    std::optional<double> resultado = dividir(numerador, denominador);

    // Comprobamos si el resultado contiene un valor válido
    if (resultado.has_value()) {
        // Se puede acceder al valor con *resultado o resultado.value()
        std::cout << "Resultado: " << *resultado << '\n';
    } else {
        // Caso en que la división no es válida (denominador = 0)
        std::cout << "Error: división por cero.\n";

        // value_or() devuelve un valor alternativo si el optional está vacío
        double valorPorDefecto = resultado.value_or(0.0);
        std::cout << "Resultado por defecto: " << valorPorDefecto << '\n';
    }

    return 0;
}
