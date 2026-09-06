
#include <stdio.h>
#include <string.h>

void normalizar_espacios(const char *origen, char *destino) {
  int i = 0;
  int j = 0;
  int len = (int)strlen(origen);

  // Ignorar salto de linea al final
  while (len > 0 && (origen[len - 1] == '\n' || origen[len - 1] == '\r')) {
    len--;
  }

  // Saltar espacios en blanco al inicio
  while (i < len && origen[i] == ' ') {
    i++;
  }

  int en_espacio = 0;
  while (i < len) {
    if (origen[i] == ' ') {
      if (!en_espacio) {
        destino[j++] = ' ';
        en_espacio = 1;
      }
    } else {
      destino[j++] = origen[i];
      en_espacio = 0;
    }
    i++;
  }

  // Si el ultimo caracter anadido fue un espacio, eliminarlo
  if (j > 0 && destino[j - 1] == ' ') {
    j--;
  }

  destino[j] = '\0';
}

int main(void) {
  char entrada[1024];
  char salida[1024];

  if (fgets(entrada, sizeof(entrada), stdin) != NULL) {
    normalizar_espacios(entrada, salida);
    printf("%s\n", salida);
  }

  return 0;
}
