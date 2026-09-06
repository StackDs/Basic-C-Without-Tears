# Búsqueda Lineal en un Arreglo

La búsqueda lineal o secuencial inspecciona cada posición de una colección ordenada o desordenada desde el inicio hasta encontrar el valor deseado o confirmar su ausencia. Escribe un programa que reciba un arreglo de $N$ números enteros y un valor objetivo $X$, e informe en qué índice (base 0) se produce la primera aparición de $X$ o si no se encuentra en el arreglo.

## Entrada
La primera línea contiene dos números enteros $N$ y $X$ separados por un espacio, donde $N$ es el tamaño del arreglo y $X$ es el valor buscado.
La segunda línea contiene $N$ números enteros separados por espacios.

Límites:
- 1 <= N <= 1000
- -10^9 <= X, Elemento <= 10^9

## Salida
Imprime una única línea con el mensaje:
- `Encontrado en el indice I.` si $X$ está en el arreglo (donde `I` es el primer índice en base 0 donde aparece).
- `No encontrado.` si $X$ no está presente.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 5 7<br>2 4 7 9 7 | Encontrado en el indice 2. |
| 4 15<br>1 2 3 4 | No encontrado. |
| 3 10<br>10 20 30 | Encontrado en el indice 0. |
