# Número Narcisista

Un número narcisista (también conocido como número de Armstrong) de $n$ dígitos es aquel que resulta igual a la suma de cada uno de sus propios dígitos elevados a la potencia $n$. Por ejemplo, el número $153$ tiene $3$ dígitos y $1^3 + 5^3 + 3^3 = 1 + 125 + 27 = 153$. Tu tarea es escribir un programa que lea un número entero no negativo y determine si cumple con esta propiedad matemática.

## Entrada
La entrada consiste en una única línea que contiene un número entero no negativo $N$.

Límites: 0 <= N <= 10^9

## Salida
Imprime una única línea con el mensaje:
- `N es un numero narcisista.` si el número cumple la condición.
- `N no es un numero narcisista.` en caso contrario.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 153 | 153 es un numero narcisista. |
| 370 | 370 es un numero narcisista. |
| 9474 | 9474 es un numero narcisista. |
| 10 | 10 no es un numero narcisista. |
| 0 | 0 es un numero narcisista. |