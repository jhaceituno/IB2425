/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 13.dic.2025
 * @brief Cabecera de la clase Artículo
 */

#ifndef ARTICULO_H
#define ARTICULO_H

#include <iostream>

/// Clase que representa artículos de un supermercado
class Articulo {
 public:
  Articulo() = default;
  Articulo(const std::string& nombre, double precio_unidad = 1.0);
  // Getters
  std::string nombre() const { return nombre_; }
  double precio() const { return precio_; }
  // Setters
  void nombre(const std::string& nuevo_nombre) { nombre_ = nuevo_nombre; }
  void precio(double nuevo_precio) { precio_ = nuevo_precio; }
 private:
  std::string nombre_{""};
  double precio_{0.0};
};

bool operator==(const Articulo& primero, const Articulo& segundo);
std::istream& operator>>(std::istream& entrada, Articulo& articulo);

#endif
