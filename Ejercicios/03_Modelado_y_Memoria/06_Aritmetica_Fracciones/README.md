# Aritmética de Fracciones

Modelar números racionales mediante estructuras permite representar fracciones exactas sin pérdida de precisión por redondeo flotante. Escribe un programa que defina `struct Fraccion` con numerador y denominador, e implemente funciones para sumarlas, restarlas y simplificarlas a su forma irreducible utilizando el Máximo Común Divisor (MCD).

## Entrada
Una única línea con el formato `N1 D1 OP N2 D2`, donde $N_1, D_1$ es la primera fracción, $OP$ es el operador (`+` o `-`), y $N_2, D_2$ es la segunda fracción.

Límites:
- -10^6 <= N_1, N_2 <= 10^6
- D_1, D_2 != 0
- OP en {'+', '-'}

## Salida
Imprime la fracción simplificada resultante en formato `NUM/DEN`. Si el denominador es 1, imprime únicamente el número entero `NUM`. Si algún denominador inicial es 0, imprime `Error: Denominador no valido.`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 1 2 + 1 3 | 5/6 |
| 3 4 - 1 4 | 1/2 |
| 2 3 + 1 3 | 1 |
| 5 0 + 1 2 | Error: Denominador no valido. |
| 1 2 - 3 2 | -1 |
