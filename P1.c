#include <stdio.h> //scanf y printf
#include <stdlib.h>
#include <math.h> //raiz cuadrada(sqrt), potencias(pow)

//Constante para los ejercicios 9, 10 y 12
#define PI 3.1416

/*Ejercicio 1 Predecir salidas*/
int Ej1_a() {
    printf("El numero es %d \n", 15);
    printf("El numero es %i \n", 15);
    printf("El numero es %x \n", 15);
    printf("El numero es %o \n", 15);
    printf("El numero es %e \n", 15);
    printf("El numero es %E \n", 15);
    return 0;
}

int Ej1_b() {
    char letra;
    letra = 'b';
    printf("Esta es %d or %c or %x\n", letra, letra, letra );
    return 0;
}

int Ej1_c(){
    float resultado;
    resultado = 2 * (3 + 5) / 8 - 3;
    printf("El resultado es %f. \n", resultado);
    return 0;
}

int Ej1() {
    printf("\nSalida del apartado a: \n"); Ej1_a();
    printf("\nSalida del apartado b: \n"); Ej1_b();
    printf("\nSalida del apartado b: \n"); Ej1_c();
    printf("\n");
    return 0;
}

/*Ejercicio2 Escribir constantes como distintos tipos de datos*/
int Ej2() {
    const char letra ='A';
    const int entero = 3;
    const float flotante = 3.3f;
    printf("Las constantes son %c , %d y %f. \n", letra ,entero ,flotante );
    return 0;
}

/*Ejercicio3 Leer datos y mostrarlos en pantalla*/
int Ej3() {
    char letra;
    int entero;
    float flotante;
    double flotante_doble;
    printf("Introduzca un char  : "); scanf("%c" ,&letra); scanf("%c");
    printf("Introduzca un int   : "); scanf("%d" ,&entero);
    printf("Introduzca un float : "); scanf("%f" ,&flotante);
    printf("Introduzca un double: "); scanf("%lf",&flotante_doble);

    printf("char introducido   : %c.\n", letra);
    printf("int introducido    : %d.\n", entero);
    printf("float introducido  : %f.\n", flotante);
    printf("double introducido : %f.\n", flotante_doble);
    return 0;
}

/*Ejercicio4 Leer un char y escribir su valor ASCII y el siguiente char.*/
int Ej4(){
    char letra;
    printf("\nIntroduzca un char  : ");
    scanf("%c",&letra);
    scanf("%c"); //Limpiar el \n que queda al pulsar enter
    printf("ASCII: %d ; Siguiente: %c \n", letra, letra+1);
    return 0;
}

/*Ejercicio5 tamaño en bytes de los tipos basicos*/
int Ej5(){
    printf("char  : %d\n", sizeof(char) );
    printf("int   : %d\n", sizeof(int) );
    printf("float : %d\n", sizeof(float) );
    printf("double: %d\n", sizeof(double) );
    return 0;
}

/*Ejercicio6 Valor de un polinomio ax^3+bx^2+cx+d introduciendo  x,a,b,c y d*/
int Ej6(){
    float x, a, b, c, d;
    printf("Introduzca x: "); scanf("%f",&x);
    printf("Introduzca a: "); scanf("%f",&a);
    printf("Introduzca b: "); scanf("%f",&b);
    printf("Introduzca c: "); scanf("%f",&c);
    printf("Introduzca d: "); scanf("%f",&d);
    printf("x=%f, a=%f, b=%f, c=%f, d=%f \n", x, a, b, c, d );
    float resultado = a*x*x*x + b*x*x + c*x + d;
    printf("ax^3 + bx^2 + cx + d = %f \n", resultado);
    return 0;
}

/*Ejercicio7 Leer 2 enteros y calcular sus operaciones matematicas basicas*/
int Ej7(){
    int a, b;
    printf("Introduzca a: "); scanf("%d", &a);
    printf("Introduzca b: "); scanf("%d", &b);
    printf("a+b     : %d \n", a+b);
    printf("a-b     : %d \n", a-b);
    printf("b-a     : %d \n", b-a);
    printf("a*b     : %d \n", a*b);
    printf("a/b     : %d \n", a/b);
    printf("a mod b : %d \n", a%b);
    printf("b/a     : %d \n", b/a);
    printf("b mod a : %d \n", b%a);
    return 0;
}

/*Ejercicio8 Leer 3 enteros y calcular su media aritmetica*/
int Ej8(){
    int a, b, c;
    printf("Introduzca a: "); scanf("%d", &a);
    printf("Introduzca b: "); scanf("%d", &b);
    printf("Introduzca c: "); scanf("%d", &c);
    printf("Media aritmetica: %f \n", (a+b+c)/3.0f);
    return 0;
}


