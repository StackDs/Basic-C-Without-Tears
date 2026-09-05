/**
   ######################################################
   ##                                                  ##
   ##          Argumentos del Main (Consola)           ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>

// Observa la firma de main. Ya no es "int main(void)", ahora recibe argumentos.
// argc = cantidad de palabras (Argument Count).
// argv = arreglo con las palabras (Argument Vector).
int main(int argc, char *argv[]){
    printf("\n=== 7. Argumentos del Main (Consola) ===\n");
    printf("Has ejecutado este programa con %d argumentos en total.\n", argc);
    printf("El argumento 0 (el nombre del programa) es: %s\n", argv[0]);
    
    if (argc > 1){
        printf("Wow, le pasaste argumentos extra al programa. El argumento 1 es: %s\n", argv[1]);
    } else {
        printf("Prueba ejecutar este programa desde la terminal agregando palabras al final. (Ej: ./sintaxis pato)\n");
    }

    return 0;
}
