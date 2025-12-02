/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 02.dic.2025
 * @brief Programa principal de la clase Graph
 */

#include <iostream>
#include <sstream>
#include "graph.h"

int main() {
  Graph graph;
  std::cin >> graph;
  std::cout << graph << std::endl;

  /* Manually read two graphs and add them:
                  ╭─> 1     ╭─> 1 ─> 2
  0 ─> 1 ─> 2  +  0      =  0   ╭──> 4
                  ╰─> 2     ╰─> 3
                                ╰──> 5  */
  Graph first, second, result;
  std::stringstream auxiliar{"3 2 0 1 1 2  3 2 0 1 0 2"};
  auxiliar >> first >> second;
  std::cout << first << "+\n" << second << "=\n"
            << first + second << std::endl;
  // The result should be "6 5 0 1 0 3 1 2 3 4 3 5"
  return 0;
}
