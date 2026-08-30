/**
   ######################################################
   ##                                                  ##
   ##        Input, Output y el caos del Buffer        ## 
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <string.h> // Necesario para strcspn()

int main(void) {
  printf("=== Salida de Datos (Output) ===\n");

  /** Uso basico y secuencias de escape:
   * La funcion printf permite imprimir texto formateado.
   * - \n: Salto de linea
   * - \t: Tabulador
   * - \\: Barra invertida
   * - \": Comillas dobles
   **/
  printf("\n--- Uso basico ---\n");
  printf("Hola Mundo\n");
  printf("Me llamo \"C\" y uso una barra \\.\n");
  printf("Esto usa\tun\ttabulador.\n");

  /** Especificadores de formato:
   * %d o %i para enteros (int, short)
   * %u para enteros sin signo (unsigned int)
   * %ld / %lld para enteros largos (long, long long)
   * %f para flotantes (float)
   * %lf para flotantes de doble precision (double)
   * %Lf para flotantes de precision extendida (long double)
   * %c para caracteres
   * %s para strings
   **/
  printf("\n--- Especificadores de formato ---\n");
  int edad = 25;
  float peso = 70.5;
  char inicial = 'J';
  char nombre_corto[] = "Juan";
  printf("Tengo %d anios, peso %f kg. Inicial: %c, Nombre: %s\n", edad, peso, inicial, nombre_corto);

  /** Formateo de precision y alineacion:
   * Podemos controlar los decimales (%.2f), el relleno (%04d) 
   * y la alineacion izquierda o derecha (%-10s).
   **/
  printf("\n--- Formateo y precision ---\n");
  printf("Precio (2 decimales): $%.2f\n", 19.999);
  printf("ID con relleno: [%04d]\n", 7);
  printf("Alineado a la izquierda: [%-10s] <- fin\n", "C");

  /** Impresion de numeros en otras bases:
   * %x / %X para Hexadecimal
   * %o para Octal
   **/
  printf("\n--- Bases numericas ---\n");
  int numero = 255;
  printf("Decimal: %d, Hexadecimal: %X, Octal: %o\n", numero, numero, numero);

  /** Alternativas simples a printf:
   * puts() imprime una cadena y agrega salto de linea automaticamente.
   * putchar() imprime un solo caracter en pantalla.
   **/
  printf("\n--- puts() y putchar() ---\n");
  puts("Man you got a light?");
  putchar('A');
  putchar('\n');


  /**
     ############################################
     ##                                        ##
     ##      Entrada basica de datos (Input)   ##  
     ##                                        ##
     ############################################
  **/
  
  printf("\n\n=== Entrada basica de datos (Input) ===\n");

  /** scanf y el operador & (Ampersand):
   * scanf necesita la direccion de memoria donde guardar el valor.
   * Por eso usamos & antes del nombre de la variable (excepto en strings).
   * Ademas, scanf retorna cuantos valores leyo correctamente.
   **/
  int edad_input;
  float altura_input;
  float peso_input;
  
  printf("Ingresa tu edad (entero): ");
  if (scanf("%d", &edad_input) != 1) {
      fprintf(stderr, "Error fatal: No se ingreso un numero valido para la edad.\n");
      return 1;
  }

  printf("Ingresa tu altura y tu peso separados por espacio (ej. 1.75 70.5): ");
  if (scanf("%f %f", &altura_input, &peso_input) != 2) {
      fprintf(stderr, "Error fatal: No se ingresaron dos numeros validos.\n");
      return 1;
  }

  printf("Datos leidos: Edad = %d, Altura = %.2f, Peso = %.2f\n", edad_input, altura_input, peso_input);


  /**
     ############################################
     ##                                        ##
     ##      Gestion del buffer de entrada     ##  
     ##                                        ##
     ############################################
  **/

  printf("\n\n=== Gestion del Buffer de Entrada ===\n");

  /** El problema del \n residual:
   * Al usar scanf para numeros, el ENTER (\n) presionado queda en el buffer.
   * Si intentamos leer un char ahora, leera ese \n.
   * Solucion: Limpiar el buffer manualmente con un bucle getchar.
   **/
  int c;
  // Limpiando el buffer
  while ((c = getchar()) != '\n' && c != EOF); 
  
  char una_letra;
  printf("Ingresa una letra favorita: ");
  scanf("%c", &una_letra); 
  printf("Letra leida correctamente: %c\n", una_letra);

  // Limpiamos el buffer de nuevo tras leer el char por el ENTER presionado
  while ((c = getchar()) != '\n' && c != EOF);


  /**
     ###########################################################
     ##                                                       ##
     ##          Captura de Cadenas con Espacios              ##
     ##                                                       ##
     ###########################################################
  **/

  printf("\n\n=== Captura de Cadenas con Espacios ===\n");

  /** El problema de scanf con strings:
   * scanf se detiene al leer un espacio en blanco.
   * Para leer lineas enteras de forma segura, usamos fgets.
   **/
  char nombre_completo[50];
  
  printf("Ingresa tu nombre completo y apellidos (se aceptan espacios): ");
  fgets(nombre_completo, sizeof(nombre_completo), stdin);
  
  // fgets guarda el \n final si cabe, lo eliminamos con strcspn
  nombre_completo[strcspn(nombre_completo, "\n")] = '\0';
  
  printf("Tu nombre completo procesado por fgets es: %s\n", nombre_completo);


  /**
     ###########################################################
     ##                                                       ##
     ##             Flujos de consola avanzados               ##
     ##                                                       ##
     ###########################################################
  **/

  printf("\n\n=== Flujos de consola avanzados ===\n");

  /** stdin, stdout y stderr:
   * La consola se divide en flujos de datos (archivos virtuales).
   * Podemos usar fprintf para mandar texto especificamente a la salida normal (stdout)
   * o a la salida de errores (stderr).
   **/
  fprintf(stdout, "Esto se imprime con fprintf(stdout). Es identico a printf.\n");
  fprintf(stderr, "[Mensaje de Sistema]: Esto es un mensaje usando fprintf(stderr). Se usa para notificar errores.\n");

  return 0;
}
