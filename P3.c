#include <math.h>
#include <stdio.h>
#include <stdlib.h>

#define PI 3.1416
#define ES_PAR(n) ((n) % 2 == 0)
#define SWAP(a, b, tipo) \
    do {                 \
        tipo temp = a;   \
        a = b;           \
        b = temp;        \
    } while (0)

/* ==========================================================
   DECLARACIÓN DE FUNCIONES DE LOS EJERCICIOS (1 al 21)
   ========================================================== */

/* 1. Cuadrante de un punto */
int obtener_cuadrante(float x, float y) {
    if (x == 0 || y == 0) return 0;
    if (x > 0 && y > 0) return 1;
    if (x < 0 && y > 0) return 2;
    if (x < 0 && y < 0) return 3;
    return 4;
}

int Ej01() {
    float x, y;
    printf("Introduce las coordenadas (x y): ");
    scanf("%f %f", &x, &y);
    printf("El punto está en el cuadrante: %d\n", obtener_cuadrante(x, y));
    return 0;
}

/* 2. Funciones geométricas */
float perimetro_circunferencia(float r) { return 2 * PI * r; }
float area_circulo(float r) { return PI * r * r; }
float volumen_esfera(float r) { return (4.0f / 3.0f) * PI * r * r * r; }

int Ej02() {
    float r;
    int opcion;
    printf("Introduce el radio: ");
    scanf("%f", &r);
    printf("1. Perímetro\n2. Área\n3. Volumen\nElige opción: ");
    scanf("%d", &opcion);

    switch (opcion) {
        case 1:
            printf("Perímetro: %.2f\n", perimetro_circunferencia(r));
            break;
        case 2:
            printf("Área: %.2f\n", area_circulo(r));
            break;
        case 3:
            printf("Volumen: %.2f\n", volumen_esfera(r));
            break;
        default:
            printf("Opción no válida.\n");
    }
    return 0;
}

/* 3. Menú y operaciones básicas */
int mostrar_menu_ej3() {
    int op;
    printf("\n1.-Sumar\n2.-Restar\n3.-Multiplicar\n4.-Dividir\n5.-Salir\n");
    printf("Seleccione la operación deseada: ");
    scanf("%d", &op);
    return op;
}

int Ej03() {
    int op;
    float d1, d2;
    do {
        op = mostrar_menu_ej3();
        if (op >= 1 && op <= 4) {
            printf("Introducir dato1 : ");
            scanf("%f", &d1);
            printf("Introducir dato2 : ");
            scanf("%f", &d2);
            switch (op) {
                case 1:
                    printf("Resultado %.2f\n", d1 + d2);
                    break;
                case 2:
                    printf("Resultado %.2f\n", d1 - d2);
                    break;
                case 3:
                    printf("Resultado %.2f\n", d1 * d2);
                    break;
                case 4:
                    if (d2 != 0)
                        printf("Resultado %.2f\n", d1 / d2);
                    else
                        printf("Error: División entre cero.\n");
                    break;
            }
        }
    } while (op != 5);
    return 0;
}

/* 4. Número de cifras */
int contar_cifras(int n) {
    if (n == 0) return 1;
    int cifras = 0;
    if (n < 0) n = -n;
    while (n > 0) {
        cifras++;
        n /= 10;
    }
    return cifras;
}

int Ej04() {
    int n;
    printf("Introduce un número entero: ");
    scanf("%d", &n);
    printf("Número de cifras: %d\n", contar_cifras(n));
    return 0;
}

/* 5. Producto por sumas, división por restas y macro */
int producto_sumas(int a, int b) {
    int res = 0;
    int veces = (b < 0) ? -b : b;
    for (int i = 0; i < veces; i++) res += a;
    return (b < 0) ? -res : res;
}

int division_restas(int a, int b) {
    if (b == 0) return 0;
    int cociente = 0;
    int negativo = (a < 0) ^ (b < 0);
    a = (a < 0) ? -a : a;
    b = (b < 0) ? -b : b;
    while (a >= b) {
        a -= b;
        cociente++;
    }
    return negativo ? -cociente : cociente;
}

int Ej05() {
    int n1, n2;
    for (int i = 1; i <= 10; i++) {
        printf("\nLectura %d:\n", i);
        printf("Introduce num1: ");
        scanf("%d", &n1);
        printf("Introduce num2: ");
        scanf("%d", &n2);

        if (ES_PAR(i)) {
            printf("Operación (División por restas): %d / %d = %d\n", n1, n2,
                   division_restas(n1, n2));
        } else {
            printf("Operación (Producto por sumas): %d * %d = %d\n", n1, n2,
                   producto_sumas(n1, n2));
        }
    }
    return 0;
}

