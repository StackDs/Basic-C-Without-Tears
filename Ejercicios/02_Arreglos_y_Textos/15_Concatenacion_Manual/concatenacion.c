
#include <stdio.h>

void concatenar(char destino[], const char s1[], const char s2[]) {
  int i = 0;
  // Copiar primera cadena
  while (s1[i] != '\0' && s1[i] != '\n') {
    destino[i] = s1[i];
    i++;
  }
  int j = 0;
  // Copiar segunda cadena a continuacion
  while (s2[j] != '\0' && s2[j] != '\n') {
    destino[i] = s2[j];
    i++;
    j++;
  }
  // Asegurar el caracter terminador nulo
  destino[i] = '\0';
}

int main(void) {
  char s1[512];
  char s2[512];
  char resultado[1024];

  if (fgets(s1, sizeof(s1), stdin) != NULL &&
      fgets(s2, sizeof(s2), stdin) != NULL) {
    concatenar(resultado, s1, s2);
    printf("%s\n", resultado);
  }

  return 0;
}
