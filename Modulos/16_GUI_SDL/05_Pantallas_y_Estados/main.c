/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 5: Prueba           ##
   ##     (Main interactivo con FSM y botones)         ##
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
#include "../04_Texto_y_Cronometro/texto.h"
#include "estados.h"

int main(void) {
    Laberinto laberinto;
    Jugador jugador;

    // Cargar laberinto desde archivo
    const char *ruta_mapa = "../assets/mapa.txt";
    if (!laberinto_cargar_desde_archivo(ruta_mapa, &laberinto, &jugador)) {
        fprintf(stderr, "Fallo al cargar el mapa desde: %s\n", ruta_mapa);
        return 1;
    }

    // Guardar la posicion inicial de spawn para reinicios
    int spawn_x = jugador.x;
    int spawn_y = jugador.y;

    int ancho_ventana = laberinto.columnas * TAM_TILE;
    int alto_ventana = (laberinto.filas * TAM_TILE) + PANEL_HUD_ALTO;

    SDL_Window *ventana = NULL;
    SDL_Renderer *renderer = NULL;

    if (!ventana_inicializar(&ventana, &renderer, "Submodulo 5 - Maquina de Estados y Botones", ancho_ventana, alto_ventana)) {
        laberinto_liberar(&laberinto);
        return 1;
    }

    Texturas texturas;
    if (!render_cargar_texturas(renderer, &texturas)) {
        ventana_destruir(ventana, renderer);
        laberinto_liberar(&laberinto);
        return 1;
    }

    // Configurar botones interactivos para el menu y la victoria
    float centro_x = (float)ancho_ventana / 2.0f;
    Boton boton_entrar = boton_crear(centro_x - 120.0f, 410.0f, 240.0f, 56.0f, "ENTRAR");
    Boton boton_reiniciar = boton_crear(centro_x - 140.0f, 420.0f, 280.0f, 56.0f, "JUGAR DE NUEVO");

    // Variables de control de la maquina de estados
    EstadoJuego estado = ESTADO_MENU;
    Uint64 tiempo_inicio = 0;
    Uint64 tiempo_final = 0;
    bool corriendo = true;

    printf("-> Estado inicial: Pantalla de Menu. Haz clic en ENTRAR.\n");

    while (corriendo) {
        SDL_Event evento;
        while (SDL_PollEvent(&evento)) {
            // Manejo de salida general
            if (evento.type == SDL_EVENT_QUIT) {
                corriendo = false;
            }

            if (evento.type == SDL_EVENT_KEY_DOWN && evento.key.key == SDLK_ESCAPE) {
                corriendo = false;
            }

            // Procesar interacciones segun el estado activo
            switch (estado) {
                case ESTADO_MENU:
                    if (evento.type == SDL_EVENT_MOUSE_MOTION) {
                        boton_actualizar_hover(&boton_entrar, evento.motion.x, evento.motion.y);
                    }
                    if (evento.type == SDL_EVENT_MOUSE_BUTTON_DOWN && evento.button.button == SDL_BUTTON_LEFT) {
                        if (boton_contiene_punto(&boton_entrar, evento.button.x, evento.button.y)) {
                            // Transicion al estado de juego e inicio del cronometro
                            jugador.x = spawn_x;
                            jugador.y = spawn_y;
                            tiempo_inicio = SDL_GetTicks();
                            estado = ESTADO_JUGANDO;
                            printf("-> Transicion: MENU -> JUGANDO\n");
                        }
                    }
                    break;

                case ESTADO_JUGANDO:
                    if (evento.type == SDL_EVENT_KEY_DOWN) {
                        switch (evento.key.key) {
                            case SDLK_UP:
                            case SDLK_W:
                                jugador_intentar_mover(&jugador, &laberinto, 0, -1);
                                break;
                            case SDLK_DOWN:
                            case SDLK_S:
                                jugador_intentar_mover(&jugador, &laberinto, 0, 1);
                                break;
                            case SDLK_LEFT:
                            case SDLK_A:
                                jugador_intentar_mover(&jugador, &laberinto, -1, 0);
                                break;
                            case SDLK_RIGHT:
                            case SDLK_D:
                                jugador_intentar_mover(&jugador, &laberinto, 1, 0);
                                break;
                            default:
                                break;
                        }

                        // Comprobar llegada a la meta
                        if (laberinto_es_salida(&laberinto, jugador.x, jugador.y)) {
                            tiempo_final = SDL_GetTicks() - tiempo_inicio;
                            estado = ESTADO_VICTORIA;
                            printf("-> Transicion: JUGANDO -> VICTORIA (Tiempo: %llu ms)\n", (unsigned long long)tiempo_final);
                        }
                    }
                    break;

                case ESTADO_VICTORIA:
                    if (evento.type == SDL_EVENT_MOUSE_MOTION) {
                        boton_actualizar_hover(&boton_reiniciar, evento.motion.x, evento.motion.y);
                    }
                    if (evento.type == SDL_EVENT_MOUSE_BUTTON_DOWN && evento.button.button == SDL_BUTTON_LEFT) {
                        if (boton_contiene_punto(&boton_reiniciar, evento.button.x, evento.button.y)) {
                            // Reiniciar partida desde el inicio
                            jugador.x = spawn_x;
                            jugador.y = spawn_y;
                            tiempo_inicio = SDL_GetTicks();
                            estado = ESTADO_JUGANDO;
                            printf("-> Transicion: VICTORIA -> JUGANDO (Reinicio)\n");
                        }
                    }
                    break;
            }
        }

        // Renderizado dependiente del estado actual
        switch (estado) {
            case ESTADO_MENU:
                estados_dibujar_menu(renderer, &boton_entrar, ancho_ventana, alto_ventana);
                break;

            case ESTADO_JUGANDO: {
                SDL_SetRenderDrawColor(renderer, 18, 18, 22, 255);
                SDL_RenderClear(renderer);

                render_dibujar_laberinto(renderer, &laberinto, &texturas);
                render_dibujar_jugador(renderer, &jugador, &texturas);

                Uint64 transcurrido = SDL_GetTicks() - tiempo_inicio;
                hud_renderizar(renderer, transcurrido, ancho_ventana);
                break;
            }

            case ESTADO_VICTORIA:
                estados_dibujar_victoria(renderer, tiempo_final, &boton_reiniciar, ancho_ventana, alto_ventana);
                break;
        }

        SDL_RenderPresent(renderer);
    }

    // Liberacion de recursos
    render_destruir_texturas(&texturas);
    ventana_destruir(ventana, renderer);
    laberinto_liberar(&laberinto);

    printf("-> Fin de la prueba del Submodulo 5.\n");
    return 0;
}
