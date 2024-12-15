/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 10.dic.2024
 * @brief Cabecera de la clase Graph
 */

#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

/** Clase de representación de grafos */
class Graph {
 public:
  friend std::ostream& operator<<(std::ostream& out, const Graph& graph);
  friend std::istream& operator>>(std::istream& in, Graph& graph);
 private:
  int vertices_{0};
  std::vector<std::pair<int, int>> edges_{};
};

//std::ostream& operator<<(std::ostream& out, const Graph& graph);
//std::istream& operator>>(std::istream& in, Graph& graph);

#endif

