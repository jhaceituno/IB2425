/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Clase de gestión de números complejos
 */

#include <iostream>
#include "complex_number.h"

/** Constructor de la clase
 *  @param[in] real Parte real
 *  @param[in] imaginary Parte imaginaria
 */
ComplexNumber::ComplexNumber(double real, double imaginary) :
                             real_{real}, imaginary_{imaginary} {}

/** Operador de cambio de signo
 *  @return Número complejo cambiado de signo
 */
ComplexNumber ComplexNumber::operator-() const {
  return ComplexNumber{-real_, -imaginary_};
}

/** Cálculo de la conjugada de un número complejo
 *  @return Conjugada del número complejo
 */
ComplexNumber ComplexNumber::Conjugate() const {
  return ComplexNumber{real_, -imaginary_};
}

/** Cálculo de la inversa de un número complejo
 *  @return Inversa del número complejo
 */
ComplexNumber ComplexNumber::Reverse() const {
  double square_modulus{real_ * real_ + imaginary_ * imaginary_};
  return Conjugate() / square_modulus;
}

/** Operador de suma de números complejos
 *  @param[in] c1 Sumando izquierdo
 *  @param[in] c2 Sumando derecho
 *  @return Resultado de la suma
 */
ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2) {
  return ComplexNumber{c1.real() + c2.real(), c1.imaginary() + c2.imaginary()};
}

/** Operador de resta de números complejos
 *  @param[in] c1 Minuendo
 *  @param[in] c2 Sustraendo
 *  @return Resultado de la resta
 */
ComplexNumber operator-(const ComplexNumber& c1, const ComplexNumber& c2) {
  return c1 + (-c2);
}

/** Operador de multiplicación de un número complejo por un escalar
 *  @param[in] complex Factor complejo
 *  @param[in] scalar Factor escalar
 *  @return Resultado de la multiplicación
 */
ComplexNumber operator*(const ComplexNumber& complex, const double scalar) {
  return ComplexNumber{complex.real() * scalar, complex.imaginary() * scalar};
}

/** Operador de multiplicación de números complejos
 *  @param[in] c1 Factor izquierdo
 *  @param[in] c2 Factor derecho
 *  @return Resultado de la multiplicación
 */
ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2) {
  return ComplexNumber{c1.real() * c2.real() - c1.imaginary() * c2.imaginary(),
                       c1.real() * c2.imaginary() + c2.real() * c1.imaginary()};
}

/** Operador de división de un número complejo entre un escalar
 *  @param[in] complex Dividendo complejo
 *  @param[in] scalar Divisor escalar
 *  @return Cociente de la división
 */
ComplexNumber operator/(const ComplexNumber& complex, const double scalar) {
  return complex * (1.0 / scalar);
}

/** Operador de división de números complejos
 *  @param[in] c1 Dividendo
 *  @param[in] c2 Divisor
 *  @return Cociente de la división
 */
ComplexNumber operator/(const ComplexNumber& c1, const ComplexNumber& c2) {
  return c1 * c2.Reverse();
}

/** Operador de inserción en el flujo de salida para números complejos
 *  @param[out] out Flujo de salida
 *  @param[in] c Número complejo
 *  @return Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const ComplexNumber& c) {
  out << '(' << c.real() << ", " << c.imaginary() << ')';
  return out; 
}

