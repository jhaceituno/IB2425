/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 27.nov.2024
 * @brief Implementación de la ordenación de caracteres
 */

#include <iostream>
#include <string>

/** Comprobación de si una cadena contiene sólo letras
 * @param cadena Cadena de caracteres
 * @return Verdadero si sólo contiene letras
 */
bool SoloLetras(const std::string& cadena) {
  for (char letra: cadena) {
    if (!(letra >= 'A' && letra <= 'Z') && !(letra >= 'a' && letra <= 'z')) {
      return false;
    }
  }
  return true;
}

/** Ordenación alfabética de una cadena
 * @param cadena Cadena de caracteres
 */
void Ordenar(std::string& cadena) {
  if (!SoloLetras(cadena)) {
    return;
  }
  bool cambio{};
  do {
    cambio = false;
    for (int i{1}; i < cadena.length(); ++i) {
      if (cadena[i - 1] > cadena[i]) {
        char intercambio{cadena[i]};
        cadena[i] = cadena[i - 1];
        cadena[i - 1] = intercambio;
        cambio = true;
      }
    }
  } while (cambio);
}

int main(int argc, char** argv) {
  if (argc <= 1) {
    std::cerr << argv[0] << " {cadenas}\n";
    return 1;
  }
  for (int i{1}; i < argc; ++i) {
    std::string cadena{argv[i]};
    Ordenar(cadena);
    std::cout << cadena << std::endl;
  }
  return 0;
}
