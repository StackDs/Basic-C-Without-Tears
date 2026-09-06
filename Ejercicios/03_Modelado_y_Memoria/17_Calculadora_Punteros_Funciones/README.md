# Calculadora con Punteros a Funciones

Los punteros a funciones en C permiten pasar algoritmos y comportamientos como parámetros a otras funciones, habilitando patrones de diseño modulares y llamadas dinámicas. Escribe un programa que implemente funciones para suma, resta, multiplicación y división, y utilice una función de orden superior que reciba un puntero a función para evaluar la operación.

## Entrada
Una única línea con el formato `A OP B`, donde $A$ y $B$ son operandos reales y $OP$ es el operador (`+`, `-`, `*`, `/`).

Límites:
- -10^6 <= A, B <= 10^6
- OP en {'+', '-', '*', '/'}

## Salida
Imprime `Resultado: R` (formateado a dos decimales). Si se intenta dividir entre cero, imprime `Error: Division por cero.`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 15.0 + 25.0 | Resultado: 40.00 |
| 10.0 / 4.0 | Resultado: 2.50 |
| 8.0 / 0.0 | Error: Division por cero. |
| 7.0 * 3.0 | Resultado: 21.00 |
