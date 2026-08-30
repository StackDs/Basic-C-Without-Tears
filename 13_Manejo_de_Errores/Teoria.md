# Módulo 13: Manejo de Errores (Aceptar que todo va a salir mal)

En lenguajes modernos como Python o Java, estás acostumbrado a que si algo falla, el programa entra en pánico y te lanza una "Excepción" gigante y roja en la cara informándote del error. C no es así de dramático (ni así de servicial). 

En C, si una función falla, a menudo se encoge de hombros, te devuelve un número extraño y sigue ejecutándose silenciosamente hasta que tu programa colapsa en un glorioso y confuso *Segmentation Fault*. Kernighan y Ritchie, en su infinita sabiduría, confían en que tú, el programador, eres un adulto responsable que verificará el resultado de cada operación crítica.

---

## 1. El Paradigma de Errores en C

### La Ausencia de Excepciones
En C **no hay bloques `try/catch` nativos** ni "errores que detienen el programa automáticamente". Si `malloc()` falla al pedir memoria a tu sistema operativo, simplemente te devuelve `NULL` y sigue de largo. Si intentas usar ese `NULL` en la siguiente línea, el sistema operativo asesinará tu programa. La responsabilidad de revisar si algo falló recae única y exclusivamente en ti.

### El flujo estándar (`stderr`)
¿Recuerdas el módulo de Input/Output? Los mensajes de error **jamás** se imprimen con un simple `printf()`. `printf` escupe datos en el flujo de salida estándar (`stdout`), el cual puede estar siendo redirigido a un archivo de texto por el usuario (o entubado a otro programa). Si tienes un error crítico, debes gritarlo por el flujo de errores estándar (`stderr`) usando `fprintf`.
```c
fprintf(stderr, "Error catastrófico: El puntero era NULL.\n");
```

---

## 2. Patrones de Códigos de Retorno (Return Codes)

Como no hay excepciones, C usa el valor de retorno de las funciones para avisarte si hubo éxito o tragedia. Existen tres estándares de la industria para esto:

### Retorno Booleano / Entero
La función devuelve `0` (o `true`/`false` si usas `<stdbool.h>`) si todo salió bien, y `-1` (o un código de error específico) si algo falló.
```c
int iniciar_sistema(void);

if (iniciar_sistema() == -1) {
    fprintf(stderr, "El sistema no pudo iniciar.\n");
    // Manejar el error
}
```

### Retorno de Punteros (`NULL`)
Si la función debe devolver un puntero (como `fopen` al abrir un archivo, o `malloc` al pedir memoria), devolverá una dirección de memoria válida en caso de éxito, y el macro `NULL` en caso de fallo.
```c
FILE *archivo = fopen("datos.txt", "r");
if (archivo == NULL) {
    fprintf(stderr, "Oye, ese archivo no existe.\n");
}
```

### Paso de parámetros por referencia
¿Qué pasa si tu función necesita devolver un dato útil *Y* un código de error al mismo tiempo? (Recuerda, en C solo puedes hacer un solo `return`). El truco de la industria está en devolver el dato modificando un puntero, y usar el `return` real para el código de estado.
```c
int leer_sensor(float *resultado) {
    if (sensor_desconectado) return -1; // Fallo
    *resultado = 25.5; // Dato útil (Enviado por referencia)
    return 0; // Éxito
}
```

---

## 3. La variable global `errno` (`<errno.h>`)

Vale, la función devolvió `-1` o `NULL`. Pero, ¿*por qué* falló? ¿Se acabó la memoria? ¿Faltan permisos? ¿El archivo estaba bloqueado? Aquí entra el salvavidas del estándar POSIX y de la librería de C: `errno`.

### ¿Qué es `errno`?
Es una variable global "oculta" que el Sistema Operativo y la librería estándar utilizan para comunicar qué salió mal. Cuando una función estándar falla, escribe un número entero en `errno` que representa el error específico.

### Regla de uso
**Solo tiene sentido evaluar `errno` inmediatamente después de que una función haya fallado** (es decir, luego de comprobar que retornó `NULL` o `-1`). 
Si `fopen` te devuelve un puntero válido, NO mires `errno`. Podría contener "basura" de un error que ocurrió hace 10 minutos en otra función y que fue manejado correctamente.

### Reinicio manual
Las funciones exitosas **no** limpian el valor de `errno` por arte de magia. Por eso, es una buena práctica reiniciar explícitamente `errno = 0;` antes de ejecutar una operación crítica, para estar absolutamente seguro de que si `errno` cambia a un valor distinto de cero, fue por culpa exclusiva de la operación que acabas de ejecutar.

---

## 4. Traducción de Errores a texto humano

