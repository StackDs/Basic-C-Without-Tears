#include <stdio.h>
#include <string.h>

// Anexa una linea de texto al final del archivo de bitacora en modo "a"
int anexar_log(const char *archivo_log, const char *mensaje) {
  FILE *fp = fopen(archivo_log, "a");
  if (fp == NULL) {
    return 0;
  }
  // Escribir mensaje asegurando salto de linea
  fprintf(fp, "%s\n", mensaje);
  fclose(fp);
  return 1;
}

int main(void) {
  char nombre_archivo[128];
  int n;

  // Leer nombre del archivo de log y cantidad de mensajes
  if (scanf("%127s %d", nombre_archivo, &n) == 2 && n >= 1) {
    // Limpiar el salto de linea restante en el buffer de entrada
    int c;
    while ((c = getchar()) != '\n' && c != EOF);

    char mensaje[256];
    int guardados = 0;

    // Leer cada linea de mensaje y agregarla al log
    for (int i = 0; i < n; i++) {
      if (fgets(mensaje, sizeof(mensaje), stdin) != NULL) {
        size_t len = strlen(mensaje);
        if (len > 0 && mensaje[len - 1] == '\n') {
          mensaje[len - 1] = '\0';
        }
        if (anexar_log(nombre_archivo, mensaje)) {
          guardados++;
        }
      }
    }

    printf("Se anexaron %d mensajes al archivo %s.\n", guardados, nombre_archivo);
  }

  return 0;
}
