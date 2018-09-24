#include <stdio.h> //scanf y printf
#include <stdlib.h>
#include <math.h> //raiz cuadrada(sqrt), potencias(pow)

/*Ejercicio1 Leer entero y decir si es par o impar*/
int Ej01(){
    int n;
    printf("Introduzca un entero: "); scanf("%d",&n);
    if(n%2)
        printf("%d es impar\n", n);
    else
        printf("%d es par\n", n);
    return 0;
}

/*Ejercicio2 Mayor y el menor de 3 numeros, con el minimo de comparaciones*/
int Ej02(){
    int n1, n2, n3;
    printf("Introduzca un entero: "); scanf("%d",&n1);
    printf("Introduzca un entero: "); scanf("%d",&n2);
    printf("Introduzca un entero: "); scanf("%d",&n3);
    if(n1>n2){
        if(n2>n3){
            printf("Mayor : %d\n", n1);
            printf("Menor : %d\n", n3);
        }else if(n1>n3){ //Máximo 3 comparaciones
            printf("Mayor : %d\n", n1);
            printf("Menor : %d\n", n2);
        }else{
            printf("Mayor : %d\n", n3);
            printf("Menor : %d\n", n2);
        }
    }else{
        if(n1>n3) {
            printf("Mayor : %d\n", n2);
            printf("Menor : %d\n", n3);
        }else if (n2>n3) { //Máximo 3 comparaciones
            printf("Mayor : %d\n", n2);
            printf("Menor : %d\n", n1);
        }else{
            printf("Mayor : %d\n", n3);
            printf("Menor : %d\n", n1);
        }
    }
    return 0;
}

int Ej03(){
    float a,b,c;
    printf("Introduzca a: "); scanf("%f",&a);
    printf("Introduzca b: "); scanf("%f",&b);
    printf("Introduzca b: "); scanf("%f",&c);
    float root = b*b - 4*a*c;
    if (root<0.0f){
        printf("No existen raices reales \n");
    }else{
        printf("Raiz 1: %f \n", ( -b + sqrt(root))/ 2.0f*a );
        printf("Raiz 2: %f \n", ( -b - sqrt(root))/ 2.0f*a );
    }
    return 0;
}

int Ej04(){
    int a,b;
    printf("Introduzca a: "); scanf("%d",&a);
    printf("Introduzca b: "); scanf("%d",&b);
    if(a%b==0){ printf("a es divisible por b"); }
    if(b%a==0){ printf("b es divisible por a"); }
}

int Ej05(){
    float a,b;
    char op;
    printf("Introduzca a: "); scanf("%f",&a);
    printf("Introduzca b: "); scanf("%f",&b);
    printf("Introduzca operador(+, -, *, /):"); scanf("%c",&op); scanf("%c");
    switch (op) {
        case '+': printf("Resultado: %f ",a+b); break;
        case '-': printf("Resultado: %f ",a-b); break;
        case '*': printf("Resultado: %f ",a*b); break;
        case '/': printf("Resultado: %f ",a/b); break;
    }
}

int Ej06(){
    int a;
    printf("Introduzca a: "); scanf("%d",&a);
    switch (a) {
        case 1: printf("Lunes"      ); break;
        case 2: printf("Martes"     ); break;
        case 3: printf("Miercoles"  ); break;
        case 4: printf("Jueves"     ); break;
        case 5: printf("Viernes"    ); break;
        case 6: printf("Sabado"     ); break;
        case 7: printf("Domingo"    ); break;
    }
}

int Ej07(){
    int d,m,a;
    printf("Introduce el día : "); scanf("%d",&d);
    printf("Introduce el mes : "); scanf("%d",&m);
    printf("Introduce el anno: "); scanf("%d",&a);
    switch (m) {
        case  1:
        case  3:
        case  5:
        case  7:
        case  8:
        case 10:
        case 12:
            if(d<1 || d>31){
                printf("Fecha erronea.\n");
            }else{
                printf("Fecha correcta.\n");
            }
            break;
        case  4:
        case  6:
        case  9:
        case 11:
            if(d<1 || d>30){
                printf("Fecha erronea.\n");
            }else{
                printf("Fecha correcta.\n");
            }
            break;
        case 2:
            if(d<1){
                printf("Fecha erronea.\n");
            }else if(d%400==0 || (d%4==0 && d%100!=0)){
                if(d>29){
                    printf("Fecha erronea.\n");
                }else{
                    printf("Fecha correcta.\n");
                }
            }else{
                if(d>28){
                    printf("Fecha erronea.\n");
                }else{
                    printf("Fecha correcta.\n");
                }
            }
            break;
        default:
            printf("Fecha erronea .\n");
            break;
    }
    return 0;
}

