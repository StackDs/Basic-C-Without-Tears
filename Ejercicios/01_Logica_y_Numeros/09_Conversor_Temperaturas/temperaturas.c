
#include <stdio.h>

// Convierte la temperatura dada en su unidad original a grados Celsius
double a_celsius(double temp, char unidad, int *valido) {
  switch (unidad) {
  case 'C':
  case 'c':
    return temp;
  case 'F':
  case 'f':
    return (temp - 32.0) * 5.0 / 9.0;
  case 'K':
  case 'k':
    return temp - 273.15;
  default:
    *valido = 0;
    return 0.0;
  }
}

// Convierte una temperatura en Celsius a la unidad de destino deseada
double desde_celsius(double celsius, char unidad, int *valido) {
  switch (unidad) {
  case 'C':
  case 'c':
    return celsius;
  case 'F':
  case 'f':
    return celsius * 9.0 / 5.0 + 32.0;
  case 'K':
  case 'k':
    return celsius + 273.15;
  default:
    *valido = 0;
    return 0.0;
  }
}

int main(void) {
  double temp;
  char u_orig, u_dest;

  // Leer la temperatura y las unidades de origen y destino
  if (scanf("%lf %c %c", &temp, &u_orig, &u_dest) == 3) {
    int valido = 1;
    double celsius = a_celsius(temp, u_orig, &valido);
    double resultado = desde_celsius(celsius, u_dest, &valido);

    if (!valido) {
      printf("Error: Unidad no valida.\n");
    } else {
      printf("%.2f\n", resultado);
    }
  }

  return 0;
}
