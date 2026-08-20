/**
 * ============================================================================
 * Curso de C - Módulo 00: Introducción
 * Archivo: 01_Sintaxis.c
 * Propósito: El clásico "hello, world" comentado al extremo para entender
 *            cada elemento sintáctico y el "choque cultural" de C.
 * ============================================================================
 */

/* 
 * 1. DIRECTIVAS DEL PREPROCESADOR:
 * En C, las líneas que comienzan con '#' son procesadas por el preprocesador antes 
 * de la compilación real.
 * '#include' le indica al preprocesador que inserte textualmente el contenido de otro archivo.
 * Aquí incluimos <stdio.h> (Standard Input/Output Header), que contiene la declaración
 * de funciones estándar de entrada/salida como 'printf'. Sin esta cabecera, el
 * compilador no sabría qué argumentos recibe ni qué retorna 'printf'.
 */
#include <stdio.h> // <--- Las cabeceras del sistema van entre ángulos '< >'

/*
 * 2. LA FUNCIÓN PRINCIPAL (main):
 * Todo programa ejecutable en C debe tener obligatoriamente una función llamada 'main'.
 * Es el punto de entrada exclusivo: aquí es donde el sistema operativo inicia la ejecución.
 * 
 * - 'int': Es el tipo de dato que retorna la función (un número entero). Al finalizar, 
 *   'main' le devolverá este entero al sistema operativo para informarle del estado de ejecución.
 * - 'void' dentro de los paréntesis: Le dice explícitamente al compilador que esta función
 *   no espera recibir ningún argumento desde la consola en su llamada más básica.
 */
int main(void) 
{
    /* 
     * 3. BLOQUES DE CÓDIGO (Llaves):
     * Las llaves '{' y '}' delimitan un bloque de código o el cuerpo de una función.
     * A diferencia de Python, donde el bloque se define mediante indentación (espacios),
     * en C la indentación es puramente estética y para legibilidad humana. 
     * Sin embargo, mantener un estilo limpio es crítico para la mantenibilidad.
     */

    /*
     * 4. LLAMADA A FUNCIONES:
     * Invocamos a la función de la biblioteca estándar 'printf' pasándole un argumento:
     * una cadena de caracteres constante (string literal o string constant).
     * En C, los strings se delimitan obligatoriamente por comillas dobles ("..."). 
     * Las comillas simples ('...') se reservan estrictamente para caracteres individuales ('char').
     */
    printf("hello, world\n");

    /*
     * 5. EL SALTO DE LÍNEA Y SECUENCIAS DE ESCAPE:
     * '\n' es la notación en C para el carácter de nueva línea (newline). 
     * 'printf' nunca suministra un salto de línea automáticamente (choque cultural con Python).
     * Si llamaras a printf("hello, "); y luego a printf("world"); sin '\n', se imprimiría 
     * todo junto en la misma línea ("hello, world").
     * La barra invertida '\' inicia una secuencia de escape para caracteres difíciles de escribir
     * (como '\t' para tabuladores o '\\' para la propia barra invertida).
     */

    /*
     * 6. EL PUNTO Y COMA (;):
     * En C, el punto y coma ';' es un terminador de sentencias obligatorio. 
     * Cada instrucción ejecutable individual debe finalizar con ';'. Olvidar uno es el error 
     * de compilación más común del lenguaje.
     */

    /*
     * 7. ESTADO DE RETORNO:
     * Dado que 'main' está definida para retornar un 'int', debemos finalizar con 'return'.
     * Por estándar ANSI C (y UNIX), retornar '0' indica que el programa se ejecutó
     * de manera exitosa y finalizó sin inconvenientes. Cualquier otro valor (como 1 o -1) 
     * se interpreta como un código de error o comportamiento inusual en la terminal.
     */
    return 0;
}
