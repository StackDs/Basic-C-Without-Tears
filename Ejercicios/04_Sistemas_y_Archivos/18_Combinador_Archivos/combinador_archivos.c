#include <stdio.h>

// Copia secuencialmente todo el contenido de un flujo a otro
static void copiar_flujo(FILE *origen, FILE *destino) {
  int c;
  while ((c = fgetc(origen)) != EOF) {
    fputc(c, destino);
  }
}

int main(void) {
  char arch1[128], arch2[128], destino[128];

  // Leer nombres de los dos archivos origen y el archivo destino
  if (scanf("%127s %127s %127s", arch1, arch2, destino) == 3) {
    // Abrir ambos archivos de entrada
    FILE *fp1 = fopen(arch1, "r");
    FILE *fp2 = fopen(arch2, "r");

    if (fp1 == NULL || fp2 == NULL) {
      printf("Error: No se pudieron abrir los archivos de origen.\n");
      if (fp1) fclose(fp1);
      if (fp2) fclose(fp2);
      return 0;
    }

    // Abrir archivo destino en modo escritura
    FILE *fp_out = fopen(destino, "w");
    if (fp_out == NULL) {
      printf("Error: No se pudo crear el archivo destino.\n");
      fclose(fp1);
      fclose(fp2);
      return 0;
    }

    // Copiar el contenido del primer archivo y luego el del segundo
    copiar_flujo(fp1, fp_out);
    copiar_flujo(fp2, fp_out);

    // Cerrar todos los flujos abiertos
    fclose(fp1);
    fclose(fp2);
    fclose(fp_out);

    printf("Archivos combinados exitosamente en %s.\n", destino);
  }

  return 0;
}
