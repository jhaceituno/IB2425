/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 13.dic.2025
 * @brief Cabecera de la clase Compra
 */

#ifndef COMPRA_H
#define COMPRA_H

#include <iostream>
#include <vector>
#include "articulo.h"

/// Clase que representa listas de la compra
class Compra {
 public:
  void Agregar(const Articulo& articulo);
  double Total() const;
  friend std::ostream& operator<<(std::ostream& salida, const Compra& compra);
 private:
  using Par = std::pair<int, Articulo>;
  std::vector<Par> lista_{};
};

#endif
