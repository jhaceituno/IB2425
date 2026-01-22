/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 13.dic.2025
 * @brief Cálculo del máximo común divisor
 */

/* Rúbrica de evaluación .... 3 ptos
-------------------------------------
Paso de parámetros ........ 0.5 ptos
Implem. y llamada a Swap .. 0.5 ptos
Bucle y cálculo de MCD .... 0.5 ptos
Uso de línea de comandos .. 0.5 ptos
Llamada a MCD en bucle .... 0.5 ptos
Doxygen y guía de estilo .. 0.5 ptos
---------------------------------- */

#include <iostream>

/** Intercambio de dos valores enteros
 * @param primero Primer valor
 * @param segundo Segundo valor
 */
void Intercambio(int& primero, int& segundo) {
  int auxiliar{primero};
  primero = segundo;
  segundo = auxiliar;
}

/** Cálculo del máximo común divisor de dos valores naturales
 * @param mayor Primer valor
 * @param menor Segundo valor
 * @return Resultado del cálculo
 */
int MaximoComunDivisor(int mayor, int menor) {
  if (mayor < menor) {
    Intercambio(menor, mayor);
  }
  while (menor != 0) {
    int resto{mayor % menor};
    mayor = menor;
    menor = resto;
  }
  return mayor;
}

int main(int argc, char** argv) {
  if (argc < 3) {
    std::cerr << "Se esperaban al menos dos números naturales\n";
    return 1;
  }
  int mcd_actual{atoi(argv[1])};
  for (int i{2}; i < argc; ++i) {
    int siguiente_valor{atoi(argv[i])};
    if (siguiente_valor < 1) {
      std::cerr << siguiente_valor << " no es un número natural\n";
      return 2;
    }
    mcd_actual = MaximoComunDivisor(mcd_actual, siguiente_valor);
  }
  std::cout << "MCD: " << mcd_actual << std::endl;
  return 0;
}
