
#include <stdio.h>
#include <string.h>

void invertir_cadena(char *str) {
  int izq = 0;
  int der = (int)strlen(str) - 1;

  while (izq < der) {
    char temp = str[izq];
    str[izq] = str[der];
    str[der] = temp;
    izq++;
    der--;
  }
}

int main(void) {
  char texto[1024];

  if (fgets(texto, sizeof(texto), stdin) != NULL) {
    // Remover salto de linea al final si existe
    size_t len = strlen(texto);
    if (len > 0 && texto[len - 1] == '\n') {
      texto[len - 1] = '\0';
    }

    invertir_cadena(texto);
    printf("%s\n", texto);
  }

  return 0;
}
