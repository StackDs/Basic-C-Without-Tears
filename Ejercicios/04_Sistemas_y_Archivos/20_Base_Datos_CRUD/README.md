# Base de Datos Simple CRUD en Archivo Binario

Los sistemas de bases de datos relacionales y de almacenamiento plano utilizan archivos binarios estructurados para ofrecer operaciones fundamentales: **C**reate (Crear), **R**ead (Leer), **U**pdate (Actualizar) y **D**elete (Borrar). En sistemas de archivos, el borrado suele implementarse de forma lógica mediante una bandera (`activo = 0`), lo cual evita costosos reordenamientos del archivo físico.

Implementa un sistema de gestión persistente para registros de estudiantes en un archivo binario `estudiantes.bin` que soporte las siguientes operaciones ingresadas por código numérico:
- `1 id nombre promedio`: Crear/Insertar un nuevo registro de estudiante.
- `2 id`: Consultar y mostrar los datos del estudiante con dicho ID.
- `3 id nuevo_promedio`: Actualizar la calificación del estudiante con dicho ID.
- `4 id`: Borrado lógico del estudiante con dicho ID (marca `activo = 0`).
- `5`: Listar todos los estudiantes actualmente activos.
- `0`: Terminar la ejecución del programa.

## Entrada
Una secuencia de comandos numéricos con sus respectivos parámetros según la operación elegida, finalizada con el comando `0`.

Límites:
- 1 <= ID <= 1000
- Nombres de hasta 30 caracteres (sin espacios).
- 0.0 <= Promedio <= 10.0

## Salida
Para cada operación procesada, imprime el mensaje correspondiente:
- Para creación (`1`): `Estudiante guardado.`
- Para consulta (`2`): `ID: X | Nombre: N | Promedio: P` (con dos decimales) o `Estudiante no encontrado.` si no existe o está inactivo.
- Para actualización (`3`): `Promedio actualizado.` o `Estudiante no encontrado.`
- Para eliminación (`4`): `Estudiante eliminado.` o `Estudiante no encontrado.`
- Para listado (`5`): Imprime cada estudiante activo en una línea con formato `ID: X | Nombre: N | Promedio: P`. Si no hay estudiantes activos, imprime `No hay registros activos.`
- Para salir (`0`): `Fin del programa.`

## Ejemplos

| Entrada | Salida |
| :--- | :--- |
| 1 101 Juan 8.5<br>1 102 Maria 9.3<br>2 101<br>3 101 9.0<br>2 101<br>4 102<br>5<br>0 | Estudiante guardado.<br>Estudiante guardado.<br>ID: 101 &#124; Nombre: Juan &#124; Promedio: 8.50<br>Promedio actualizado.<br>ID: 101 &#124; Nombre: Juan &#124; Promedio: 9.00<br>Estudiante eliminado.<br>ID: 101 &#124; Nombre: Juan &#124; Promedio: 9.00<br>Fin del programa. |
