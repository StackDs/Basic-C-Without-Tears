# Contador de Métricas en Archivo

Una de las utilidades más populares en entornos tipo Unix es `wc` (*word count*). Este programa analiza un archivo de texto para determinar cuántas líneas, cuántas palabras y cuántos caracteres contiene en total.

Escribe un programa que reciba el nombre de un archivo y calcule estas tres métricas analizando su flujo de caracteres.

## Entrada
La entrada consiste en una única línea con el nombre del archivo a analizar.

Límites:
- Nombre de archivo de hasta 100 caracteres.

## Salida
Imprime una línea con el formato: `Lineas: L | Palabras: P | Caracteres: C`. Si el archivo no puede abrirse, imprime `Error: No se pudo abrir el archivo.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| documento.txt | Lineas: 2 &#124; Palabras: 5 &#124; Caracteres: 27 |
| vacio.txt | Lineas: 0 &#124; Palabras: 0 &#124; Caracteres: 0 |
