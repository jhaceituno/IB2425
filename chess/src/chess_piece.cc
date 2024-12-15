/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 17.dic.2024
 * @brief Implementación de la clase ChessPiece
 */

#include <iostream>
#include <cstdlib>
#include <string>
#include "chess_piece.h"

/** Constructor por defecto de la clase ChessPiece
 * Genera aleatoriamente el color, el tipo y la posición de la pieza */
ChessPiece::ChessPiece() :
    type_{static_cast<ChessType>(rand() % ChessType::KTotal)},
    is_white_{rand() % 2 == 0}, row_{0}, column_{0} {
  RandomPosition();
}

/** Función que genera una posición aleatoria para una pieza */
void ChessPiece::RandomPosition() {
  // El static_cast de int a unsigned char es innecesario,
  // pero así le ahorramos trabajo al compilador:
  row_ = static_cast<unsigned char>(1 + rand() % kBoardSize);
  column_ = static_cast<unsigned char>(1 + rand() % kBoardSize);
}

/** Operador de igualdad entre posiciones de piezas de ajedrez
 * @param piece Segundo operando
 * @return Verdadero si ambas piezas están en la misma posición
 */
bool ChessPiece::operator==(const ChessPiece& piece) const {
  return row_ == piece.row_ && column_ == piece.column_;
}

/** Conversor del tipo de pieza a cadena de caracteres
 * @return Tipo como cadena de caracteres
 */
std::string ChessPiece::type() const {
  // No es necesario añadir break después de una sentencia return,
  // porque ya se habrá salido de la función:
  switch (type_) {
    case ChessType::kPawn:
      return "pawn";
    case ChessType::kRook:
      return "rook";
    case ChessType::kKnight:
      return "knight";
    case ChessType::kQueen:
      return "queen";
    case ChessType::kKing:
      return "king";
    default:
      return "unknown";
  }
}

/** Operador de inserción en el flujo de salida para ChessPiece
 * @param out Flujo de salida
 * @param piece Pieza de ajedrez a mostrar
 * @return Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const ChessPiece& piece) {
  // El static_cast de unsigned char a int en este caso sí es necesario,
  // de lo contrario el operador << intentaría mostrarlos como caracteres
  // en lugar de como números enteros:
  return out << piece.type() << (piece.is_white_ ? " white" : " black")
             << ", row=" << static_cast<int>(piece.row_)
             << ", column=" << static_cast<int>(piece.column_);
}

/** Comprobación de solapes entre piezas de un vector
 * @param pieces Vector de ChessPiece
 * @return Verdadero si dos o más piezas están en igual posición
 */
bool CheckOverlap(const ChessVector& pieces) {
  // Se evalúan todas las posibles parejas de piezas.
  // size_t es un alias de unsigned long que usa std::vector
  for (size_t i{1}; i < pieces.size(); ++i) {
    for (size_t j{0}; j < i; ++j) {
      if (pieces[i] == pieces[j]) {
        return true;  // Hay dos piezas en igual posición
      }
    }
  }
  return false;  // Todas las piezas tienen distintas posiciones
}

/** Operador de inserción en el flujo de salida para vectores de ChessPiece
 * @param out Flujo de salida
 * @param pieces Vector de piezas de ajedrez a mostrar
 * @return Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const ChessVector& pieces) {
  for (const auto& piece: pieces) {
    out << piece << std::endl;
  }
  return out;
}
