/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Cabecera de la clase Rey
 */

#ifndef REY_H
#define REY_H

#include <iostream>

class Rey {
 public:
  Rey() = default;
  // Getters
  std::string nombre() const { return nombre_; }
  int comienzo_reinado() const { return comienzo_reinado_; }
  int fin_reinado() const { return fin_reinado_; }
  // Setters
  void nombre(const std::string& nuevo_nombre) { nombre_ = nuevo_nombre; }
  void comienzo_reinado(int comienzo) { comienzo_reinado_ = comienzo; }
  void fin_reinado(int fin) { fin_reinado_ = fin; }
  int DuracionReinado() const;
 private: 
  std::string nombre_;
  int comienzo_reinado_;
  int fin_reinado_;
};

bool operator<(const Rey& primero, const Rey& segundo);
std::ostream& operator<<(std::ostream& salida, const Rey& rey);
std::istream& operator>>(std::istream& entrada, Rey& rey);

#endif
