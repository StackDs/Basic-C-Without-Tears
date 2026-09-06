# Clonador de Archivos

Al duplicar archivos es fundamental utilizar el modo binario (`"rb"` y `"wb"`). A diferencia del modo texto, el modo binario no realiza traducciones de caracteres especiales de fin de línea (`
` a `
`), garantizando que la copia sea idéntica byte a byte para cualquier tipo de archivo (texto, imágenes, ejecutables, etc.).

Escribe un programa que reciba los nombres de un archivo origen y un archivo destino, copie íntegramente su contenido y reporte la cantidad de bytes transferidos.

## Entrada
La entrada consiste en dos nombres de archivo separados por un espacio: el archivo de origen y el archivo de destino.

Límites:
- Nombres de archivo de hasta 100 caracteres.

## Salida
Si la copia es exitosa, imprime `Archivo clonado exitosamente (N bytes copiados).` donde $N$ es el número de bytes copiados. Si el archivo de origen no se puede abrir, imprime `Error: No se pudo abrir el archivo de origen.` Si ocurre un error al crear el archivo de destino, imprime `Error: No se pudo crear el archivo destino.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| origen.txt copia.txt | Archivo clonado exitosamente (10 bytes copiados). |
| inexistente.txt copia.txt | Error: No se pudo abrir el archivo de origen. |
