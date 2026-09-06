
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Contacto {
  char nombre[50];
  char telefono[50];
};

int main(void) {
  int capacidad = 4;
  int total = 0;
  struct Contacto *agenda =
      (struct Contacto *)malloc((size_t)capacidad * sizeof(struct Contacto));

  if (agenda == NULL) {
    return 1;
  }

  char comando[20];
  while (scanf("%19s", comando) == 1 && strcmp(comando, "FIN") != 0) {
    if (strcmp(comando, "AGREGAR") == 0) {
      // Duplicar capacidad si el arreglo se llena
      if (total == capacidad) {
        capacidad *= 2;
        struct Contacto *temp = (struct Contacto *)realloc(
            agenda, (size_t)capacidad * sizeof(struct Contacto));
        if (temp == NULL) {
          free(agenda);
          return 1;
        }
        agenda = temp;
      }
      if (scanf("%49s %49s", agenda[total].nombre, agenda[total].telefono) ==
          2) {
        total++;
      }
    } else if (strcmp(comando, "BUSCAR") == 0) {
      char buscado[50];
      if (scanf("%49s", buscado) == 1) {
        int encontrado = 0;
        for (int i = 0; i < total; i++) {
          if (strcmp(agenda[i].nombre, buscado) == 0) {
            printf("Contacto: %s, Telefono: %s\n", agenda[i].nombre,
                   agenda[i].telefono);
            encontrado = 1;
            break;
          }
        }
        if (!encontrado) {
          printf("Contacto no encontrado.\n");
        }
      }
    }
  }

  // Liberar toda la memoria dinamica
  free(agenda);
  return 0;
}
