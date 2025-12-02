/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 02.dic.2025
 * @brief Implementación de la clase Corona
 */

#include "corona.h"

/// Sobrecarga del operador de flujo de salida para coronas
std::ostream& operator<<(std::ostream& salida, const Corona& corona) {
  return salida << "corona de " << corona.material_;
}
