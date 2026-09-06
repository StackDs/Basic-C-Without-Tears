
#include <stdio.h>

int main(void) {
  int secreto;

  // Leer el numero secreto fijado para la partida
  if (scanf("%d", &secreto) == 1) {
    int intento;
    int conteo = 0;

    // Leer intentos sucesivos hasta acertar
    while (scanf("%d", &intento) == 1) {
      conteo++;
      if (intento < secreto) {
        printf("Mas alto\n");
      } else if (intento > secreto) {
        printf("Mas bajo\n");
      } else {
        printf("Correcto en %d intentos.\n", conteo);
        break;
      }
    }
  }

  return 0;
}
