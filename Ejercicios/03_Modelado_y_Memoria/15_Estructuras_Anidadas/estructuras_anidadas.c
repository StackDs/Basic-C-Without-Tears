

#include <stdio.h>

struct Fecha {
  int dia;
  int mes;
  int anio;
};

struct Empleado {
  char nombre[50];
  double salario;
  struct Fecha contratacion;
};

int main(void) {
  struct Empleado emp;

  if (scanf("%49s %lf %d %d %d", emp.nombre, &emp.salario,
            &emp.contratacion.dia, &emp.contratacion.mes,
            &emp.contratacion.anio) == 5) {

    printf("Empleado: %s | Salario: $%.2f | Fecha de contratacion: "
           "%02d/%02d/%04d\n",
           emp.nombre, emp.salario, emp.contratacion.dia, emp.contratacion.mes,
           emp.contratacion.anio);
  }

  return 0;
}
