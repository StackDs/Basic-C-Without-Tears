#include <stdio.h>

int main(void) {
  char nombre_archivo[128];

  // Leer el nombre del archivo a abrir
  if (scanf("%127s", nombre_archivo) == 1) {
    // Abrir el archivo en modo lectura ("r")
    FILE *fp = fopen(nombre_archivo, "r");
    if (fp == NULL) {
      printf("Error: No se pudo abrir el archivo.\n");
      return 0;
    }

    // Leer caracter por caracter hasta alcanzar el fin de archivo (EOF)
    int c;
    while ((c = fgetc(fp)) != EOF) {
      putchar(c);
    }

    // Cerrar el archivo abierto
    fclose(fp);
  }

  return 0;
}
