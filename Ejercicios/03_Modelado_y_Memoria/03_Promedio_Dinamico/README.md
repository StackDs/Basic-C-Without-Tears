# Promedio Dinámico con Malloc

La función `malloc` permite reservar memoria en tiempo de ejecución para un número arbitrario de elementos, evitando el desperdicio o las limitaciones de los arreglos estáticos de tamaño fijo. Escribe un programa que lea la cantidad $N$ de calificaciones a ingresar, reserve la memoria exacta mediante `malloc`, calcule el promedio y libere la memoria con `free`.

## Entrada
La primera línea contiene un número entero $N$ (cantidad de calificaciones).
La segunda línea contiene $N$ números decimales separados por espacios.

Límites:
- 1 <= N <= 10^5
- 0.0 <= Calificación <= 100.0

## Salida
Imprime una única línea con el formato `Promedio: PROM` (a dos decimales). Si $N \le 0$, imprime `La cantidad debe ser mayor a cero.`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 4<br>85.5 90.0 78.0 92.5 | Promedio: 86.50 |
| 3<br>10.0 9.5 8.0 | Promedio: 9.17 |
| 0 | La cantidad debe ser mayor a cero. |
