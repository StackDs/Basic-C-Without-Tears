
#include <stdio.h>
#include <stdlib.h>

struct Libro {
  char titulo[60];
  int anio;
};

void ordenar_libros(struct Libro *libros, int n) {
  for (int i = 0; i < n - 1; i++) {
    int min_idx = i;
    for (int j = i + 1; j < n; j++) {
      if (libros[j].anio < libros[min_idx].anio) {
        min_idx = j;
      }
    }
    if (min_idx != i) {
      struct Libro temp = libros[i];
      libros[i] = libros[min_idx];
      libros[min_idx] = temp;
    }
  }
}

int main(void) {
  int n;

  if (scanf("%d", &n) == 1 && n >= 1) {
    struct Libro *catalogo =
        (struct Libro *)malloc((size_t)n * sizeof(struct Libro));
    if (catalogo == NULL)
      return 1;

    for (int i = 0; i < n; i++) {
      if (scanf("%59s %d", catalogo[i].titulo, &catalogo[i].anio) != 2) {
        free(catalogo);
        return 1;
      }
    }

    ordenar_libros(catalogo, n);

    for (int i = 0; i < n; i++) {
      printf("%d - %s\n", catalogo[i].anio, catalogo[i].titulo);
    }

    free(catalogo);
  }

  return 0;
}
