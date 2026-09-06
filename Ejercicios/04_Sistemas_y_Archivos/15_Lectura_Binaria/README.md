# Lectura de Registros Binarios

La función `fread` permite leer bloques binarios directamente desde el disco hacia una variable o estructura en memoria RAM. Al retornar la cantidad de elementos leídos exitosamente, podemos iterar en un bucle `while (fread(...) == 1)` hasta alcanzar el final del archivo de manera limpia y robusta.

Escribe un programa que lea un archivo binario con registros de personas (creado en el ejercicio anterior) e imprima cada registro en la consola.

## Entrada
La entrada consiste en una línea con el nombre del archivo binario a leer (por ejemplo `personas.dat`).

Límites:
- Nombre de archivo de hasta 100 caracteres.

## Salida
Para cada registro contenido en el archivo, imprime: `Registro i: Nombre = N, Edad = E`. Si el archivo no existe, imprime `Error: No se pudo abrir el archivo.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| personas.dat | Registro 1: Nombre = Carlos, Edad = 25<br>Registro 2: Nombre = Ana, Edad = 30 |
| inexistente.dat | Error: No se pudo abrir el archivo. |
