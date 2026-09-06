#include <ctype.h>
#include <stdio.h>

int main(void) {
  char origen[128], destino[128];

  // Leer nombres de los archivos origen y destino
  if (scanf("%127s %127s", origen, destino) == 2) {
    // Abrir archivo de entrada
    FILE *fp_in = fopen(origen, "r");
    if (fp_in == NULL) {
      printf("Error: No se pudo abrir el archivo de origen.\n");
      return 0;
    }

    // Abrir archivo de salida
    FILE *fp_out = fopen(destino, "w");
    if (fp_out == NULL) {
      printf("Error: No se pudo crear el archivo destino.\n");
      fclose(fp_in);
      return 0;
    }

    int c;
    // Leer cada caracter, convertir a mayuscula y escribir en destino
    while ((c = fgetc(fp_in)) != EOF) {
      fputc(toupper(c), fp_out);
    }

    // Cerrar archivos
    fclose(fp_in);
    fclose(fp_out);

    printf("Conversion completada exitosamente.\n");
  }

  return 0;
}
