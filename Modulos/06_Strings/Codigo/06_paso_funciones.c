/**
   ######################################################
   ##                                                  ##
   ##           Paso de Strings a Funciones            ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <string.h>

void imprimir_con_longitud(char cadena[]);

int main(void){
    char pass[] = "Pa55word!";
    printf("\n=== 6. Paso de Strings a Funciones ===\n");
    imprimir_con_longitud(pass);

    return 0;
}

void imprimir_con_longitud(char cadena[]){
    // A diferencia de los arreglos normales de enteros, aqui NO hace falta 
    // recibir el 'size' como parametro extra. Gracias al caracter nulo ('\0'), 
    // strlen() puede calcular la longitud dinamicamente.
    printf("-> La funcion recibio '%s', que tiene %lu caracteres reales.\n", cadena, (unsigned long)strlen(cadena));
}
