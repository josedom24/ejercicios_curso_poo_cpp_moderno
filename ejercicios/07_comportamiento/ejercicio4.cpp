#include <iostream>
#include <string>
#include <vector>

class FormateadorMensaje {
public:
    explicit FormateadorMensaje(std::string prefijo)
        : prefijo_{std::move(prefijo)}, numMensajes_{0} {}

    std::string operator()(const std::string& mensaje) {
        ++numMensajes_;
        return prefijo_ + ": " + mensaje;
    }

    int numMensajes() const {
        return numMensajes_;
    }

private:
    std::string prefijo_;
    int numMensajes_;
};

int main() {
    FormateadorMensaje info("INFO");
    FormateadorMensaje error("ERROR");

    std::vector<std::string> mensajes{
        "Inicio del programa",
        "Archivo no encontrado",
        "Operación completada"
    };

    std::cout << "=== Mensajes INFO ===\n";
    for (const auto& m : mensajes) {
        std::cout << info(m) << '\n';
    }

    std::cout << "\n=== Mensajes ERROR ===\n";
    for (const auto& m : mensajes) {
        std::cout << error(m) << '\n';
    }

    std::cout << "\nINFO ha formateado " << info.numMensajes() << " mensajes.\n";
    std::cout << "ERROR ha formateado " << error.numMensajes() << " mensajes.\n";

    return 0;
}

