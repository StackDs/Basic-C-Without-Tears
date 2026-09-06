# Limpieza de Cadenas (In-Place)

A menudo recibimos datos de usuarios llenos de símbolos raros, espacios innecesarios y mayúsculas desordenadas. Antes de procesar texto en motores de búsqueda o bases de datos, es indispensable normalizarlo. Tu objetivo es implementar una función que reciba una cadena de texto, elimine todos los caracteres que no sean alfanuméricos (dejando solo letras y dígitos) y convierta las letras restantes a minúsculas. Para optimizar el uso de memoria, la transformación debe realizarse directamente sobre la cadena original (*in-place*).

## Entrada
La entrada consiste en una única línea de texto que puede contener caracteres alfanuméricos, espacios y signos de puntuación.

Límites: 1 <= Longitud de la cadena <= 1000

## Salida
Imprime una única línea con la cadena resultante tras aplicar la limpieza y conversión a minúsculas. Si la cadena no contiene caracteres alfanuméricos, se debe imprimir una línea vacía.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| Hola, Mundo! 2026 | holamundo2026 |
| C_Programming == Awesome #1 | cprogrammingawesome1 |
| ??? !!! ... | |
| 123-ABC_xyz | 123abcxyz |