A menos que seas una suerte de autómata, no sabes de memoria qué significa el "Error 2" (`ENOENT`) o el "Error 13" (`EACCES`). Afortunadamente, C nos da herramientas para traducirlos.

### Uso de `perror()` (`<stdio.h>`)
Es la forma más rápida y perezosa. Imprime un mensaje personalizado tuyo a `stderr`, seguido automáticamente por dos puntos y la descripción en texto del error actual alojado en `errno`.
```c
FILE *f = fopen("no_existo.txt", "r");
if (f == NULL) {
    perror("Fallo al abrir archivo"); 
    // Imprimirá en consola: 
    // Fallo al abrir archivo: No such file or directory
}
```

### Uso de `strerror()` (`<string.h>`)
La forma avanzada y elegante. Recibe el número de error (tu querido `errno`) y devuelve una cadena de texto (string) con la descripción de ese error. Esto te permite formatear el mensaje como te dé la gana.
```c
fprintf(stderr, "Error crítico %d: %s\n", errno, strerror(errno));
```

---

## 5. Terminación Controlada (`<stdlib.h>`)

A veces, el error es simplemente insalvable. Si tu programa de cálculo de nóminas no puede abrir la base de datos de los empleados, no tiene sentido seguir ejecutándose. El programa debe morir.

### La función `exit()`
Te permite asesinar tu programa desde *cualquier* parte o función, de forma inmediata. No tienes que hacer una cadena ridícula de `returns` y validaciones hasta llegar de vuelta a la función `main()`. Llamas a `exit()` y se acabó.

### Códigos de salida
Cuando matas tu programa, debes avisarle al Sistema Operativo si lo mataste por causas naturales o por una tragedia. Para eso usamos los macros estándar:
* `exit(EXIT_SUCCESS);` (Equivalente a devolver `0` en el `main`). Significa que todo terminó pacíficamente y como se esperaba.
* `exit(EXIT_FAILURE);` (Equivalente a devolver `1`). Le grita al SO que el programa se cerró debido a un error crítico o catástrofe.

---

## 6. Aserciones y Contratos (`<assert.h>`)

Esto es una herramienta exclusiva para ti, el programador, durante tus madrugadas de desarrollo. **No es para interactuar con los usuarios**.

### Uso de `assert(condición)`
Un `assert` verifica que una condición sea verdadera. Si es falsa, detiene el programa violentamente de un hachazo y te imprime en la consola la línea exacta de código y el archivo de texto donde falló la condición.
```c
#include <assert.h>

void procesar_datos(int *datos) {
    assert(datos != NULL); // Si enviaste NULL, el programa muere AQUÍ MISMO.
    // ...
}
```

Muy util cuando estas depurando el codigo y buscando ciertos errores que hacen que tu programa se comporte de forma inesperada.

### El propósito
Los asertos sirven para detectar errores de lógica y atrapar tus propios bugs. Sirven para decir: *"Es matemáticamente imposible que esta variable sea negativa en este punto, y si lo es, es que programé algo mal"*. 
**NUNCA** uses `assert` para manejar errores del usuario (como que el usuario ingrese una letra en lugar de un número en un menú). Para los usuarios usas un triste `if` y le muestras un mensaje amigable. El `assert` es un botón de autodestrucción diseñado para ti.

### Desactivación (`NDEBUG`)
Lo hermoso de `assert` es que cuando terminas tu programa y estás listo para compilar la versión de producción que entregarás a los clientes (versión "Release"), puedes decirle al compilador que ignore todos los `assert` del código definiendo el macro `NDEBUG` antes de compilar (usualmente con la bandera `-DNDEBUG` en gcc). Así no afectas ni ralentizas el rendimiento del programa final.

---

## 7. Saltos no locales (El "Try-Catch" primitivo de C) - Opcional/Avanzado

C tiene un lado oscuro escondido en la librería `<setjmp.h>`. 

A través de las funciones `setjmp` y `longjmp`, puedes guardar un "punto de control" (checkpoint) del estado del CPU y los registros en un punto específico de tu programa. Si ocurre un error profundo a 15 niveles de funciones de distancia, puedes hacer un `longjmp` y "teletransportarte" mágicamente de regreso a ese punto de control inicial.

**Advertencia:** Mencionamos esto para que sepas que existe, porque Kernighan y Ritchie lo documentaron en el libro en el cual se basa este curso. Su uso es extremadamente de nicho (útil si estás programando tu propio intérprete de un lenguaje o un sistema operativo). Si lo usas en un programa normal, generarás el peor código espagueti imaginable, violarás todas las reglas lógicas del flujo de un programa, e invocarás demonios antiguos que corromperán tu memoria. Mantente alejado a menos que sepas exactamente lo que haces o al menos hasta que tengas un poco mas de experiencia con el lenguaje.
