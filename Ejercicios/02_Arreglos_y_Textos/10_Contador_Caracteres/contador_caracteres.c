
#include <stdio.h>

int contar_caracteres(const char *str) {
  int len = 0;
  while (str[len] != '\0' && str[len] != '\n') {
    len++;
  }
  return len;
}

int main(void) {
  char texto[1024];

  // Leer la linea de texto desde la entrada estandar
  if (fgets(texto, sizeof(texto), stdin) != NULL) {
    int longitud = contar_caracteres(texto);
    printf("%d\n", longitud);
  }

  return 0;
}
