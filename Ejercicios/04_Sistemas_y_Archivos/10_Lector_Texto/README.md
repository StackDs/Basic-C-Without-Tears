# Lector de Texto

Leer datos desde un archivo en C requiere abrir el archivo en modo lectura (`"r"`), verificar que el puntero `FILE*` retornado por `fopen` no sea nulo (`NULL`), y procesar secuencialmente su contenido con funciones como `fgetc` o `fgets` hasta alcanzar el fin de archivo (`EOF`).

Escribe un programa que reciba el nombre de un archivo de texto e imprima todo su contenido en la consola. Si el archivo no puede ser abierto, debe mostrar un mensaje de error descriptivo.

## Entrada
La entrada consiste en una línea con el nombre del archivo de texto a leer.

Límites:
- Nombre de archivo de hasta 100 caracteres.

## Salida
Imprime el contenido exacto del archivo en la consola. Si el archivo no existe o no se puede abrir, imprime `Error: No se pudo abrir el archivo.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| saludo.txt | Hola Mundo |
| inexistente.txt | Error: No se pudo abrir el archivo. |
