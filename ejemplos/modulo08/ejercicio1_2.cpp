#include <iostream>
#include <vector>
#include <string>
#include <numeric>  // std::accumulate
#include <sstream>  // std::ostringstream

// Clase plantilla genérica para acumular y mostrar valores
template <typename T>
class Acumulador {
private:
    std::vector<T> datos;  // Contenedor interno

public:
    // Añade un valor
    void agregar(const T& valor) {
        datos.push_back(valor);
    }

    // Devuelve el número de elementos
    std::size_t tamano() const {
        return datos.size();
    }

    // Muestra todos los elementos
    void mostrar() const {
        std::cout << "[ ";
        for (const auto& x : datos)
            std::cout << x << ' ';
        std::cout << "]\n";
    }

    // Devuelve una representación textual del contenido
    std::string comoTexto() const {
        std::ostringstream os;
        for (const auto& x : datos)
            os << x << ' ';
        return os.str();
    }

    // Devuelve la suma o concatenación de los elementos (si el operador + está definido)
    T combinar() const {
        if (datos.empty())
            throw std::runtime_error("No hay elementos para combinar");
        return std::accumulate(std::next(datos.begin()), datos.end(), datos.front());
    }
};

int main() {
    // Acumulador de enteros
    Acumulador<int> numeros;
    numeros.agregar(10);
    numeros.agregar(20);
    numeros.agregar(30);
    numeros.mostrar();
    std::cout << "Suma total: " << numeros.combinar() << "\n\n";

    // Acumulador de cadenas
    Acumulador<std::string> textos;
    textos.agregar("Hola ");
    textos.agregar("mundo ");
    textos.agregar("C++");
    textos.mostrar();
    std::cout << "Concatenación: " << textos.combinar() << "\n\n";
}