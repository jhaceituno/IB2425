/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 22.nov.2025
 * @brief Implementación de la clase ChessPiece
 */

#include <iostream>
#include <string>
#include <array>
#include "chess_piece.h"

/// Iniciales de los nombres de las piezas, como cadena estática
const std::string ChessPiece::kInitialLetter{"ptcaRr"};

/// Nombres de las piezas, como array constante estático
const std::array<std::string, kTotal> ChessPiece::kPieceNames = {
  "Peon", "Torre", "Caballo", "Alfil", "Reina", "Rey"
};

/** Conversión del nombre de la pieza a cadena de caracteres
 * @return Nombre de la pieza */
std::string ChessPiece::type() const {
  return kPieceNames[type_];
}

/** Fijar tipo de la pieza a partir de su inicial
 * @param code Inicial del nombre de la pieza
 * @return Falso si no se reconoce la inicial
 */
bool ChessPiece::type(char code) {
  type_ = GetTypeFromInitial(code);
  row_ = column_ = 0;
  return type_ != kTotal;
}

/** Comprobar si la casilla proporcionada tiene un formato válido
 * @param square Código de la casilla
 * @return Verdadero si la casilla es válida
 */
bool ChessPiece::IsValidSquare(const std::string& square) {
  return square.length() == 2 && square[0] >= 'a' && square[0] <= 'g'
                              && square[1] >= '1' && square[1] <= '8';
}

/** Conversión de inicial a tipo de pieza
 * @param code Inicial del nombre de la pieza
 * @return Tipo de pieza, kTotal en caso de error
 */
ChessType ChessPiece::GetTypeFromInitial(char code) {
  for (int i{0}; i < kTotal; ++i) {
    if (code == kInitialLetter[i]) {
      return static_cast<ChessType>(i);
    }
  }
  return kTotal;
}

/** Movimiento a una nueva posición
 * @param target Posición deseada
 * @return Verdadero si el movimiento es válido
 */
bool ChessPiece::MoveTo(const std::string& target) {
  if (!row_ || !column_) {  // Posición no inicializada
    column_ = target[0];
    row_ = target[1];
    return true;
  }
  int row_forward_shift{target[1] - row_};  // Variación vertical con signo
  int row_shift{abs(row_forward_shift)};    // Variación vertical
  int col_shift{abs(column_ - target[0])};  // Variación horizontal

  if (!row_shift && !col_shift) { return false; }  // Si no hay movimiento

  bool diagonal = row_shift == col_shift;  // Movimiento diagonal
  column_ = target[0];
  row_ = target[1];

  switch (type_) {  // Devolvemos 'verdadero' si el movimiento es legal
    case kPawn:
      return !col_shift  // Sólo mueve 1 hacia delante o 2 desde la fila 2
          && (row_forward_shift == 1 || target[1] == '4');
    case kRook:
      return !row_shift || !col_shift;  // Movimiento en una sola dirección
    case kKnight:
      return (row_shift == 1 && col_shift == 2)   // 1 vertical, 2 horizontal
          || (row_shift == 2 && col_shift == 1);  // 2 vertical, 1 horizontal
    case kBishop:
      return diagonal;  // Sólo diagonal
    case kQueen:
      return !row_shift || !col_shift || diagonal;  // Una dirección o diagonal
    case kKing:
      return row_shift <= 1 && col_shift <= 1;  // 1 en cualquier dirección
    default:
      std::cerr << "This should not have happened!\n";
  }
  return false;
}
