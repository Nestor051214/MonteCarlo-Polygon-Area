#ifndef POLIGONO_H
#define POLIGONO_H

#include "Segmento.h"
#include <vector>

class Poligono {
protected:
    std::vector<Segmento> lados; // lados del polígono en orden
public:
    Poligono() = default;
    explicit Poligono(const std::vector<Punto>& vertices); // construye desde vértices
    Poligono(const Poligono&) = default;
    virtual ~Poligono() = default;

    bool esCerrado() const;
    bool esConvexo() const;
    bool puntoInterior(const Punto& p) const;

    // Devuelve el área aproximada usando simulación de Monte Carlo con 'precision' dígitos
    virtual double area(int precision) const;

    // Funciones auxiliares para bounding box
    double getMenorX() const;
    double getMayorX() const;
    double getMenorY() const;
    double getMayorY() const;
};

#endif // POLIGONO_H