# Estructuras Anidadas (Fecha y Empleado)

La anidación de estructuras permite componer tipos de datos complejos a partir de piezas modulares reutilizables. Escribe un programa que defina un `struct Fecha` (con día, mes y año) y lo anide dentro de un `struct Empleado` (con nombre, salario y fecha de contratación), leyendo los datos e imprimiendo el reporte con el formato de fecha `DD/MM/AAAA`.

## Entrada
Una única línea con el formato `Nombre Salario Dia Mes Anio`.

Límites:
- Nombre: hasta 50 caracteres sin espacios
- Salario >= 0.0
- 1 <= Dia <= 31, 1 <= Mes <= 12, 1900 <= Anio <= 2100

## Salida
Imprime una única línea con el formato:
`Empleado: NOMBRE | Salario: $SALARIO | Fecha de contratacion: DD/MM/AAAA`

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| Carlos 2500.50 15 8 2021 | Empleado: Carlos &#124; Salario: $2500.50 &#124; Fecha de contratacion: 15/08/2021 |
| Valeria 3800.00 1 1 2020 | Empleado: Valeria &#124; Salario: $3800.00 &#124; Fecha de contratacion: 01/01/2020 |
