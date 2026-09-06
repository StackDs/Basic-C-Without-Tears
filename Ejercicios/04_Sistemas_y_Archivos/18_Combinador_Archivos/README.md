# Combinador de Archivos de Texto

Combinar o concatenar múltiples fuentes de datos en un único archivo de salida es una tarea cotidiana en procesamiento de logs y compilación de informes. Requiere abrir ordenadamente flujos de lectura y transferir su contenido hacia un flujo común de escritura.

Escribe un programa que reciba los nombres de dos archivos de texto de entrada y un archivo de destino, y copie el contenido del primer archivo seguido del segundo en el archivo de salida.

## Entrada
La entrada consiste en tres nombres de archivos separados por espacios: `archivo1.txt archivo2.txt combinado.txt`.

Límites:
- Nombres de archivo de hasta 100 caracteres.

## Salida
Imprime `Archivos combinados exitosamente en combinado.txt.` Si alguno de los archivos de origen no se puede abrir, imprime `Error: No se pudieron abrir los archivos de origen.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| parte1.txt parte2.txt total.txt | Archivos combinados exitosamente en total.txt. |
