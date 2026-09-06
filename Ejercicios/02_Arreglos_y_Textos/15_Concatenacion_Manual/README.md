# Concatenación Manual de Cadenas

La concatenación de cadenas consiste en añadir secuencialmente los caracteres de una segunda cadena al final de la primera, garantizando que el carácter nulo (`'\0'`) quede colocado en la última posición del nuevo arreglo. Escribe un programa que lea dos cadenas de texto y las una en un único arreglo resultante sin utilizar la función `strcat` de `<string.h>`.

## Entrada
La primera línea contiene la primera cadena de texto $S_1$.
La segunda línea contiene la segunda cadena de texto $S_2$.

Límites:
- 1 <= Longitud de cada cadena <= 500

## Salida
Imprime una única línea con el resultado de unir $S_1$ y $S_2$.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| Hola <br>Mundo | Hola Mundo |
| Lenguaje <br>C | Lenguaje C |
| Sin<br>Espacio | SinEspacio |
