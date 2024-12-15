/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 10.dic.2024
 * @brief Implementación de las clases Square, Circle y Triangle
 */

#ifndef SHAPES_H
#define SHAPES_H

#include "shape.h"

const double kPi{3.14159265359};

/** Clase de representación de cuadrados */
class Square : public Shape {
 public:
  Square(double side = 1.0) : Shape{"[]", side * side} {}
};

/** Clase de representación de círculos */
class Circle : public Shape {
 public:
  Circle(double radius = 1.0) : Shape{"()", kPi * radius * radius} {}
};

/** Clase de representación de triángulos */
class Triangle : public Shape {
 public:
  Triangle(double base = 1.0, double height = 1.0) : Shape{"/\\", 0.5 * base * height} {}
};

#endif