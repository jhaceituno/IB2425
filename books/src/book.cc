/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Clase de gestión de libros
 */

#include <iostream>
#include <string>
#include "book.h"

/** Constructor de la clase
 *  @param[in] title Título del libro
 *  @param[in] year Año de publicación
 *  @param[in] price Precio de venta
 */
Book::Book(const std::string& title, int year, double price) :
           title_{title}, year_{year}, price_{price} {}

/** Cálculo del precio de venta con impuesto
 *  @param[in] tax Impuesto de venta
 *  @return Previo con impuesto
 */
double Book::GetPriceWithTax(double tax) const {
  return price_ * (1.0 + 0.01 * tax);
}

/** Operador de inserción en el flujo de salida parala clase Book
 *  @param[out] out Flujo de salida
 *  @param[in] book Libro
 *  @return Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const Book& book) {
  out << book.title_ << ", " << book.year_ << ", " << book.price_;
  return out; 
}

