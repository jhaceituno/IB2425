/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 13.dic.2025
 * @brief Implementación de la clase Compra
 */

#include <iostream>
#include <iomanip>
#include <vector>
#include "compra.h"

/** Método que agrega un nuevo artículo a la lista
 * @param articulo Artículo a agregar
 */
void Compra::Agregar(const Articulo& articulo) {
  for (auto& par: lista_) {
    if (par.second == articulo) {
      ++par.first;
      return;
    }
  }
  lista_.emplace_back(Par{1, articulo});
}

/// Cálculo del precio total de la lista
double Compra::Total() const {
  double total{0.0};
  for (const auto& par: lista_) {
    total += par.first * par.second.precio();
  }
  return total;
}

/// Sobrecarga del operador de inserción en el flujo de salida para Compra
std::ostream& operator<<(std::ostream& salida, const Compra& compra) {
  size_t longitud_nombre{0};
  for (const auto& par: compra.lista_) {
    longitud_nombre = std::max(longitud_nombre, par.second.nombre().length());
  }
  for (const auto& par: compra.lista_) {
    salida << std::setw(longitud_nombre) << par.second.nombre()
           << std::setw(3) << par.first << std::fixed << std::setprecision(2)
           << std::setw(6) << par.second.precio() << std::endl;
  }
  salida << std::fixed << std::setprecision(2)
         << std::setw(longitud_nombre + 9) << compra.Total() << std::endl;
  return salida;
}