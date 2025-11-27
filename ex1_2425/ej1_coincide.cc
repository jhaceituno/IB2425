/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Implementación de la función Coincide
 */

#include <iostream>
#include <fstream>

/** Contar las letras comunes de dos cadenas
 * @param primera Cadena de caracteres
 * @param segunda Cadena de caracteres
 * @return Número de letras comunes
 */
int Coincide(const std::string& primera, const std::string& segunda) {
  size_t longitud{std::min(primera.length(), segunda.length())};
  int contador{0};
  for (int i{0}; i < longitud; ++i) {
    if (primera[i] == segunda[i]) {
      ++contador;
    }
  }
  return contador;
}

// No es necesario implementar la función main para este ejercicio
int main(int argc, char** argv) {
  if (argc != 3) {
    std::cerr << argv[0] << " <palabra1> <palabra2>\n";
    return 1;
  }
  std::cout << Coincide(argv[1], argv[2]) << std::endl;
  return 0;
}
