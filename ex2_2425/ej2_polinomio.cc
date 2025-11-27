/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 24.nov.2024
 * @brief Implementación de la evaluación de polinomios
 */

#include <iostream>
#include <vector>

/** Cálculo de una potencia de exponente entero positivo
 * @param base Base de la potencia
 * @param exponente Exponente de la potencia
 * @return Resultado de la potencia
 */
double Potencia(double base, int exponente) {
  double producto{1.0};
  for (int i{0}; i < exponente; ++i) {
    producto *= base;
  }
  return producto;
}

/** Búsqueda de la posición de la primera o última vocal
 * @param cadena Cadena de caracteres para la búsqueda
 * @param ultima Verdadero si se desea la última vocal
 * @return Posición de la vocal, -1 si no hay ninguna
 */
double EvaluarPolinomio(const std::vector<double>& coeficientes, double valor) {
  double resultado{0.0};
  for (int i{0}; i < coeficientes.size(); ++i) {
    resultado += coeficientes[i] * Potencia(valor, i);
  }
  return resultado;
}

int main(int argc, char** argv) {
  if (argc == 1) {
    std::cerr << argv[0] << " {coeficientes}\n";
    return 1;
  }
  std::vector<double> coeficientes(argc - 1);
  for (int i{1}; i < argc; ++i) {
    coeficientes[i - 1] = atof(argv[i]);
  }
  double valor{0};
  std::cout << "Valor de evaluación: ";
  std::cin >> valor;
  std::cout << "f(" << valor << ") = "
            << EvaluarPolinomio(coeficientes, valor) << std::endl;
  return 0;
}
