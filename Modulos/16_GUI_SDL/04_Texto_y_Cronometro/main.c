/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 4: Prueba           ##
   ##        (Main interactivo con HUD y tiempo)       ##
   ##                                                  ##
   ######################################################
**/

#include <stdio.h>
#include <stdbool.h>
#include <SDL3/SDL.h>
#include "../01_Ventana_y_Ciclo/laberinto.h"
#include "../01_Ventana_y_Ciclo/ventana.h"
#include "../02_Renderizado_y_Assets/render.h"
#include "../03_Interaccion_y_Eventos/input.h"
#include "texto.h"

int main(void) {
    Laberinto laberinto;
    Jugador jugador;

    // Cargar laberinto dinamico desde disco
    const char *ruta_mapa = "../assets/mapa.txt";
    if (!laberinto_cargar_desde_archivo(ruta_mapa, &laberinto, &jugador)) {
        fprintf(stderr, "Fallo al cargar el laberinto desde: %s\n", ruta_mapa);
        return 1;
    }

    // Calcular resolucion de la ventana con espacio para HUD
    int ancho_ventana = laberinto.columnas * TAM_TILE;
    int alto_ventana = (laberinto.filas * TAM_TILE) + PANEL_HUD_ALTO;

    SDL_Window *ventana = NULL;
    SDL_Renderer *renderer = NULL;

    if (!ventana_inicializar(&ventana, &renderer, "Submodulo 4 - Cronometro y HUD", ancho_ventana, alto_ventana)) {
        laberinto_liberar(&laberinto);
        return 1;
    }

    Texturas texturas;
    if (!render_cargar_texturas(renderer, &texturas)) {
        ventana_destruir(ventana, renderer);
        laberinto_liberar(&laberinto);
        return 1;
    }

    printf("-> Controles: Muevete con las flechas o WASD. Sal con ESC.\n");
    printf("-> Observa el cronometro contando milisegundos en la barra superior.\n");

    // Marcar el instante de inicio del cronometro
    Uint64 tiempo_inicio = SDL_GetTicks();
    Uint64 tiempo_congelado = 0;
    bool corriendo = true;
    bool salida_alcanzada = false;

    while (corriendo) {
        // Capturar eventos y desplazamiento
        if (!input_procesar_eventos(&jugador, &laberinto, &salida_alcanzada)) {
            corriendo = false;
        }

        // Determinar el tiempo a proyectar en el HUD
        Uint64 tiempo_actual = SDL_GetTicks();
        Uint64 tiempo_a_mostrar = 0;

        if (salida_alcanzada) {
            if (tiempo_congelado == 0) {
                tiempo_congelado = tiempo_actual - tiempo_inicio;
            }
            tiempo_a_mostrar = tiempo_congelado;
        } else {
            tiempo_a_mostrar = tiempo_actual - tiempo_inicio;
        }

        // Limpiar el fondo
        SDL_SetRenderDrawColor(renderer, 18, 18, 22, 255);
        SDL_RenderClear(renderer);

        // Dibujar elementos del mundo
        render_dibujar_laberinto(renderer, &laberinto, &texturas);
        render_dibujar_jugador(renderer, &jugador, &texturas);

        // Renderizar el panel HUD con el tiempo transcurrido
        hud_renderizar(renderer, tiempo_a_mostrar, ancho_ventana);

        // Notificar en pantalla si se supero el reto
        if (salida_alcanzada) {
            SDL_Color color_victoria = { 255, 215, 0, 255 };
            texto_renderizar(renderer, 480.0f, 22.0f, "[META ALCANZADA!]", 2.2f, color_victoria);
        }

        SDL_RenderPresent(renderer);
    }

    // Liberacion ordenada de memoria y subsistemas
    render_destruir_texturas(&texturas);
    ventana_destruir(ventana, renderer);
    laberinto_liberar(&laberinto);

    printf("-> Fin de la prueba del Submodulo 4.\n");
    return 0;
}
