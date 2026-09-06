#include <stdio.h>
#include <string.h>

int main(void) {
  char mensaje[256];

  // Leer la linea de texto desde la entrada estandar
  if (fgets(mensaje, sizeof(mensaje), stdin) != NULL) {
    // Remover el salto de linea final si esta presente
    size_t len = strlen(mensaje);
    if (len > 0 && mensaje[len - 1] == '\n') {
      mensaje[len - 1] = '\0';
    }

    // Abrir o crear el archivo saludo.txt en modo escritura ("w")
    FILE *archivo = fopen("saludo.txt", "w");
    if (archivo == NULL) {
      return 1;
    }

    // Escribir el mensaje en el archivo
    fprintf(archivo, "%s\n", mensaje);

    // Cerrar el archivo para asegurar el vaciado del buffer a disco
    fclose(archivo);

    // Confirmar en consola la creacion exitosa
    printf("Archivo saludo.txt creado exitosamente.\n");
  }

  return 0;
}
