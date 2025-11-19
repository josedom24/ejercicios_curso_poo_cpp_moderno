#include <memory>
#include <iostream>

int main() {
    std::shared_ptr<int> sp1 = std::make_shared<int>(100);

    {
        std::shared_ptr<int> sp2 = sp1; // Copia: ambos comparten propiedad
        std::cout << "Valor: " << *sp2 << "\n";
        std::cout << "Conteo: " << sp1.use_count() << "\n";
    } // sp2 se destruye: el conteo baja

    std::cout << "Conteo tras salir del bloque: " << sp1.use_count() << "\n";

    return 0; // El recurso se libera cuando desaparece el último shared_ptr
}
