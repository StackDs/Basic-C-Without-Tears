
#include <stdio.h>
#include <stdlib.h>

struct Fraccion {
  long long num;
  long long den;
};

// Calcula el Maximo Comun Divisor
long long mcd(long long a, long long b) {
  a = llabs(a);
  b = llabs(b);
  while (b != 0) {
    long long temp = b;
    b = a % b;
    a = temp;
  }
  return a;
}

// Simplifica la fraccion y normaliza el signo al numerador
struct Fraccion simplificar(struct Fraccion f) {
  if (f.num == 0) {
    f.den = 1;
    return f;
  }
  long long divisor = mcd(f.num, f.den);
  f.num /= divisor;
  f.den /= divisor;

  if (f.den < 0) {
    f.num = -f.num;
    f.den = -f.den;
  }
  return f;
}

struct Fraccion sumar(struct Fraccion f1, struct Fraccion f2) {
  struct Fraccion r;
  r.num = f1.num * f2.den + f2.num * f1.den;
  r.den = f1.den * f2.den;
  return simplificar(r);
}

struct Fraccion restar(struct Fraccion f1, struct Fraccion f2) {
  struct Fraccion r;
  r.num = f1.num * f2.den - f2.num * f1.den;
  r.den = f1.den * f2.den;
  return simplificar(r);
}

int main(void) {
  struct Fraccion f1, f2;
  char op;

  if (scanf("%lld %lld %c %lld %lld", &f1.num, &f1.den, &op, &f2.num,
            &f2.den) == 5) {
    if (f1.den == 0 || f2.den == 0) {
      printf("Error: Denominador no valido.\n");
      return 0;
    }

    struct Fraccion res = (op == '+') ? sumar(f1, f2) : restar(f1, f2);

    if (res.den == 1) {
      printf("%lld\n", res.num);
    } else {
      printf("%lld/%lld\n", res.num, res.den);
    }
  }

  return 0;
}
