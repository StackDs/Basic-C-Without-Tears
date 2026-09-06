# Hola Archivo

La persistencia en disco es una de las tareas más comunes en el desarrollo de software. En C, la biblioteca estándar provee `fopen` para abrir o crear archivos, `fputs` o `fprintf` para escribir en ellos y `fclose` para guardar y cerrar el flujo de datos asegurando que el búfer del sistema operativo se vacíe en el almacenamiento.

Escribe un programa que reciba una línea de texto, la escriba dentro del archivo `saludo.txt` e imprima un mensaje de confirmación en la consola.

## Entrada
La entrada consiste en una línea de texto con el saludo o mensaje a almacenar.

Límites:
- Longitud del texto entre 1 y 200 caracteres.

## Salida
Imprime en consola `Archivo saludo.txt creado exitosamente.` tras completar la escritura.

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| Hola Mundo | Archivo saludo.txt creado exitosamente. |
| Bienvenidos a C sin lagrimas | Archivo saludo.txt creado exitosamente. |
