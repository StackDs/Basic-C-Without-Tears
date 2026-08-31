#include <stdio.h>

int main(void){
    printf("\n=== 1. Declaracion e Inicializacion ===\n");
    // Asignacion literal (el compilador calcula el espacio y el '\0' automaticamente)
    char saludo1[] = "Hola";
    
    // Asignacion caracter por caracter (tu responsabilidad agregar el '\0')
    char saludo2[5] = {'H', 'o', 'l', 'a', '\0'};
    
    printf("Asignacion literal: %s\n", saludo1);
    printf("Asignacion manual:  %s\n", saludo2);
    
    return 0;
}
