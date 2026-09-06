
#include <stdio.h>

// Calcula base^exponente de forma iterativa
long long elevar(int base, int exponente) {
  long long resultado = 1;
  for (int i = 0; i < exponente; i++) {
    resultado *= base;
  }
  return resultado;
}

// Cuenta la cantidad de digitos que componen el numero
int contar_digitos(int num) {
  if (num == 0) {
    return 1;
  }
  int digitos = 0;
  while (num > 0) {
    digitos++;
    num /= 10;
  }
  return digitos;
}

// Verifica si un numero cumple la condicion de narcisista
int es_narcisista(int num) {
  if (num < 0) {
    return 0;
  }
  if (num == 0) {
    return 1;
  }

  int num_digitos = contar_digitos(num);
  long long suma = 0;
  int temp = num;

  // Elevar cada digito a la cantidad total de digitos y sumar
  while (temp > 0) {
    int digito = temp % 10;
    suma += elevar(digito, num_digitos);
    temp /= 10;
  }

  return (suma == num);
}

int main(void) {
  int num;

  // Leer el numero a evaluar
  if (scanf("%d", &num) == 1) {
    if (es_narcisista(num)) {
      printf("%d es un numero narcisista.\n", num);
    } else {
      printf("%d no es un numero narcisista.\n", num);
    }
  }

  return 0;
}
