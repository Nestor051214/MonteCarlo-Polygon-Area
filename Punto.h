#ifndef PUNTO_H
#define PUNTO_H

#include <cmath>

class Punto {
    double x;
    double y;
public:
    Punto() : x(0), y(0) {}
    Punto(double x, double y) : x(x), y(y) {}
    Punto(const Punto&) = default;
    Punto& operator=(const Punto&) = default;

    bool operator==(const Punto& otro) const {
        // Usamos una tolerancia pequeña para comparar doubles
        const double EPS = 1e-9;
        return std::fabs(x - otro.x) < EPS && std::fabs(y - otro.y) < EPS;
    }

    Punto operator-(const Punto& otro) const {
        return Punto(x - otro.x, y - otro.y);
    }

    double distancia(const Punto& p2) const {
        double dx = x - p2.x;
        double dy = y - p2.y;
        return std::sqrt(dx*dx + dy*dy);
    }

    double getX() const { return x; }
    double getY() const { return y; }
    void setX(double x) { this->x = x; }
    void setY(double y) { this->y = y; }
};

#endif // PUNTO_H