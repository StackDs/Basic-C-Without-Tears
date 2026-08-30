/**
   ######################################################
   ##                                                  ##
   ##              Punteros en C                       ## 
   ##               (El Filtro)                        ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>
#include <stddef.h> // Para ptrdiff_t

void saludar(){
    printf("Hola desde un Callback!\n");
}

void despedir(){
    printf("Adios desde un Callback!\n");
}

// Esta función recibe un puntero a una función que no toma argumentos y retorna void
void ejecutar_callback(void (*func)()){
    printf("Ejecutando funcion inyectada...\n");
    func();
}


int main(void){
    printf("\n=== 1. Fundamentos: Direcciones y Tamanos ===\n");
    int x = 42;
    int *ptr_x = &x; // ptr_x guarda la dirección física de x
    
    printf("Valor de x: %d\n", x);
    printf("Direccion de x en RAM: %p\n", (void *)&x);
    printf("Valor guardado en ptr_x: %p\n", (void *)ptr_x);
    
    // Todos los punteros pesan lo mismo (normalmente 8 bytes en 64 bits)
    printf("Tamano de int: %lu bytes\n", sizeof(int));
    printf("Tamano de int*: %lu bytes\n", sizeof(int *));
    printf("Tamano de double*: %lu bytes\n", sizeof(double *));
    printf("Tamano de char*: %lu bytes\n", sizeof(char *));

    printf("\n=== 2. Desreferenciacion (Viajando a la memoria) ===\n");
    printf("Valor original apuntado por ptr_x: %d\n", *ptr_x);
    
    // Modificamos el valor de x a través de su puntero
    *ptr_x = 99;
    printf("Nuevo valor de x tras hacer '*ptr_x = 99': %d\n", x);
    
    // Puntero NULL seguro
    int *ptr_nulo = NULL;
    printf("Valor de un puntero NULL (No desreferenciar!): %p\n", (void *)ptr_nulo);

    printf("\n=== 3. Aritmetica de Punteros ===\n");
    int numeros[5] = {10, 20, 30, 40, 50};
    int *p1 = &numeros[0];
    int *p2 = &numeros[3];
    
    printf("Direccion de p1 (numeros[0]): %p\n", (void *)p1);
    // Un salto avanza sizeof(int) bytes
    printf("Direccion de p1 + 1 (numeros[1]): %p (Salto de %lu bytes)\n", (void *)(p1 + 1), sizeof(int));
    
    // Distancia entre punteros del mismo tipo
    ptrdiff_t distancia = p2 - p1;
    printf("Distancia entre numeros[3] y numeros[0]: %td elementos\n", distancia);

    printf("\n=== 4. La Dualidad: Arreglos y Punteros ===\n");
    printf("El nombre 'numeros' por si solo decae en su direccion base: %p\n", (void *)numeros);
    printf("numeros[2] es: %d\n", numeros[2]);
    printf("*(numeros + 2) es: %d (Equivalencia absoluta)\n", *(numeros + 2));
    
    printf("Iterando arreglo con pura aritmetica de punteros:\n");
    for(int *p = numeros; p < numeros + 5; p++){
        printf("%d ", *p);
    }
    printf("\n");

    printf("\n=== 5. Punteros a Punteros y Arreglos de Strings ===\n");
    int y = 5;
    int *p_y = &y;
    int **pp_y = &p_y; // Puntero a puntero
    
    printf("Valor original de y: %d\n", y);
    printf("Desreferencia doble (**pp_y): %d\n", **pp_y);
    **pp_y = 7;
    printf("Nuevo valor de y tras hacer '**pp_y = 7': %d\n", y);

    // Arreglo de strings (char **)
    char *nombres[] = {"Dennis", "Ken", "Stack"};
    char **ptr_nombres = nombres;
    printf("Primer elemento (nombres[0]): %s\n", nombres[0]);
    printf("Tercer elemento (*(ptr_nombres + 2)): %s\n", *(ptr_nombres + 2));

    printf("\n=== 6. Punteros Genericos (void *) ===\n");
    void *comodin;
    float f = 3.1416;
    comodin = &f;
    // printf("%f", *comodin); // ESTO DA ERROR DE COMPILACION (no se sabe el tamaño)
    
    // Debemos "castear" el comodín antes de desreferenciarlo
    printf("Valor float leido desde comodin: %f\n", *(float *)comodin);

    printf("\n=== 7. Punteros a Funciones (Callbacks) ===\n");
    // Pasamos el nombre de la función, que decae en un puntero a sus instrucciones
    ejecutar_callback(saludar);
    ejecutar_callback(despedir);

    printf("\n=== 8. Teaser de Memoria Dinamica (Heap) ===\n");
    // Creamos un arreglo dinamico de 3 enteros usando malloc
    int *dinamico = malloc(3 * sizeof(int));
    if (dinamico != NULL){
        dinamico[0] = 100;
        *(dinamico + 1) = 200; // Demostrando sintaxis equivalente
        dinamico[2] = 300;
        
        printf("Elemento dinamico[1]: %d\n", dinamico[1]);
        
        // REGLA DE ORO: Si pides, devuelves.
        free(dinamico);
        dinamico = NULL; // Evitar el Dangling Pointer (Puntero Colgante)
        printf("Memoria liberada exitosamente, y puntero neutralizado (NULL).\n");
    }

    return 0;
}
