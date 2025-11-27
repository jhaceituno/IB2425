/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Programa principal de la clase Rey
 */

#include <iostream>
#include <algorithm>
#include <vector>
#include "ej3_rey.h"

int main() {
  std::vector<Rey> reyes{};
  reyes.reserve(10);
  Rey auxiliar_lectura{};
  while (std::cin >> auxiliar_lectura) {
    reyes.emplace_back(auxiliar_lectura);
  }
  std::sort(reyes.begin(), reyes.end());
  for (const Rey& rey: reyes) {
    std::cout << rey << ' ' << rey.DuracionReinado() << std::endl;
  }
  return 0;
}