int Ej08(){
    int h,m,s;
    printf("Introduzca la hora     : "); scanf("%f",&h);
    printf("Introduzca los minutos : "); scanf("%f",&m);
    printf("Introduzca los segundos: "); scanf("%f",&s);
    if( (h<0 || h>24) && (m<0 || m>59) && (m<0 || m>59) ){
        printf("Hora no valida.\n");
    }else{
        printf("Hora introducida: %d:%d:%d \n", h, m, s);
        s=s+1;
        if(s==60){
            s=0;
            m=m+1;
        }
        if(m==60){
            m=0;
            h=h+1;
        }
        if (h==24) {
            h=0;
        }
        printf("Hora 1 segundo despues: %d:%d:%d\n", h, m, s);
    }
}

int Ej09(){
    int a, b, c, cubo1, cubo2;
    printf("Introduzca a: "); scanf("%d",&a);
    printf("Introduzca b: "); scanf("%d",&b);
    printf("Introduzca c: "); scanf("%d",&c);
    if(a>b){
        if(b>c){
            cubo1=a*a*a;
            cubo2=b*b*b;
        }else{
            cubo1=a*a*a;
            cubo2=c*c*c;
        }
    }else{
        if(a>c){
            cubo1=b*b*b;
            cubo2=a*a*a;
        }else{
            cubo1=b*b*b;
            cubo2=c*c*c;
        }
    }
    printf("Cubo 1: %d\n", cubo1);
    printf("Cubo 2: %d\n", cubo2);
    return 0;
}

int Ej10(){
    for (size_t i = 0; i < 256; ++i) {
        printf("%d : %c \n", i, i);
    }
    return 0;
}

int Ej11(){
    int a,b;
    printf("Introduzca a: "); scanf("%d",&a);
    printf("Introduzca b: "); scanf("%d",&b);
    if (b<a) {
        int aux=a;
        a=b;
        b=aux;
    }
    for (size_t i = a; i <= b; ++i) {
        printf("%d\n", i);
    }
    return 0;
}

int Ej12(){
    int b, e;
    printf("Introduzca la base     : "); scanf("%d",&b);
    printf("Introduzca el exponente: "); scanf("%d",&e);
    int v=1;
    for (size_t i = 0; i < e; ++i){
        v=v*b;
    }
    printf("%d elevado a %d = %d \n", b, e, v);
    return 0;
}

int Ej13(){
    int n, fact=1;
    printf("Introduzca un entero : "); scanf("%d",&n);
    while (n>0){
        fact = fact*n;
        n = n-1;
    }
    printf("factorial del numero leido: %d",fact);
    return 0;
}

int Ej14(){
    int sum=0;
    for (size_t i = 0; i < 1001; i=i+2) {
        sum=sum+i;
    }
    printf("Suma de los pares: %d", sum/10);
    return 0;
}

int Ej15(){
    float sum=0,aux=0;
    for (size_t i = 0; i < 10; ++i) {
        printf("Introduzca un número: "); scanf("%f",&aux);
        sum=sum+aux;
    }
    printf("Media: %f", sum/10);
    return 0;
}

int Ej16(){
    for (size_t i = 1; i < 11; ++i) {
        printf("Tabla del %d \n",i);
        for (size_t j = 1; j < 11; ++j) {
            printf("%d x %d = %d \n", i, j, i*j);
        }
    }
    return 0;
}

int Ej17(){
    int n=-1, primo=1;
    while(n<0){
        printf("Introduzca un entero no negativo: "); scanf("%d",&n);
    }
    if (n==0 || n==1) {
        primo=0;
    }else{
        for (size_t i = 2; i <= sqrt(n) && primo; i++){
            if(n%i==0) {
                primo=0;
            }
        }
    }
    if (primo) {
        printf("%d es primo.\n",n);
    }else{
        printf("%d no es primo.\n",n);
    }
    return 0;
}

