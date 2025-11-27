/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Implementación de la clase Rey
 */

#include <iostream>
#include "ej3_rey.h"

/// Cálculo de la duración del reinado de un rey
int Rey::DuracionReinado() const { return fin_reinado_ - comienzo_reinado_; }

/** Operador de comparación de reyes
 * @param primero Operando izquierdo
 * @param segundo Operando derecho
 * @return Verdadero si el primer rey gobernó antes que el segundo
 */
bool operator<(const Rey& primero, const Rey& segundo) {
  return primero.comienzo_reinado() < segundo.comienzo_reinado();
}

/// Sobrecarga de la inserción en el flujo de salida para reyes
std::ostream& operator<<(std::ostream& salida, const Rey& rey) {
  salida << rey.nombre() << ' '
         << rey.comienzo_reinado() << ' ' << rey.fin_reinado();
  return salida;
}

/// Sobrecarga de la extracción del flujo de entrada para reyes
std::istream& operator>>(std::istream& entrada, Rey& rey) {
  std::string nombre{""};
  int comienzo{0}, fin{0};
  entrada >> nombre >> comienzo >> fin;
  rey.nombre(nombre);
  rey.comienzo_reinado(comienzo);
  rey.fin_reinado(fin);
  return entrada;
}
