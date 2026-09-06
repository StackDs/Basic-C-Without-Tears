
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
  long long valor;
  struct Nodo *siguiente;
};

struct Pila {
  struct Nodo *tope;
};

void push(struct Pila *p, long long v) {
  struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
  if (nuevo != NULL) {
    nuevo->valor = v;
    nuevo->siguiente = p->tope;
    p->tope = nuevo;
  }
}

void pop(struct Pila *p) {
  if (p->tope == NULL) {
    printf("Error: Pila vacia.\n");
    return;
  }
  struct Nodo *temp = p->tope;
  printf("Pop: %lld\n", temp->valor);
  p->tope = temp->siguiente;
  free(temp);
}

void top(const struct Pila *p) {
  if (p->tope == NULL) {
    printf("Error: Pila vacia.\n");
    return;
  }
  printf("Top: %lld\n", p->tope->valor);
}

void vaciar_pila(struct Pila *p) {
  while (p->tope != NULL) {
    struct Nodo *temp = p->tope;
    p->tope = temp->siguiente;
    free(temp);
  }
}

int main(void) {
  struct Pila mi_pila = {NULL};
  char cmd[20];

  while (scanf("%19s", cmd) == 1 && strcmp(cmd, "FIN") != 0) {
    if (strcmp(cmd, "PUSH") == 0) {
      long long val;
      if (scanf("%lld", &val) == 1) {
        push(&mi_pila, val);
      }
    } else if (strcmp(cmd, "POP") == 0) {
      pop(&mi_pila);
    } else if (strcmp(cmd, "TOP") == 0) {
      top(&mi_pila);
    }
  }

  vaciar_pila(&mi_pila);
  return 0;
}
