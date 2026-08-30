# Módulo 14: Operaciones a Nivel de Bits (O cómo hablarle al procesador en su idioma natal)

Si has llegado hasta aquí, Felicidades: ya sabes programar en C a un nivel decente. Pero Kernighan y Ritchie no crearon este lenguaje solo para que pudieras sumar enteros e imprimir "Hola Mundo" en la consola; lo crearon para escribir sistemas operativos (UNIX, para ser exactos). Y si quieres dominar el hardware real, leer sensores, escribir drivers o programar microcontroladores, tienes que ensuciarte las manos. Tienes que bajar al barro y manipular los mismísimos unos y ceros. 

Bienvenidos al nivel más bajo de un sistema: los bits.

---

## 1. Fundamentos: El Sistema Binario y Tipos de Datos

Antes de manipular bits, hay que entender cómo demonios los guarda tu computadora.

### El mapa de bits
A tu procesador no le importan tus letras ni tus números decimales. Todo se guarda en base 2. Un número entero como el `5` no es un "5" mágico en la memoria; es una secuencia de interruptores encendidos y apagados: `0000 0101`. Cada uno de esos interruptores es un **bit**.

Información acerca de representación de números en binario la puedes encontrar en el módulo de **tipos de datos**.


### La regla de oro del `unsigned`
Si vas a hacer operaciones de bits, **jamás** utilices variables con signo (`int`, `char`, `short`). Siempre, absolutamente siempre, usa tipos sin signo (como `unsigned int`, o mejor aún, los de `<stdint.h>` como `uint8_t` o `uint32_t`). 
¿Por qué? Porque el bit más a la izquierda en los tipos con signo es el infame **bit de signo** (que indica si el número es negativo o positivo). Hacer operaciones de bits con un número negativo te llevará a un mundo de dolor, comportamiento indefinido y resultados matemáticos absurdos que varían según el compilador. No te busques problemas.

### Representación Hexadecimal (`0x`)
Escribir `0011 1100 1111 0000` en el código es un infierno visual y propenso a errores. Por eso usamos el sistema hexadecimal (base 16). 
Su magia radica en que **1 dígito hexadecimal equivale exactamente a 4 bits** (lo que llamamos un *nibble*). Así que puedes agruparlos mentalmente:
* `1111` en binario = `F` en hexadecimal.
* `0000` en binario = `0` en hexadecimal.
En C, cualquier número precedido por `0x` es hexadecimal. Así que en lugar de la cadena en binario de arriba la podemos escribir elegantemente como `0x3CF0`. Acostúmbrate a leer código en "hex".

---

## 2. Los 6 Operadores a Nivel de Bits

Es **crucial** que dejes de confundir a estos operadores con los operadores lógicos (`&&`, `||`, `!`) que viste en el módulo de Control de Flujo. Los operadores lógicos evalúan la verdad de una expresión completa. Los operadores a nivel de bits evalúan **bit por bit**, de forma paralela.

1. **AND a nivel de bits (`&`)**: Devuelve `1` solo si *ambos* bits son `1`. Funciona como un **filtro**.
2. **OR a nivel de bits (`|`)**: Devuelve `1` si *al menos uno* de los bits es `1`. Funciona como una **fusión**.
3. **XOR a nivel de bits (`^`)**: (OR Exclusivo). Devuelve `1` solo si los bits son *diferentes*. Funciona como una **alternancia**.
4. **NOT a nivel de bits (`~`)**: Es el único operador unario. Invierte todos los bits (los `0` pasan a `1` y los `1` pasan a `0`).
5. **Desplazamiento a la Izquierda (`<<`)**: Empuja todos los bits hacia la izquierda, rellenando con ceros a la derecha. (Matemáticamente es equivalente a multiplicar el número por potencias de 2).
6. **Desplazamiento a la Derecha (`>>`)**: Empuja todos los bits hacia la derecha. (Matemáticamente equivale a dividir por potencias de 2).

---

## 3. Máscaras de Bits (Bitmasking)

Este es el concepto central de todo el módulo. Imagina que tienes 8 bits y quieres modificar el tercero, pero **sin alterar** a sus siete vecinos inocentes. Para eso fabricas una "máscara".

### Creación de Máscaras
Usamos el operador de desplazamiento a la izquierda (`<<`) para crear máscaras dinámicamente. Queremos tomar un miserable `1` y empujarlo hacia la izquierda hasta la posición deseada:
`1 << 3` toma el número binario `00000001` y empuja el uno 3 veces, creando la máscara `00001000`. Con esta máscara en mano, ya tienes tu mira láser apuntando exactamente al cuarto bit (recuerda que empezamos a contar desde la posición 0).

### Macros para Máscaras (Buenas prácticas)
Ver en el código un `variable | (1 << 4)` no te dice absolutamente nada sobre el propósito de esa operación. Son los odiados "números mágicos". La forma correcta de programar en C es crear un macro:
```c
#define BIT_LED_ROJO (1 << 4)

// Más adelante en tu código...
estado |= BIT_LED_ROJO; // Ahora sé que estás encendiendo un LED.
```

---

## 4. Las 4 Operaciones Clásicas (El "CRUD" de los bits)

Si quieres que te tomen en serio en la industria, debes memorizarte estos 4 patrones sagrados. Son los que usarás todos los días.

* **Encender un bit (Set)**: Usas `OR`. 
  `variable |= (1 << posicion);`
  Sin importar en qué estado estuviera el bit antes, ahora será un `1`. Los demás quedan igual.
