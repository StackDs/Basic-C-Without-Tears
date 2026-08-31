#include <stdio.h>

typedef struct {
    char nombre[30];
    float precio;
    int stock;
} Producto;

void aplicar_descuento_malo(Producto p, float descuento);
void aplicar_descuento_bueno(Producto *p, float descuento);

int main(void){
    Producto p1 = {"Laptop", 999.99, 10};

    printf("\n=== 5. Structs y Funciones: El Operador Flecha (->) ===\n");
    printf("Precio original de p1: $%.2f\n", p1.precio);
    
    // Pasamos por valor (solo manda una copia de p1, la original no muta)
    aplicar_descuento_malo(p1, 100.0);
    printf("Precio despues del descuento MALO: $%.2f (No cambia, porque paso por valor)\n", p1.precio);
    
    // Pasamos por referencia (mandamos la direccion de p1, permitiendo la mutacion)
    aplicar_descuento_bueno(&p1, 100.0);
    printf("Precio despues del descuento BUENO: $%.2f (Exito!)\n", p1.precio);

    return 0;
}

// Recibe una COPIA del struct. Todo lo que pasa aqui muere aqui.
void aplicar_descuento_malo(Producto p, float descuento){
    p.precio = p.precio - descuento; // Usamos punto porque es un struct normal
}

// Recibe un PUNTERO al struct. Actua sobre la variable original.
void aplicar_descuento_bueno(Producto *p, float descuento){
    // Usamos FLECHA (->) porque 'p' es un puntero a un struct.
    // p->precio es lo mismo que (*p).precio
    p->precio = p->precio - descuento;
}
