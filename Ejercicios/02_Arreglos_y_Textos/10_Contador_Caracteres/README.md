# Contador Manual de Caracteres

En lenguaje C, las cadenas de texto son secuencias de caracteres que concluyen con el carácter nulo (`'\0'`). Comprender cómo iterar sobre una cadena hasta encontrar este centinela es fundamental para entender la manipulación de texto en bajo nivel. Escribe un programa que lea una línea de texto y cuente manualmente su cantidad de caracteres sin utilizar la función `strlen` de `<string.h>`.

## Entrada
Una única línea de texto.

Límites:
- 1 <= Longitud <= 1000

## Salida
Un único número entero que represente la cantidad de caracteres contenidos en la línea (sin contar el salto de línea final ni el terminador nulo).

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| Hola Mundo | 10 |
| C programming | 13 |
| A | 1 |
