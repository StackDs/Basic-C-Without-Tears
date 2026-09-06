# Número Perfecto

En aritmética, un número perfecto es un entero positivo que es igual a la suma de sus divisores propios positivos (es decir, todos sus divisores excepto el propio número). Por ejemplo, los divisores propios de $6$ son $1$, $2$ y $3$, cuya suma es $1 + 2 + 3 = 6$, por lo que $6$ es perfecto. Escribe un programa que determine si un número entero positivo cumple con esta condición.

## Entrada
La entrada consiste en una única línea que contiene un número entero positivo $N$.

Límites: 1 <= N <= 10^8

## Salida
Imprime una única línea con el mensaje:
- `N es un numero perfecto.` si la suma de los divisores propios es igual a $N$.
- `N no es un numero perfecto.` en caso contrario.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 6 | 6 es un numero perfecto. |
| 28 | 28 es un numero perfecto. |
| 12 | 12 no es un numero perfecto. |
| 496 | 496 es un numero perfecto. |
