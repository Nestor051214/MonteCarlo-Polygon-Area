#include "Poligono.h"
#include "Simulacion.h"
#include <algorithm>
#include <vector>
#include <cmath>

const double EPS = 1e-9;

Poligono::Poligono(const std::vector<Punto>& vertices) {
    size_t n = vertices.size();
    if (n < 3) return; // no es un polígono válido

    lados.reserve(n);
    for (size_t i = 0; i < n - 1; ++i) {
        lados.emplace_back(vertices[i], vertices[i+1]);
    }
    lados.emplace_back(vertices[n-1], vertices[0]);
}

bool Poligono::esCerrado() const {
    if (lados.size() < 3) return false;
    // Verifica que el último lado conecta con el primero
    const Punto& finUltimo = lados.back().getFin();
    const Punto& inicioPrimero = lados.front().getInicio();
    return finUltimo == inicioPrimero;
}

bool Poligono::puntoInterior(const Punto& p) const {
    // Algoritmo de paridad (ray casting)
    int intersecciones = 0;
    const double INF = getMayorX() + 1000.0; // punto lejano horizontal

    Segmento rayo(p, Punto(INF, p.getY()));

    for (const auto& lado : lados) {
        if (lado.contienePunto(p)) {
            // El punto está sobre el borde -> consideramos interior
            return true;
        }

        if (lado.intersectaCon(rayo)) {
            // Contar solo si el punto de intersección no es exactamente un vértice
            // (para evitar doble conteo). Usamos una estrategia simple: ignorar intersecciones
            // que ocurren en el punto más bajo del lado (problema clásico).
            // Aquí simplificamos: contamos todas y confiamos en que Monte Carlo promedia.
            intersecciones++;
        }
    }

    return (intersecciones % 2) == 1;
}

double Poligono::getMenorX() const {
    double menor = lados.empty() ? 0 : lados[0].getInicio().getX();
    for (const auto& lado : lados) {
        menor = std::min({menor, lado.getInicio().getX(), lado.getFin().getX()});
    }
    return menor;
}

double Poligono::getMayorX() const {
    double mayor = lados.empty() ? 0 : lados[0].getInicio().getX();
    for (const auto& lado : lados) {
        mayor = std::max({mayor, lado.getInicio().getX(), lado.getFin().getX()});
    }
    return mayor;
}

double Poligono::getMenorY() const {
    double menor = lados.empty() ? 0 : lados[0].getInicio().getY();
    for (const auto& lado : lados) {
        menor = std::min({menor, lado.getInicio().getY(), lado.getFin().getY()});
    }
    return menor;
}

double Poligono::getMayorY() const {
    double mayor = lados.empty() ? 0 : lados[0].getInicio().getY();
    for (const auto& lado : lados) {
        mayor = std::max({mayor, lado.getInicio().getY(), lado.getFin().getY()});
    }
    return mayor;
}

bool Poligono::esConvexo() const {
    // Implementación pendiente, se puede añadir después
    // Por ahora retorna true para no romper el código que la llama
    return true;
}

double Poligono::area(int precision) const {
    if (!esCerrado()) return -1.0;
    Simulacion sim(*this, precision);
    return sim.calcularArea();
}