# Cacería de Fugas de Memoria (Memory Leaks)

La correcta liberación de estructuras complejas multinivel requiere un orden inverso al de su asignación (desde los nodos hoja más internos hacia el puntero raíz). Si se libera primero el contenedor principal, se pierde el acceso a los bloques internos generando fugas de memoria (*memory leaks*). Escribe un programa que construya una estructura jerárquica de `Empresa` -> `Empleados` -> `Proyectos` asignada totalmente en el *heap*, imprima el organigrama y libere minuciosamente cada nivel de memoria.

## Entrada
La primera línea contiene `NombreEmpresa CantidadEmpleados`.
Para cada empleado, una línea con `NombreEmpleado CantidadProyectos` seguida de los nombres de los proyectos.

Límites:
- 1 <= CantidadEmpleados <= 20
- 0 <= CantidadProyectos <= 10

## Salida
El reporte jerárquico de la empresa y, en la última línea, `Memoria liberada exitosamente en todos los niveles.`.

## Ejemplos
| Entrada | Salida |
| :--- | :--- |
| TechCorp 2<br>Ana 2 ProyectoAlpha ProyectoBeta<br>Luis 1 ProyectoGamma | Empresa: TechCorp<br>- Empleado: Ana (2 proyectos)<br>  * ProyectoAlpha<br>  * ProyectoBeta<br>- Empleado: Luis (1 proyectos)<br>  * ProyectoGamma<br>Memoria liberada exitosamente en todos los niveles. |
