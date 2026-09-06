# Mini Hexdump de Archivos

Una utilidad `hexdump` permite inspeccionar la representación hexadecimal byte a byte de cualquier archivo, lo cual resulta vital para depurar formatos binarios corruptos o realizar ingeniería inversa.

Escribe un programa que reciba el nombre de un archivo, lo abra en modo binario (`"rb"`) e imprima el valor hexadecimal de cada byte (con dos dígitos en mayúsculas `%02X`) separado por espacios.

## Entrada
La entrada consiste en una línea con el nombre del archivo a inspeccionar.

Límites:
- Archivos de hasta 1024 bytes.

## Salida
Imprime la secuencia de bytes en hexadecimal separados por un espacio. Si el archivo no existe o no se puede abrir, imprime `Error: No se pudo abrir el archivo.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| hola.txt | 48 6F 6C 61 |
| inexistente.bin | Error: No se pudo abrir el archivo. |
