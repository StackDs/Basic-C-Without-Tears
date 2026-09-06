#include <stdio.h>

// Estructura identica a la usada durante la escritura
struct Persona {
  char nombre[32];
  int edad;
};

int main(void) {
  char nombre_archivo[128];

  // Leer el nombre del archivo binario
  if (scanf("%127s", nombre_archivo) == 1) {
    // Abrir el archivo en modo lectura binaria ("rb")
    FILE *fp = fopen(nombre_archivo, "rb");
    if (fp == NULL) {
      printf("Error: No se pudo abrir el archivo.\n");
      return 0;
    }

    struct Persona p;
    int index = 1;

    // Leer registros completos con fread mientras haya datos disponibles
    while (fread(&p, sizeof(struct Persona), 1, fp) == 1) {
      printf("Registro %d: Nombre = %s, Edad = %d\n", index, p.nombre, p.edad);
      index++;
    }

    // Cerrar archivo
    fclose(fp);
  }

  return 0;
}
