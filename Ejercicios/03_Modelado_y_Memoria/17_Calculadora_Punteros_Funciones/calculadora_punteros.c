
#include <stdio.h>

// Definicion de tipo para puntero a funcion aritmetica
typedef double (*Operacion)(double, double);

double sumar(double a, double b) { return a + b; }
double restar(double a, double b) { return a - b; }
double multiplicar(double a, double b) { return a * b; }
double dividir(double a, double b) { return a / b; }

// Funcion evaluadora que ejecuta la operacion recibida por puntero
double evaluar(Operacion op, double a, double b) { return op(a, b); }

int main(void) {
  double a, b;
  char op;

  if (scanf("%lf %c %lf", &a, &op, &b) == 3) {
    Operacion func = NULL;

    switch (op) {
    case '+':
      func = sumar;
      break;
    case '-':
      func = restar;
      break;
    case '*':
      func = multiplicar;
      break;
    case '/':
      if (b == 0.0) {
        printf("Error: Division por cero.\n");
        return 0;
      }
      func = dividir;
      break;
    default:
      printf("Error: Operador no valido.\n");
      return 0;
    }

    if (func != NULL) {
      double res = evaluar(func, a, b);
      printf("Resultado: %.2f\n", res);
    }
  }

  return 0;
}
