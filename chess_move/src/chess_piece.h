/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 22.nov.2025
 * @brief Cabecera de la clase ChessPiece
 */

#ifndef CHESS_PIECE_H
#define CHESS_PIECE_H

/// Clase enumerada de tipo de pieza: peón, torre, caballo, alfil, reina y rey
enum ChessType { kPawn, kRook, kKnight, kBishop, kQueen, kKing, kTotal };

/// Clase de representación de piezas de ajedrez
class ChessPiece {
 public:
  ChessPiece() = default;
  std::string type() const;
  bool type(char code);
  bool MoveTo(const std::string& target);
  static bool IsValidSquare(const std::string& square);
 private:
  ChessType type_{kPawn};
  char row_{0}, column_{0};
  static const std::string kInitialLetter;
  static const std::array<std::string, kTotal> kPieceNames;
  static ChessType GetTypeFromInitial(char code);
};

#endif

