
#include <stdio.h>
#include <string.h>

void cifrar_cesar(char *str, int k) {
  k = k % 26; // Normalizar el desplazamiento dentro del rango de 26 letras

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= 'a' && str[i] <= 'z') {
      str[i] = (char)('a' + (str[i] - 'a' + k) % 26);
    } else if (str[i] >= 'A' && str[i] <= 'Z') {
      str[i] = (char)('A' + (str[i] - 'A' + k) % 26);
    }
  }
}

int main(void) {
  int k;

  // Leer el desplazamiento K
  if (scanf("%d", &k) == 1 && k >= 0) {
    // Consumir el salto de linea restante
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
      ;

    char texto[1024];
    if (fgets(texto, sizeof(texto), stdin) != NULL) {
      // Remover salto de linea final
      size_t len = strlen(texto);
      if (len > 0 && texto[len - 1] == '\n') {
        texto[len - 1] = '\0';
      }

      cifrar_cesar(texto, k);
      printf("%s\n", texto);
    }
  }

  return 0;
}
