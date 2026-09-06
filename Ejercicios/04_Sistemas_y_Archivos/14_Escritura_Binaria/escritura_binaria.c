#include <stdio.h>

// Estructura con campos de tamano fijo para serializacion binaria
struct Persona {
  char nombre[32];
  int edad;
};

int main(void) {
  int n;
  char nombre_archivo[128];

  // Leer cantidad de personas y nombre del archivo binario
  if (scanf("%d %127s", &n, nombre_archivo) == 2 && n >= 1) {
    // Abrir archivo en modo escritura binaria ("wb")
    FILE *fp = fopen(nombre_archivo, "wb");
    if (fp == NULL) {
      return 1;
    }

    struct Persona p;
    int guardados = 0;

    // Leer los datos de cada persona y escribirlos con fwrite
    for (int i = 0; i < n; i++) {
      if (scanf("%31s %d", p.nombre, &p.edad) == 2) {
        fwrite(&p, sizeof(struct Persona), 1, fp);
        guardados++;
      }
    }

    // Cerrar archivo binario
    fclose(fp);

    printf("Se guardaron %d registros en el archivo %s.\n", guardados, nombre_archivo);
  }

  return 0;
}
