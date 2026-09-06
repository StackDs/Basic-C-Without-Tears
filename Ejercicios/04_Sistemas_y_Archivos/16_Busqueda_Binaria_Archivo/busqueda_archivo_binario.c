#include <stdio.h>

// Definicion de la estructura del registro
struct Persona {
  char nombre[32];
  int edad;
};

int main(void) {
  char nombre_archivo[128];
  long indice;

  // Leer nombre del archivo e indice del registro a consultar (0-indexado)
  if (scanf("%127s %ld", nombre_archivo, &indice) == 2) {
    // Abrir archivo en modo binario
    FILE *fp = fopen(nombre_archivo, "rb");
    if (fp == NULL) {
      printf("Error: No se pudo abrir el archivo.\n");
      return 0;
    }

    // Calcular la posicion exacta en bytes dentro del archivo
    long offset = indice * (long)sizeof(struct Persona);

    // Mover el cursor directamente al registro deseado (acceso aleatorio O(1))
    if (fseek(fp, offset, SEEK_SET) != 0) {
      printf("Error: Registro no encontrado.\n");
      fclose(fp);
      return 0;
    }

    struct Persona p;
    // Leer el registro en la posicion actual
    if (fread(&p, sizeof(struct Persona), 1, fp) == 1) {
      printf("Nombre: %s | Edad: %d\n", p.nombre, p.edad);
    } else {
      printf("Error: Registro no encontrado.\n");
    }

    // Cerrar archivo
    fclose(fp);
  }

  return 0;
}
