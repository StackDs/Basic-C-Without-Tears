

#include <ctype.h>
#include <stdio.h>
#include <string.h>

int main(void) {
  char palabra[64];
  int vidas;

  // Leer la palabra secreta y la cantidad de vidas iniciales
  if (scanf("%63s %d", palabra, &vidas) == 2 && vidas >= 1) {
    int len = (int)strlen(palabra);
    int revelado[64] = {0};
    int letras_restantes = len;

    char intento;
    while (vidas > 0 && letras_restantes > 0 && scanf(" %c", &intento) == 1) {
      intento = (char)toupper((unsigned char)intento);
      int acierto = 0;

      // Comprobar apariciones de la letra intentada
      for (int i = 0; i < len; i++) {
        if (palabra[i] == intento && !revelado[i]) {
          revelado[i] = 1;
          letras_restantes--;
          acierto = 1;
        } else if (palabra[i] == intento && revelado[i]) {
          acierto = 1;
        }
      }

      if (!acierto) {
        vidas--;
      }

      // Imprimir estado actual de la palabra
      for (int i = 0; i < len; i++) {
        if (i > 0) {
          printf(" ");
        }
        if (revelado[i]) {
          printf("%c", palabra[i]);
        } else {
          printf("_");
        }
      }
      printf(" (Vidas: %d)\n", vidas);
    }

    // Imprimir desenlace de la partida
    if (letras_restantes == 0) {
      printf("Victoria: %s\n", palabra);
    } else {
      printf("Derrota: %s\n", palabra);
    }
  }

  return 0;
}
