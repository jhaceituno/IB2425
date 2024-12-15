/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Cabecera de la clase ComplexNumber
 */

#ifndef COMPLEX_NUMBER_H
#define COMPLEX_NUMBER_H

/** Clase de representación de números complejos */
class ComplexNumber {
 public:
  ComplexNumber(double real = 0.0, double imaginary = 0.0);
  double real() const { return real_; }
  double imaginary() const { return imaginary_; }
  ComplexNumber operator-() const;
  ComplexNumber Conjugate() const;
  ComplexNumber Reverse() const;
 private:
  double real_;
  double imaginary_;
};

ComplexNumber operator+(const ComplexNumber& c1, const ComplexNumber& c2);
ComplexNumber operator-(const ComplexNumber& c1, const ComplexNumber& c2);
ComplexNumber operator*(const ComplexNumber& complex, const double scalar);
ComplexNumber operator*(const ComplexNumber& c1, const ComplexNumber& c2);
ComplexNumber operator/(const ComplexNumber& complex, const double scalar);
ComplexNumber operator/(const ComplexNumber& c1, const ComplexNumber& c2);
std::ostream& operator<<(std::ostream& out, const ComplexNumber& c);

#endif

