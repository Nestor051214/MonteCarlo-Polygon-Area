#include "Simulacion.h"
#include "Rectangulo.h"
#include <random>
#include <cmath>

double Simulacion::calcularArea() {
    // Crear rectángulo contenedor
    Punto supIzq(poligono.getMenorX(), poligono.getMayorY());
    Punto supDer(poligono.getMayorX(), poligono.getMayorY());
    Punto infDer(poligono.getMayorX(), poligono.getMenorY());
    Punto infIzq(poligono.getMenorX(), poligono.getMenorY());
    Rectangulo rect(supIzq, supDer, infDer, infIzq);
    double areaRect = rect.area();

    // Generador de números aleatorios
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> distX(poligono.getMenorX(), poligono.getMayorX());
    std::uniform_real_distribution<> distY(poligono.getMenorY(), poligono.getMayorY());

    long long totalPuntos = static_cast<long long>(std::pow(10, precision));
    long long puntosDentro = 0;

    for (long long i = 0; i < totalPuntos; ++i) {
        Punto p(distX(gen), distY(gen));
        if (poligono.puntoInterior(p)) {
            ++puntosDentro;
        }
    }

    // Proporción de puntos dentro del polígono respecto al rectángulo
    return (static_cast<double>(puntosDentro) / totalPuntos) * areaRect;
}