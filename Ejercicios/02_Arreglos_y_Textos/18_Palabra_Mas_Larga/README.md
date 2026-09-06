# Palabra Más Larga en una Frase

El procesamiento de lenguaje natural y la extracción de vocabulario requieren segmentar textos en palabras delimitadas por espacios. Escribe un programa que lea una oración e identifique la palabra con mayor número de caracteres. Si existen varias palabras con la misma longitud máxima, se debe reportar la primera encontrada.

## Entrada
Una única línea de texto que contiene una o más palabras separadas por espacios.

Límites:
- 1 <= Longitud <= 1000

## Salida
Imprime una única línea con el formato `Palabra: PALABRA, Longitud: L`, donde `PALABRA` es la palabra más extensa y `L` es su cantidad de caracteres.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| Aprender programacion en C es fascinante | Palabra: programacion, Longitud: 12 |
| El sol brilla hoy | Palabra: brilla, Longitud: 6 |
| Hola | Palabra: Hola, Longitud: 4 |
