/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 1: Laberinto        ##
   ##         (Implementación: Heap y Lectura)         ##
   ##                                                  ##
   ######################################################
**/

#include "laberinto.h"
#include <stdio.h>
#include <stdlib.h>

bool laberinto_cargar_desde_archivo(const char *ruta_archivo,
                                    Laberinto *laberinto, Jugador *jugador) {
  if (ruta_archivo == NULL || laberinto == NULL || jugador == NULL) {
    fprintf(
        stderr,
        "[ERROR] Punteros nulos pasados a laberinto_cargar_desde_archivo.\n");
    return false;
  }

  FILE *archivo = fopen(ruta_archivo, "r");
  if (archivo == NULL) {
    fprintf(stderr, "[ERROR] No se pudo abrir el archivo de mapa: %s\n",
            ruta_archivo);
    return false;
  }

  // Leer dimensiones desde la primera línea: filas y columnas
  if (fscanf(archivo, "%d %d", &laberinto->filas, &laberinto->columnas) != 2) {
    fprintf(stderr,
            "[ERROR] Formato inválido en la cabecera de dimensiones de %s\n",
            ruta_archivo);
    fclose(archivo);
    return false;
  }

  if (laberinto->filas <= 0 || laberinto->columnas <= 0) {
    fprintf(stderr, "[ERROR] Dimensiones de mapa inválidas: %d x %d\n",
            laberinto->filas, laberinto->columnas);
    fclose(archivo);
    return false;
  }

  // Asignar memoria dinámica en el Heap para el arreglo de punteros a fila
  laberinto->celdas = malloc(laberinto->filas * sizeof(int *));
  if (laberinto->celdas == NULL) {
    fprintf(stderr,
            "[ERROR] Falló malloc para el arreglo de filas del laberinto.\n");
    fclose(archivo);
    return false;
  }

  // Asignar memoria dinámica para cada fila individual
  for (int f = 0; f < laberinto->filas; f++) {
    laberinto->celdas[f] = malloc(laberinto->columnas * sizeof(int));
    if (laberinto->celdas[f] == NULL) {
      fprintf(stderr, "[ERROR] Falló malloc para la fila %d del laberinto.\n",
              f);
      // Liberar filas previas si falla la asignacion
      for (int k = 0; k < f; k++) {
        free(laberinto->celdas[k]);
      }
      free(laberinto->celdas);
      laberinto->celdas = NULL;
      fclose(archivo);
      return false;
    }
  }

  // Leer cada celda de la matriz y detectar el punto de spawn del jugador
  bool spawn_encontrado = false;

  for (int f = 0; f < laberinto->filas; f++) {
    for (int c = 0; c < laberinto->columnas; c++) {
      int valor = 0;
      if (fscanf(archivo, "%d", &valor) != 1) {
        fprintf(stderr,
                "[ERROR] Datos insuficientes en %s al leer celda [%d, %d]\n",
                ruta_archivo, f, c);
        laberinto_liberar(laberinto);
        fclose(archivo);
        return false;
      }

      if (valor == CELDA_JUGADOR_SPAWN) {
        jugador->x = c;
        jugador->y = f;
        spawn_encontrado = true;
        // Desacoplar jugador del terreno dejando camino libre
        laberinto->celdas[f][c] = CELDA_CAMINO;
      } else {
        laberinto->celdas[f][c] = valor;
      }
    }
  }

  fclose(archivo);

  if (!spawn_encontrado) {
    fprintf(stderr, "[ADVERTENCIA] No se encontró la casilla '3' de spawn. "
                    "Asignando (1, 1) por defecto.\n");
    jugador->x = 1;
    jugador->y = 1;
  }

  return true;
}

void laberinto_imprimir_consola(const Laberinto *laberinto) {
  if (laberinto == NULL || laberinto->celdas == NULL) {
    printf("[LOG] Laberinto no inicializado en memoria.\n");
    return;
  }

  printf("\n=== Log de Carga del Laberinto en Memoria Dinámica ===\n");
  printf("-> Dimensiones leídas: %d filas x %d columnas\n", laberinto->filas,
         laberinto->columnas);
  printf("-> Matriz cargada (números crudos):\n\n");

  for (int f = 0; f < laberinto->filas; f++) {
    for (int c = 0; c < laberinto->columnas; c++) {
      printf("%d ", laberinto->celdas[f][c]);
    }
    printf("\n");
  }

  printf("\n-> [OK] Matriz asignada en el Heap y verificada exitosamente.\n\n");
}

int laberinto_obtener_celda(const Laberinto *laberinto, int x, int y) {
  if (laberinto == NULL || laberinto->celdas == NULL) {
    return CELDA_PARED;
  }

  // Validar limites para evitar Segmentation Fault
  if (x < 0 || x >= laberinto->columnas || y < 0 || y >= laberinto->filas) {
    return CELDA_PARED;
  }

  return laberinto->celdas[y][x];
}

bool laberinto_es_pared(const Laberinto *laberinto, int x, int y) {
  return laberinto_obtener_celda(laberinto, x, y) == CELDA_PARED;
}

bool laberinto_es_salida(const Laberinto *laberinto, int x, int y) {
  return laberinto_obtener_celda(laberinto, x, y) == CELDA_SALIDA;
}

void laberinto_liberar(Laberinto *laberinto) {
  if (laberinto == NULL || laberinto->celdas == NULL) {
    return;
  }

  // Liberar cada fila individual en el Heap
  for (int f = 0; f < laberinto->filas; f++) {
    if (laberinto->celdas[f] != NULL) {
      free(laberinto->celdas[f]);
      laberinto->celdas[f] = NULL;
    }
  }

  // Liberar el arreglo principal de punteros
  free(laberinto->celdas);
  laberinto->celdas = NULL;
  laberinto->filas = 0;
  laberinto->columnas = 0;
}
