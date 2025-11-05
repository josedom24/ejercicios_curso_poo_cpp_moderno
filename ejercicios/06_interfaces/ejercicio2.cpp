#include <iostream>
#include <string>
#include <vector>
#include <memory>

// -----------------------------------------------------------
// Interfaz pura: define el contrato común
// -----------------------------------------------------------
class Notificador {
public:
    // Establece el remitente del mensaje
    virtual void establecerRemitente(const std::string& r) = 0;

    // Envía el mensaje al destinatario
    virtual void enviarMensaje(const std::string& mensaje) const = 0;

    // Devuelve el tipo de notificador (texto descriptivo)
    virtual std::string obtenerTipo() const = 0;

    virtual ~Notificador() = default;
};

// -----------------------------------------------------------
// Clase concreta: notificación por correo electrónico
// -----------------------------------------------------------
class NotificadorEmail : public Notificador {
private:
    std::string remitente;

public:
    void establecerRemitente(const std::string& r) override {
        remitente = r;
    }

    void enviarMensaje(const std::string& mensaje) const override {
        std::cout << "[EMAIL] De: " << remitente
                  << " — Enviando correo: " << mensaje << "\n";
    }

    std::string obtenerTipo() const override {
        return "Correo electrónico";
    }
};

// -----------------------------------------------------------
// Clase concreta: notificación por SMS
// -----------------------------------------------------------
class NotificadorSMS : public Notificador {
private:
    std::string remitente;

public:
    void establecerRemitente(const std::string& r) override {
        remitente = r;
    }

    void enviarMensaje(const std::string& mensaje) const override {
        std::cout << "[SMS] De: " << remitente
                  << " — Enviando SMS: " << mensaje << "\n";
    }

    std::string obtenerTipo() const override {
        return "Mensaje de texto";
    }
};

// -----------------------------------------------------------
// Clase concreta: notificación tipo Push
// -----------------------------------------------------------
class NotificadorPush : public Notificador {
private:
    std::string remitente;

public:
    void establecerRemitente(const std::string& r) override {
        remitente = r;
    }

    void enviarMensaje(const std::string& mensaje) const override {
        std::cout << "[PUSH] De: " << remitente
                  << " — Notificación enviada: " << mensaje << "\n";
    }

    std::string obtenerTipo() const override {
        return "Notificación Push";
    }
};

// -----------------------------------------------------------
// Función cliente que usa la interfaz, sin depender de detalles
// -----------------------------------------------------------
void registrarEvento(Notificador& n, const std::string& mensaje) {
    std::cout << "Registrando evento con notificador: "
              << n.obtenerTipo() << "\n";
    n.enviarMensaje(mensaje);
}

// -----------------------------------------------------------
// Función principal
// -----------------------------------------------------------
int main() {
    std::vector<std::unique_ptr<Notificador>> notificadores;

    notificadores.push_back(std::make_unique<NotificadorEmail>());
    notificadores.push_back(std::make_unique<NotificadorSMS>());
    notificadores.push_back(std::make_unique<NotificadorPush>());

    // Establecemos el remitente y enviamos un mensaje con cada uno
    for (auto& n : notificadores) {
        n->establecerRemitente("SistemaCentral");
        registrarEvento(*n, "Alerta de seguridad detectada");
        std::cout << "----------------------------------\n";
    }

    return 0;
}
