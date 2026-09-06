

#include <stdio.h>

int main(void) {
  char modo;

  // Leer el caracter de modo: 'M' (mayusculas) o 'm' (minusculas)
  if (scanf(" %c", &modo) == 1) {
    // Consumir el salto de linea restante en el buffer
    int ch;
    while ((ch = getchar()) != '\n' && ch != EOF)
      ;

    char texto[1024];
    if (fgets(texto, sizeof(texto), stdin) != NULL) {
      for (int i = 0; texto[i] != '\0' && texto[i] != '\n'; i++) {
        if (modo == 'M' || modo == 'm' - 32) {
          // Convertir de minuscula ('a'-'z') a mayuscula restando 32
          if (texto[i] >= 'a' && texto[i] <= 'z') {
            texto[i] = (char)(texto[i] - 32);
          }
        }
        if (modo == 'm') {
          // Convertir de mayuscula ('A'-'Z') a minuscula sumando 32
          if (texto[i] >= 'A' && texto[i] <= 'Z') {
            texto[i] = (char)(texto[i] + 32);
          }
        }
      }

      // Eliminar salto de linea final antes de imprimir
      for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '\n') {
          texto[i] = '\0';
          break;
        }
      }

      printf("%s\n", texto);
    }
  }

  return 0;
}
