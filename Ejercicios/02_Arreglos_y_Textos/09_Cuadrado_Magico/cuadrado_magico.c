
#include <stdio.h>

int main(void) {
  int m[3][3];

  // Leer la matriz 3x3
  for (int i = 0; i < 3; i++) {
    for (int j = 0; j < 3; j++) {
      if (scanf("%d", &m[i][j]) != 1) {
        return 0;
      }
    }
  }

  // Tomar la suma de la primera fila como referencia
  int suma_ref = m[0][0] + m[0][1] + m[0][2];

  // Comprobar filas 1 y 2
  for (int i = 1; i < 3; i++) {
    if (m[i][0] + m[i][1] + m[i][2] != suma_ref) {
      printf("No es un cuadrado magico.\n");
      return 0;
    }
  }

  // Comprobar columnas
  for (int j = 0; j < 3; j++) {
    if (m[0][j] + m[1][j] + m[2][j] != suma_ref) {
      printf("No es un cuadrado magico.\n");
      return 0;
    }
  }

  // Comprobar diagonal principal
  if (m[0][0] + m[1][1] + m[2][2] != suma_ref) {
    printf("No es un cuadrado magico.\n");
    return 0;
  }

  // Comprobar diagonal secundaria
  if (m[0][2] + m[1][1] + m[2][0] != suma_ref) {
    printf("No es un cuadrado magico.\n");
    return 0;
  }

  printf("Es un cuadrado magico (Suma = %d).\n", suma_ref);
  return 0;
}
