/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 6: Audio            ##
   ##   (Implementación: Efectos y Música con Mixer)   ##
   ##                                                  ##
   ######################################################
**/

#include "audio.h"
#include <stdio.h>
#include <SDL3/SDL.h>
#include <SDL3_mixer/SDL_mixer.h>

static MIX_Mixer *mixer = NULL;
static MIX_Audio *audio_paso = NULL;
static MIX_Audio *audio_victoria = NULL;
static MIX_Audio *audio_musica = NULL;
static MIX_Track *track_musica = NULL;

static MIX_Audio *cargar_audio_con_fallbacks(MIX_Mixer *m, const char *archivo, bool predecode) {
    char ruta[256];
    const char *prefijos[] = { "assets/", "../assets/", "Modulos/16_GUI_SDL/assets/" };

    // Buscar el archivo de audio en las rutas relativas soportadas
    for (size_t i = 0; i < sizeof(prefijos) / sizeof(prefijos[0]); i++) {
        snprintf(ruta, sizeof(ruta), "%s%s", prefijos[i], archivo);
        MIX_Audio *audio = MIX_LoadAudio(m, ruta, predecode);
        if (audio != NULL) {
            return audio;
        }
    }

    fprintf(stderr, "[AUDIO] Error al cargar: %s (%s)\n", archivo, SDL_GetError());
    return NULL;
}

bool audio_inicializar(void) {
    // Inicializar el subsistema oficial SDL3_mixer
    if (!MIX_Init()) {
        fprintf(stderr, "[AUDIO] Error al inicializar SDL3_mixer: %s\n", SDL_GetError());
        return false;
    }

    // Crear el dispositivo mezclador predeterminado para reproduccion
    mixer = MIX_CreateMixerDevice(SDL_AUDIO_DEVICE_DEFAULT_PLAYBACK, NULL);
    if (mixer == NULL) {
        fprintf(stderr, "[AUDIO] Error al crear mixer device: %s\n", SDL_GetError());
        MIX_Quit();
        return false;
    }

    // Cargar efectos de sonido en formato WAV
    audio_paso = cargar_audio_con_fallbacks(mixer, "paso.wav", true);
    audio_victoria = cargar_audio_con_fallbacks(mixer, "victoria.wav", true);

    // Cargar la banda sonora en formato MP3
    audio_musica = cargar_audio_con_fallbacks(mixer, "Escape.mp3", false);
    if (audio_musica == NULL) {
        audio_musica = cargar_audio_con_fallbacks(mixer, "escape.mp3", false);
    }

    // Configurar la pista de musica en bucle infinito en segundo plano
    if (audio_musica != NULL) {
        track_musica = MIX_CreateTrack(mixer);
        if (track_musica != NULL) {
            MIX_SetTrackAudio(track_musica, audio_musica);
            MIX_SetTrackLoops(track_musica, -1);
        }
    }

    printf("-> [AUDIO] Subsistema SDL3_mixer inicializado correctamente.\n");
    return true;
}

void audio_reproducir_paso(void) {
    if (mixer != NULL && audio_paso != NULL) {
        // Disparar sonido de paso de forma instantanea
        MIX_PlayAudio(mixer, audio_paso);
    }
}

void audio_reproducir_victoria(void) {
    if (mixer != NULL && audio_victoria != NULL) {
        // Disparar fanfarria de victoria
        MIX_PlayAudio(mixer, audio_victoria);
    }
}

void audio_reproducir_musica(bool reiniciar) {
    if (track_musica == NULL) {
        return;
    }

    // Rebobinar pista si se solicita reinicio
    if (reiniciar) {
        MIX_StopTrack(track_musica, 0);
        MIX_SetTrackPlaybackPosition(track_musica, 0);
    }

    // Iniciar reproduccion en bucle
    MIX_PlayTrack(track_musica, 0);
}

void audio_detener_musica(void) {
    if (track_musica != NULL) {
        // Detener la reproduccion de la banda sonora
        MIX_StopTrack(track_musica, 0);
    }
}

void audio_liberar(void) {
    // Destruir pista musical
    if (track_musica != NULL) {
        MIX_DestroyTrack(track_musica);
        track_musica = NULL;
    }

    // Destruir objetos de audio cargados
    if (audio_paso != NULL) {
        MIX_DestroyAudio(audio_paso);
        audio_paso = NULL;
    }

    if (audio_victoria != NULL) {
        MIX_DestroyAudio(audio_victoria);
        audio_victoria = NULL;
    }

    if (audio_musica != NULL) {
        MIX_DestroyAudio(audio_musica);
        audio_musica = NULL;
    }

    // Destruir el mezclador y cerrar el subsistema
    if (mixer != NULL) {
        MIX_DestroyMixer(mixer);
        mixer = NULL;
    }

    MIX_Quit();
}
