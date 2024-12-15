/**
 * Universidad de La Laguna
 * Escuela Superior de Ingeniería y Tecnología
 * Grado en Ingeniería Informática
 * Informática Básica
 *
 * @author Javier Hdez. Aceituno
 * @date 17.dic.2024
 * @brief Cabecera de la clase Task
 */

#ifndef TASK_H
#define TASK_H

#include <iostream>

/** Clase de representación de tareas */
class Task {
 public:
  Task(const std::string& name, int duration);
  static void setAvailableTime(int time) { available_time_ = time; }
  static int available_time() { return available_time_; }  // Los métodos
  // estáticos nunca pueden ser constantes porque no pertenecen a ningún objeto
  friend std::ostream& operator<<(std::ostream& out, const Task& task);
 private:
  static int available_time_;
  std::string name_;
  int duration_;
};

void InstanceTasks();

#endif

