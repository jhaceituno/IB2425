/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 25.nov.2025
 * @brief Programa principal de gestión de números complejos
 */

#include <iostream>
#include <iomanip>
#include "complex_number.h"

int main() {
  const ComplexNumber complex1{68.04}, complex2{56.62, -21.12};
  std::cout << std::fixed << std::setprecision(2)
            << "Numeros: " << complex1 << ' ' << complex2 << std::endl
            << "Suma:    " << complex1 + complex2 << std::endl
            << "Resta:   " << complex1 - complex2 << std::endl
            << "Mult.:   " << complex1 * complex2 << std::endl
            << "Div.:    " << complex1 / complex2 << std::endl;
  return 0;
}

