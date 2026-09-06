
#include <ctype.h>
#include <stdio.h>

int es_vocal(char c) {
  c = (char)tolower((unsigned char)c);
  return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
}

int main(void) {
  char texto[1024];

  if (fgets(texto, sizeof(texto), stdin) != NULL) {
    int vocales = 0;
    int consonantes = 0;
    int espacios = 0;

    for (int i = 0; texto[i] != '\0' && texto[i] != '\n'; i++) {
      unsigned char c = (unsigned char)texto[i];
      if (c == ' ') {
        espacios++;
      } else if (isalpha(c)) {
        if (es_vocal((char)c)) {
          vocales++;
        } else {
          consonantes++;
        }
      }
    }

    printf("Vocales: %d, Consonantes: %d, Espacios: %d\n", vocales, consonantes,
           espacios);
  }

  return 0;
}
