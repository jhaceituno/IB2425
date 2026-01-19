/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 13.dic.2025
 * @brief Implementación de la clase Artículo
 */

#include <iostream>
#include "articulo.h"

constexpr double kUnCentimo{0.01};

/** Constructor de la clase Articulo
 * @param nombre Nombre del artículo
 * @param precio Precio del artículo
 */
Articulo::Articulo(const std::string& nombre, double precio)
                  : nombre_{nombre}, precio_{precio} {
  if (precio < kUnCentimo) {
    std::cerr << "Error en el precio de " << nombre << std::endl;
    precio_ = kUnCentimo;
  }
}

/// Sobrecarga del operador de igualdad entre artículos
bool operator==(const Articulo& primero, const Articulo& segundo) {
  return primero.nombre() == segundo.nombre()
      && abs(primero.precio() - segundo.precio()) < kUnCentimo;
}

/// Sobrecarga del operador de extracción del flujo de entrada para Artículo
std::istream& operator>>(std::istream& entrada, Articulo& articulo) {
  std::string nombre{""};
  double precio{0.0};
  entrada >> nombre >> precio;
  articulo.nombre(nombre);
  articulo.precio(precio);
  return entrada;
}
