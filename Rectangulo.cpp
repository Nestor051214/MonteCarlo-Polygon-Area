#include "Rectangulo.h"

Rectangulo::Rectangulo(const Punto& a, const Punto& b, const Punto& c, const Punto& d) {
    std::vector<Punto> vertices = {a, b, c, d};
    // Usamos el constructor de Poligono que crea los lados desde vértices
    // Nota: esto asume que los puntos están en orden correcto
    lados.clear();
    lados.reserve(4);
    lados.emplace_back(a, b);
    lados.emplace_back(b, c);
    lados.emplace_back(c, d);
    lados.emplace_back(d, a);
}

double Rectangulo::area() const {
    if (lados.size() < 2) return 0.0;
    return lados[0].longitud() * lados[1].longitud();
}