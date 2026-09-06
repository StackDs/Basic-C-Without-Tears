# Redimensionamiento de Arreglos con Realloc

La función `realloc` permite modificar el tamaño de un bloque de memoria previamente asignado con `malloc` o `calloc`, preservando los datos ya existentes y reubicando el bloque si fuera necesario. Escribe un programa que reserve espacio inicial para $N$ números enteros, los lea, luego duplique el tamaño del arreglo a $2N$ mediante `realloc`, lea los $N$ números adicionales e imprima los $2N$ elementos completos.

## Entrada
La primera línea contiene un número entero positivo $N$.
La segunda línea contiene los primeros $N$ enteros.
La tercera línea contiene los siguientes $N$ enteros.

Límites:
- 1 <= N <= 500
- -10^9 <= Elemento <= 10^9

## Salida
Imprime los $2N$ números enteros en una sola línea, separados por un espacio.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 3<br>1 2 3<br>4 5 6 | 1 2 3 4 5 6 |
| 2<br>10 20<br>30 40 | 10 20 30 40 |
