
#include <stdio.h>

// Retorna 1 si el anio es bisiesto, 0 en caso contrario
int es_bisiesto(int anio) {
  if ((anio % 4 == 0 && anio % 100 != 0) || (anio % 400 == 0)) {
    return 1;
  }
  return 0;
}

int main(void) {
  int anio;

  // Leer el anio a evaluar
  if (scanf("%d", &anio) == 1 && anio > 0) {
    if (es_bisiesto(anio)) {
      printf("%d es bisiesto.\n", anio);
    } else {
      printf("%d no es bisiesto.\n", anio);
    }
  }

  return 0;
}
