#ifndef RECTANGULO_H
#define RECTANGULO_H

#include "Poligono.h"
#include <vector>

class Rectangulo : public Poligono {
public:
    // Construye un rectángulo a partir de cuatro puntos en orden (sentido horario o antihorario)
    Rectangulo(const Punto& a, const Punto& b, const Punto& c, const Punto& d);
    double area() const; // área exacta (producto de dos lados adyacentes)
};

#endif // RECTANGULO_H