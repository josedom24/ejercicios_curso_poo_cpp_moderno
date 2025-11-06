#include <iostream>
#include <string>
#include <variant>
#include <vector>

// Definición del tipo heterogéneo usando std::variant
// Puede contener tres tipos distintos:
// - int: código de operación (1 = ingreso, 2 = retiro)
// - double: cantidad monetaria
// - std::string: comentario o descripción
using Operacion = std::variant<int, double, std::string>;

// Clase visitante que define cómo procesar cada tipo de dato
struct ProcesadorOperacion {
    void operator()(int codigo) const {
        if (codigo == 1)
            std::cout << "Operación: INGRESO\n";
        else if (codigo == 2)
            std::cout << "Operación: RETIRO\n";
        else
            std::cout << "Operación desconocida (código " << codigo << ")\n";
    }

    void operator()(double cantidad) const {
        std::cout << "Cantidad: " << cantidad << '\n';
    }

    void operator()(const std::string& texto) const {
        std::cout << "Comentario: " << texto << "\n\n";
    }
};

int main() {
    // Vector con operaciones heterogéneas:
    // códigos (int), cantidades (double) y comentarios (string)
    std::vector<Operacion> operaciones = {
        1, 250.0, "Ingreso en efectivo",
        2, 100.0, "Retiro en cajero",
        3, 50.0, "Código no reconocido"
    };

    std::cout << "--- Procesando operaciones bancarias ---\n\n";

    // Procesar cada elemento del vector aplicando el visitante
    for (const auto& op : operaciones) {
        std::visit(ProcesadorOperacion{}, op);
    }

    return 0;
}