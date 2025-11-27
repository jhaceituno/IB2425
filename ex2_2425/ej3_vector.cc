/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 27.nov.2024
 * @brief Implementación de la clase Vector
 */

#include <iostream>
#include <cmath>
#include "ej3_vector.h"

/** Constructor de la clase Vector
 * @param componente_1 Primera componente
 * @param componente_2 Segunda componente
 * @param componente_3 Tercera componente
 */
Vector::Vector(double componente_1, double componente_2, double componente_3)
              : valores_{componente_1, componente_2, componente_3} {}

/** Getter de los valores del vector
 * @param indice Índice del elemento a leer
 * @return Elemento leído
 */
double Vector::Get(int indice) const {
  return valores_[indice];
}

/** Setter de los valores del vector
 * @param indice Índice del elemento a modificar
 * @param valor Nuevo valor del elemento
 */
void Vector::Set(int indice, double valor) {
  valores_[indice] = valor;
}

/// Cálculo del módulo del vector
double Vector::Modulo() const {
  double sumatorio{0.0};
  for (const auto& valor: valores_) {
    sumatorio += valor * valor;
  }
  return std::sqrt(sumatorio);
}

/** Sobrecarga de la suma de vectores
 * @param primero Sumando izquierdo
 * @param segundo Sumando derecho
 * @return Vector suma
 */
Vector operator+(const Vector& primero, const Vector& segundo) {
  Vector suma{};
  for (int i{0}; i < kLongitudVector; ++i) {
    suma.Set(i, primero.Get(i) + segundo.Get(i));
  }
  return suma;
}

/** Sobrecarga del producto escalar
 * @param primero Factor izquierdo
 * @param segundo Factor derecho
 * @return Producto escalar
 */
double operator*(const Vector& primero, const Vector& segundo) {
  double sumatorio{0.0};
  for (int i{0}; i < kLongitudVector; ++i) {
    sumatorio += primero.Get(i) * segundo.Get(i);
  }
  return sumatorio;
}

/// Sobrecarga del operador de inserción en el flujo de salida para vectores
std::ostream& operator<<(std::ostream& salida, const Vector& vector) {
  salida << '(' << vector.Get(0) << ", " << vector.Get(1)
         << ", " << vector.Get(2) << ')';
  return salida;
}

/// Sobrecarga del operador de extracción del flujo de entrada para vectores
std::istream& operator>>(std::istream& entrada, Vector& vector) {
  char auxiliar{0};
  double componente_0{0.0}, componente_1{0.0}, componente_2{0.0};
  entrada >> auxiliar >> componente_0 >> auxiliar >> componente_1
          >> auxiliar >> componente_2 >> auxiliar;
  vector.Set(0, componente_0);
  vector.Set(1, componente_1);
  vector.Set(2, componente_2);
  return entrada;
}
