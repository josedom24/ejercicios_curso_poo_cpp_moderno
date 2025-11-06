#include <iostream>
#include <vector>

class Accion {
public:
    virtual void operator()(int x) const = 0;
    virtual ~Accion() = default;
};

class Mostrar : public Accion {
public:
    void operator()(int x) const override {
        std::cout << "Valor: " << x << '\n';
    }
};

class Cuadrado : public Accion {
public:
    void operator()(int x) const override {
        std::cout << x << "² = " << x * x << '\n';
    }
};

// El procesador no es dueño de la acción, solo la usa
class Procesador {
public:
    explicit Procesador(const Accion& accion) : accion_(accion) {}

    void ejecutar(const std::vector<int>& datos) const {
        for (int valor : datos)
            accion_(valor);
    }

private:
    const Accion& accion_; // referencia constante, sin propiedad
};

int main() {
    std::vector<int> numeros = {1, 2, 3};

    Mostrar mostrar;
    Cuadrado cuadrado;

    Procesador p1(mostrar);
    Procesador p2(cuadrado);

    p1.ejecutar(numeros);
    p2.ejecutar(numeros);
}