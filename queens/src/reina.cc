/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 02.dic.2025
 * @brief Implementación de la clase Reina
 */

#include <iostream>
#include <string>
#include "reina.h"

/** Constructor de la clase Reina
 * @param nombre Nombre de la reina
 * @param corona Material de su corona
 */
Reina::Reina(const std::string& nombre, const std::string& corona)
            : nombre_{nombre}, corona_{corona} {}

/// Sobrecarga del operador de flujo de salida para reinas
std::ostream& operator<<(std::ostream& salida, const Reina& reina) {
  return salida << reina.nombre() << " tiene una " << reina.corona();
}
