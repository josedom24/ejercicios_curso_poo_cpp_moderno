#include <iostream>
#include <memory>
#include <string>

// Clase Jugador
class Jugador {
public:
    explicit Jugador(std::string nombre)
        : nombre_(std::move(nombre)) {}

    void jugar() const {
        std::cout << nombre_ << " está jugando.\n";
    }

    std::string obtenerNombre() const { return nombre_; }

private:
    std::string nombre_;
};

// Clase Equipo que agrega a un jugador sin ser su propietario
class Equipo {
public:
    Equipo(std::string nombre, std::shared_ptr<Jugador> jugador)
        : nombre_(std::move(nombre)), jugador_(jugador) {}

    void mostrar() const {
        std::cout << "Equipo: " << nombre_ << "\n";
        if (auto j = jugador_.lock()) { // comprobamos si el jugador sigue existiendo
            std::cout << "Jugador: " << j->obtenerNombre() << "\n";
        } else {
            std::cout << "Jugador: [ya no existe]\n";
        }
    }

    void entrenar() const {
        std::cout << "Entrenando equipo " << nombre_ << "...\n";
        if (auto j = jugador_.lock()) {
            j->jugar();
        } else {
            std::cout << "No hay jugador disponible.\n";
        }
    }

private:
    std::string nombre_;
    std::weak_ptr<Jugador> jugador_; // relación no propietaria
};

int main() {
    auto jugador = std::make_shared<Jugador>("Laura");

    Equipo equipo("Águilas", jugador);

    equipo.mostrar();
    equipo.entrenar();

    jugador.reset(); // simulamos que el jugador fue eliminado del sistema

    std::cout << "\nDespués de eliminar al jugador:\n";
    equipo.mostrar();
    equipo.entrenar();

    return 0;
}
