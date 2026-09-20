/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 1: Prueba           ##
   ##        (Main simple de verificación)             ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include "laberinto.h"
#include "ventana.h"

int main(void) {
    Laberinto laberinto;
    Jugador jugador;

    // Cargar laberinto dinamico desde el archivo de assets
    const char *ruta_mapa = "../assets/mapa.txt";
    if (!laberinto_cargar_desde_archivo(ruta_mapa, &laberinto, &jugador)) {
        fprintf(stderr, "Error al cargar el mapa desde: %s\n", ruta_mapa);
        return 1;
    }

    // Imprimir matriz por consola para comprobar la carga
    laberinto_imprimir_consola(&laberinto);
    printf("Posicion inicial del jugador: (%d, %d)\n", jugador.x, jugador.y);

    // Calcular resolucion segun las dimensiones de la grilla
    int ancho_ventana = laberinto.columnas * TAM_TILE;
    int alto_ventana = (laberinto.filas * TAM_TILE) + PANEL_HUD_ALTO;

    // Crear ventana y contexto de renderizado
    SDL_Window *ventana = NULL;
    SDL_Renderer *renderer = NULL;

    if (!ventana_inicializar(&ventana, &renderer, "Submodulo 1 - Laberinto Base", ancho_ventana, alto_ventana)) {
        laberinto_liberar(&laberinto);
        return 1;
    }

    // Ejecutar ciclo de eventos preliminar con pantalla negra
    ventana_ejecutar_ciclo_base(renderer);

    // Limpieza de memoria de video y memoria dinamica
    ventana_destruir(ventana, renderer);
    laberinto_liberar(&laberinto);

    return 0;
}
