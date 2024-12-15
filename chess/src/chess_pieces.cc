/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 17.dic.2024
 * @brief Programa principal de la clase ChessPiece
 */

#include <iostream>
#include <cstdlib>
#include <vector>
#include <ctime>
#include "chess_piece.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << argv[0] << " <numero de piezas>\n";
    return 1;
  }
  srand(time(0));  // Inicialización de la semilla aleatoria
  // size_t es un alias de unsigned long que usa std::vector
  size_t numero_de_piezas{static_cast<size_t>(atoi(argv[1]))};
  ChessVector piezas{numero_de_piezas};
  while (CheckOverlap(piezas)) {
    std::cout << piezas << "Several piezas are in the same position. "
              << "We are going to relocate them:\n";
    for (auto& pieza: piezas) {
      pieza.RandomPosition();
    }
  }
  std::cout << piezas << "All the pieces are in different positions.\n";
  return 0;
}