# Analizador de Vocales, Consonantes y Espacios

El análisis léxico de texto requiere clasificar caracteres en diferentes grupos. Escribe un programa que lea una línea de texto y cuente la cantidad de vocales (a, e, i, o, u en mayúsculas o minúsculas), consonantes (letras del alfabeto que no son vocales) y espacios en blanco. Los dígitos y signos de puntuación no deben contabilizarse en estas categorías.

## Entrada
Una única línea de texto.

Límites:
- 1 <= Longitud <= 1000

## Salida
Imprime una única línea con el formato `Vocales: V, Consonantes: C, Espacios: E`, donde `V`, `C` y `E` corresponden a las cantidades respectivas encontradas.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| Hola Mundo 2026 | Vocales: 4, Consonantes: 5, Espacios: 2 |
| C language | Vocales: 4, Consonantes: 5, Espacios: 1 |
| 12345 | Vocales: 0, Consonantes: 0, Espacios: 0 |
