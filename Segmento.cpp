#include "Segmento.h"
#include <algorithm>
#include <cmath>

const double EPS = 1e-9;

Segmento::Segmento(const Punto& p1, const Punto& p2)
    : inicio(p1), fin(p2), recta(p1, p2) {}

bool Segmento::contienePunto(const Punto& p) const {
    // Primero verifica que esté en la recta
    if (!recta.incluyePunto(p)) return false;

    // Luego verifica que esté dentro del bounding box del segmento
    double minX = std::min(inicio.getX(), fin.getX());
    double maxX = std::max(inicio.getX(), fin.getX());
    double minY = std::min(inicio.getY(), fin.getY());
    double maxY = std::max(inicio.getY(), fin.getY());

    return (p.getX() >= minX - EPS && p.getX() <= maxX + EPS &&
            p.getY() >= minY - EPS && p.getY() <= maxY + EPS);
}

bool Segmento::intersectaCon(const Segmento& otro) const {
    if (recta.esParalela(otro.recta)) return false;
    Punto p = recta.interseccion(otro.recta);
    return contienePunto(p) && otro.contienePunto(p);
}

double Segmento::longitud() const {
    double dx = inicio.getX() - fin.getX();
    double dy = inicio.getY() - fin.getY();
    return std::sqrt(dx*dx + dy*dy);
}

Punto Segmento::puntoMedio() const {
    return Punto((inicio.getX() + fin.getX()) / 2.0,
                 (inicio.getY() + fin.getY()) / 2.0);
}