/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 27.nov.2024
 * @brief Implementación de la función Factores
 */

#include <iostream>
#include <vector>

/** Descomposición de un valor entero en sus factores primos
 * @param valor Valor a descomponer
 * @return Vector de factores primos
 */
std::vector<int> Factores(unsigned int valor) {
  int divisor{2};
  std::vector<int> factores{};
  factores.reserve(10);
  while (divisor * divisor <= valor) {
    if (valor % divisor == 0) {
      factores.emplace_back(divisor);
      valor /= divisor;
    } else {
      ++divisor;
    }
  }
  if (valor > 1 || factores.size() == 0) {
    factores.emplace_back(valor);
  }
  return factores;
}

// No es necesario implementar la función main para este ejercicio
int main() {
  const std::vector<int> valores{31, 777, 1024, 10082};
  for (auto valor: valores) {
    std::cout << valor << " = ";
    std::vector<int> factores{Factores(valor)};
    int ultimo{factores.back()};
    factores.pop_back();
    for (auto factor: factores) {
      std::cout << factor << " x ";
    }
    std::cout << ultimo << std::endl;
  }
  return 0;
}
