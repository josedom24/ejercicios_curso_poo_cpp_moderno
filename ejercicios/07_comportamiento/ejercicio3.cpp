#include <iostream>
#include <string>
#include <functional>
#include <cctype>

void validarEntrada(const std::string& valor,
                    std::function<bool(const std::string&)> validador) {
    if (validador(valor))
        std::cout << "'" << valor << "' es válido.\n";
    else
        std::cout << "'" << valor << "' NO es válido.\n";
}

int main() {
    // 1. Validar si la cadena es un número
    auto esNumero = [](const std::string& s) {
        if (s.empty()) return false;
        for (unsigned char c : s) {
            if (!std::isdigit(c)) return false;
        }
        return true;
    };

    // 2. Validación muy sencilla de email
    auto esEmailSimple = [](const std::string& s) {
        auto posArroba = s.find('@');
        if (posArroba == std::string::npos) return false;
        auto posPunto = s.find('.', posArroba);
        return posPunto != std::string::npos;
    };

    // 3. Comprobar longitud entre 5 y 10
    auto longitudAdecuada = [](const std::string& s) {
        return s.size() >= 5 && s.size() <= 10;
    };

    validarEntrada("12345", esNumero);
    validarEntrada("hola", esNumero);

    validarEntrada("usuario@dominio.com", esEmailSimple);
    validarEntrada("usuario_sin_dominio", esEmailSimple);

    validarEntrada("hola", longitudAdecuada);
    validarEntrada("programacion", longitudAdecuada);

    return 0;
}
