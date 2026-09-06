
#include <stdio.h>
#include <string.h>

int main(void) {
  char texto[1024];

  if (fgets(texto, sizeof(texto), stdin) != NULL) {
    // Eliminar salto de linea al final si existe
    size_t total_len = strlen(texto);
    if (total_len > 0 && texto[total_len - 1] == '\n') {
      texto[total_len - 1] = '\0';
    }

    char mejor_palabra[1024] = "";
    int max_len = 0;

    int i = 0;
    while (texto[i] != '\0') {
      // Saltar espacios
      while (texto[i] == ' ') {
        i++;
      }
      if (texto[i] == '\0') {
        break;
      }

      // Extraer palabra actual
      char actual[1024];
      int j = 0;
      while (texto[i] != ' ' && texto[i] != '\0') {
        actual[j++] = texto[i++];
      }
      actual[j] = '\0';

      if (j > max_len) {
        max_len = j;
        strcpy(mejor_palabra, actual);
      }
    }

    printf("Palabra: %s, Longitud: %d\n", mejor_palabra, max_len);
  }

  return 0;
}
