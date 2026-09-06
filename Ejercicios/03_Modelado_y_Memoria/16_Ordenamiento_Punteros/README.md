# Ordenamiento de Estructuras por Punteros

El ordenamiento de registros en memoria dinámica permite organizar catálogos de información según criterios numéricos o alfabéticos. Escribe un programa que cree un arreglo dinámico de estructuras `struct Libro` (con título y año de publicación), lo ordene de forma ascendente por año de publicación y muestre el catálogo ordenado.

## Entrada
La primera línea contiene un número entero positivo $N$ (cantidad de libros).
Las siguientes $N$ líneas contienen `Titulo Anio` (donde `Titulo` es una palabra sin espacios y `Anio` es un entero).

Límites:
- 1 <= N <= 100
- 1400 <= Anio <= 2100

## Salida
$N$ líneas correspondientes a los libros ordenados cronológicamente, con el formato `ANIO - TITULO`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| 3<br>El_Quijote 1605<br>C_Programming 1978<br>Clean_Code 2008 | 1605 - El_Quijote<br>1978 - C_Programming<br>2008 - Clean_Code |
