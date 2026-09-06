# Calculadora de Promedios Dinámica

Calcular promedios escolares parece sencillo, pero en el mundo real no siempre sabemos de antemano cuántos estudiantes o materias tendremos que procesar. Usar arreglos con tamaño fijo puede desperdiciar memoria o quedarse corto. Para solucionar esto, la memoria dinámica nos permite reservar exactamente los bytes que necesitamos durante la ejecución. Escribe un programa que lea la cantidad de calificaciones a ingresar, reserve la memoria exacta mediante `malloc`, calcule el promedio de todas ellas con dos decimales de precisión y finalmente libere la memoria utilizada con `free`.

## Entrada
La primera línea contiene un número entero $N$ que representa la cantidad de calificaciones.
La segunda línea contiene $N$ números decimales (*float*) separados por espacios, que representan las calificaciones obtenidas.

Límites:
- 1 <= N <= 10^5
- 0.0 <= Calificación <= 100.0

## Salida
Imprime una única línea con el promedio de las calificaciones formateado a dos lugares decimales. Si $N$ es menor o igual a 0, imprime `La cantidad debe ser mayor a cero.`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 4<br>85.5 90.0 78.0 92.5 | 86.50 |
| 3<br>10.0 9.5 8.0 | 9.17 |
| 1<br>100.0 | 100.00 |
| 0 | La cantidad debe ser mayor a cero. |