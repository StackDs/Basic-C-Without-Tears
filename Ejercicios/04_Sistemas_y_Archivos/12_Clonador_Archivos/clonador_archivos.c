#include <stdio.h>

#define BUFFER_SIZE 4096

int main(void) {
  char origen[128], destino[128];

  // Leer los nombres del archivo de origen y destino
  if (scanf("%127s %127s", origen, destino) == 2) {
    // Abrir origen en modo lectura binaria ("rb")
    FILE *fp_in = fopen(origen, "rb");
    if (fp_in == NULL) {
      printf("Error: No se pudo abrir el archivo de origen.\n");
      return 0;
    }

    // Abrir destino en modo escritura binaria ("wb")
    FILE *fp_out = fopen(destino, "wb");
    if (fp_out == NULL) {
      printf("Error: No se pudo crear el archivo destino.\n");
      fclose(fp_in);
      return 0;
    }

    unsigned char buffer[BUFFER_SIZE];
    size_t leidos;
    unsigned long long total_bytes = 0;

    // Transferir datos en bloques de memoria hasta completar el archivo
    while ((leidos = fread(buffer, 1, sizeof(buffer), fp_in)) > 0) {
      fwrite(buffer, 1, leidos, fp_out);
      total_bytes += leidos;
    }

    // Cerrar ambos flujos
    fclose(fp_in);
    fclose(fp_out);

    // Notificar el total de bytes transferidos
    printf("Archivo clonado exitosamente (%llu bytes copiados).\n", total_bytes);
  }

  return 0;
}
