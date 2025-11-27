/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Implementación del coeficiente binomial
 */

#include <iostream>
#include <fstream>

/** Función factorial
 * @param valor Valor entero positivo
 * @return Factorial de dicho valor
 */
int Factorial(int valor) {
  int productorio{1};
  for (int i{2}; i <= valor; ++i) {
    productorio *= i;
  }
  return productorio;
}

/** Cálculo del coeficiente binomial
 * @param valor_n Cardinal del conjunto de valores a escoger
 * @param valor_k Número de elementos a escoger de dicho conjunto
 * @return Número de posibles selecciones sin repetición
 */
int CoeficienteBinomial(int valor_n, int valor_k) {
  if (valor_n < valor_k) {
    return 0;
  } else if (valor_k <= 0) {
    return 1;
  } else {
    return Factorial(valor_n)
         / (Factorial(valor_k) * Factorial(valor_n - valor_k));
  }
}

int main(int argc, char** argv) {
  if (argc != 4) {
    std::cerr << argv[0] << " <fichero> <n> <k>\n";
    return 1;
  }
  std::ofstream fichero{argv[1], std::ios::app};
  if (!fichero) {
    std::cerr << "No se pudo abrir el fichero " << argv[1] << std::endl;
    return 2;
  }
  fichero << CoeficienteBinomial(atoi(argv[2]), atoi(argv[3]));
  return 0;
}