* **Apagar un bit (Clear)**: Usas `AND` en combinación con `NOT`. 
  `variable &= ~(1 << posicion);`
  Esto invierte tu máscara (convirtiendo los `0` en `1` y el `1` en `0`) y hace un filtro agresivo que asesina tu bit objetivo y deja en paz al resto.
* **Alternar un bit (Toggle)**: Usas `XOR`. 
  `variable ^= (1 << posicion);`
  Si el bit estaba en `1`, pasa a `0`. Si estaba en `0`, pasa a `1`. Ideal para hacer parpadear cosas.
* **Comprobar un bit (Check)**: Usas `AND`. 
  `if (variable & (1 << posicion))`
  Evalúa si un bit específico está actualmente encendido (`1`).

---

## 5. Aplicaciones Prácticas y Empaquetado de Datos

¿Para qué sirve toda esta tortura mental en el mundo real?

### Banderas de Estado (Flags)
Imagina un sistema de archivos. Tiene permisos de Lectura, Escritura, y Ejecución. Podrías declarar 3 variables booleanas distintas que pesarían mínimo 3 bytes en total. O, podrías empaquetar esos 3 estados en los 3 primeros bits de un solo `unsigned char` (que pesa 1 byte). En sistemas con recursos limitados, ahorrar cada byte es vital.

### Matemáticas ultrarrápidas
Los circuitos aritméticos del procesador toman su tiempo para dividir o multiplicar. Pero desplazar bits es increíblemente rápido en hardware. Si estás en un bucle crítico, usar `x << 1` es mucho más rápido que `x * 2`. *(Nota: Los compiladores modernos de hoy, como `gcc -O3`, ya hacen esto por ti, pero hace un par de décadas esto separaba a los programadores experimentados de los novatos).*

### Comunicaciones y Redes
Cuando mandas datos por internet (paquetes TCP/IP), los protocolos están diseñados a medida del bit para ahorrar ancho de banda. Leer la cabecera de un paquete a menudo implica desempaquetar trozos de 3 o 4 bits agrupados dentro de un solo byte.

---

## 6. Campos de Bits en Structs (Bit-fields)

C te permite ser tan quisquilloso que puedes pedirle que un campo de un `struct` no ocupe los típicos 8, 16 o 32 bits, sino la cantidad exacta que a ti te dé la gana.

### Sintaxis
Le pones dos puntos y el número de bits que quieres que ocupe:
```c
struct Configuracion {
    unsigned int wifi_encendido : 1; // Solo usa 1 bit (0 o 1)
    unsigned int volumen        : 4; // Usa 4 bits (valores del 0 al 15)
};
```
### La gran limitación
Como el procesador de tu computadora solo puede acceder a la memoria byte por byte, no puedes pedirle la dirección en memoria de medio byte. Por lo tanto, **es ilegal crear un puntero que apunte hacia un campo de bits**. No intentes hacer `&config.wifi_encendido` o el compilador se reirá en tu cara.

---

## 7. Las "Trampas Mortales"

Finalmente, las 3 formas más comunes de arruinar tu programa con bits.

### Confusión Letal (`&` vs `&&`)
Usar un operador lógico (`&&`) en lugar de uno a nivel de bits (`&`).
Ejemplo: `3 & 4` te dará `0`. (Porque `0011 & 0100` no comparten ningún bit encendido).
Sin embargo, `3 && 4` te dará `1`. (Porque en C, el número 3 es "verdadero" y el 4 es "verdadero", y "Verdadero AND Verdadero" es "Verdadero"). Es un error de una sola tecla que te puede costar días de depuración.

### Desplazamientos con signo (Arithmetic vs Logical Shift)
¿Recuerdas la regla de oro del `unsigned`? Si tienes un número negativo y le aplicas el desplazamiento a la derecha `>>`, el estándar de C no especifica si debe rellenar los espacios vacíos con ceros (Logical Shift) o si debe clonar el bit de signo negativo para "preservar" la negatividad (Arithmetic Shift). Depende del humor del desarrollador de tu compilador. Para mantener un comportamiento predecible y estandarizado, usa `unsigned`, así te evitarás dolores de cabeza.

### Desbordamiento de Desplazamiento
Si tu variable `uint32_t` tiene 32 bits, intentar desplazarla a la izquierda 35 veces (`x << 35`) es matemáticamente estúpido y es considerado **Comportamiento Indefinido** (Undefined Behavior) por el estándar de C. Tu programa podría dar `0`, podría dar un número al azar, o podría abrir un agujero negro. Mantén tus desplazamientos dentro de los límites del tipo de dato.

Para ser sincero, es poca la experiencia que tengo trabajando con bits, sin embargo, logré recuperar una serie de ejemplos que te ayudarán a manejarlos mejor.

## 8. Llegaste a otra hoguera

Felicidades, lograste aprender casi todo lo que C tiene para ofrecerte, los siguientes módulos serán orientados a debug, que básicamente es el arte de encontrar y solucionar errores en el código, usando herramientas de depuración estándar.

De igual forma, más adelante verás la sintaxis y el uso práctico de una biblioteca llamada SDL que sirve para crear interfaces gráficas, videojuegos, animaciones y mucho más, todo esto usando C. A pesar de que C no es un lenguaje orientado a la creación de videojuegos, sigue siendo posible crear algo decente con la suficiente dedicación y a su vez, un proyecto de tal magnitud te dará mucha experiencia con el lenguaje. Tómate un descanso, un cigarro, una cerveza, lo que sea que te relaje.

Ha sido un largo camino y si llegaste hasta acá, te felicito por tu dedicación. No todas las personas son tan perseverantes con temas tan difíciles y abstractos, buena suerte, sigue aprendiendo y no te rindas. Nos vemos en el siguiente módulo.
