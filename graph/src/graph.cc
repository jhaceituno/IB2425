/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 10.dic.2024
 * @brief Implementación de la clase Graph
 */

#include "graph.h"
#include <stdexcept>

/** Operador de inserción en el flujo de salida
 * @param out Flujo de salida
 * @param graph Grafo a mostrar
 * @return Flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const Graph& graph) {
  out << graph.vertices_ << ' ' << graph.edges_.size() << std::endl;
  for (auto edge: graph.edges_) {
    out << edge.first << ' ' << edge.second << std::endl;
  }
  return out;
}

/** Operador de extracción del flujo de entrada
 * @param in Flujo de entrada
 * @param graph Grafo a leer
 * @return Flujo de entrada
 */
std::istream& operator>>(std::istream& in, Graph& graph) {
  int number_of_edges{0};
  in >> graph.vertices_ >> number_of_edges;
  graph.edges_.resize(number_of_edges);
  for (auto& edge: graph.edges_) {
    in >> edge.first >> edge.second;
    if (!in) {
      throw std::length_error("Inconsistent number of edges");
    } else if (edge.first >= graph.vertices_ || edge.second >= graph.vertices_) {
      throw std::out_of_range("Vertex out of range");
    }
  }
  return in;
}