int Ej18(){
    int n=-1;
    while(n<0){
        printf("Introduzca un entero no negativo: "); scanf("%d",&n);
    }
    int a=0,b=1,aux;
    if (n==1) {
        printf("0\n");
    }else if(n==2){
        printf("0\n1\n");
    }else{
        for (size_t i = 0; i < n; i++) {
            printf("%d\n", a);
            aux=b;
            b=b+a;
            a=aux;
        }
    }
    return 0;
}

int Ej19(){
    int n=-1;
    while(n<0){
        printf("Introduzca un entero no negativo: "); scanf("%d",&n);
    }
    int a=0,b=1,aux;
    if (n==1) {
        printf("0\n");
    }else if(n==2){
        printf("1\n");
    }else{
        for (size_t i = 0; i < n; i++) {
            aux=b;
            b=b+a;
            a=aux;
        }
        printf("%d\n", a);
    }
    return 0;
}

int Ej20(){
    int a,b,aux;
    printf("Introduzca un entero: "); scanf("%d",&a);
    printf("Introduzca un entero: "); scanf("%d",&b);
    while(b){
        aux=a;
        a=b;
        b=aux%b;
    }
    printf("MCD: %d \n",a);
    return 0;
}

int Ej21(){
    int c;
    while ( (c = getchar()) != EOF){
        putchar(c);
    }
    return 0;
}

int Ej22(){
    int c;
    int n=0;
    int space=0;
    while ( (c = getchar()) != EOF){
        if( !( c==' ' && space) ){
            putchar(c);
            if (c==' ') {
                space=1;
            }else{
                space=0;
            }
        }
        n++;
    }
    printf("Numero de caracteres introducidos:%d",n);
    return 0;
}

int Ej23(){
    int c;
    int nc = 0;
    int npalabras = 0;
    int space = 0;
    int nlineas = 0;
    while ( (c = getchar()) != EOF){
        if(c=='\n'){
            nlineas++;
            space=1;
        }
        if(space==1 && c!=' ') {
            npalabras++;
        }
        if (c==' ') {
            space=1;
        }else{
            space=0;
        }
        nc++;
    }
    printf("Numero de caracteres introducidos: %d \n",nc);
    printf("Numero de lineas: %d \n",nlineas-1);//-1 es para no contar el EOF
    printf("Numero de npalabras: %d \n",npalabras-1);
    return 0;
}

int Ej24(){
    int primo;
    for (size_t i = 3; i <= 32767; i=i+2) {
        primo=1;
        for (size_t j = 2; j <= sqrt(i) && primo; j++){
            if(i%j==0) {
                primo=0;
            }
        }
        if (primo) {
            printf("%d es primo \n",i);
        }
    }
    return 0;
}


int esPrimo(int n){
    int primo = 1;
    if(n==2){ return 1; }
    if(n%2==0 || n<2){ return 0; }
    for(size_t i = 3; i <= sqrt(n) && primo; i++){
        if(n%i==0){
            primo=0;
        }
    }
    return primo;
}

int Ej25(){
    unsigned int n;
    printf("Introduzca un entero no negativo: "); scanf("%d",&n);
    while(n>1){
        for (size_t i = 2; i <= n; i++){
            if(esPrimo(i)) {
                if( n%i==0 ){
                    n=n/i;
                    printf("%d,%d\n", i,n);
                    i=2;
                }
            }
        }
    }
    return 0;
}

int main() {
    int i;
    i=3;
    while (0<i && i<26) { //16 ejercicios
        printf("\nSeleccione un ejercicio (1-25) o salir: "); scanf("%d",&i);
        switch(i){
            case  1: Ej01(); break;
            case  2: Ej02(); break;
            case  3: Ej03(); break;
            case  4: Ej04(); break;
            case  5: Ej05(); break;
            case  6: Ej06(); break;
            case  7: Ej07(); break;
            case  8: Ej08(); break;
            case  9: Ej09(); break;
            case 10: Ej10(); break;
            case 11: Ej11(); break;
            case 12: Ej12(); break;
            case 13: Ej13(); break;
            case 14: Ej14(); break;
            case 15: Ej15(); break;
            case 16: Ej16(); break;
            case 17: Ej17(); break;
            case 18: Ej18(); break;
            case 19: Ej19(); break;
            case 20: Ej20(); break;
            case 21: Ej21(); break;
            case 22: Ej22(); break;
            case 23: Ej23(); break;
            case 24: Ej24(); break;
            case 25: Ej25(); break;
        }
    }
    return 0;
}
