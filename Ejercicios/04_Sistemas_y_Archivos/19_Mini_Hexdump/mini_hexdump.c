#include <stdio.h>

int main(void) {
  char nombre_archivo[128];

  // Leer nombre del archivo a inspeccionar
  if (scanf("%127s", nombre_archivo) == 1) {
    // Abrir en modo binario ("rb")
    FILE *fp = fopen(nombre_archivo, "rb");
    if (fp == NULL) {
      printf("Error: No se pudo abrir el archivo.\n");
      return 0;
    }

    int c;
    int primero = 1;

    // Leer byte a byte e imprimir su representacion hexadecimal de 2 digitos
    while ((c = fgetc(fp)) != EOF) {
      if (!primero) {
        printf(" ");
      }
      printf("%02X", (unsigned char)c);
      primero = 0;
    }
    printf("\n");

    // Cerrar el archivo
    fclose(fp);
  }

  return 0;
}
