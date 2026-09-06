
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *concatenar_dinamico(const char *s1, const char *s2) {
  size_t len1 = strlen(s1);
  size_t len2 = strlen(s2);

  // Reservar espacio exacto para len1 + len2 + terminador nulo ('\0')
  char *resultado = (char *)malloc(len1 + len2 + 1);
  if (resultado == NULL) {
    return NULL;
  }

  // Copiar primera cadena y anexar la segunda
  strcpy(resultado, s1);
  strcat(resultado, s2);

  return resultado;
}

int main(void) {
  char b1[512], b2[512];

  if (fgets(b1, sizeof(b1), stdin) != NULL &&
      fgets(b2, sizeof(b2), stdin) != NULL) {
    // Remover saltos de linea finales
    size_t l1 = strlen(b1);
    if (l1 > 0 && b1[l1 - 1] == '\n')
      b1[l1 - 1] = '\0';
    size_t l2 = strlen(b2);
    if (l2 > 0 && b2[l2 - 1] == '\n')
      b2[l2 - 1] = '\0';

    char *unido = concatenar_dinamico(b1, b2);
    if (unido != NULL) {
      printf("%s\n", unido);
      free(unido); // Liberar memoria asignada dinamicamente
    }
  }

  return 0;
}
