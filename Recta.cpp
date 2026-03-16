#include "Recta.h"
#include <cmath>
#include <algorithm>
#include <limits>   // <--- necesario para std::numeric_limits

const double EPS = 1e-9;

Recta::Recta(const Punto& p1, const Punto& p2) {
    double dx = p2.getX() - p1.getX();
    double dy = p2.getY() - p1.getY();
    if (std::fabs(dx) < EPS) {
        m = std::numeric_limits<double>::quiet_NaN();
        n = p1.getX(); // almacenamos la coordenada X constante
    } else {
        m = dy / dx;
        n = p1.getY() - m * p1.getX();
    }
}

bool Recta::incluyePunto(const Punto& p) const {
    if (std::isnan(m)) {
        // Recta vertical: la X debe ser igual a n
        return std::fabs(p.getX() - n) < EPS;
    } else {
        double y_esperada = m * p.getX() + n;
        return std::fabs(p.getY() - y_esperada) < EPS;
    }
}

bool Recta::esParalela(const Recta& r) const {
    if (std::isnan(m) && std::isnan(r.m)) return true;
    if (std::isnan(m) || std::isnan(r.m)) return false;
    return std::fabs(m - r.m) < EPS;
}

Punto Recta::interseccion(const Recta& r) const {
    // Se asume que no son paralelas
    if (std::isnan(m)) {
        // Esta recta es vertical: x = n
        double x = n;
        double y = r.m * x + r.n;
        return Punto(x, y);
    }
    if (std::isnan(r.m)) {
        // La otra recta es vertical
        double x = r.n;
        double y = m * x + n;
        return Punto(x, y);
    }
    // Ambas tienen pendiente finita
    double x = (r.n - n) / (m - r.m);
    double y = m * x + n;
    return Punto(x, y);
}

double Recta::evaluar(double x) const {
    // Solo debe llamarse si no es vertical
    return m * x + n;
}