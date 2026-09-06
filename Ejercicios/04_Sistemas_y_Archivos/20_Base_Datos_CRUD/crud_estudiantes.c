#include <stdio.h>
#include <string.h>

#define DB_FILE "estudiantes.bin"

// Estructura de estudiante con bandera de estado para borrado logico
struct Estudiante {
  int id;
  char nombre[32];
  double promedio;
  int activo; // 1: Activo, 0: Borrado logico
};

// Agrega un nuevo registro al final del archivo binario
static void crear_estudiante(int id, const char *nombre, double promedio) {
  FILE *fp = fopen(DB_FILE, "ab");
  if (fp == NULL) return;

  struct Estudiante e;
  e.id = id;
  strncpy(e.nombre, nombre, sizeof(e.nombre) - 1);
  e.nombre[sizeof(e.nombre) - 1] = '\0';
  e.promedio = promedio;
  e.activo = 1;

  fwrite(&e, sizeof(struct Estudiante), 1, fp);
  fclose(fp);

  printf("Estudiante guardado.\n");
}

// Consulta un estudiante por ID recorriendo los registros activos
static void consultar_estudiante(int id) {
  FILE *fp = fopen(DB_FILE, "rb");
  if (fp == NULL) {
    printf("Estudiante no encontrado.\n");
    return;
  }

  struct Estudiante e;
  int encontrado = 0;

  while (fread(&e, sizeof(struct Estudiante), 1, fp) == 1) {
    if (e.activo && e.id == id) {
      printf("ID: %d | Nombre: %s | Promedio: %.2f\n", e.id, e.nombre, e.promedio);
      encontrado = 1;
      break;
    }
  }

  if (!encontrado) {
    printf("Estudiante no encontrado.\n");
  }

  fclose(fp);
}

// Actualiza el promedio de un estudiante sobreescribiendo su registro en el archivo
static void actualizar_estudiante(int id, double nuevo_promedio) {
  FILE *fp = fopen(DB_FILE, "r+b");
  if (fp == NULL) {
    printf("Estudiante no encontrado.\n");
    return;
  }

  struct Estudiante e;
  int encontrado = 0;

  while (fread(&e, sizeof(struct Estudiante), 1, fp) == 1) {
    if (e.activo && e.id == id) {
      e.promedio = nuevo_promedio;
      // Retroceder el cursor un registro para sobreescribir la estructura modificada
      fseek(fp, -(long)sizeof(struct Estudiante), SEEK_CUR);
      fwrite(&e, sizeof(struct Estudiante), 1, fp);
      encontrado = 1;
      break;
    }
  }

  if (encontrado) {
    printf("Promedio actualizado.\n");
  } else {
    printf("Estudiante no encontrado.\n");
  }

  fclose(fp);
}

// Marca el registro con activo = 0 sin reestructurar el archivo fisico
static void eliminar_estudiante(int id) {
  FILE *fp = fopen(DB_FILE, "r+b");
  if (fp == NULL) {
    printf("Estudiante no encontrado.\n");
    return;
  }

  struct Estudiante e;
  int encontrado = 0;

  while (fread(&e, sizeof(struct Estudiante), 1, fp) == 1) {
    if (e.activo && e.id == id) {
      e.activo = 0;
      fseek(fp, -(long)sizeof(struct Estudiante), SEEK_CUR);
      fwrite(&e, sizeof(struct Estudiante), 1, fp);
      encontrado = 1;
      break;
    }
  }

  if (encontrado) {
    printf("Estudiante eliminado.\n");
  } else {
    printf("Estudiante no encontrado.\n");
  }

  fclose(fp);
}

// Lista todos los estudiantes con la bandera activo = 1
static void listar_estudiantes(void) {
  FILE *fp = fopen(DB_FILE, "rb");
  if (fp == NULL) {
    printf("No hay registros activos.\n");
    return;
  }

  struct Estudiante e;
  int contador = 0;

  while (fread(&e, sizeof(struct Estudiante), 1, fp) == 1) {
    if (e.activo) {
      printf("ID: %d | Nombre: %s | Promedio: %.2f\n", e.id, e.nombre, e.promedio);
      contador++;
    }
  }

  if (contador == 0) {
    printf("No hay registros activos.\n");
  }

  fclose(fp);
}

int main(void) {
  // Limpiar el archivo de prueba al inicio de la sesion
  remove(DB_FILE);

  int opcion;
  // Bucle de menu por codigos numericos
  while (scanf("%d", &opcion) == 1) {
    if (opcion == 0) {
      printf("Fin del programa.\n");
      break;
    } else if (opcion == 1) {
      int id;
      char nombre[32];
      double promedio;
      if (scanf("%d %31s %lf", &id, nombre, &promedio) == 3) {
        crear_estudiante(id, nombre, promedio);
      }
    } else if (opcion == 2) {
      int id;
      if (scanf("%d", &id) == 1) {
        consultar_estudiante(id);
      }
    } else if (opcion == 3) {
      int id;
      double nuevo_prom;
      if (scanf("%d %lf", &id, &nuevo_prom) == 2) {
        actualizar_estudiante(id, nuevo_prom);
      }
    } else if (opcion == 4) {
      int id;
      if (scanf("%d", &id) == 1) {
        eliminar_estudiante(id);
      }
    } else if (opcion == 5) {
      listar_estudiantes();
    }
  }

  return 0;
}
