#include <stdio.h>
#include <string.h>

struct Empleado {
    char nombre[50];
    int edad;
    float salario;
};

int main(void){
    printf("\n=== 1 y 2. Introduccion, Acceso e Inicializacion ===\n");
    // Inicializacion campo por campo
    struct Empleado emp1;
    strcpy(emp1.nombre, "Juan Perez");
    emp1.edad = 30;
    emp1.salario = 1500.50;
    
    // Inicializacion rapida
    struct Empleado emp2 = {"Jane Doe", 28, 2100.75};
    
    // Copia directa
    struct Empleado emp_clon = emp2;
    printf("Empleado 1: %s, %d anos, $%.2f\n", emp1.nombre, emp1.edad, emp1.salario);
    printf("Empleado Clon (Copia de emp2): %s, %d anos\n", emp_clon.nombre, emp_clon.edad);

    return 0;
}
