# Makefile General del Proyecto Final: Videojuego Laberinto 2D (SDL3)
# Modulo 16: Basic-C-Without-Tears

CC = gcc
CFLAGS = -Wall -Wextra -std=c11 $(shell pkg-config --cflags sdl3 sdl3-mixer)
LDLIBS = $(shell pkg-config --libs sdl3 sdl3-mixer) -lm

TARGET = juego_laberinto

SRCS = main.c \
       audio.c \
       ../05_Pantallas_y_Estados/estados.c \
       ../04_Texto_y_Cronometro/texto.c \
       ../03_Interaccion_y_Eventos/input.c \
       ../02_Renderizado_y_Assets/render.c \
       ../01_Ventana_y_Ciclo/laberinto.c \
       ../01_Ventana_y_Ciclo/ventana.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) $(SRCS) -o $(TARGET) $(LDLIBS)

run: all
	./$(TARGET)

clean:
	rm -f $(TARGET)

valgrind: all
	valgrind --leak-check=full --track-origins=yes ./$(TARGET)

.PHONY: all run clean valgrind
