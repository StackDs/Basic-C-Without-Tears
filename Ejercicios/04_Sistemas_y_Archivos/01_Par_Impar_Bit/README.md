# Par o Impar Bit a Bit

¿Alguna vez te has preguntado cómo los procesadores realizan comprobaciones aritméticas elementales a máxima velocidad? En lugar de utilizar la operación módulo (`%`), que requiere divisiones aritméticas relativamente costosas para la unidad de control, las operaciones a nivel de bits nos permiten inspeccionar directamente el bit menos significativo (*Least Significant Bit* o LSB). Si el último bit de un número entero es `0`, el número es divisible por 2 y por lo tanto es par; si el último bit es `1`, el número es impar.

Escribe un programa que reciba un número entero y determine su paridad utilizando exclusivamente el operador lógico bit a bit AND (`&`).

## Entrada
La entrada consiste en un único número entero $N$.

Límites:
- -1000000000 <= N <= 1000000000

## Salida
Imprime una única línea con el texto:
- `PAR` si el número es par.
- `IMPAR` si el número es impar.

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| 8 | PAR |
| 15 | IMPAR |
| -4 | PAR |
| -7 | IMPAR |
| 0 | PAR |
