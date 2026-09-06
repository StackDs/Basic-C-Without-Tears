# Clonador Manual de Cadenas (strdup)

La función estándar `strdup` duplica una cadena de caracteres reservando dinámicamente memoria suficiente e insertando una copia fiel en el *heap*. Escribe tu propia implementación `char *mi_strdup(const char *origen)` sin usar `strdup`, midiendo manualmente la longitud y copiando los caracteres mediante bucles.

## Entrada
Una única línea de texto.

Límites:
- 1 <= Longitud <= 1000

## Salida
Dos líneas:
- `Clon: TEXTO_CLONADO`
- `Punteros independientes: OK` (verificando que las direcciones en memoria sean distintas).

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| Lenguaje C sin lagrimas | Clon: Lenguaje C sin lagrimas<br>Punteros independientes: OK |
| Hola Mundo | Clon: Hola Mundo<br>Punteros independientes: OK |
