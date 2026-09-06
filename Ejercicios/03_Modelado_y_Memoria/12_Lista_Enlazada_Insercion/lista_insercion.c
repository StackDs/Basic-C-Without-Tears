
#include <stdio.h>
#include <stdlib.h>

struct Nodo {
  long long dato;
  struct Nodo *siguiente;
};

// Inserta un nuevo nodo al inicio de la lista
void insertar_inicio(struct Nodo **cabeza, long long val) {
  struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
  if (nuevo == NULL)
    return;
  nuevo->dato = val;
  nuevo->siguiente = *cabeza;
  *cabeza = nuevo;
}

// Imprime la lista completa
void imprimir_lista(const struct Nodo *cabeza) {
  printf("Lista: ");
  const struct Nodo *actual = cabeza;
  while (actual != NULL) {
    printf("%lld -> ", actual->dato);
    actual = actual->siguiente;
  }
  printf("NULL\n");
}

// Libera todos los nodos de la lista
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
    struct Nodo *lista = NULL;

    for (int i = 0; i < n; i++) {
      long long val;
      if (scanf("%lld", &val) == 1) {
        insertar_inicio(&lista, val);
      }
    }

    imprimir_lista(lista);
    liberar_lista(lista);
  }

  return 0;
}
