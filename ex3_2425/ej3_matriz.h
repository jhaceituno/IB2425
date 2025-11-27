/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 27.nov.2024
 * @brief Cabecera de la clase Matriz
 */

#ifndef MATRIZ_H
#define MATRIZ_H

#include <iostream>
#include <array>

constexpr int kLadoMatriz{2};

class Matriz {
 public:
  Matriz(double elemento_11 = 1.0, double elemento_12 = 0.0,
         double elemento_21 = 0.0, double elemento_22 = 1.0);
  double Get(int fila, int columna) const;
  void Set(int fila, int columna, double valor);
  double Determinante() const;
 private: 
  std::array<std::array<double, kLadoMatriz>, kLadoMatriz> valores_;
};

Matriz operator+(const Matriz& primera, const Matriz& segunda);
Matriz operator*(const Matriz& primera, const Matriz& segunda);
std::ostream& operator<<(std::ostream& salida, const Matriz& vector);
std::istream& operator>>(std::istream& entrada, Matriz& vector);

#endif
