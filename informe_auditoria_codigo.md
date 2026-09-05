# 📋 Informe de Auditoría de Código — Basic-C-Without-Tears

**Fecha:** Septiembre 2026
**Revisor:** Auditoría técnica senior de código C (C99/C11)
**Alcance:** Todos los archivos `.c`, `.h` y `Makefile` en los módulos 00–15
**Total de archivos revisados:** 80 archivos fuente

---

## 1. Resumen Ejecutivo del Código

El código fuente del repositorio es **sólido en su gran mayoría**. Los ejemplos son compilables, bien segmentados y pedagógicamente efectivos. Las "3 Reglas de Oro" de memoria dinámica (validar, liberar, neutralizar) se cumplen de forma ejemplar en los módulos 08 y 09.

**Riesgos principales identificados:**

- **Comportamiento Indefinido (UB):** Se lee una variable local no inicializada y se imprime su valor en dos archivos distintos (módulos 01 y 05). Técnicamente es UB según el estándar.
- **Validación de `malloc` incompleta:** El módulo 09 (`05_matrices_dinamicas.c`) no valida los `malloc` internos de las filas, lo que podría causar un segfault silencioso.
- **`#include` innecesarios:** Varios archivos incluyen `<stdlib.h>` o `<string.h>` sin usarlos.
- **Firmas de `main` inconsistentes:** Algunos archivos usan `int main()` (implícitamente acepta cualquier argumento) en vez de `int main(void)`.
- **Falta de Makefiles:** Solo el módulo 12 tiene un Makefile. Ningún otro módulo provee uno.

### Estadísticas de hallazgos en código

| Categoría | Cantidad |
|---|---|
| 🔴 Comportamiento Indefinido / Memory Leak | 5 |
| 🟠 Mala Práctica | 8 |
| 🟡 Falta Claridad Pedagógica | 6 |
| 🔵 Código Incongruente con Teoría | 3 |
| **Total** | **22** |

---

## 2. Hallazgos por Carpeta / Módulo

---

### Módulo 01 — Tipos y Variables

---

- **Archivo:** [01_tipos_primitivos.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/01_Tipos_y_Variables/Codigo/01_tipos_primitivos.c)
- **Línea:** 40
- **Categoría:** Mala Práctica
- **Gravedad:** Baja
- **Descripción:** `printf("entero_corto: %d\n", entero_corto);` usa `%d` para un `short`. El especificador correcto es `%hd`. Funciona por promoción implícita a `int`, pero un estudiante de Python que está aprendiendo especificadores debería ver el correcto.
- **Sugerencia:**
```c
printf("entero_corto: %hd\n", entero_corto);
```

---

- **Archivo:** [01_tipos_primitivos.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/01_Tipos_y_Variables/Codigo/01_tipos_primitivos.c)
- **Línea:** 14–20
- **Categoría:** Falta Claridad Pedagógica
- **Gravedad:** Baja
- **Descripción:** El bloque de comentario tiene caracteres rotos (faltan tildes/acentos): "bsicos", "vlidos", "nmero", "precisin". Esto ocurre probablemente por un problema de encoding. Un estudiante podría pensar que es un error de compilación o de su editor.
- **Sugerencia:** Corregir a "básicos", "válidos", "número", "precisión" o bien usar las versiones sin tilde consistentemente (como hace el resto del curso).

---

- **Archivo:** [02_declaraciones_asignaciones.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/01_Tipos_y_Variables/Codigo/02_declaraciones_asignaciones.c)
- **Línea:** 38–40
- **Categoría:** Comportamiento Indefinido
- **Gravedad:** Crítica
- **Descripción:** Se imprime `variable_basura` sin inicializarla: `printf("Valor de variable_basura: %d\n", variable_basura);`. Leer una variable automática no inicializada es **comportamiento indefinido** según C11 §6.3.2.1. Si bien el propósito pedagógico es demostrar que C no inicializa variables, el código es técnicamente UB y `-Wall` producirá un warning. Un estudiante de Python, acostumbrado a que todo está inicializado, podría creer que el "valor basura" es un comportamiento definido y predecible.
- **Sugerencia:** Añadir un comentario explícito:
```c
// ⚠️ ADVERTENCIA INTENCIONAL: Leer esta variable sin inicializar es
// "Comportamiento Indefinido" (UB) en C. Lo hacemos aquí SOLO para
// demostrar que C no inicializa variables por ti como Python.
// Si compilas con -Wall, verás un warning. ¡Ese warning es tu amigo!
int variable_basura;
printf("Valor de variable_basura: %d (IMPREDECIBLE - UB)\n", variable_basura);
```

