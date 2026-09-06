
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

int eliminar_valor(struct Nodo **cabeza, long long x) {
  struct Nodo *actual = *cabeza;
  struct Nodo *anterior = NULL;

  while (actual != NULL) {
    if (actual->dato == x) {
      if (anterior == NULL) {
        // El elemento a eliminar es la cabeza
        *cabeza = actual->siguiente;
      } else {
        anterior->siguiente = actual->siguiente;
      }
      free(actual);
      return 1;
    }
    anterior = actual;
    actual = actual->siguiente;
  }
  return 0;
}

void imprimir_lista(const struct Nodo *cabeza) {
  printf("Lista: ");
  if (cabeza == NULL) {
    printf("NULL\n");
    return;
  }
  const struct Nodo *actual = cabeza;
  while (actual != NULL) {
    printf("%lld -> ", actual->dato);
    actual = actual->siguiente;
  }
  printf("NULL\n");
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

    long long x;
    if (scanf("%lld", &x) == 1) {
      if (eliminar_valor(&cabeza, x)) {
        printf("Eliminado: %lld\n", x);
      } else {
        printf("No encontrado: %lld\n", x);
      }
      imprimir_lista(cabeza);
    }

    liberar_lista(cabeza);
  }

  return 0;
}
