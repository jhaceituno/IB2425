/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 02.dic.2025
 * @brief Programa principal para la clase Reina
 */

#include <iostream>
#include <vector>
#include "corona.h"
#include "reina.h"

int main() {
  const std::vector<Reina> reinas{
    {"Isabel I de Castilla", "hierro"},
    {"Cleopatra Filopátor", "oro"},
    {"Ingeborg de Dinamarca", "plata"}
  };
  std::cout << "La reina " << reinas[0] << ", la reina "
            << reinas[1] << " y la reina " << reinas[2] << ".\n";
  return 0;
}
