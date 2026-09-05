/**
   ######################################################
   ##                                                  ##
   ##      Conversion Texto a Numero: <stdlib.h>       ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>

int main(void){
    printf("\n=== 5. Conversion Texto a Numero: <stdlib.h> ===\n");
    char str_entero[] = "42";
    char str_decimal[] = "3.14159";
    char str_basura[] = "100pts";
    
    // Funciones rapidas pero inseguras
    int numero_entero = atoi(str_entero);
    double numero_decimal = atof(str_decimal);
    
    printf("atoi(\"42\") -> %d\n", numero_entero);
    printf("atof(\"3.14159\") -> %f\n", numero_decimal);
    
    // Funcion robusta (strtol) que permite detectar basura
    char *resto;
    long numero_seguro = strtol(str_basura, &resto, 10);
    printf("strtol(\"100pts\") -> Numero real: %ld | Basura ignorada: '%s'\n", numero_seguro, resto);

    return 0;
}
