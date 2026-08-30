/**
   ######################################################
   ##                                                  ##
   ##           Structs y Unions en C                  ## 
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <string.h>

/**
 * 1. Declaración Global: El Molde
 **/
struct Empleado {
    char nombre[50];
    int edad;
    float salario;
};

/**
 * 2. Simplificación con typedef
 **/
typedef struct {
    char nombre[30];
    float precio;
    int stock;
} Producto;

/**
 * 3. Uniones y Tagged Unions
 **/
union Datos {
    int i;
    float f;
    char str[20];
};

typedef struct {
    int tipo_dato; // 1: int, 2: float, 3: string
    union {
        int i;
        float f;
        char str[20];
    } contenido; 
} VariableMagica;

/**
 * 4. Struct para demostrar Padding
 **/
struct PaddingEjemplo {
    char letra;  // 1 byte
    int numero;  // 4 bytes
};


void aplicar_descuento_malo(Producto p, float descuento);
void aplicar_descuento_bueno(Producto *p, float descuento);


int main(void){
    
    printf("\n=== 1 y 2. Introduccion, Acceso e Inicializacion ===\n");
    // Inicializacion campo por campo
    struct Empleado emp1;
    strcpy(emp1.nombre, "Juan Perez");
    emp1.edad = 30;
    emp1.salario = 1500.50;
    
    // Inicializacion rapida
    struct Empleado emp2 = {"Jane Doe", 28, 2100.75};
    
    // Copia directa
    struct Empleado emp_clon = emp2;
    printf("Empleado 1: %s, %d anos, $%.2f\n", emp1.nombre, emp1.edad, emp1.salario);
    printf("Empleado Clon (Copia de emp2): %s, %d anos\n", emp_clon.nombre, emp_clon.edad);

    printf("\n=== 3. Simplificacion con typedef ===\n");
    // Usamos 'Producto' como si fuera int o float
    Producto p1 = {"Laptop", 999.99, 10};
    printf("Producto creado con typedef: %s a $%.2f\n", p1.nombre, p1.precio);

    printf("\n=== 4. Arreglos de Estructuras (Base de Datos en RAM) ===\n");
    Producto inventario[3] = {
        {"Laptop", 999.99, 10},
        {"Mouse", 25.50, 50},
        {"Teclado", 45.00, 30}
    };
    
    // Iteracion (Busqueda)
    printf("Buscando productos menores a $50:\n");
    for(int i = 0; i < 3; i++){
        if (inventario[i].precio < 50.0){
            printf("- %s ($%.2f)\n", inventario[i].nombre, inventario[i].precio);
        }
    }

    printf("\n=== 5. Structs y Funciones: El Operador Flecha (->) ===\n");
    printf("Precio original de p1: $%.2f\n", p1.precio);
    
    // Pasamos por valor (solo manda una copia de p1, la original no muta)
    aplicar_descuento_malo(p1, 100.0);
    printf("Precio despues del descuento MALO: $%.2f (No cambia, porque paso por valor)\n", p1.precio);
    
    // Pasamos por referencia (mandamos la direccion de p1, permitiendo la mutacion)
    aplicar_descuento_bueno(&p1, 100.0);
    printf("Precio despues del descuento BUENO: $%.2f (Exito!)\n", p1.precio);

    printf("\n=== 6. Uniones: Compartiendo la Memoria ===\n");
    union Datos mis_datos;
    mis_datos.i = 42;
    printf("Union -> Escribimos int: %d\n", mis_datos.i);
    
    mis_datos.f = 3.14; // Al escribir esto, el 42 muere para siempre
    printf("Union -> Escribimos float: %.2f\n", mis_datos.f);
    printf("Union -> Intentar leer el int ahora da basura de memoria: %d\n", mis_datos.i);
    
    // Uso del Tagged Union
    VariableMagica var1;
    var1.tipo_dato = 2; // Avisamos que guardaremos un float
    var1.contenido.f = 9.99;
    printf("Tagged Union -> Dato tipo %d, valor: %.2f\n", var1.tipo_dato, var1.contenido.f);

    printf("\n=== 7. Padding y Alineacion de Memoria (sizeof) ===\n");
    struct PaddingEjemplo pad_ejemplo;
    
    // Hacemos el barrido interno de los campos
    unsigned long size_letra = sizeof(pad_ejemplo.letra);
    unsigned long size_numero = sizeof(pad_ejemplo.numero);
    unsigned long size_total_logico = size_letra + size_numero;
    
    // Medimos el molde completo
    unsigned long size_real = sizeof(struct PaddingEjemplo);
    
    printf("Barrido de los campos internos:\n");
    printf(" - Tamano logico de 'char letra': %lu byte(s)\n", size_letra);
    printf(" - Tamano logico de 'int numero': %lu byte(s)\n", size_numero);
    printf("------------------------------------------\n");
    printf("Tamano total logico (suma): %lu bytes\n", size_total_logico);
    printf("Tamano REAL devuelto por el procesador: %lu bytes\n", size_real);
    
    if (size_real > size_total_logico){
        printf("-> Diferencia por Padding: %lu bytes ocultos (basura insertada para alinear a 4/8 bytes)\n", 
                size_real - size_total_logico);
    } else {
        printf("-> No hubo padding (el tamano es exacto).\n");
    }

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
