
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Producto {
  char nombre[40];
  double precio;
  int cantidad;
};

int main(void) {
  int n;

  if (scanf("%d", &n) == 1 && n >= 1) {
    int capacidad = 2;
    int total_items = 0;
    struct Producto *carrito =
        (struct Producto *)malloc((size_t)capacidad * sizeof(struct Producto));
    if (carrito == NULL)
      return 1;

    for (int i = 0; i < n; i++) {
      if (total_items == capacidad) {
        capacidad *= 2;
        struct Producto *temp = (struct Producto *)realloc(
            carrito, (size_t)capacidad * sizeof(struct Producto));
        if (temp == NULL) {
          free(carrito);
          return 1;
        }
        carrito = temp;
      }

      if (scanf("%39s %lf %d", carrito[total_items].nombre,
                &carrito[total_items].precio,
                &carrito[total_items].cantidad) == 3) {
        total_items++;
      }
    }

    double total_pagar = 0.0;
    for (int i = 0; i < total_items; i++) {
      double subtotal = carrito[i].precio * (double)carrito[i].cantidad;
      total_pagar += subtotal;
      printf("[%d] %s x %d = $%.2f\n", i + 1, carrito[i].nombre,
             carrito[i].cantidad, subtotal);
    }

    printf("Total a pagar: $%.2f\n", total_pagar);
    free(carrito);
  }

  return 0;
}