/* 6. Análisis de punteros */
int Ej06() {
    int var = 42;
    int *ptr = &var;
    printf("a) Dirección de la variable: %p | Contenido: %d\n", (void *)&var,
           var);
    printf("b) Dirección del puntero   : %p | Contenido (dirección): %p\n",
           (void *)&ptr, (void *)ptr);
    printf("c) Valor referenciado (*ptr): %d\n", *ptr);
    return 0;
}

/* 7. Swap con punteros */
void swap(int *x, int *y) {
    int aux = *x;
    *x = *y;
    *y = aux;
}
int Ej07() {
    int a = 5, b = 10;
    printf("Antes: a = %d, b = %d\n", a, b);
    swap(&a, &b);
    printf("Después: a = %d, b = %d\n", a, b);
    return 0;
}

/* 8. Cálculo de intensidad */
void obtener_valores(float *r, float *v) {
    printf("Introduce resistencia (R): ");
    scanf("%f", r);
    printf("Introduce voltaje (V)    : ");
    scanf("%f", v);
}
float calcular_intensidad(float r, float v) {
    if (r == 0) return 0;
    return v / r;
}
void imprimir_respuesta(float intensidad) {
    printf("La intensidad calculada (I) es: %.2f A\n", intensidad);
}
int Ej08() {
    float res, vol, intensidad;
    obtener_valores(&res, &vol);
    intensidad = calcular_intensidad(res, vol);
    imprimir_respuesta(intensidad);
    return 0;
}

/* 9. Factorial y Fibonacci */
long long factorial(int n) {
    long long f = 1;
    for (int i = 1; i <= n; i++) f *= i;
    return f;
}
void fibonacci_ref(int n, long long *resultado) {
    long long a = 0, b = 1, aux;
    printf("Fibonacci hasta el término %d: ", n);
    for (int i = 0; i < n; i++) {
        printf("%lld ", a);
        aux = a + b;
        a = b;
        b = aux;
    }
    printf("\n");
    *resultado = a;
}
int Ej09() {
    int n;
    printf("Introduce un número para factorial y fibonacci: ");
    scanf("%d", &n);
    long long fact = factorial(n);
    printf("Factorial de %d = %lld\n", n, fact);
    long long ultimo_fib;
    fibonacci_ref(n, &ultimo_fib);
    return 0;
}

/* 10. Función múltiplo */
int multiplo(int a, int b) {
    if (a == 0) return 0;
    return (b % a == 0) ? 1 : 0;
}
int Ej10() {
    int a, b;
    printf("Introduce pares de enteros (0 0 para salir):\n");
    while (1) {
        printf("Par (a b): ");
        scanf("%d %d", &a, &b);
        if (a == 0 && b == 0) break;
        if (multiplo(a, b))
            printf("%d es múltiplo de %d (1)\n", b, a);
        else
            printf("%d NO es múltiplo de %d (0)\n", b, a);
    }
    return 0;
}

/* 11. Mínimo de tres números reales */
float minimo_tres(float a, float b, float c) {
    float min = a;
    if (b < min) min = b;
    if (c < min) min = c;
    return min;
}
int Ej11() {
    float x, y, z;
    printf("Introduce tres números reales: ");
    scanf("%f %f %f", &x, &y, &z);
    printf("El menor es: %.2f\n", minimo_tres(x, y, z));
    return 0;
}

/* 12. Coeficiente binomial */
long long combinatorio(int m, int n) {
    if (n > m || n < 0) return 0;
    return factorial(m) / (factorial(n) * factorial(m - n));
}
int Ej12() {
    int m, n;
    printf("Introduce m y n (m sobre n): ");
    scanf("%d %d", &m, &n);
    printf("Coeficiente binomial C(%d, %d) = %lld\n", m, n, combinatorio(m, n));
    return 0;
}

/* 13. Cálculo de e */
double calcular_euler(int n_terminos) {
    double e = 0.0;
    for (int i = 0; i < n_terminos; i++) {
        e += 1.0 / factorial(i);
    }
    return e;
}
int Ej13() {
    int n;
    printf("Introduce términos para calcular e: ");
    scanf("%d", &n);
    printf("Valor aproximado de e = %.10f\n", calcular_euler(n));
    return 0;
}

