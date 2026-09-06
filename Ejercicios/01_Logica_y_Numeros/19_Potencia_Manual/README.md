# Potencia Manual

Implementar la exponenciación mediante bucles permite comprender la construcción de operaciones de orden superior a partir de multiplicaciones sucesivas, sin depender de funciones externas como `pow` de `<math.h>`. Escribe un programa que reciba una base entera $B$ y un exponente entero no negativo $E$, y calcule el valor de $B^E$ utilizando únicamente estructuras de repetición. Recuerda que por convención matemática $B^0 = 1$ para cualquier base distinta de cero (y $0^0 = 1$).

## Entrada
La entrada consiste en una única línea que contiene dos números enteros $B$ y $E$ separados por un espacio, donde $B$ es la base y $E$ es el exponente.

Límites:
- -50 <= B <= 50
- 0 <= E <= 30

## Salida
Imprime un único número entero que represente el resultado de $B^E$.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 2 10 | 1024 |
| 5 0 | 1 |
| -3 3 | -27 |
| -2 4 | 16 |
| 0 5 | 0 |
