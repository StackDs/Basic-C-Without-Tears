#include <ctype.h>
#include <stdio.h>

int main(void) {
  char nombre_archivo[128];

  // Leer el nombre del archivo
  if (scanf("%127s", nombre_archivo) == 1) {
    // Abrir el archivo en modo lectura
    FILE *fp = fopen(nombre_archivo, "r");
    if (fp == NULL) {
      printf("Error: No se pudo abrir el archivo.\n");
      return 0;
    }

    long lineas = 0;
    long palabras = 0;
    long caracteres = 0;
    int en_palabra = 0;
    int c;

    // Recorrer el archivo contando caracteres, lineas y transiciones de palabras
    while ((c = fgetc(fp)) != EOF) {
      caracteres++;

      // Contar salto de linea
      if (c == '\n') {
        lineas++;
      }

      // Detectar palabras basandose en espacios en blanco
      if (isspace(c)) {
        en_palabra = 0;
      } else if (!en_palabra) {
        en_palabra = 1;
        palabras++;
      }
    }

    // Cerrar el flujo
    fclose(fp);

    // Imprimir el reporte de metricas
    printf("Lineas: %ld | Palabras: %ld | Caracteres: %ld\n", lineas, palabras, caracteres);
  }

  return 0;
}