/*Ejercicio9 Leer radio de circunferencia y mostrar, perimetro, area y volumen*/
int Ej9(){
    float r;
    printf("Introduzca el radio: "); scanf("%f", &r);
    printf("Perimetro de la circunferencia : %f \n", 2*PI*r );
    printf("Area del circulo               : %f \n", PI*PI*r );
    printf("Volumen de la esfera           : %f \n", (4/3.0f)*PI*r*r*r );
    return 0;
}

/*Ejercicio10 Periodo de un pendulo dado su longitud*/
int Ej10(){
    const float G = 9.8f;
    float L;
    printf("Introduzca la longitud del pendulo: "); scanf("%f", &L);
    printf("El periodo del pendulo es : %f \n", 2*PI*sqrt(L/G) );
    return 0;
}

/*Ejercicio11 Trabajar con potencias de un numero introducido*/
int Ej11(){
    float N;
    printf("Introduzca N: "); scanf("%f", &N);
    printf("N^2 : %f \n", pow(N,2) );
    printf("N^3 : %f \n", pow(N,3) );
    printf("2^N : %f \n", pow(2,N) );
    printf("3^N : %f \n", pow(3,N) );
    return 0;
}

/*Ejercicio12 Calcular la reactancia inductiva de una frecuencia*/
int Ej12(){
    float f, L;
    printf("Introduzca el valor de la frecuencia: "); scanf("%f", &f);
    printf("Introduzca el valor del inductor    : "); scanf("%f", &L);
    printf("Resistencia inducida(X_L): %f \n", 2*PI*f*L );
    return 0;
}

/*Ejercicio13 Conversor Celsius a Farenheit */
int Ej13(){
    float C;
    printf("Introduzca los grados Celsius(C): "); scanf("%f", &C);
    printf("Valor en grados farenheit    (F): %f \n", (9/5.0f)*C+32);
    return 0;
}

/*Ejercicio14 Salario neto con impuestos al 10% dado nº horas y precio/hora */
int Ej14(){
    float n, precioH;
    printf("Introduzca el numero de horas trabajadas: "); scanf("%f", &n);
    printf("Introduzca el salario/hora              : "); scanf("%f", &precioH);
    printf("Salario bruto : %f \n", (n*precioH) );
    printf("Salario neto  : %f \n", (n*precioH)*0.9 );
    //printf("Salario neto  : %f \n", (n*precioH)-(n*precioH)*0.1 );
    return 0;
}

/*Ejercicio15 Distancia euclidea entre dos puntos */
int Ej15(){
    float x1, y1, x2, y2;
    printf("Introduzca x1: "); scanf("%f", &x1);
    printf("Introduzca y1: "); scanf("%f", &y1);
    printf("Introduzca x2: "); scanf("%f", &x2);
    printf("Introduzca y2: "); scanf("%f", &y2);
    printf("Distancia de (%f,%f) a (%f,%f) : ", x1, y1, x2, y2 );
    printf("%f \n ", sqrt(pow(x2-x1, 2)+pow(y2-y1, 2)) );
    return 0;
}

/*Ejercicio16 Consumo y velocidad en coche */
int Ej16(){
    float distancia, precio, dinero, horas, minutos;
    printf("Distancia recorrida(Km)              : "); scanf("%f", &distancia);
    printf("Precio del combustible(centimos/l)   : "); scanf("%f", &precio);
    printf("Dinero gastado en gasolina(centimos) : "); scanf("%f", &dinero);
    printf("Tiempo gastado en el viaje(horas)    : "); scanf("%f", &horas);
    printf("Minutos añadidos sobre la ultima hora: "); scanf("%f", &minutos);
    horas = horas + (minutos/60);

    printf("Consumo de 100km(litros): %f \n", 100*(dinero/precio)/distancia);
    printf("Consumo de   1km(litros): %f \n", (dinero/precio)/distancia);
    printf("Consumo de 100km(euros) : %f \n", 100*(dinero/distancia)/100 );
    printf("Consumo de   1km(euros) : %f \n", (dinero/distancia)/100 );
    printf("Velocidad media(km/h)   : %f \n", distancia/horas );
    printf("Velocidad media (m/s)   : %f \n", 1000*(distancia/horas)/3600 );
    return 0;
}

int Ej(){ return 0; }
int main() {
    int i;
    i=3;
    while (0<i && i<17) { //16 ejercicios
        printf("\nSeleccione un ejercicio (1-16) o salir: "); scanf("%d",&i);
        switch(i){
            case  1: Ej1() ; break;
            case  3: Ej3() ; break;
            case  2: Ej2() ; break;
            case  4: Ej4() ; break;
            case  5: Ej5() ; break;
            case  6: Ej6() ; break;
            case  7: Ej7() ; break;
            case  8: Ej8() ; break;
            case  9: Ej9() ; break;
            case 10: Ej10(); break;
            case 11: Ej11(); break;
            case 12: Ej12(); break;
            case 13: Ej13(); break;
            case 14: Ej14(); break;
            case 15: Ej15(); break;
            case 16: Ej16(); break;
        }
    }
    return 0;
}
