#include <stdio.h>
#include <ctype.h>

int main(void){
    printf("\n=== 4. Modificacion Caracter a Caracter: <ctype.h> ===\n");
    char pass[] = "Pa55word!";
    int digitos = 0;
    
    printf("Analizando el string '%s':\n", pass);
    for (int i = 0; pass[i] != '\0'; i++){
        if (isdigit(pass[i])){
            digitos++;
        }
        // Convertimos todo a mayuscula sobre la marcha
        pass[i] = toupper(pass[i]);
    }
    printf("Contiene %d digitos.\n", digitos);
    printf("Version en mayusculas pura: %s\n", pass);
    
    return 0;
}
