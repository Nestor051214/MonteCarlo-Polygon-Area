cmake_minimum_required(VERSION 3.10)
project(MonteCarloPolygonArea)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Add executable
add_executable(monte_carlo
    main.cpp
    Poligono.cpp
    Recta.cpp
    Rectangulo.cpp
    Segmento.cpp
    Simulacion.cpp
)

# Note: Punto.h is included via headers, no .cpp file needed.
