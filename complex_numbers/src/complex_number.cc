/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 25.nov.2025
 * @brief Clase de gestión de números complejos
 */

#include <iostream>
#include "complex_number.h"

/** Constructor de la clase
 *  @param real Parte real
 *  @param imaginary Parte imaginaria
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
 *  @param left Sumando izquierdo
 *  @param right Sumando derecho
 *  @return Resultado de la suma
 */
ComplexNumber operator+(const ComplexNumber& left,
                        const ComplexNumber& right) {
  return ComplexNumber{left.real() + right.real(),
                       left.imaginary() + right.imaginary()};
}

/** Operador de resta de números complejos
 *  @param left Minuendo
 *  @param right Sustraendo
 *  @return Resultado de la resta
 */
ComplexNumber operator-(const ComplexNumber& left,
                        const ComplexNumber& right) {
  return left + (-right);
}

/** Operador de multiplicación de un número complejo por un escalar
 *  @param complex Factor complejo
 *  @param scalar Factor escalar
 *  @return Resultado de la multiplicación
 */
ComplexNumber operator*(const ComplexNumber& complex, const double scalar) {
  return ComplexNumber{complex.real() * scalar, complex.imaginary() * scalar};
}

/** Operador de multiplicación de números complejos
 *  @param left Factor izquierdo
 *  @param right Factor derecho
 *  @return Resultado de la multiplicación
 */
ComplexNumber operator*(const ComplexNumber& left,
                        const ComplexNumber& right) {
  return ComplexNumber{
    left.real() * right.real() - left.imaginary() * right.imaginary(),
    left.real() * right.imaginary() + right.real() * left.imaginary()
  };
}

/** Operador de división de un número complejo entre un escalar
 *  @param complex Dividendo complejo
 *  @param scalar Divisor escalar
 *  @return Cociente de la división
 */
ComplexNumber operator/(const ComplexNumber& complex, const double scalar) {
  return complex * (1.0 / scalar);
}

/** Operador de división de números complejos
 *  @param left Dividendo
 *  @param right Divisor
 *  @return Cociente de la división
 */
ComplexNumber operator/(const ComplexNumber& left,
                        const ComplexNumber& right) {
  return left * right.Reverse();
}

/** Operador de inserción en el flujo de salida para números complejos
 *  @param out Flujo de salida
 *  @param complex Número complejo
 *  @return Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const ComplexNumber& complex) {
  out << '(' << complex.real() << ", " << complex.imaginary() << ')';
  return out; 
}