---

### Módulo 02 — Input/Output

---

- **Archivo:** [01_output_formatos.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/02_Input_Output/Codigo/01_output_formatos.c)
- **Línea:** 2
- **Categoría:** Mala Práctica
- **Gravedad:** Baja
- **Descripción:** `#include <string.h>` está incluido pero no se usa en ninguna parte del archivo. Puede confundir a un estudiante que piense que `string.h` es necesario para usar `printf` con `%s`.
- **Sugerencia:** Eliminar `#include <string.h>`.

---

### Módulo 05 — Arreglos y Matrices

---

- **Archivo:** [01_arreglos_1d.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/05_Arreglos_y_Matrices/Codigo/01_arreglos_1d.c)
- **Línea:** 6–7
- **Categoría:** Comportamiento Indefinido
- **Gravedad:** Crítica
- **Descripción:** Mismo problema que en módulo 01: se declara `int basura[3];` sin inicializar y se leen sus valores con `printf`. Es UB. El propósito pedagógico es válido pero el código viola el estándar.
- **Sugerencia:** Aplicar el mismo patrón de comentario advertencia que en módulo 01.

---

- **Archivo:** [01_arreglos_1d.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/05_Arreglos_y_Matrices/Codigo/01_arreglos_1d.c)
- **Línea:** 10
- **Categoría:** Falta Claridad Pedagógica
- **Gravedad:** Baja
- **Descripción:** Se declara `int edades[5] = {18, 22, 35, 40, 19};` pero nunca se usa ni se imprime. La variable `edades` queda huérfana.
- **Sugerencia:** Imprimir el arreglo o eliminar la declaración.

---

### Módulo 06 — Strings

---

- **Archivo:** [03_string_h.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/06_Strings/Codigo/03_string_h.c)
- **Línea:** 11–12
- **Categoría:** Falta Claridad Pedagógica
- **Gravedad:** Media
- **Descripción:** `strncpy` se usa correctamente con `destino[19] = '\0'`, pero falta un comentario que explique *por qué* — `strncpy` **no** pone el nulo si la fuente es más larga que `n`. Para un estudiante de Python, donde `texto[:19]` simplemente funciona, este es el tipo de trampa que merece un comentario más enfático.
- **Sugerencia:**
```c
strncpy(destino, origen, 19);
// ⚠️ TRAMPA DE strncpy: Si el texto fuente es más largo que 19 chars,
// strncpy NO agrega el '\0' al final. Debes hacerlo tú manualmente.
// En Python harías simplemente: destino = origen[:19] y listo.
destino[19] = '\0';
```

---

### Módulo 08 — Punteros

---

- **Archivo:** [01_fundamentos_tamanos.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/08_Punteros/Codigo/01_fundamentos_tamanos.c) y [02_desreferenciacion.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/08_Punteros/Codigo/02_desreferenciacion.c)
- **Línea:** 2
- **Categoría:** Mala Práctica
- **Gravedad:** Baja
- **Descripción:** `#include <stdlib.h>` está incluido pero no se usa en ninguno de los dos archivos.
- **Sugerencia:** Eliminar la línea en ambos archivos.

---

- **Archivo:** [07_punteros_funciones.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/08_Punteros/Codigo/07_punteros_funciones.c)
- **Línea:** 3, 7, 12
- **Categoría:** Mala Práctica
- **Gravedad:** Media
- **Descripción:** Las funciones `saludar()` y `despedir()` usan paréntesis vacíos `()` en su definición y en la firma del callback `void (*func)()`. En C, `()` significa "acepta un número indeterminado de argumentos" (a diferencia de C++ donde significa "sin argumentos"). La forma correcta es `(void)`.
- **Sugerencia:**
```c
void saludar(void){ ... }
void despedir(void){ ... }
void ejecutar_callback(void (*func)(void)){ ... }
```

---

### Módulo 09 — Memoria Dinámica

---

- **Archivo:** [04_calloc_vs_malloc.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/09_Memoria_Dinamica/Codigo/04_calloc_vs_malloc.c)
- **Línea:** 7–14
- **Categoría:** Mala Práctica
- **Gravedad:** Media
- **Descripción:** No se valida el retorno de `malloc` ni de `calloc` antes de usarlos. No se neutralizan los punteros tras `free()`. Este archivo **contradice las "3 Reglas de Oro"** que el propio módulo enseña.
- **Sugerencia:**
```c
int *basura = malloc(5 * sizeof(int));
int *limpio = calloc(5, sizeof(int));
if (basura == NULL || limpio == NULL) {
    free(basura); free(limpio); // free(NULL) es seguro
    return 1;
}
// ... uso ...
free(basura); basura = NULL;
free(limpio); limpio = NULL;
```