/* 14. Factores primos con potencia */
int Ej14() {
    int n;
    printf("Introduce un entero positivo: ");
    scanf("%d", &n);
    if (n <= 1) {
        printf("Debe ser mayor que 1.\n");
        return 0;
    }
    printf("Descomposición de %d:\n", n);
    for (int i = 2; i <= n; i++) {
        int exp = 0;
        while (n % i == 0) {
            exp++;
            n /= i;
        }
        if (exp > 0) {
            printf("Primo: %i con potencia: %i\n", i, exp);
        }
    }
    return 0;
}

/* 15. Números perfectos menores que 1000 */
int suma_divisores(int numero) {
    int suma = 0;
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) suma += i;
    }
    return suma;
}
int Ej15() {
    printf("Números perfectos menores que 1000:\n");
    for (int i = 2; i < 1000; i++) {
        if (suma_divisores(i) == i) {
            printf("%d es perfecto\n", i);
        }
    }
    return 0;
}

/* 16. Números amigos */
void suma_divisores_ref(int numero, int *suma) {
    *suma = 0;
    for (int i = 1; i < numero; i++) {
        if (numero % i == 0) *suma += i;
    }
}
int Ej16() {
    int a, b;
    printf("Introduce dos números enteros positivos: ");
    scanf("%d %d", &a, &b);
    int suma_a, suma_b;
    suma_divisores_ref(a, &suma_a);
    suma_divisores_ref(b, &suma_b);
    if (suma_a == b && suma_b == a) {
        printf("%d y %d SÍ son números amigos.\n", a, b);
    } else {
        printf("%d y %d NO son números amigos.\n", a, b);
    }
    return 0;
}

/* 17. Cociente, residuo y dígitos espaciados */
int cociente_entero(int a, int b) { return a / b; }
int residuo_entero(int a, int b) { return a % b; }
int Ej17() {
    int n;
    printf("Introduce un entero entre 1 y 32767: ");
    scanf("%d", &n);
    if (n < 1 || n > 32767) {
        printf("Fuera de rango.\n");
        return 0;
    }
    int divisor = 1, temp = n;
    while (temp >= 10) {
        divisor *= 10;
        temp /= 10;
    }
    printf("Resultado: ");
    while (divisor > 0) {
        printf("%d  ", n / divisor);
        n %= divisor;
        divisor /= 10;
    }
    printf("\n");
    return 0;
}

/* 18. Redondeo al entero más cercano */
int redondear(float num) { return (int)(num >= 0 ? num + 0.5f : num - 0.5f); }
int Ej18() {
    float n;
    printf("Introduce un número real a redondear: ");
    scanf("%f", &n);
    printf("Original: %.2f -> Redondeado: %d\n", n, redondear(n));
    return 0;
}

/* 19. Ordenar tres números con macro SWAP */
int Ej19() {
    int x, y, z;
    printf("Introduce tres números: ");
    scanf("%d %d %d", &x, &y, &z);
    if (x > y) SWAP(x, y, int);
    if (x > z) SWAP(x, z, int);
    if (y > z) SWAP(y, z, int);
    printf("Ordenados: %d, %d, %d\n", x, y, z);
    return 0;
}

/* 20. Punteros a función */
int sumar_op(int a, int b) { return a + b; }
int restar_op(int a, int b) { return a - b; }
int mult_op(int a, int b) { return a * b; }
int div_op(int a, int b) { return (b != 0) ? a / b : 0; }
int opera(int a, int b, int (*operacion)(int, int)) { return operacion(a, b); }
int Ej20() {
    int a, b, op;
    printf("Introduce dos enteros: ");
    scanf("%d %d", &a, &b);
    printf("1. Sumar\n2. Restar\n3. Multiplicar\n4. Dividir\nElige: ");
    scanf("%d", &op);
    int (*func)(int, int) = NULL;
    switch (op) {
        case 1:
            func = sumar_op;
            break;
        case 2:
            func = restar_op;
            break;
        case 3:
            func = mult_op;
            break;
        case 4:
            func = div_op;
            break;
        default:
            printf("Opción inválida.\n");
            return 1;
    }
    printf("Resultado: %d\n", opera(a, b, func));
    return 0;
}

