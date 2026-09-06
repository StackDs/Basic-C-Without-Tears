# Filtro de Espacios Múltiples

El saneamiento y normalización de texto a menudo requiere compactar secuencias repetidas de espacios en blanco, dejando únicamente un espacio simple entre palabras consecutivas y eliminando los espacios sobrantes tanto al inicio como al final de la línea. Escribe un programa que reciba una oración y aplique este filtro de limpieza.

## Entrada
Una única línea de texto que puede contener espacios múltiples y espacios en los extremos.

Límites:
- 1 <= Longitud <= 1000

## Salida
Imprime una única línea con la oración normalizada (un solo espacio entre palabras y sin espacios al inicio ni al final).

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| &nbsp;&nbsp;Hola&nbsp;&nbsp;&nbsp;&nbsp;mundo&nbsp;&nbsp;&nbsp;&nbsp;desde&nbsp;&nbsp;&nbsp;&nbsp;C&nbsp;&nbsp; | Hola mundo desde C |
| Programacion&nbsp;&nbsp;&nbsp;&nbsp;sin&nbsp;&nbsp;&nbsp;&nbsp;lagrimas | Programacion sin lagrimas |
| &nbsp;&nbsp;&nbsp;&nbsp;&nbsp;UnSoloEspacio&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; | UnSoloEspacio |
