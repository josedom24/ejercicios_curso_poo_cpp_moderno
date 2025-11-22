#ifndef EVENTOS_H
#define EVENTOS_H

#include <string>
#include <variant>
#include <iostream>

// ---------------------------------------------------------------------------
// Tipos de eventos concretos
// ---------------------------------------------------------------------------

struct EventoLectura {
    std::string nombre;
    double valor;
};

struct EventoError {
    std::string nombre;
};

struct EventoAccion {
    std::string nombre;
};

// Variante
using Evento = std::variant<EventoLectura, EventoError, EventoAccion>;

// ---------------------------------------------------------------------------
// Visitor explícito con overloads
// ---------------------------------------------------------------------------
struct ProcesadorEventos {
    void operator()(const EventoLectura& ev) const {
        std::cout << "[Lectura] " << ev.nombre << ": " << ev.valor << '\n';
    }

    void operator()(const EventoError& ev) const {
        std::cout << "[Error] Fallo en " << ev.nombre << '\n';
    }

    void operator()(const EventoAccion& ev) const {
        std::cout << "[Acción] " << ev.nombre << " ejecutado\n";
    }
};

// ---------------------------------------------------------------------------
// Función que procesa eventos genéricos mediante std::visit
// ---------------------------------------------------------------------------
void procesarEvento(const Evento& e) {
    std::visit(ProcesadorEventos{}, e);
}

#endif // EVENTOS_H
