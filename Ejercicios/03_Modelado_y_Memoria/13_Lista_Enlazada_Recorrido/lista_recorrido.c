
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
  long long dato;
  struct Nodo *siguiente;
};

void insertar_final(struct Nodo **cabeza, struct Nodo **ultimo, long long val) {
  struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
  if (nuevo == NULL)
    return;
  nuevo->dato = val;
  nuevo->siguiente = NULL;

  if (*cabeza == NULL) {
    *cabeza = nuevo;
    *ultimo = nuevo;
  } else {
    (*ultimo)->siguiente = nuevo;
    *ultimo = nuevo;
  }
}

void calcular_estadisticas(const struct Nodo *cabeza) {
  int nodos = 0;
  long long suma = 0;
  const struct Nodo *actual = cabeza;

  while (actual != NULL) {
    nodos++;
    suma += actual->dato;
    actual = actual->siguiente;
  }

  double promedio = (nodos > 0) ? ((double)suma / (double)nodos) : 0.0;

  printf("Nodos: %d\n", nodos);
  printf("Suma: %lld\n", suma);
  printf("Promedio: %.2f\n", promedio);
}

void liberar_lista(struct Nodo *cabeza) {
  while (cabeza != NULL) {
    struct Nodo *temp = cabeza;
    cabeza = cabeza->siguiente;
    free(temp);
  }
}

int main(void) {
  int n;

  if (scanf("%d", &n) == 1 && n >= 1) {
    struct Nodo *cabeza = NULL;
    struct Nodo *ultimo = NULL;

    for (int i = 0; i < n; i++) {
      long long val;
      if (scanf("%lld", &val) == 1) {
        insertar_final(&cabeza, &ultimo, val);
      }
    }

    calcular_estadisticas(cabeza);
    liberar_lista(cabeza);
  }

  return 0;
}
