/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 27.nov.2024
 * @brief Programa principal de la clase Vector
 */

#include <iostream>
#include <fstream>
#include "ej3_vector.h"

int main() {
  const std::string kEntrada{"vectores.txt"};
  const std::string kSalida{"producto.txt"};
  std::ifstream entrada{kEntrada};
  std::ofstream salida{kSalida};
  if (!entrada || !salida) {
    std::cerr << "No se pudo abrir uno de los ficheros.\n";
    return 1;
  }
  Vector izquierdo{}, derecho{};
  while (entrada >> izquierdo >> derecho) {
    salida << izquierdo << " * " << derecho << " = "
           << izquierdo * derecho << std::endl;
  }
  return 0;
}