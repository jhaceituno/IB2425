/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 10.dic.2024
 * @brief Cabecera de la clase Shape
 */

#ifndef SHAPE_H
#define SHAPE_H

#include <iostream>
#include <string>

/** Clase de representación de figuras geométricas */
class Shape {
 public:
  Shape(const std::string& graphic, double area) : graphic_{graphic}, area_{area} {}
  double area() const { return area_; }
  friend std::ostream& operator<<(std::ostream& out, const Shape& shape);
 private:
  std::string graphic_;
  double area_;
};

bool operator<(const Shape& left, const Shape& right);

#endif

