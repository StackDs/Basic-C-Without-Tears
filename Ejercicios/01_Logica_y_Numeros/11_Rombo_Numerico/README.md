# Rombo Numérico

El rombo numérico es un patrón simétrico bidimensional donde los dígitos crecen y decrecen progresivamente en cada línea. Escribe un programa que lea un número entero positivo $N$ y genere un rombo numérico cuya fila central alcance el valor máximo $N$. La mitad superior comprende las filas desde $1$ hasta $N$, y la mitad inferior desde $N-1$ descendiendo hasta $1$. En cada fila de nivel $k$, los números avanzan desde $1$ hasta $k$ y luego descienden hasta $1$, manteniendo el centrado con espacios.

## Entrada
La entrada consiste en una única línea que contiene un número entero positivo $N$.

Límites: 1 <= N <= 9

## Salida
Imprime $2N - 1$ líneas que formen el rombo numérico correspondiente.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 3 | &nbsp;&nbsp;1<br>&nbsp;121<br>12321<br>&nbsp;121<br>&nbsp;&nbsp;1 |
| 1 | 1 |
