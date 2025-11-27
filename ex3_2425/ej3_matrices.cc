/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 27.nov.2024
 * @brief Programa principal de la clase Matriz
 */

#include <iostream>
#include <fstream>
#include "ej3_matriz.h"

int main() {
  const std::string kEntrada{"matrices.txt"};
  const std::string kSalida{"producto.txt"};
  std::ifstream entrada{kEntrada};
  std::ofstream salida{kSalida};
  if (!entrada || !salida) {
    std::cerr << "No se pudo abrir uno de los ficheros.\n";
    return 1;
  }
  Matriz izquierda{}, derecha{};
  while (entrada >> izquierda >> derecha) {
    salida << izquierda << " x " << derecha << " = "
           << izquierda * derecha << std::endl;
  }
  return 0;
}