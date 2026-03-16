#ifndef RECTA_H
#define RECTA_H

#include "Punto.h"
#include <cmath>

class Recta {
    double m; // pendiente (NaN si es vertical)
    double n; // intersección con Y (o con X si es vertical)
public:
    Recta() : m(0), n(0) {}
    Recta(double m, double n) : m(m), n(n) {}
    Recta(const Punto& p1, const Punto& p2);
    Recta(const Recta&) = default;

    bool incluyePunto(const Punto& p) const;
    bool esParalela(const Recta& r) const;
    Punto interseccion(const Recta& r) const; // asume que no son paralelas
    double evaluar(double x) const; // y = m*x + n (solo válido si no es vertical)
};

#endif // RECTA_H