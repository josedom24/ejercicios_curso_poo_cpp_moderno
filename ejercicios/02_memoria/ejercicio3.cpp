#include <iostream>
#include <memory>
#include <string>

class Nodo {
public:
    std::string nombre;
    std::shared_ptr<Nodo> siguiente;  // Propiedad fuerte
    std::weak_ptr<Nodo> anterior;     // Observador débil (sin propiedad)

    Nodo(const std::string& n) : nombre(n) {
        std::cout << "Creando nodo: " << nombre << "\n";
    }

    ~Nodo() {
        std::cout << "Destruyendo nodo: " << nombre << "\n";
    }
};

int main() {
    // Crear nodos usando make_shared (recomendado en C++ moderno)
    auto nodo1 = std::make_shared<Nodo>("A");
    auto nodo2 = std::make_shared<Nodo>("B");
    auto nodo3 = std::make_shared<Nodo>("C");

    // Enlace hacia adelante con shared_ptr
    nodo1->siguiente = nodo2;
    nodo2->siguiente = nodo3;

    // Enlace hacia atrás con weak_ptr para evitar ciclo
    nodo2->anterior = nodo1;
    nodo3->anterior = nodo2;

    // Mostrar contadores de referencias
    std::cout << "\nContadores de shared_ptr:\n";
    std::cout << "nodo1.use_count(): " << nodo1.use_count() << "\n";
    std::cout << "nodo2.use_count(): " << nodo2.use_count() << "\n";
    std::cout << "nodo3.use_count(): " << nodo3.use_count() << "\n\n";

    //Recorrido hacia adelante:
    std::cout << "Recorrido hacia adelante:\n";
    auto actual = nodo1;
    while (actual) {
        std::cout << actual->nombre << " ";
        actual = actual->siguiente;
    }
    std::cout << "\n";


    //Recorrido hacia atrás:
    std::cout << "Recorrido hacia atrás:\n";
    auto actual_back = nodo3;
    while (actual_back) {
        std::cout << actual_back->nombre << " ";
        actual_back = actual_back->anterior.lock();
    }
    std::cout << "\n";

    // Fin del bloque -> los nodos serán destruidos automáticamente
    std::cout << "Saliendo de main...\n";

    return 0;
}
