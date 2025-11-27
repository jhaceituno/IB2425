/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Implementación de la función PosicionVocal
 */

#include <iostream>

/** Comprobación de si una letra es una vocal minúscula 
 * @param letra Carácter a comprobar
 * @return Verdadero si es una vocal minúscula
 */
bool EsVocalMinuscula(char letra) {
  return letra == 'a' || letra == 'e' || letra == 'i'
      || letra == 'o' || letra == 'u';
}

/** Búsqueda de la posición de la primera o última vocal
 * @param cadena Cadena de caracteres para la búsqueda
 * @param ultima Verdadero si se desea la última vocal
 * @return Posición de la vocal, -1 si no hay ninguna
 */
int PosicionVocal(const std::string& cadena, bool ultima = false) {
  if (ultima) {
    for (size_t i{cadena.length() - 1}; i >= 0; --i) {
      if (EsVocalMinuscula(cadena[i])) {
        return i;
      }
    }
  } else {
    for (size_t i{0}; i < cadena.length(); ++i) {
      if (EsVocalMinuscula(cadena[i])) {
        return i;
      }
    }
  }
  return -1;
}

// No es necesario implementar la función main para este ejercicio
int main() {
  const std::string palabra_con_vocales{"Informatica"},
                    palabra_sin_vocales{"Mr.Myxlplyx"};
  std::cout << palabra_con_vocales << ": "
            << PosicionVocal(palabra_con_vocales) << ' '
            << PosicionVocal(palabra_con_vocales, true) << ' '
            << PosicionVocal(palabra_sin_vocales) << std::endl;
  return 0;
}
