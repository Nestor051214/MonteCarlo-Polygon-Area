#ifndef SIMULACION_H
#define SIMULACION_H

#include "Poligono.h"

class Simulacion {
    int precision;           // número de dígitos de precisión (10^precision puntos)
    const Poligono& poligono; // referencia al polígono a evaluar

public:
    Simulacion(const Poligono& pol, int prec) : poligono(pol), precision(prec) {}

    // Calcula el área aproximada usando Monte Carlo
    double calcularArea();
};

#endif // SIMULACION_H