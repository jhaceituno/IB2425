/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 27.nov.2024
 * @brief Cabecera de la clase Vector
 */

#ifndef VECTOR_H
#define VECTOR_H

#include <iostream>
#include <array>

constexpr int kLongitudVector{3};

class Vector {
 public:
  /// Constructor por defecto 
  Vector() : valores_{0.0, 0.0, 0.0} {}
  Vector(double componente_1, double componente_2, double componente_3);
  double Get(int indice) const;
  void Set(int indice, double valor);
  double Modulo() const;
 private: 
  std::array<double, kLongitudVector> valores_;
};

Vector operator+(const Vector& primero, const Vector& segundo);
double operator*(const Vector& primero, const Vector& segundo);
std::ostream& operator<<(std::ostream& salida, const Vector& vector);
std::istream& operator>>(std::istream& entrada, Vector& vector);

#endif
