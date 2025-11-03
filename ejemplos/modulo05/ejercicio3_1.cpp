#include <iostream>
#include <string>

class Token {
private:
    std::string valor;

    // Constructor privado
    Token(const std::string& v) : valor(v) {}

public:
    void mostrar() const { std::cout << "Token: " << valor << '\n'; }

    // Función estática controlada
    static Token crearSeguro(const std::string& texto) {
        // Aquí podrían hacerse validaciones o transformaciones
        return Token(texto);
    }
};

int main() {
    // Token t("XYZ"); // Error: constructor privado
    Token t = Token::crearSeguro("ABC123"); // Creación controlada
    t.mostrar();
}