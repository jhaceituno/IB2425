/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 10.dic.2024
 * @brief Programa principal de la clase Graph
 */

#include <iostream>
#include <sstream>
#include "graph.h"

int main() {
  Graph graph;
  std::cin >> graph;
  std::cout << graph << std::endl;

  // Manually read two graphs and add them
  Graph first, second, result;
  std::stringstream auxiliar{"3 2 0 1 1 2  3 2 0 1 0 2"};
  auxiliar >> first >> second;
  std::cout << first << "+\n" << second << "=\n"
            << first + second << std::endl;
  return 0;
}