---

- **Archivo:** [05_matrices_dinamicas.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/09_Memoria_Dinamica/Codigo/05_matrices_dinamicas.c)
- **Línea:** 10–14
- **Categoría:** Comportamiento Indefinido / Memory Leak
- **Gravedad:** Crítica
- **Descripción:** No se valida el `malloc` del puntero principal ni los `malloc` internos de las filas. Si un `malloc` interno falla, se produce segfault y las filas previas quedan como memory leak. Este es el archivo más importante del módulo.
- **Sugerencia:**
```c
int **matriz = malloc(filas * sizeof(int *));
if (matriz == NULL) { return 1; }
for (int i = 0; i < filas; i++) {
    matriz[i] = malloc(columnas * sizeof(int));
    if (matriz[i] == NULL) {
        for (int k = 0; k < i; k++) free(matriz[k]);
        free(matriz);
        return 1;
    }
}
```

---

- **Archivo:** [06_structs_dinamicos.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/09_Memoria_Dinamica/Codigo/06_structs_dinamicos.c)
- **Línea:** 19–20
- **Categoría:** Falta Claridad Pedagógica
- **Gravedad:** Media
- **Descripción:** `char *texto = "Linus Torvalds";` sin `const`. Un estudiante de Python podría intentar modificar `texto[0]` y obtener un segfault. Además, no se valida el `malloc` interno de `estudiante->nombre`.
- **Sugerencia:** Usar `const char *texto` y validar el `malloc` interno.

---

### Módulo 10 — Archivos

---

- **Archivo:** Todos los `.c` del módulo (01–05)
- **Categoría:** Código Incongruente con Teoría
- **Gravedad:** Baja
- **Descripción:** Todos usan `int main()` en vez de `int main(void)`. Inconsistente con el resto del curso.
- **Sugerencia:** Cambiar a `int main(void)`.

---

- **Archivo:** [04_binario_lectura.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/10_Archivos/Codigo/04_binario_lectura.c)
- **Línea:** 19
- **Categoría:** Mala Práctica
- **Gravedad:** Media
- **Descripción:** No se valida el retorno de `fread`. Si lee menos structs de los esperados, se imprimiría basura como datos válidos.
- **Sugerencia:** `size_t leidos = fread(...); if (leidos != 3) { ... }`

---

### Módulo 11 — Modularidad y Headers

---

- **Archivo:** [01_main.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/11_Modularidad_y_Headers/Codigo/01_main.c)
- **Línea:** 11–14
- **Categoría:** Código Incongruente con Teoría
- **Gravedad:** Media
- **Descripción:** El comentario dice `el código real vive en "sintaxis.c"` y la instrucción de compilación dice `gcc main.c sintaxis.c`. Sin embargo, el archivo real se llama `02_motor.c`. **Residuo de la refactorización** que engañará al estudiante.
- **Sugerencia:** Actualizar a `gcc 01_main.c 02_motor.c -o juego`.

---

### Módulo 12 — Makefiles

---

- **Archivo:** [Makefile](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/12_Makefiles/Codigo/Makefile)
- **Línea:** 10
- **Categoría:** Código Incongruente con Teoría
- **Gravedad:** Baja
- **Descripción:** El comentario menciona `sintaxis.o` pero la regla usa `02_saludo.o`. Residuo de refactorización.

---

- **Archivo:** [Makefile](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/12_Makefiles/Codigo/Makefile)
- **Línea:** 26
- **Categoría:** Falta Claridad Pedagógica
- **Gravedad:** Baja
- **Descripción:** La regla `clean` solo borra `.o` pero no el ejecutable `programa`.
- **Sugerencia:** `rm -f *.o programa`

---

### Módulo 13 — Manejo de Errores

---

- **Archivo:** [02_punteros_null.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/13_Manejo_de_Errores/Codigo/02_punteros_null.c)
- **Línea:** 9
- **Categoría:** Mala Práctica
- **Gravedad:** Baja
- **Descripción:** `(int*)malloc(...)` — Cast innecesario de `malloc` en C. El resto del curso (módulos 08, 09) correctamente **no** castea. Inconsistencia.
- **Sugerencia:** `int *ptr = malloc(tamano * sizeof(int));`

