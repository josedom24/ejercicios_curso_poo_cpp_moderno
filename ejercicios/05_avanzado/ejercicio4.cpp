#include <iostream>

class Tiempo {
private:
    int horas;
    int minutos;

    // Normaliza los minutos (por ejemplo, 90 min → 1h 30min)
    void normalizar() {
        if (minutos >= 60) {
            horas += minutos / 60;
            minutos %= 60;
        } else if (minutos < 0) {
            int h = (std::abs(minutos) + 59) / 60;
            horas -= h;
            minutos += h * 60;
        }
    }

public:
    // Constructor
    Tiempo(int h = 0, int m = 0) : horas(h), minutos(m) {
        normalizar();
    }

    // Sobrecarga de +
    Tiempo operator+(const Tiempo& otro) const {
        return Tiempo(horas + otro.horas, minutos + otro.minutos);
    }

    // Sobrecarga de -
    Tiempo operator-(const Tiempo& otro) const {
        return Tiempo(horas - otro.horas, minutos - otro.minutos);
    }

    // Sobrecarga de ==
    bool operator==(const Tiempo& otro) const {
        return horas == otro.horas && minutos == otro.minutos;
    }

    // Sobrecarga de <<
    friend std::ostream& operator<<(std::ostream& os, const Tiempo& t) {
        os << (t.horas < 10 ? "0" : "") << t.horas << ":"
           << (t.minutos < 10 ? "0" : "") << t.minutos;
        return os;
    }
};

int main() {
    Tiempo t1(1, 45);  // 1h 45min
    Tiempo t2(2, 30);  // 2h 30min

    Tiempo suma = t1 + t2;   // 4h 15min
    Tiempo resta = t1 - t2;  // -0h 45min → se normaliza como 0h -45min = -1h 15min

    std::cout << "t1 = " << t1 << "\n";
    std::cout << "t2 = " << t2 << "\n";
    std::cout << "Suma: " << suma << "\n";
    std::cout << "Resta: " << resta << "\n";

    if (t1 == t2)
        std::cout << "Los tiempos son iguales\n";
    else
        std::cout << "Los tiempos son diferentes\n";

    return 0;
}