/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 10.dic.2024
 * @brief Programa principal de la clase Shape
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include "shape.h"
#include "shapes.h"

int main() {
  std::vector<Shape> shapes{Square{1.0}, Circle{0.5}, Triangle{1.0, 1.0}, Triangle{2.0, 2.0}};
  std::sort(shapes.begin(), shapes.end());
  for (auto shape: shapes) {
    std::cout << shape << ' ';
  }
  std::cout << std::endl;
  return 0;
}
