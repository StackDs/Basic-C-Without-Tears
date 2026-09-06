# Filtro de Mayúsculas en Archivo

Los filtros de procesamiento de flujo leen información de una fuente, transforman los datos sobre la marcha y escriben el resultado en un destino.

Escribe un programa que reciba los nombres de un archivo de entrada y un archivo de salida, lea el texto del primero, transforme todas las letras minúsculas a mayúsculas y guarde el texto resultante en el archivo de salida.

## Entrada
La entrada contiene dos nombres de archivo separados por un espacio: el archivo origen y el archivo destino.

Límites:
- Nombres de archivo de hasta 100 caracteres.

## Salida
Imprime en consola `Conversion completada exitosamente.` tras generar el archivo. Si el archivo de entrada no se puede abrir, imprime `Error: No se pudo abrir el archivo de origen.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| entrada.txt salida.txt | Conversion completada exitosamente. |
| inexistente.txt salida.txt | Error: No se pudo abrir el archivo de origen. |
