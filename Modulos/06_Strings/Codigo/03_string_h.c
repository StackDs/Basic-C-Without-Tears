/**
   ######################################################
   ##                                                  ##
   ##       Manipulacion de Bloques: <string.h>        ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <string.h>

int main(void) {
  printf("\n=== 3. Manipulacion de Bloques: <string.h> ===\n");
  char origen[] = "Secreto super clasificado";
  char destino[20];

  printf("-- Copiar (strcpy vs strncpy) --\n");
  // strcpy(destino, origen); // ERROR: Destino (20) es menor que origen (26)
  strncpy(destino, origen, 19);
  // Si la cadena origen es igual o más larga que n (19 chars),
  // strncpy NO añade el carácter nulo '\0' al final. Debemos colocarlo
  // manualmente. En Python harías simplemente destino = origen[:19], pero en C
  // requiere cuidado explícito.
  destino[19] = '\0';
  printf("Copia segura (max 19 chars): %s\n", destino);

  printf("\n-- Medir (strlen) --\n");
  printf("Longitud real de '%s': %lu caracteres (sin contar el nulo)\n",
         destino, (unsigned long)strlen(destino));
  printf("Tamano de memoria reservado: %lu bytes\n",
         (unsigned long)sizeof(destino));

  printf("\n-- Comparar (strcmp vs strncmp) --\n");
  if (strcmp("Apple", "Apple") == 0) {
    printf("'Apple' y 'Apple' son exactamente iguales.\n");
  }

  // Comparamos solo las primeras 4 letras para buscar el prefijo
  if (strncmp("Automovil", "Autobus", 4) == 0) {
    printf("'Automovil' y 'Autobus' tienen los mismos primeros 4 caracteres "
           "('Auto').\n");
  }

  printf("\n-- Concatenar (strcat vs strncat) --\n");
  char saludo_completo[30] = "Hola, ";
  char nombre_concatenar[] = "Mundo cruel";

  // Concatenamos solo "Mundo" para evitar textos demasiado largos
  strncat(saludo_completo, nombre_concatenar, 5);
  printf("Concatenacion parcial (max 5 letras): %s\n", saludo_completo);

  printf("\n-- Buscar (strchr y strcspn) --\n");
  char correo[] = "tudireccion@gmail.com";
  char *arroba = strchr(correo, '@');
  if (arroba != NULL) {
    printf("Arroba encontrada en el correo: %s\n", correo);
    printf("Texto a partir del arroba: %s\n", arroba);
  }

  // Simulacion de la limpieza del salto de linea de fgets
  char input_usuario[] = "Texto con enter\n";
  printf("Texto original tiene '\\n' en el indice: %lu\n",
         (unsigned long)strcspn(input_usuario, "\n"));

  // Reemplazamos el salto de linea con el caracter nulo
  input_usuario[strcspn(input_usuario, "\n")] = '\0';
  printf("Despues de limpiar con strcspn, nueva longitud es: %lu\n",
         (unsigned long)strlen(input_usuario));

  return 0;
}
