# Conjetura de Collatz

La conjetura de Collatz (también conocida como el problema $3n + 1$) propone que al tomar cualquier número entero positivo $N$ y aplicar iterativamente las siguientes transformaciones:
- Si el número es par, se divide entre $2$: $N \to N / 2$.
- Si el número es impar, se multiplica por $3$ y se le suma $1$: $N \to 3N + 1$.

La secuencia siempre alcanza el valor $1$. Escribe un programa que lea un número entero positivo $N$, imprima la secuencia completa de valores hasta llegar a $1$ y reporte la cantidad de pasos realizados.

## Entrada
La entrada consiste en una única línea que contiene un número entero positivo $N$.

Límites: 1 <= N <= 10^6

## Salida
- Primera línea: La secuencia de números generada desde $N$ hasta $1$, separados por un espacio.
- Segunda línea: `Total de pasos: P`, donde $P$ es la cantidad de transiciones realizadas.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 6 | 6 3 10 5 16 8 4 2 1<br>Total de pasos: 8 |
| 1 | 1<br>Total de pasos: 0 |
| 5 | 5 16 8 4 2 1<br>Total de pasos: 5 |
