/**
   ######################################################
   ##                                                  ##
   ##        Módulo 16 - Submódulo 6: Audio            ##
   ##        (Header: Audio con SDL3_mixer)            ##
   ##                                                  ##
   ######################################################
**/

#ifndef AUDIO_H
#define AUDIO_H

#include <stdbool.h>

// Inicializa el subsistema SDL3_mixer y carga los efectos y musica
bool audio_inicializar(void);

// Reproduce el efecto de sonido de un paso al caminar
void audio_reproducir_paso(void);

// Reproduce la fanfarria de victoria al pisar la meta
void audio_reproducir_victoria(void);

// Inicia o reanuda la reproduccion de la musica de fondo en bucle
void audio_reproducir_musica(bool reiniciar);

// Detiene la reproduccion de la musica ambiental
void audio_detener_musica(void);

// Libera los recursos de audio y cierra SDL3_mixer
void audio_liberar(void);

#endif
