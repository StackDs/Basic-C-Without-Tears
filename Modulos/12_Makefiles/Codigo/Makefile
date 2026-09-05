# ==========================================
# MAKEFILE DE EJEMPLO
# ==========================================

# 1. Variables y Macros
CC = gcc
CFLAGS = -Wall -Wextra -Werror -g

# 2. Objetivo Principal (El ejecutable final)
# $^ representa todas las dependencias (01_main.o 02_saludo.o)
# $@ representa el objetivo actual (programa)
programa: 01_main.o 02_saludo.o
	$(CC) $(CFLAGS) $^ -o $@

# 3. Regla de Patrón para compilar archivos .c a .o
# $< representa la primera dependencia (el archivo .c)
# $@ representa el objetivo (el archivo .o)
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# 4. Objetivos Ficticios (Phony Targets)
# Mantenimiento para limpiar los archivos compilados
.PHONY: clean

clean:
	rm -f *.o programa


# Para ejecutar el archivo simplemente escribimos make en la terminal.
# Para limpiar el directorio de archivos compilados simplemente escribimos make clean en la terminal.