#include <iostream>
#include <string>

// Clase plantilla genérica para representar un sensor de cualquier tipo
template <typename T>
class Sensor {
private:
    T lectura;  // Valor almacenado: puede ser numérico, texto, etc.

public:
    // Asigna una nueva lectura al sensor
    void setLectura(const T& valor) {
        lectura = valor;
    }

    // Devuelve la lectura actual
    T getLectura() const {
        return lectura;
    }

    // Muestra la lectura con un mensaje descriptivo
    //    Este método es genérico: imprimirá el valor de cualquier tipo T
    void mostrar(const std::string& nombre) const {
        std::cout << "Sensor de " << nombre << ": " << lectura << '\n';
    }
};

int main() {
    // Sensor de temperatura (usa tipo double)
    Sensor<double> sensorTemp;
    sensorTemp.setLectura(23.5);

    // Sensor de humedad (usa tipo int)
    Sensor<int> sensorHumedad;
    sensorHumedad.setLectura(45);

    // Sensor de estado (usa tipo std::string)
    Sensor<std::string> sensorEstado;
    sensorEstado.setLectura("OK");

    // Mostrar los valores de cada sensor
    sensorTemp.mostrar("temperatura (°C)");
    sensorHumedad.mostrar("humedad (%)");
    sensorEstado.mostrar("estado");

    return 0;
}
