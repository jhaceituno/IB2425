/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 16.dic.2025
 * @brief Programa de cálculo de integrales de polinomios
 */

#include <iostream>
#include <sstream>
#include "polinomio.h"

int main(int argc, char** argv) {
  if (argc == 1 || argc != atoi(argv[1]) + 6) {
    // Si el grado es N, se debe recibir N + 6 parámetros:
    // (1 prog) + (1 grado) + (N + 1 coefs) + (2 intervalo) + (1 precision)
    std::cerr << argv[0]
              << " <grado> {coeficientes} {intervalo} <precision>\n";
    return 1;
  }
  std::stringstream auxiliar{};
  for (int i{1}; i < argc; ++i) {
    auxiliar << argv[i] << ' ';
  }
  Polinomio polinomio{};
  double comienzo{0.0}, fin{0.0}, precision{0.0};
  auxiliar >> polinomio >> comienzo >> fin >> precision;
  Polinomio integral{polinomio.Integral()};
  std::cout << "f(x) = " << polinomio << "\n∫f(x)dx = " << integral
            << "\n∫(" << comienzo << ',' << fin << ")f(x)dx = "
            << polinomio.Integral(comienzo, fin, precision) 
            << " (por Runge-Kutta)" << std::endl
            << "∫(" << comienzo << ',' << fin << ")f(x)dx = "
            << integral.Evaluar(fin) - integral.Evaluar(comienzo)
            << " (por diferencia)" << std::endl;
  return 0;
}
