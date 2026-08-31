#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("\n=== 5. Terminación Controlada (exit) ===\n");
    
    printf("El programa ha llegado a su fin.\n");
    printf("En una aplicación real, si el error anterior fuera fatal, usaríamos exit(EXIT_FAILURE).\n");
    printf("Como todo ha sido una simulación controlada, el main devolverá EXIT_SUCCESS.\n");

    return EXIT_SUCCESS;
}
