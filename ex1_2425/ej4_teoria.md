# Examen de Informática Básica, GII-ULL
## Convocatoria de enero, curso 2024/2025
### Ejercicio de teoría

1. Un sistema operativo es un dispositivo que gestiona el acceso de las aplicaciones de usuario a los recursos de un ordenador.
   > **Falso,** un sistema operativo es un *programa,* no un dispositivo.
1. El directorio `/` es la raíz del árbol de directorios en un sistema Linux.
   > **Verdadero.**
1. El comando ls `*[abc]?` muestra la lista de los nombres de todos los ficheros del directorio actual cuya penúltima letra es una `a`, una `b` o una `c`.
   > **Verdadero,** el patrón `*[abc]?` significa "cualquier número de caracteres, seguidos de `a`, `b` o `c`, y después cualquier otro carácter".
1. La etapa de ensamblado (*assembler*) permite generar un programa ejecutable a partir de uno o más códigos objeto.
   > **Falso,** la etapa de ensamblado traduce el código ensamblador a código máquina, la etapa de enlazado genera un programa ejecutable a partir de uno o más códigos objeto.
1. Los enteros, los caracteres y los booleanos son tipos integrales.
   > **Verdadero,** todos ellos se codifican internamente como valores enteros.
1. Se denomina *argumento* al valor que recibe un parámetro al llamar a una función.
   > **Verdadero.**
1. El objeto `std::cout` es una instancia de la clase `std::ofstream`.
   > **Falso,** pertenece a la clase `std::ostream`, no `std::ofstream`.
1. El tipo de retorno del destructor de una clase siempre debe ser `void`.
   > **Falso,** los destructores no tienen ningún tipo de retorno.
1. La sobrecarga del operador de inserción en el flujo de salida se implementa como un método de clase.
   > **Falso,** el operador de inserción en el flujo de salida jamás puede implementarse como un método de clase, ya que su operando izquierdo es de tipo `std::ofstream` y, por tanto, sólo podría ser un método de la clase `std::ofstream`, a la que no tenemos acceso.
1. Una clase hija sólo podrá acceder a los miembros privados de su clase madre si hereda en modo público.
   > **Falso,** los miembros privados de una clase son siempre inaccesibles a sus clases derivadas, independientemente de en qué modo hereden.
1. La capa de interfaz de red del modelo TCP/IP corresponde a la conexión física.
   > **Verdadero.**
1. Las claves foráneas no pueden tener valores nulos ni repetidos.
   > **Falso,** las claves primarias no pueden tener valores nulos ni repetidos, las foráneas sí.