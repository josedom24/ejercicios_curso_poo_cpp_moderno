#include <iostream>
#include <string>

// Clase plantilla con dos parámetros de tipo genérico
// T representa el tipo del valor numérico
// U representa el tipo de la unidad de medida
template <typename T, typename U>
class Medida {
private:
    T valor;    // Valor numérico de la magnitud
    U unidad;   // Unidad de medida asociada (por ejemplo, "kg", "°C")

public:
    // Constructor que inicializa ambos atributos
    Medida(const T& v, const U& u) : valor(v), unidad(u) {}

    // Devuelve el valor numérico
    T getValor() const {
        return valor;
    }

    // Devuelve la unidad de medida
    U getUnidad() const {
        return unidad;
    }

    // Muestra la medida en formato legible
    void mostrar(const std::string& nombre) const {
        std::cout << nombre << ": " << valor << " " << unidad << '\n';
    }
};

int main() {
    // Creación de varios objetos Medida con diferentes combinaciones de tipos

    // Medida de temperatura: valor double y unidad string
    Medida<double, std::string> temperatura(23.5, "°C");

    // Medida de distancia: valor int y unidad string
    Medida<int, std::string> distancia(150, "km");

    // Medida de tiempo: valor float y unidad const char*
    Medida<float, const char*> tiempo(2.5f, "h");

    // Medida de velocidad: valor double y unidad string
    Medida<double, std::string> velocidad(100.8, "km/h");

    // Mostrar las medidas con sus nombres descriptivos
    temperatura.mostrar("Temperatura");
    distancia.mostrar("Distancia");
    tiempo.mostrar("Tiempo");
    velocidad.mostrar("Velocidad");

    return 0;
}
