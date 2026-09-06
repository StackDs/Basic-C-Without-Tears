
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int es_palindromo(const char *str) {
  int izq = 0;
  int der = (int)strlen(str) - 1;

  // Ignorar salto de linea al final si existe
  while (der >= 0 && (str[der] == '\n' || str[der] == '\r')) {
    der--;
  }

  while (izq < der) {
    // Saltar caracteres no alfanumericos por la izquierda
    while (izq < der && !isalnum((unsigned char)str[izq])) {
      izq++;
    }
    // Saltar caracteres no alfanumericos por la derecha
    while (izq < der && !isalnum((unsigned char)str[der])) {
      der--;
    }

    // Comparar caracteres normalizados a minusculas
    if (tolower((unsigned char)str[izq]) != tolower((unsigned char)str[der])) {
      return 0;
    }

    izq++;
    der--;
  }

  return 1;
}

int main(void) {
  char texto[1024];

  if (fgets(texto, sizeof(texto), stdin) != NULL) {
    if (es_palindromo(texto)) {
      printf("Es palindromo.\n");
    } else {
      printf("No es palindromo.\n");
    }
  }

  return 0;
}
