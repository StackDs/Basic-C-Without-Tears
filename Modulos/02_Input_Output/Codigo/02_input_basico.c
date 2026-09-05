/**
   ######################################################
   ##                                                  ##
   ##         Entrada Basica de Datos (Input)          ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

int main(void) {
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

  return 0;
}
