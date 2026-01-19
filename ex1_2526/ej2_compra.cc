/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 13.dic.2025
 * @brief Programa principal de la clase Compra
 */

/* Rúbrica de evaluación ..... 4 ptos
-------------------------------------
.h/.cc guardas inclusión .. 0.25 ptos
Expresión const céntimo ... 0.25 ptos
-------------------------------------
Constructor por defecto ... 0.25 ptos
Lista de inicialización ... 0.25 ptos
Comprobación del precio ... 0.25 ptos
Getters const y setters ... 0.25 ptos
Sobrecarga de igualdad .... 0.25 ptos
Sobrecarga de extracción .. 0.25 ptos
-------------------------------------
Atributo vector de pares .. 0.25 ptos
Agregar art preexistente .. 0.25 ptos
Agregar artículo nuevo .... 0.25 ptos
Cálculo del precio total .. 0.25 ptos
Inserción con formato ..... 0.25 ptos
-------------------------------------
Lectura de fichero ........ 0.25 ptos
Generación y escritura .... 0.25 ptos
Doxygen y guía de estilo .. 0.25 ptos
-----------------------------------*/

#include <iostream>
#include <fstream>
#include <vector>
#include "compra.h"

int main() {
  const std::string kCompra{"compra.txt"};
  const std::string kSalida{"salida.txt"};
  std::ifstream entrada{kCompra};
  std::ofstream salida{kSalida};
  if (!entrada || !salida) {
    std::cerr << "No se pudo abrir alguno de los ficheros.\n";
    return 1;
  }
  Articulo articulo{};
  Compra compra{};
  while (entrada >> articulo) {
    compra.Agregar(articulo);
  }
  salida << compra;
  return 0;
}
