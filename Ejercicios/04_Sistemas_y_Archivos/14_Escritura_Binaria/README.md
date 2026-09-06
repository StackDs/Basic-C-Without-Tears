# Escritura de Estructuras en Archivo Binario

Guardar datos estructurados en formato de texto suele requerir conversiones repetitivas a cadenas mediante `fprintf` y `sscanf`. En cambio, con la función `fwrite` podemos volcar directamente bloques continuos de memoria RAM que representan estructuras completas (`struct`) al disco en formato binario.

Escribe un programa que reciba un listado de personas (nombre y edad) y las guarde como registros binarios en un archivo `.dat`.

## Entrada
- La primera línea contiene un entero $N$ (número de personas) y el nombre del archivo destino (por ejemplo `personas.dat`).
- Las siguientes $N$ líneas contienen cada una el nombre (una palabra) y la edad (entero) de cada persona.

Límites:
- 1 <= N <= 50
- Longitud de nombres <= 30 caracteres
- 1 <= Edad <= 120

## Salida
Imprime `Se guardaron N registros en el archivo nombre_archivo.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| 2 personas.dat<br>Carlos 25<br>Ana 30 | Se guardaron 2 registros en el archivo personas.dat. |
