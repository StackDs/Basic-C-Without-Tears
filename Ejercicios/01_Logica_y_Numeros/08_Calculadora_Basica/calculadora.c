
#include <stdio.h>

int main(void) {
  double a, b;
  char op;

  // Leer la expresion con formato: A OP B
  if (scanf("%lf %c %lf", &a, &op, &b) == 3) {
    switch (op) {
    case '+':
      printf("%.2f\n", a + b);
      break;
    case '-':
      printf("%.2f\n", a - b);
      break;
    case '*':
      printf("%.2f\n", a * b);
      break;
    case '/':
      // Validar intento de division entre cero
      if (b == 0.0) {
        printf("Error: Division por cero.\n");
      } else {
        printf("%.2f\n", a / b);
      }
      break;
    default:
      // Operador no soportado
      printf("Error: Operador no valido.\n");
      break;
    }
  }

  return 0;
}
