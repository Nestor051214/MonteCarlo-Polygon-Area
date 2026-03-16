#include <iostream>
#include <vector>
#include "Poligono.h"

int main() {
    int numPuntos;
    std::cout << "Monte Carlo Figure Area Simulation\n"
              << "Enter the number of vertices of the polygon (>=3): ";
    std::cin >> numPuntos;

    if (numPuntos < 3) {
        std::cerr << "A polygon must have at least 3 vertices.\n";
        return 1;
    }

    std::vector<Punto> vertices;
    vertices.reserve(numPuntos);
    std::cout << "Enter the coordinates of each vertex (x y):\n";
    for (int i = 0; i < numPuntos; ++i) {
        double x, y;
        std::cout << "Vertex " << i << ": ";
        std::cin >> x >> y;
        vertices.emplace_back(x, y);
    }

    Poligono poligono(vertices);

    std::cout << "Polygon is " << (poligono.esCerrado() ? "closed" : "not closed") << "\n";

    for (int prec = 3; prec < 9; ++prec) {
        double areaAprox = poligono.area(prec);
        std::cout << "Approximate area with precision " << prec << ": " << areaAprox << " u^2\n";
    }

    return 0;
}