#include <stdio.h>
#include <stdlib.h>

int main(void) {
    printf("\n=== 4. calloc vs malloc ===\n");
    // calloc inicializa todo en 0, malloc deja basura de la memoria reciclada
    int *basura = malloc(5 * sizeof(int));
    int *limpio = calloc(5, sizeof(int));
    
    printf("Valor en malloc (potencial basura): %d\n", basura[0]);
    printf("Valor en calloc (garantizado cero): %d\n", limpio[0]);
    
    free(basura);
    free(limpio);

    return 0;
}
