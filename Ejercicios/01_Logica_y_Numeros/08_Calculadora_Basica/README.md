# Calculadora Básica

La estructura de control `switch-case` en C permite canalizar la ejecución del programa hacia distintas ramas de código en función de un valor de tipo carácter o entero. Escribe un programa que simule una calculadora elemental para evaluar operaciones aritméticas entre dos operandos reales: suma (`+`), resta (`-`), multiplicación (`*`) y división (`/`). En caso de división entre cero o de ingresar un operador no reconocido, el programa debe mostrar el mensaje de error correspondiente.

## Entrada
La entrada consiste en una única línea con el formato `A OP B`, donde $A$ y $B$ son números reales y $OP$ es un carácter que representa la operación aritmética (`+`, `-`, `*`, `/`).

Límites:
- -10^6 <= A, B <= 10^6
- OP es un carácter

## Salida
Imprime una única línea con el resultado numérico formateado a dos decimales.
- Si se intenta dividir entre cero, imprime `Error: Division por cero.`.
- Si el operador no corresponde a ninguno de los cuatro permitidos, imprime `Error: Operador no valido.`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 10 + 5 | 15.00 |
| 20 / 4 | 5.00 |
| 7 / 0 | Error: Division por cero. |
| 3.5 * 2 | 7.00 |
| 10 % 3 | Error: Operador no valido. |
