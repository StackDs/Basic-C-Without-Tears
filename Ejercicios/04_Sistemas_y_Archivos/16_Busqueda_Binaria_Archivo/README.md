# Búsqueda de Registros con Acceso Aleatorio (fseek)

Una de las grandes ventajas de los archivos binarios de tamaño de registro fijo es el **acceso aleatorio**. En lugar de recorrer secuencialmente todos los registros precedentes, podemos saltar directamente a la posición deseada en tiempo constante $O(1)$ utilizando `fseek(fp, indice * sizeof(struct), SEEK_SET)`.

Escribe un programa que reciba el nombre de un archivo binario y un índice de registro (iniciado en `0`), salte directamente a dicho registro con `fseek` e imprima sus datos.

## Entrada
La entrada consiste en una línea con el nombre del archivo binario y el índice del registro a consultar (0-indexado).

Límites:
- 0 <= Indice <= 1000

## Salida
Imprime los datos del registro en el formato `Nombre: N | Edad: E`. Si el índice está fuera de los límites del archivo, imprime `Error: Registro no encontrado.` Si el archivo no existe, imprime `Error: No se pudo abrir el archivo.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| personas.dat 1 | Nombre: Ana &#124; Edad: 30 |
| personas.dat 10 | Error: Registro no encontrado. |
| inexistente.dat 0 | Error: No se pudo abrir el archivo. |
