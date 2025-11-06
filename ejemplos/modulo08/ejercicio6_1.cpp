#include <iostream>
#include <variant>
#include <string>

int main() {
    // std::variant puede contener un valor de cualquiera de los tipos listados
    std::variant<int, std::string> dato;

    // Asignamos inicialmente una cadena
    dato = "Hola mundo";

    // Primer uso de std::visit:
    //    std::visit aplica una función (lambda, en este caso)
    //    al valor actualmente almacenado en el variant
    std::visit([](auto&& valor) {
        std::cout << "Valor inicial: " << valor << '\n';
    }, dato);

    // Ahora cambiamos el contenido del variant a un entero
    dato = 42;

    // Segundo uso de std::visit:
    //    Se vuelve a ejecutar la misma función sobre el nuevo valor
    std::visit([](auto&& valor) {
        std::cout << "Nuevo valor: " << valor << '\n';
    }, dato);

    // Podemos comprobar qué tipo contiene actualmente el variant
    if (std::holds_alternative<int>(dato)) {
        std::cout << "El variant contiene un entero.\n";
    } else if (std::holds_alternative<std::string>(dato)) {
        std::cout << "El variant contiene una cadena.\n";
    }

    // Acceder directamente al valor si sabemos su tipo
    std::cout << "Acceso directo al entero: " << std::get<int>(dato) << '\n';

    return 0;
}