/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 17.dic.2024
 * @brief Implementación de la clase Task
 */

#include <iostream>
#include <stdexcept>
#include <sstream>
#include "task.h"

int Task::available_time_{0};  // Definición del atributo estático

/** Constructor de la clase Task
 * @param name Nombre de la tarea
 * @param duration Duración de la tarea en horas
 * @throw overflow_error si se excede el tiempo disponible 
 */
Task::Task(const std::string& name, int duration) :
           name_{name}, duration_{duration} {
  if (duration <= available_time_) {  // Suficiente tiempo disponible
    available_time_ -= duration;
  } else {  // Tiempo agotado, lanzamos una excepción
    std::stringstream auxiliar;
    // La clase Stringstream de la librería <sstream> es útil para crear cadenas
    // de caracteres con formato complejo, simulando un std::ostream ficticio
    auxiliar << "No se pudo instanciar la tarea " << *this << " - tiempo agotado";
    // El método str() devuelve el std::string resultante
    throw std::overflow_error(auxiliar.str());
  }
}

/** Operador de inserción en el flujo de salida
 * @param out Flujo de salida
 * @param task Tarea a mostrar
 * @return Referencia al flujo de salida
 */
std::ostream& operator<<(std::ostream& out, const Task& task) {
  return out << task.name_ << " (" << task.duration_ << 'h)';
}

/** Función que lee tareas desde el flujo de entrada y las instancia */
void InstanceTasks() {
  int time{0};
  std::cin >> time;
  Task::setAvailableTime(time);
  // Como sabemos que se pueden generar excepciones, nos preparamos
  // para capturarlas con un bloque try/catch:
  try {
    std::string name{""};
    int duration{0};
    while (std::cin >> name >> duration) {
      Task task{name, duration};
      std::cout << "Instanciando tarea " << task << " - "
                << Task::available_time() << " horas disponibles" << std::endl;
    }
  } catch (const std::overflow_error& error) {
    // Mostrar el contenido de la excepción capturada:
    std::cerr << error.what() << std::endl;
  }
}