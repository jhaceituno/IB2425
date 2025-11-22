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
#include <fstream>
#include <iomanip>
#include <sstream>
#include "chess_piece.h"

int main(int argc, char* argv[]) {
  if (argc != 2) {
    std::cerr << argv[0] << " <fichero>\n";
    return 1;
  }
  std::ifstream chess_file(argv[1]);
  if (!chess_file) {
    std::cerr << "No se pudo abrir " << argv[1] << std::endl;
    return 2;
  }
  ChessPiece piece{};
  std::string line{};
  std::stringstream buffer{};
  while (std::getline(chess_file, line)) {
    buffer.clear();
    buffer.str(line);
    char initial{};
    buffer >> initial;
    if (!piece.type(initial)) {
      std::cout << std::setw(10) << std::left << initial << "Código erróneo\n";
      continue;
    }
    std::cout << std::setw(10) << std::left << (piece.type() + ':');
    
    std::string square{};
    bool first{true}, error{false};
    while (!error && (buffer >> square)) {
      if (first) {
        first = false;
      } else {
        std::cout << " -> ";
      }
      std::cout << square;
      if (!ChessPiece::IsValidSquare(square)) {
        std::cout << " - límites excedidos\n";
        error = true;
      } else if (!piece.MoveTo(square)) {
        std::cout << " - movimiento ilegal\n";
        error = true;
      }
    }
    if (!error) {
      std::cout << " - secuencia correcta\n";
    }
  }
  return 0;
}
