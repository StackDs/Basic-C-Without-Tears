# ==========================================
# MAKEFILE - Módulo 11: Modularidad y Headers
# ==========================================

CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g

juego: 01_main.o 02_motor.o
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: clean run

clean:
	rm -f *.o juego

run: juego
	./juego
