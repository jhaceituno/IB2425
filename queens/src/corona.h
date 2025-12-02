/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 02.dic.2025
 * @brief Cabecera de la clase COrona
 */

#ifndef CORONA_H
#define CORONA_H

#include <iostream>
#include <string>

/// Clase de representación de coronas
class Corona {
 private:
  std::string material_;
  Corona(const std::string& material) : material_{material} {};
  friend std::ostream& operator<<(std::ostream& salida, const Corona& corona);
  friend class Reina;
};

#endif

