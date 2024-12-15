/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 10.dic.2024
 * @brief Implementación de la clase Shape
 */

#include "shape.h"

/** Operador de inserción en el flujo de salida
 * @param out Flujo de salida
 * @param shape Figura a mostrar
 * @return Flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const Shape& shape) {
  return out << shape.graphic_ << shape.area_;
}

/** Operador de comparación de figuras
 * @param left Operando izquierdo
 * @param right Operando derecho
 * @return Verdadero si el área del operando izquierdo es menor que la del derecho
 */
bool operator<(const Shape& left, const Shape& right) {
  return left.area() < right.area();
}