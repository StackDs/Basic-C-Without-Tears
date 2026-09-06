
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Persona {
  char nombre[50];
  int edad;
};

// Genera una copia profunda en un nuevo bloque de memoria
struct Persona *clonar_arreglo(const struct Persona *orig, int n) {
  struct Persona *copia =
      (struct Persona *)malloc((size_t)n * sizeof(struct Persona));
  if (copia == NULL) {
    return NULL;
  }
  for (int i = 0; i < n; i++) {
    strcpy(copia[i].nombre, orig[i].nombre);
    copia[i].edad = orig[i].edad;
  }
  return copia;
}

int main(void) {
  int n;

  if (scanf("%d", &n) == 1 && n >= 1) {
    struct Persona *original =
        (struct Persona *)malloc((size_t)n * sizeof(struct Persona));
    if (original == NULL)
      return 1;

    for (int i = 0; i < n; i++) {
      if (scanf("%49s %d", original[i].nombre, &original[i].edad) != 2) {
        free(original);
        return 1;
      }
    }

    // Crear la copia profunda
    struct Persona *copia = clonar_arreglo(original, n);
    if (copia == NULL) {
      free(original);
      return 1;
    }

    int mod_idx;
    char nuevo_nombre[50];
    int nueva_edad;
    if (scanf("%d %49s %d", &mod_idx, nuevo_nombre, &nueva_edad) == 3) {
      if (mod_idx >= 0 && mod_idx < n) {
        strcpy(copia[mod_idx].nombre, nuevo_nombre);
        copia[mod_idx].edad = nueva_edad;
      }
    }

    // Imprimir el original
    printf("Original:\n");
    for (int i = 0; i < n; i++) {
      printf("[%d] %s, %d\n", i, original[i].nombre, original[i].edad);
    }

    // Imprimir la copia modificada
    printf("Copia:\n");
    for (int i = 0; i < n; i++) {
      printf("[%d] %s, %d\n", i, copia[i].nombre, copia[i].edad);
    }

    // Liberar ambos bloques independientes
    free(original);
    free(copia);
  }

  return 0;
}
