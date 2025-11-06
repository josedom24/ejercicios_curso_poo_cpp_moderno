#include <iostream>
#include <optional>
#include <string>

int main() {
    // Declaración vacía de std::optional: no contiene ningún valor
    std::optional<std::string> mensaje;

    // has_value(): comprueba si el optional contiene un valor
    if (!mensaje.has_value()) {
        std::cout << "Sin valor inicial.\n";
    }

    // Asignar un valor al optional (ahora deja de estar vacío)
    mensaje = "Hola mundo";

    // operator bool(): permite comprobar el estado directamente
    //    if (mensaje) equivale a if (mensaje.has_value())
    if (mensaje) {
        std::cout << "Valor asignado: " << *mensaje << '\n';
    }

    // value(): accede al valor almacenado
    //    Si el optional está vacío, lanza std::bad_optional_access
    std::cout << "Con value(): " << mensaje.value() << '\n';

    // Declarar otro optional vacío
    std::optional<std::string> otroMensaje;
    

    // value_or(valor_defecto): devuelve el valor almacenado si existe,
    //    o un valor por defecto si el optional está vacío
    std::cout << "Valor o por defecto: " << otroMensaje.value_or("Vacío") << '\n';
    otroMensaje = "Hola C++";
    std::cout << "Valor o por defecto: " << otroMensaje.value_or("Vacío") << '\n';
    
    // reset(): elimina el valor almacenado, dejando el optional vacío
    mensaje.reset();

    // Comprobamos que ahora está vacío nuevamente
    std::cout << "Tras reset(), has_value(): "
              << std::boolalpha << mensaje.has_value() << '\n';

    return 0;
}