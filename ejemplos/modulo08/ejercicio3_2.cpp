#include <iostream>
#include <vector>
#include <string>
#include <numeric>
#include <sstream>

// Clase plantilla genérica para acumular valores de tipo T
template <typename T>
class Acumulador {
private:
    std::vector<T> datos;  // Contenedor interno

public:
    // Añade un valor al acumulador
    void agregar(const T& valor) {
        datos.push_back(valor);
    }

    // Devuelve la cantidad de elementos
    std::size_t tamano() const {
        return datos.size();
    }

    // Muestra todos los elementos en una sola línea
    void mostrar() const {
        std::cout << "[ ";
        for (const auto& x : datos)
            std::cout << x << ' ';
        std::cout << "]\n";
    }

    // Convierte el contenido a una cadena de texto
    std::string comoTexto() const {
        std::ostringstream os;
        for (const auto& x : datos)
            os << x << ' ';
        return os.str();
    }
};

// Especialización parcial para tipos vectoriales: Acumulador<std::vector<T>>
template <typename T>
class Acumulador<std::vector<T>> {
private:
    std::vector<std::vector<T>> datos;  // Contiene varios vectores del mismo tipo

public:
    // Agrega un vector completo al acumulador
    void agregar(const std::vector<T>& vec) {
        datos.push_back(vec);
    }

    // Devuelve la cantidad de vectores almacenados
    std::size_t tamano() const {
        return datos.size();
    }

    // Muestra los vectores almacenados
    void mostrar() const {
        std::cout << "Contenido de vectores:\n";
        for (const auto& v : datos) {
            std::cout << "[ ";
            for (const auto& x : v)
                std::cout << x << ' ';
            std::cout << "]\n";
        }
    }

    // Combina todos los vectores en uno solo
    std::vector<T> combinar() const {
        std::vector<T> resultado;
        for (const auto& v : datos)
            resultado.insert(resultado.end(), v.begin(), v.end());
        return resultado;
    }
};

int main() {
    // Acumulador genérico (para strings)
    Acumulador<std::string> palabras;
    palabras.agregar("Hola");
    palabras.agregar("mundo");
    palabras.agregar("C++");
    palabras.mostrar();
    std::cout << "Como texto: " << palabras.comoTexto() << "\n\n";

    // Acumulador especializado para vectores
    Acumulador<std::vector<int>> listas;
    listas.agregar({1, 2, 3});
    listas.agregar({4, 5});
    listas.mostrar();

    auto combinado = listas.combinar();
    std::cout << "Vector combinado: [ ";
    for (int x : combinado)
        std::cout << x << ' ';
    std::cout << "]\n";
}