/* 21. Calendario mensual */
int calcular_dia_semana(int a, int m, int d) {
    int n;
    if (m == 1 || m == 2) {
        n = a + 31 * (m - 1) + d * (a - 1) / 4 - 3 * ((a + 99) / 100) / 4;
    } else {
        n = a + 31 * (m - 1) + d - (4 * m + 23) / 10 + a / 4 -
            (3 * (a / 100 + 1)) / 4 - 1;
    }
    return n % 7;
}
int dias_en_mes(int m, int a) {
    switch (m) {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            return 31;
        case 4:
        case 6:
        case 9:
        case 11:
            return 30;
        case 2:
            if ((a % 400 == 0) || (a % 4 == 0 && a % 100 != 0)) return 29;
            return 28;
        default:
            return 0;
    }
}
int Ej21() {
    int mes, anio;
    printf("Introduce mes y año (ej. 9 2004): ");
    scanf("%d %d", &mes, &anio);
    int primer_dia = calcular_dia_semana(anio, mes, 1);
    int col_inicio = (primer_dia == 0) ? 6 : primer_dia - 1;
    int total_dias = dias_en_mes(mes, anio);

    printf("\n L   M   X   J   V   S   D \n");
    int espacio = 0;
    for (int i = 0; i < col_inicio; i++) {
        printf("    ");
        espacio++;
    }
    for (int d = 1; d <= total_dias; d++) {
        printf("%3d ", d);
        espacio++;
        if (espacio % 7 == 0) printf("\n");
    }
    printf("\n");
    return 0;
}

/* ==========================================================
   BUCLE PRINCIPAL (MAIN)
   ========================================================== */
int main() {
    int opcion;

    do {
        printf("\n========================================\n");
        printf("       MENÚ DE PRÁCTICAS (1 - 21)       \n");
        printf("========================================\n");
        printf("  0.  Salir del programa\n");
        printf("  1.  Cuadrante de un punto\n");
        printf("  2.  Funciones geométricas\n");
        printf("  3.  Menú operaciones básicas\n");
        printf("  4.  Número de cifras\n");
        printf("  5.  Producto sumas / División restas\n");
        printf("  6.  Análisis de punteros\n");
        printf("  7.  Intercambio con punteros (Swap)\n");
        printf("  8.  Cálculo de intensidad (I = V/R)\n");
        printf("  9.  Factorial y Fibonacci\n");
        printf(" 10.  Función múltiplo\n");
        printf(" 11.  Mínimo de tres reales\n");
        printf(" 12.  Coeficiente binomial\n");
        printf(" 13.  Cálculo de e\n");
        printf(" 14.  Factores primos con potencia\n");
        printf(" 15.  Números perfectos (< 1000)\n");
        printf(" 16.  Números amigos\n");
        printf(" 17.  Cociente, residuo y dígitos\n");
        printf(" 18.  Redondeo al entero cercano\n");
        printf(" 19.  Ordenar 3 números con macro SWAP\n");
        printf(" 20.  Operaciones con punteros a función\n");
        printf(" 21.  Calendario mensual dinámico\n");
        printf("----------------------------------------\n");
        printf("Seleccione una opción: ");

        if (scanf("%d", &opcion) != 1) {
            printf(
                "\nError: Entrada no válida. Introduzca un número entero.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            opcion = -1;
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF);  // Limpiar buffer

        switch (opcion) {
            case 0:
                printf("\n¡Hasta pronto!\n");
                break;
            case 1:
                Ej01();
                break;
            case 2:
                Ej02();
                break;
            case 3:
                Ej03();
                break;
            case 4:
                Ej04();
                break;
            case 5:
                Ej05();
                break;
            case 6:
                Ej06();
                break;
            case 7:
                Ej07();
                break;
            case 8:
                Ej08();
                break;
            case 9:
                Ej09();
                break;
            case 10:
                Ej10();
                break;
            case 11:
                Ej11();
                break;
            case 12:
                Ej12();
                break;
            case 13:
                Ej13();
                break;
            case 14:
                Ej14();
                break;
            case 15:
                Ej15();
                break;
            case 16:
                Ej16();
                break;
            case 17:
                Ej17();
                break;
            case 18:
                Ej18();
                break;
            case 19:
                Ej19();
                break;
            case 20:
                Ej20();
                break;
            case 21:
                Ej21();
                break;
            default:
                printf("\nAviso: Opción incorrecta (1-21 o 0 para salir).\n");
                break;
        }

        if (opcion >= 1 && opcion <= 21) {
            printf("\nPresione [Enter] para volver al menú...");
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while (opcion != 0);

    return 0;
}