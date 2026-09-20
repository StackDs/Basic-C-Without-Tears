/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 1: Laberinto        ##
   ##          (Header: Memoria Dinámica y Datos)      ##
   ##                                                  ##
   ######################################################
**/

#ifndef LABERINTO_H
#define LABERINTO_H

#include <stdbool.h>
#include <stddef.h>

/* --- Dimensiones Gráficas --- */
#define TAM_TILE 32       // Cada casilla mide 32x32 píxeles
#define PANEL_HUD_ALTO 64 // Altura del panel superior para cronómetro/texto

/* --- Códigos Numéricos de Celda --- */
#define CELDA_CAMINO 0        // Espacio transitable (suelo)
#define CELDA_PARED 1         // Muro sólido
#define CELDA_SALIDA 2        // Meta / Salida del laberinto
#define CELDA_JUGADOR_SPAWN 3 // Marcador en mapa.txt para spawn del jugador

/* --- Estructura del Jugador --- */
typedef struct {
  int x; // Coordenada lógica en columnas (0 a columnas - 1)
  int y; // Coordenada lógica en filas (0 a filas - 1)
} Jugador;

/* --- Estructura del Laberinto Dinámico --- */
typedef struct {
  int filas;    // Cantidad de filas leídas desde el archivo
  int columnas; // Cantidad de columnas leídas desde el archivo
  int **celdas; // Matriz dinámica bidimensional asignada en el Heap
} Laberinto;

/* Funciones Públicas --- */

/**
 * Lee un archivo .txt, reserva memoria dinámica (Heap) para la matriz
 * y localiza el punto de aparición del jugador (celda con valor 3).
 * Convierte automáticamente la celda del jugador a CELDA_CAMINO (0)
 * para mantener la pureza del mapa.
 *
 * Retorna true en caso de éxito, false ante error de archivo o memoria.
 */
bool laberinto_cargar_desde_archivo(const char *ruta_archivo,
                                    Laberinto *laberinto, Jugador *jugador);

/**
 * Imprime en la consola estándar la matriz completa en formato crudo
 * (números separados por espacio por cada fila) confirmando la carga correcta.
 */
void laberinto_imprimir_consola(const Laberinto *laberinto);

/**
 * Consulta el valor de una celda en (x, y).
 * Si las coordenadas escapan de los límites de la matriz, devuelve
 * CELDA_PARED por seguridad defensiva para evitar accesos indebidos a memoria.
 */
int laberinto_obtener_celda(const Laberinto *laberinto, int x, int y);

/**
 * Determina si la casilla (x, y) es una pared.
 */
bool laberinto_es_pared(const Laberinto *laberinto, int x, int y);

/**
 * Determina si la casilla (x, y) es la meta de salida.
 */
bool laberinto_es_salida(const Laberinto *laberinto, int x, int y);

/**
 * Libera toda la memoria dinámica reservada en el Heap para la matriz
 * y restablece los punteros y dimensiones a cero.
 */
void laberinto_liberar(Laberinto *laberinto);

#endif
