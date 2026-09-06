# Búsqueda de Extremos en un Arreglo

Trabajar con colecciones de datos numéricos frecuentemente requiere identificar los valores límite para tareas de normalización, filtrado o análisis estadístico. Escribe un programa que lea un arreglo de $N$ números enteros y determine el valor mínimo y el valor máximo presentes en la colección.

## Entrada
La primera línea contiene un número entero positivo $N$ que representa la cantidad de elementos.
La segunda línea contiene $N$ números enteros separados por espacios.

Límites:
- 1 <= N <= 10^5
- -10^9 <= Elemento <= 10^9

## Salida
Imprime una única línea con el formato `Min: MIN, Max: MAX`, donde `MIN` es el valor más pequeño y `MAX` es el valor más grande del arreglo.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 5<br>3 8 1 9 4 | Min: 1, Max: 9 |
| 1<br>42 | Min: 42, Max: 42 |
| 4<br>-10 -50 -3 -20 | Min: -50, Max: -3 |
