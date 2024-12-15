/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Cabecera de la clase Book
 */

#ifndef BOOK_H
#define BOOK_H

/** Clase de representación de libros */
class Book {
 public:
  Book(const std::string& title, int year, double price);
  double GetPriceWithTax(double tax) const;
  friend std::ostream& operator<<(std::ostream& out, const Book& book);
 private:
  std::string title_;
  int year_;
  double price_;
};

std::ostream& operator<<(std::ostream& out, const Book& book);

#endif

