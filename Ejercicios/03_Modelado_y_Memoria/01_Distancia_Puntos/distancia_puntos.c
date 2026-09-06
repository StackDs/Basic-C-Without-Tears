
#include <math.h>
#include <stdio.h>

// Definicion de la estructura para representar un punto en el plano
struct Punto {
  double x;
  double y;
};

// Funcion que calcula la distancia euclidiana entre dos puntos
double calcular_distancia(struct Punto p1, struct Punto p2) {
  double dx = p2.x - p1.x;
  double dy = p2.y - p1.y;
  return sqrt(dx * dx + dy * dy);
}

int main(void) {
  struct Punto p1, p2;

  // Leer coordenadas del primer y segundo punto
  if (scanf("%lf %lf", &p1.x, &p1.y) == 2 &&
      scanf("%lf %lf", &p2.x, &p2.y) == 2) {
    double distancia = calcular_distancia(p1, p2);
    printf("Distancia: %.2f\n", distancia);
  }

  return 0;
}
