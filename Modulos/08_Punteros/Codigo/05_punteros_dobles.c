/**
   ######################################################
   ##                                                  ##
   ##      Punteros Dobles y Arreglos de Strings       ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

int main(void){
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

    return 0;
}
