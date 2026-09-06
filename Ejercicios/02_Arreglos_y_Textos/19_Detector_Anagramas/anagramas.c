
#include <ctype.h>
#include <stdio.h>
#include <string.h>

int son_anagramas(const char *w1, const char *w2) {
  int frecuencias[26] = {0};

  // Incrementar frecuencias para la primera palabra
  for (int i = 0; w1[i] != '\0'; i++) {
    if (isalpha((unsigned char)w1[i])) {
      int idx = tolower((unsigned char)w1[i]) - 'a';
      frecuencias[idx]++;
    }
  }

  // Decrementar frecuencias para la segunda palabra
  for (int i = 0; w2[i] != '\0'; i++) {
    if (isalpha((unsigned char)w2[i])) {
      int idx = tolower((unsigned char)w2[i]) - 'a';
      frecuencias[idx]--;
    }
  }

  // Si todas las posiciones quedan en 0, son anagramas
  for (int i = 0; i < 26; i++) {
    if (frecuencias[i] != 0) {
      return 0;
    }
  }
  return 1;
}

int main(void) {
  char p1[128];
  char p2[128];

  // Leer ambas palabras
  if (scanf("%127s %127s", p1, p2) == 2) {
    if (son_anagramas(p1, p2)) {
      printf("Son anagramas.\n");
    } else {
      printf("No son anagramas.\n");
    }
  }

  return 0;
}
