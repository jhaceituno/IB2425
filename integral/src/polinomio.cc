/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 16.dic.2025
 * @brief Implementación de la clase Polinomio
 */

#include <iostream>
#include <vector>
#include <array>
#include <cmath>
#include "polinomio.h"

/// Evaluación del polinomio
double Polinomio::Evaluar(double valor) const {
  double resultado{0.0};
  for (int i{grado_}; i >= 0; --i) {
    resultado = resultado * valor + coeficientes_[i];
  }
  return resultado;
}

/// Cálculo de la integral del polinomio
Polinomio Polinomio::Integral(double termino_independiente) const {
  Polinomio integral{*this};
  ++integral.grado_;
  auto principio{integral.coeficientes_.begin()};
  integral.coeficientes_.insert(principio, termino_independiente);
  for (int i{1}; i <= integral.grado_; ++i) {
    integral.coeficientes_[i] /= i; 
  }
  return integral;
}

/** Cálculo de la integral definida del polinomio
 * @param comienzo Comienzo del intervalo de definición
 * @param fin Fin del intervalo de definición
 * @param precision Precisión del método de Runge-Kutta
 * @return Resultado del cálculo
 */
double Polinomio::Integral(double comienzo, double fin,
                           double precision) const {
  if (comienzo > fin || precision <= 0.0) {
    std::cerr << "Datos incorrectos para Runge-Kutta.\n";
    return 0.0; 
  }
  long double integral{0.5 * (Evaluar(comienzo) + Evaluar(fin))};
  for (double x{comienzo + precision}; x < fin; x += precision) {
    integral += Evaluar(x);
  }
  return precision * integral;
}

/// Sobrecarga del operador de extracción del flujo de entrada para polinomios
std::istream& operator>>(std::istream& entrada, Polinomio& polinomio) {
  entrada >> polinomio.grado_;
  polinomio.coeficientes_.resize(polinomio.grado_ + 1);
  for (auto& coeficiente: polinomio.coeficientes_) {
    entrada >> coeficiente;
  }
  return entrada;
}

/// Caracteres Unicode para representar exponentes
const std::array<std::string, 10> kExponentes {
  "\xe2\x81\xb0", "\xc2\xb9", "\xc2\xb2", "\xc2\xb3",
  "\xe2\x81\xb4", "\xe2\x81\xb5", "\xe2\x81\xb6",
  "\xe2\x81\xb7", "\xe2\x81\xb8", "\xe2\x81\xb9"
};

/// Función auxiliar para convertir un número a superíndices
std::string Superindice(int exponente) {
  if (exponente < 10) {  // Un solo dígito
    return kExponentes[exponente];
  }
  std::string superindice{""};
  while (exponente > 0) {  // Concatenación de dígitos
    superindice = kExponentes[exponente % 10] + superindice;
    exponente /= 10;
  }
  return superindice;
}

constexpr double kEpsilon{1e-4};

/** Inserción en el flujo de salida de un solo término del polinomio
 * @param salida Flujo de salida
 * @param indice Índice del término a mostrar
 * @param con_signo Verdadero si debe mostrarse el signo por separado
 * @return Falso si el término era nulo
 */
bool Polinomio::MostrarTermino(std::ostream& salida,
                               int indice, bool signo_separado) const {
  if (fabs(coeficientes_[indice]) < kEpsilon) {
    return false;  // Término nulo
  }
  if (indice == 0) {  // Término independiente
    salida << coeficientes_[indice];
    return true;
  }
  if (signo_separado) {  // Mostrar el signo
    salida << (coeficientes_[indice] < 0.0 ? " - " : " + ");
  } else if (coeficientes_[indice] < 0.0) {
    salida << '-';
  }
  double valor_absoluto{fabs(coeficientes_[indice])};
  if (fabs(valor_absoluto - 1.0) > kEpsilon) {  // Si el coeficiente no es 1
    salida << valor_absoluto;
  }
  salida << 'x';
  if (indice > 1) {
    salida << Superindice(indice);
  }
  return true;  // Término no nulo
}

/// Sobrecarga del operador de inserción en el flujo de salida para polinomios
std::ostream& operator<<(std::ostream& salida, const Polinomio& polinomio) {
  bool escribir_signo{false};
  for (int i{0}; i <= polinomio.grado_; ++i) {
    escribir_signo |= polinomio.MostrarTermino(salida, i, escribir_signo);
    // Se separan los signos desde que se detecte un término no nulo
  }
  return salida;
}
