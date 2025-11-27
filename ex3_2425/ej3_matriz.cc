/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 27.nov.2024
 * @brief Implementación de la clase Matriz
 */

#include <iostream>
#include "ej3_matriz.h"

/** Constructor de la clase Matriz
 * @param elemento_11 Elemento de la fila 1 y la columna 1
 * @param elemento_12 Elemento de la fila 1 y la columna 2
 * @param elemento_21 Elemento de la fila 2 y la columna 1
 * @param elemento_22 Elemento de la fila 2 y la columna 2
 */
Matriz::Matriz(double elemento_11, double elemento_12,
               double elemento_21, double elemento_22)
  : valores_{{{elemento_11, elemento_12}, {elemento_21, elemento_22}}} {}

/** Getter de los elementos de la matriz
 * @param fila Índice de la fila
 * @param columna Índice de la columna
 * @return Valor del elemento de la matriz
 */
double Matriz::Get(int fila, int columna) const {
  return valores_[fila][columna];
}

/** Setter de los elementos de la matriz
 * @param fila Índice de la fila
 * @param columna Índice de la columna
 * @param valor Nuevo valor del elemento de la matriz
 */
void Matriz::Set(int fila, int columna, double valor) {
  valores_[fila][columna] = valor;
}

/// Cálculo del determinante de la matriz
double Matriz::Determinante() const {
  return Get(0, 0) * Get(1, 1) - Get(0, 1) * Get(1, 0);
}

/** Sobrecarga de la suma de matrices
 * @param primera Sumando izquierdo
 * @param segunda Sumando derecho
 * @return Matriz suma
 */
Matriz operator+(const Matriz& primera, const Matriz& segunda) {
  Matriz suma{};
  for (int fila{0}; fila < kLadoMatriz; ++fila) {
    for (int columna{0}; columna < kLadoMatriz; ++columna) {
       suma.Set(fila, columna, primera.Get(fila, columna)
                             + segunda.Get(fila, columna));
    }
  }
  return suma;
}

/** Sobrecarga del producto matricial
 * @param primera Factor izquierdo
 * @param segunda Factor derecho
 * @return Matriz producto
 */
Matriz operator*(const Matriz& primera, const Matriz& segunda) {
  Matriz producto{};
  for (int i{0}; i < kLadoMatriz; ++i) {
    for (int j{0}; j < kLadoMatriz; ++j) {
      double suma{0.0};
      for (int k{0}; k < kLadoMatriz; ++k) {
        suma += primera.Get(i, k) * segunda.Get(k, j);
      }
      producto.Set(i, j, suma);
    }
  }
  return producto;
}

/// Sobrecarga de la inserción en el flujo de salida para matrices
std::ostream& operator<<(std::ostream& salida, const Matriz& matriz) {
  salida << '[' << matriz.Get(0, 0) << ' ' << matriz.Get(0, 1) << "; "
                << matriz.Get(1, 0) << ' ' << matriz.Get(1, 1) << ']';
  return salida;
}

/// Sobrecarga de la extracción del flujo de entrada para matrices
std::istream& operator>>(std::istream& entrada, Matriz& matriz) {
  char auxiliar{0};
  double valor{0.0};
  entrada >> auxiliar;
  for (int i{0}; i < kLadoMatriz; ++i) {
    for (int j{0}; j < kLadoMatriz; ++j) {
      entrada >> valor;
      matriz.Set(i, j, valor);
    }
    entrada >> auxiliar;
  }
  return entrada;
}
