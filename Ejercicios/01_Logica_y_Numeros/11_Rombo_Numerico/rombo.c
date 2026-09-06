
#include <stdio.h>

// Imprime una fila con el espaciado y la secuencia numerica
// ascendente/descendente
void imprimir_fila(int espacios, int max_num) {
  // Espacios iniciales de centrado
  for (int i = 0; i < espacios; i++) {
    printf(" ");
  }
  // Secuencia ascendente: 1 hasta max_num
  for (int i = 1; i <= max_num; i++) {
    printf("%d", i);
  }
  // Secuencia descendente: max_num - 1 hasta 1
  for (int i = max_num - 1; i >= 1; i--) {
    printf("%d", i);
  }
  printf("\n");
}

int main(void) {
  int n;

  // Leer el valor maximo del rombo
  if (scanf("%d", &n) == 1 && n >= 1) {
    // Parte superior (filas 1 a n)
    for (int i = 1; i <= n; i++) {
      imprimir_fila(n - i, i);
    }
    // Parte inferior (filas n-1 descendiendo a 1)
    for (int i = n - 1; i >= 1; i--) {
      imprimir_fila(n - i, i);
    }
  }

  return 0;
}
