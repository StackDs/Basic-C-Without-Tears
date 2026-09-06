
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Nodo {
  long long valor;
  struct Nodo *siguiente;
};

struct Cola {
  struct Nodo *frente;
  struct Nodo *final;
};

void enqueue(struct Cola *c, long long v) {
  struct Nodo *nuevo = (struct Nodo *)malloc(sizeof(struct Nodo));
  if (nuevo == NULL)
    return;
  nuevo->valor = v;
  nuevo->siguiente = NULL;

  if (c->final == NULL) {
    c->frente = nuevo;
    c->final = nuevo;
  } else {
    c->final->siguiente = nuevo;
    c->final = nuevo;
  }
}

void dequeue(struct Cola *c) {
  if (c->frente == NULL) {
    printf("Error: Cola vacia.\n");
    return;
  }
  struct Nodo *temp = c->frente;
  printf("Dequeue: %lld\n", temp->valor);
  c->frente = temp->siguiente;
  if (c->frente == NULL) {
    c->final = NULL;
  }
  free(temp);
}

void frente(const struct Cola *c) {
  if (c->frente == NULL) {
    printf("Error: Cola vacia.\n");
    return;
  }
  printf("Frente: %lld\n", c->frente->valor);
}

void vaciar_cola(struct Cola *c) {
  while (c->frente != NULL) {
    struct Nodo *temp = c->frente;
    c->frente = temp->siguiente;
    free(temp);
  }
  c->final = NULL;
}

int main(void) {
  struct Cola mi_cola = {NULL, NULL};
  char cmd[20];

  while (scanf("%19s", cmd) == 1 && strcmp(cmd, "FIN") != 0) {
    if (strcmp(cmd, "ENQUEUE") == 0) {
      long long val;
      if (scanf("%lld", &val) == 1) {
        enqueue(&mi_cola, val);
      }
    } else if (strcmp(cmd, "DEQUEUE") == 0) {
      dequeue(&mi_cola);
    } else if (strcmp(cmd, "FRENTE") == 0) {
      frente(&mi_cola);
    }
  }

  vaciar_cola(&mi_cola);
  return 0;
}
