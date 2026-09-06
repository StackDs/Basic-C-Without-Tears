
#include <stdio.h>

int main(void) {
  int h, m, s, t;

  // Leer hora, minuto, segundo iniciales y cantidad de segundos a avanzar
  if (scanf("%d %d %d %d", &h, &m, &s, &t) == 4) {
    for (int i = 0; i < t; i++) {
      s++;
      // Acarreo de segundos a minutos
      if (s >= 60) {
        s = 0;
        m++;
        // Acarreo de minutos a horas
        if (m >= 60) {
          m = 0;
          h++;
          // Ciclo de 24 horas
          if (h >= 24) {
            h = 0;
          }
        }
      }
      printf("%02d:%02d:%02d\n", h, m, s);
    }
  }

  return 0;
}
