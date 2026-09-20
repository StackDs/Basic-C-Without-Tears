/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 3: Prueba           ##
   ##       (Main interactivo con movimiento)          ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include "../01_Ventana_y_Ciclo/laberinto.h"
#include "../01_Ventana_y_Ciclo/ventana.h"
#include "../02_Renderizado_y_Assets/render.h"
#include "input.h"

int main(void) {
    Laberinto laberinto;
    Jugador jugador;

    // Cargar mapa dinamico desde assets
    const char *ruta_mapa = "../assets/mapa.txt";
    if (!laberinto_cargar_desde_archivo(ruta_mapa, &laberinto, &jugador)) {
        fprintf(stderr, "Fallo al cargar el mapa desde: %s\n", ruta_mapa);
        return 1;
    }

    // Calcular dimensiones de la ventana
    int ancho_ventana = laberinto.columnas * TAM_TILE;
    int alto_ventana = (laberinto.filas * TAM_TILE) + PANEL_HUD_ALTO;

    // Crear ventana y renderer
    SDL_Window *ventana = NULL;
    SDL_Renderer *renderer = NULL;

    if (!ventana_inicializar(&ventana, &renderer, "Submodulo 3 - Movimiento y Colisiones", ancho_ventana, alto_ventana)) {
        laberinto_liberar(&laberinto);
        return 1;
    }

    // Cargar texturas del escenario
    Texturas texturas;
    if (!render_cargar_texturas(renderer, &texturas)) {
        ventana_destruir(ventana, renderer);
        laberinto_liberar(&laberinto);
        return 1;
    }

    printf("-> Controles: Usa las flechas del teclado o WASD para moverte.\n");
    printf("-> Presiona ESC o cierra la ventana para salir.\n");

    // Game Loop interactivo con colisiones y movimiento
    bool corriendo = true;
    bool salida_alcanzada = false;

    while (corriendo) {
        // Procesar eventos de teclado y ventana
        if (!input_procesar_eventos(&jugador, &laberinto, &salida_alcanzada)) {
            corriendo = false;
        }

        // Limpiar el fondo
        SDL_SetRenderDrawColor(renderer, 20, 20, 25, 255);
        SDL_RenderClear(renderer);

        // Dibujar el laberinto y el personaje en su nueva posicion
        render_dibujar_laberinto(renderer, &laberinto, &texturas);
        render_dibujar_jugador(renderer, &jugador, &texturas);

        // Presentar el cuadro en pantalla
        SDL_RenderPresent(renderer);
    }

    // Liberar todos los recursos
    render_destruir_texturas(&texturas);
    ventana_destruir(ventana, renderer);
    laberinto_liberar(&laberinto);

    printf("-> Fin exitoso de la prueba del Submodulo 3.\n");
    return 0;
}