---

### Módulo 15 — Debug

---

- **Archivo:** [02_memory_leak.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/15_Debug/Codigo/02_memory_leak.c) y [03_out_of_bounds.c](file:///home/stack/Escritorio/Basic-C-Without-Tears/Modulos/15_Debug/Codigo/03_out_of_bounds.c)
- **Línea:** 21 y 20 respectivamente
- **Categoría:** Mala Práctica
- **Gravedad:** Baja
- **Descripción:** Mismo cast innecesario de `malloc`. Inconsistente con el resto del curso.
- **Sugerencia:** Quitar los casts `(int*)`.

---

## 3. Sugerencias Generales para el Código

### 3.1 Makefiles faltantes

Solo el **módulo 12** tiene un Makefile. Se recomienda agregar uno al menos para:

- **Módulo 11** (requiere compilar `01_main.c` y `02_motor.c` juntos)
- **Módulo 10** (los archivos tienen dependencias de ejecución secuencial)

### 3.2 Flags de compilación

El Makefile del módulo 12 usa `-Wall -Wextra -Werror -g` ✅. Se recomienda documentar en el README principal que los estudiantes **siempre** compilen con al menos: `gcc -Wall -Wextra -g archivo.c -o archivo`.

### 3.3 Consistencia de firmas `main`

Estandarizar **todas** las firmas a `int main(void)` (módulos 10 y 11 usan `int main()`).

### 3.4 Cast de `malloc`

Estandarizar la **ausencia** de cast en `malloc` en los módulos 13 y 15 para ser coherentes con los módulos 08 y 09.

### 3.5 Módulo 16 (GUI/SDL)

El directorio `Codigo/` está vacío. Agregar un placeholder o eliminar hasta tener contenido.

---

## Tabla Resumen

| Módulo | 🔴 UB/Leak | 🟠 Mala Práctica | 🟡 Claridad | 🔵 Incongruencia | Veredicto |
|---|---|---|---|---|---|
| 00 Introducción | 0 | 0 | 0 | 0 | ⭐⭐⭐⭐⭐ |
| 01 Tipos y Variables | 1 | 1 | 1 | 0 | ⭐⭐⭐⭐ |
| 02 Input/Output | 0 | 1 | 0 | 0 | ⭐⭐⭐⭐⭐ |
| 03 Control de Flujo | 0 | 0 | 0 | 0 | ⭐⭐⭐⭐⭐ |
| 04 Funciones | 0 | 0 | 0 | 0 | ⭐⭐⭐⭐⭐ |
| 05 Arreglos | 1 | 0 | 1 | 0 | ⭐⭐⭐⭐ |
| 06 Strings | 0 | 0 | 1 | 0 | ⭐⭐⭐⭐ |
| 07 Structs/Unions | 0 | 0 | 0 | 0 | ⭐⭐⭐⭐⭐ |
| 08 Punteros | 0 | 3 | 0 | 0 | ⭐⭐⭐⭐ |
| 09 Mem. Dinámica | 2 | 1 | 2 | 0 | ⭐⭐⭐ |
| 10 Archivos | 0 | 1 | 0 | 1 | ⭐⭐⭐⭐ |
| 11 Modularidad | 0 | 0 | 0 | 1 | ⭐⭐⭐⭐ |
| 12 Makefiles | 0 | 0 | 1 | 1 | ⭐⭐⭐⭐ |
| 13 Errores | 0 | 1 | 0 | 0 | ⭐⭐⭐⭐ |
| 14 Bits | 0 | 0 | 0 | 0 | ⭐⭐⭐⭐⭐ |
| 15 Debug | 0 | 2 | 0 | 0 | ⭐⭐⭐⭐ |

---

## Conclusión

La base de código es de **alta calidad pedagógica**. Los hallazgos críticos se concentran en el módulo 09 (Memoria Dinámica) y en demostraciones intencionales de variables no inicializadas.

**Top 5 correcciones prioritarias:**
1. Validar **todos** los `malloc` en `05_matrices_dinamicas.c`
2. Actualizar comentarios residuales de `sintaxis.c` en módulos 11 y 12
3. Estandarizar `int main(void)` en módulo 10
4. Eliminar casts de `malloc` en módulos 13 y 15
5. Agregar `(void)` a las firmas en `07_punteros_funciones.c`

**Calificación global del código: 4.3 / 5 ⭐**
