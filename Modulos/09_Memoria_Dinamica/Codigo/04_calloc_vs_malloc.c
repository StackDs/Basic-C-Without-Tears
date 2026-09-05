/**
   ######################################################
   ##                                                  ##
   ##                 calloc vs malloc                 ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdlib.h>

int main(void) {
  printf("\n=== 4. calloc vs malloc ===\n");
  // calloc inicializa todo en 0, malloc deja basura de la memoria reciclada
  int *basura = malloc(5 * sizeof(int));
  int *limpio = calloc(5, sizeof(int));
  if (basura == NULL || limpio == NULL) {
    fprintf(stderr, "Error: Fallo al asignar memoria.\n");
    free(basura);
    free(limpio); // free(NULL) es seguro en C
    return 1;
  }

  // El compilador con -Wall puede advertir sobre el uso de basura[0]
  // no inicializado; precisamente demuestra que malloc no inicializa la
  // memoria.
  printf("Valor en malloc (potencial basura): %d\n", basura[0]);
  printf("Valor en calloc (garantizado cero): %d\n", limpio[0]);

  // Liberamos y neutralizamos los punteros para evitar fugas de memoria y
  // dangling pointers
  free(basura);
  basura = NULL;
  free(limpio);
  limpio = NULL;

  return 0;
}
