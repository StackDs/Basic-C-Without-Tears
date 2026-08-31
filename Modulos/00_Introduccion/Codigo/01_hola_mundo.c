/**
   ############################################################
   ##                                                        ##
   ##             Sintaxis y estructura general de C         ##
   ##                                                        ##
   ############################################################
**/

/** 0. Comentarios en C:
 * Como habras notado, aqui no usamos '#' para comentar como en Python.
 * En C tenemos dos formas de documentar nuestro codigo:
 * - Comentarios de linea: Se hacen usando '//' al inicio, sirven para una sola linea.
 * - Comentarios de bloque: Se abren con '/*' y se cierran con '* /'.
 *   Permiten comentar multiples lineas (como este mismo bloque o el titulo de arriba).
**/

/** 1. Directivas generales del preprocesador:
 * En C, las lineas que comienzan con '#' son procesadas por el procesador antes
 * de la compilacion real.
 * '#include' le indica al preprocesador que inserte el contenido de otro archivo.
 * Lo que ustedes conocen como 'import'
 * Aqui incluimos <stdio.h> (Standar Input/Output Header), que contiene la declaracion
 * de funciones estandar de entrada/salida como 'printf'. Sin esta cabecera, el compilador
 * no sabria que argumentos recibe ni que retorna un printf, basicamente sin esta declaracion
 * tu programa no reconoceria las funciones que estas usando, hay muchas aparte de 'stdio'
 * las veremos despues, y tambien podras tus propios headers mas adelante
**/

#include <stdio.h> // <-- Las cabeceras del sistema van entre los simbolos '< >'

/**
 * 2. La funcion Main:
 * Todo programa ejecutable en C debe tener obligatoriamente una funcion llamada 'main'
 * Es el punto de entrada exclusivo: aqui es donde el sistema operativo inicia la ejecucion
 *
 * -'int': Es el tipo de dato que retorna la funcion, a diferencia de python, debes especificar
 * el tipo de dato que devuelve tu funcion
 * -'main: Es el nombre de la funcion y palabra clave reservada
 * -'void': Le dice explicitamente al compilador que esta funcion no espera recibir ningun argumento
 * Un tipo de retorno void, significa que la funcion no devuelve nada.
**/

int main(void){

  /** 3. Bloques de codigo:
   * Las llaves '{' '}' delimitan un bloque de codigo o el cuerpo de la funcion, vienen a reemplazar
   * lo que en python conocias como indentacion, que basicamente era con espacios, bueno ahora es con
   * llaves, acostumbrate
   * Esto significa que tecnicamente podrias escribir un programa entero en una sola linea, si es que
   * esta bien escrita.
  **/

  /** 4. Llamadas a funciones:
   * Invocamos a la funcion de la biblioteca estandar 'printf' pasandole un argumento:
   * una cadena de caracteres constante (string), en C los strings se delimitan por comillas
   * dobles ("....."), mientras que las comillas simples ('.') se reservan para caracteres
   * individuales ('char').
  **/

  printf("Hola mundo\n");

  /** 5. El salto de linea:
   * '\n' es la notacion en C para el caracter de nueva linea
   * en python ustedes usaban un print y automaticamente les generaba un salto de linea
   * en C debes poner dicha notacion al final del string si quieres un salto de linea
   * tenganlo en cuenta si quieren embellecer su salida
  **/

  /** 6. EL punto y coma:
   * En C, el punto y coma ';' es un terminador de sentencias obligatorio
   * Cada instruccion individual debe finalizar con ';', como declarar variables, llamar funciones
   * hacers returns, etc. olvidar ponerlo, que te va a pasar mucho, es un error de compilacion
  **/

  /** 7. Estado de retorno:
   * Dado que el main esta definido para retornar un 'int', debemos finalizar con 'return'
   * por estandar retornar '0' es un indicador que el programa se ejecuto de manera exitosa
   * cualquier otro valor se interpreta como un codigo de error o comportamiento inusual
   * aunque no es necesario ponerlo en este caso, para funciones creadas por ti, no lo olvides
   * ya que puede generar comportamientos inesperados en tu programa
  **/

  return 0;

}
