#ifndef SEGMENTO_H
#define SEGMENTO_H

#include "Punto.h"
#include "Recta.h"

class Segmento {
    Punto inicio;
    Punto fin;
    Recta recta; // recta que contiene al segmento
public:
    Segmento() = default;
    Segmento(const Punto& p1, const Punto& p2);
    Segmento(const Segmento&) = default;

    bool contienePunto(const Punto& p) const;
    bool intersectaCon(const Segmento& otro) const;
    double longitud() const;
    Punto puntoMedio() const;

    // Getters
    const Punto& getInicio() const { return inicio; }
    const Punto& getFin() const { return fin; }
    const Recta& getRecta() const { return recta; }
};

#endif // SEGMENTO_H