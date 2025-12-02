/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 02.dic.2025
 * @brief Cabecera de la clase Reina
 */

#ifndef REINA_H
#define REINA_H

#include <iostream>
#include "corona.h"

/// Clase de representación de reinas
class Reina {
 public:
  Reina(const std::string& nombre, const std::string& corona);
  const std::string& nombre() const { return nombre_; }
  const Corona& corona() const { return corona_; }
 private:
  std::string nombre_;
  Corona corona_;
};

std::ostream& operator<<(std::ostream& salida, const Reina& reina);

#endif

