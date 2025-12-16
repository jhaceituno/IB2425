/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 16.dic.2025
 * @brief Cabecera de la clase Polinomio
 */

#ifndef POLINOMIO_H
#define POLINOMIO_H

#include <iostream>
#include <vector>

/// Clase de gestión de polinomios
class Polinomio {
 public:
  double Evaluar(double valor) const;
  Polinomio Integral(double termino_independiente = 0.0) const;
  double Integral(double comienzo, double fin, double precision) const;
  friend std::istream& operator>>(std::istream&, Polinomio& polinomio);
  friend std::ostream& operator<<(std::ostream&, const Polinomio& polinomio);
 private:
  int grado_{0};
  std::vector<double> coeficientes_{};
  bool MostrarTermino(std::ostream&, int indice, bool signo_separado) const;
};

#endif