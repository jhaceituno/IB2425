/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez Aceituno
 * @date 09 Aug 2025
 * @brief Overloading product operators
 *        Operators can take already existing types, as long as the
 *        combinatior of parameter types does not already exist
 */

#include <iostream>
#include <vector>
#include <cassert>

// We can use a type alias to simplify the code
using Vector = std::vector<double>;

// Dot product operator
// (https://en.wikipedia.org/wiki/Dot_product)
double operator*(const Vector& left, const Vector& right) {
  assert(left.size() == right.size());  // Sizes must be equal
  double sum{0.0};
  for (int i{0}; i < left.size(); ++i) {
     sum += left[i] * right[i];
  }
  return sum;
}

// Scalar multiplication operator
// (https://en.wikipedia.org/wiki/Scalar_multiplication)
Vector operator*(const Vector& left, double right) {
  Vector result(left.size());  // Initialize vector size
  for (int i{0}; i < left.size(); ++i) {
    result[i] = left[i] * right;
  }
  return result;
}

// Insertion in output stream operator
std::ostream& operator<<(std::ostream& out, const Vector& vector) {
  out << '[';
  if (vector.size() > 0) {
    out << vector[0];
    for (int i{1}; i < vector.size(); ++i) {
      out << ", " << vector[i];
    }
  }
  out << ']';
  return out;
}

int main() {
  // Dot product
  const Vector kVector1{1.0, 2.0, 3.0}, kVector2{3.0, 2.0, 1.0};
  std::cout << kVector1 << " * " << kVector2 << " = "
            << kVector1 * kVector2 << std::endl;
  
  // Scalar multiplication
  const double kFactor{10.0};
  std::cout << kVector1 << " * " << kFactor << " = "
            << kVector1 * kFactor << std::endl;
  return 0;                            
}

