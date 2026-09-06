# Registro de Estudiantes

Las estructuras en C permiten modelar entidades del mundo real que combinan diferentes tipos de datos, como cadenas de texto, enteros y números decimales. Escribe un programa que defina un `struct Estudiante` con campos para nombre, edad y promedio. El programa debe leer los datos de un arreglo estático de 5 estudiantes, mostrar la ficha de cada uno y reportar el estudiante con el promedio más alto.

## Entrada
La entrada consta de 5 líneas, cada una con el formato `Nombre Edad Promedio`, donde `Nombre` es una palabra sin espacios, `Edad` es un número entero y `Promedio` es un número decimal.

Límites:
- Nombre: hasta 50 caracteres sin espacios
- 15 <= Edad <= 100
- 0.0 <= Promedio <= 100.0

## Salida
5 líneas con el formato `Estudiante: NOMBRE, Edad: EDAD, Promedio: PROM` (a dos decimales), seguidas de una línea con `Mejor estudiante: NOMBRE con promedio PROM`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| Ana 20 9.50<br>Carlos 22 8.75<br>Beatriz 19 9.80<br>David 21 7.20<br>Elena 20 9.10 | Estudiante: Ana, Edad: 20, Promedio: 9.50<br>Estudiante: Carlos, Edad: 22, Promedio: 8.75<br>Estudiante: Beatriz, Edad: 19, Promedio: 9.80<br>Estudiante: David, Edad: 21, Promedio: 7.20<br>Estudiante: Elena, Edad: 20, Promedio: 9.10<br>Mejor estudiante: Beatriz con promedio 9.80 |
