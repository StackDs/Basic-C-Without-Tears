
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *mi_strdup(const char *origen) {
  if (origen == NULL)
    return NULL;

  // Calcular longitud manualmente
  size_t len = 0;
  while (origen[len] != '\0') {
    len++;
  }

  // Reservar memoria para los caracteres mas el nulo ('\0')
  char *clon = (char *)malloc(len + 1);
  if (clon == NULL)
    return NULL;

  // Copiar caracter a caracter
  for (size_t i = 0; i < len; i++) {
    clon[i] = origen[i];
  }
  clon[len] = '\0';

  return clon;
}

int main(void) {
  char buffer[1024];

  if (fgets(buffer, sizeof(buffer), stdin) != NULL) {
    // Remover salto de linea final
    size_t len = strlen(buffer);
    if (len > 0 && buffer[len - 1] == '\n') {
      buffer[len - 1] = '\0';
    }

    char *copia = mi_strdup(buffer);
    if (copia != NULL) {
      printf("Clon: %s\n", copia);
      if (copia != buffer) {
        printf("Punteros independientes: OK\n");
      }
      free(copia);
    }
  }

  return 0;
}
