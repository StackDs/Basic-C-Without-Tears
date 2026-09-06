# Registro de Pares e Impares (Bit a Bit)

¿Sabías que la operación módulo (`%`) suele requerir más ciclos de reloj en la CPU que las operaciones lógicas a nivel de bits? En programación de bajo nivel y sistemas embebidos, comprobar la paridad de un número se hace inspeccionando el bit menos significativo con el operador AND (`&`). Además, en aplicaciones reales es indispensable mantener un registro o *log* en disco de los datos procesados. Escribe un programa que lea una secuencia de números enteros hasta encontrar un `0` (el cual finaliza la lectura sin procesarse), determine si cada número es par o impar mediante operaciones a nivel de bits, imprima el resultado por pantalla y lo anexe al archivo `historial.txt`.

## Entrada
La entrada consiste en una secuencia de números enteros separados por espacios o saltos de línea. La secuencia finaliza con el número `0`.

Límites:
- -10^9 <= N <= 10^9 (para cada número $N \ne 0$)
- La lectura termina al ingresar `0`.

## Salida
Para cada número procesado de la secuencia, imprime en consola una línea con:
- `El numero N es PAR.` si el número es par.
- `El numero N es IMPAR.` si el número es impar.

Asimismo, cada una de estas líneas debe añadirse al final del archivo `historial.txt`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 4<br>7<br>-2<br>0 | El numero 4 es PAR.<br>El numero 7 es IMPAR.<br>El numero -2 es PAR. |
| 13<br>24<br>0 | El numero 13 es IMPAR.<br>El numero 24 es PAR. |
| 0 | |