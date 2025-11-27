/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 25.nov.2025
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

ComplexNumber operator+(const ComplexNumber&, const ComplexNumber&);
ComplexNumber operator-(const ComplexNumber&, const ComplexNumber&);
ComplexNumber operator*(const ComplexNumber&, const double scalar);
ComplexNumber operator*(const ComplexNumber&, const ComplexNumber&);
ComplexNumber operator/(const ComplexNumber&, const double scalar);
ComplexNumber operator/(const ComplexNumber&, const ComplexNumber&);
std::ostream& operator<<(std::ostream& out, const ComplexNumber&);

#endif
