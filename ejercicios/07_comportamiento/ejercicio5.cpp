#include <iostream>
#include <functional>

using Filtro = std::function<double(double)>;

class ProcesadorSensor {
public:
    explicit ProcesadorSensor(Filtro f)
        : filtro_(std::move(f)) {}

    double procesar(double valor) const {
        return filtro_(valor);
    }

private:
    Filtro filtro_;
};

int main() {
    // Filtro identidad
    ProcesadorSensor identidad([](double v) {
        return v;
    });

    // Filtro con umbral mínimo
    ProcesadorSensor umbral([](double v) {
        return (v < 10.0) ? 10.0 : v;
    });

    // Filtro suavizado
    ProcesadorSensor suavizado([](double v) {
        return v * 0.8;
    });

    double entrada = 5.0;

    std::cout << "Entrada: " << entrada << "\n";
    std::cout << "Identidad:  " << identidad.procesar(entrada) << "\n";
    std::cout << "Umbral:     " << umbral.procesar(entrada) << "\n";
    std::cout << "Suavizado:  " << suavizado.procesar(entrada) << "\n";

    return 0;
}
