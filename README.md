# Monte Carlo Polygon Area Estimator (C++)

A C++ program that estimates the area of any simple polygon using the **Monte Carlo method**.  
This project demonstrates object‑oriented design, computational geometry concepts, and random sampling techniques.

## 📌 Features

- Construct a polygon from a set of Cartesian vertices.
- Check if the polygon is closed and (optionally) convex.
- Determine if a point lies inside the polygon using the **ray‑casting** algorithm.
- Compute the bounding box (rectangle) that encloses the polygon.
- Estimate the polygon’s area by generating random points inside the bounding box and counting how many fall inside the polygon (Monte Carlo integration).
- Adjustable precision: the number of random points is \(10^{\text{precision}}\).
- Clean, modern C++ code with `std::vector`, no manual memory management, and clear separation of concerns.

## 🧮 How It Works

1. The user enters the vertices of a polygon (in order, either clockwise or counter‑clockwise).
2. The program builds a `Poligono` object consisting of `Segmento` (line segments) between consecutive vertices.
3. A bounding rectangle is computed from the extreme x and y coordinates of the polygon.
4. Random points are generated uniformly inside this rectangle.
5. For each point, the ray‑casting algorithm determines whether it lies inside the polygon.
6. The area is estimated as:

\[
\text{area} \approx \frac{\text{points inside}}{\text{total points}} \times \text{area of bounding rectangle}
\]

The approximation improves as the number of points increases.

## 🛠 Requirements

- C++17 compatible compiler (e.g., g++, clang++)
- CMake (optional, for building)
- No external libraries – everything uses the C++ standard library.

## 🚀 Compilation and Execution

### Using g++ directly
```bash
g++ -std=c++17 -O2 -o monte_carlo *.cpp
./monte_carlo
```

## 📝 Usage Example
```Monte Carlo Figure Area Simulation
Enter the number of vertices of the polygon (>=3): 4
Enter the coordinates of each vertex (x y):
Vertex 0: 0 0
Vertex 1: 4 0
Vertex 2: 4 3
Vertex 3: 0 3
Polygon is closed
Approximate area with precision 3: 12.034 u²
Approximate area with precision 4: 11.997 u²
Approximate area with precision 5: 12.001 u²
Approximate area with precision 6: 12.000 u²
```
For a rectangle of width 4 and height 3, the exact area is 12. The Monte Carlo estimates converge to this value as precision increases.

## 📁 Project Structure
Punto.h:
	Represents a 2D point with basic operations.
Recta.h/cpp:
	Represents an infinite line (supports vertical/horizontal).
Segmento.h/cpp:
	Represents a line segment between two points; includes intersection tests.
Poligono.h/cpp:
	Represents a polygon built from segments; checks point inclusion, convexity.
Rectangulo.h/cpp:
	Specialized polygon for the bounding rectangle.
Simulacion.h/cpp:
	Performs the Monte Carlo simulation to estimate the area.
main.cpp:
	User interface: reads vertices and prints area estimates

## 🔍 Possible Improvements
Implement a robust convexity test.

Handle polygons with holes (currently assumes simple polygons).

Optimize point‑in‑polygon test using a sweep‑line or grid.

Provide a graphical output (e.g., export to SVG).

Add unit tests.

## 📄 License
This project is open source and available under the MIT License.

## 👥 Authors

- **Nestor Nuñez Díaz** – Computer Science student at the Central University "Marta Abreu" of Las Villas, Cuba.  
  [![GitHub](https://img.shields.io/badge/GitHub-100000?style=flat&logo=github&logoColor=white)](https://github.com/Nestor051214)  
  📧 nestor141205@gmail.com

- **Adriana Isabel Acosta González** – Computer Science student at the Central University "Marta Abreu" of Las Villas, Cuba.  
  [![GitHub](https://img.shields.io/badge/GitHub-100000?style=flat&logo=github&logoColor=white)](https://github.com/acostaAdriana-cyber)  
  📧 acostagonzalez3136@gmail.com

**_This project was developed as part of an academic portfolio. It demonstrates object‑oriented design, mathematical modelling, and the Monte Carlo method – all key concepts in computer science._**