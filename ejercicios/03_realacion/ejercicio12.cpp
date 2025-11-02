#include <iostream>
#include <string>

// Clase que representa a un profesor.
// Existe de forma independiente y puede impartir varios cursos.
class Profesor {
public:
    explicit Profesor(std::string nombre)
        : nombre_(std::move(nombre)) {}

    void darClase() const {
        std::cout << nombre_ << " está impartiendo su clase.\n";
    }

    std::string obtenerNombre() const {
        return nombre_;
    }

private:
    std::string nombre_;
};

// Clase que representa a un curso universitario.
// Mantiene una asociación hacia un profesor, pero no lo posee.
class Curso {
public:
    // El curso siempre debe tener un profesor asignado (asociación obligatoria).
    // Se usa una referencia constante, ya que el curso no modifica ni destruye al profesor.
    Curso(std::string titulo, const Profesor& profesor)
        : titulo_(std::move(titulo)), profesor_(profesor) {}

    void mostrarInfo() const {
        std::cout << "Curso: " << titulo_
                  << " | Profesor: " << profesor_.obtenerNombre() << "\n";
    }

    void iniciarClase() const {
        std::cout << "Iniciando clase de " << titulo_ << "...\n";
        profesor_.darClase();
    }

private:
    std::string titulo_;
    const Profesor& profesor_; // Asociación no propietaria (referencia obligatoria)
};

int main() {
    Profesor p("Dr. García"); // El profesor existe independientemente
    Curso c("Programación en C++", p); // El curso se asocia al profesor existente

    c.mostrarInfo();
    c.iniciarClase();

    // Al finalizar el programa:
    // - El curso NO destruye al profesor.
    // - El profesor puede seguir existiendo y usarse en otros cursos.
    return 0;
}
