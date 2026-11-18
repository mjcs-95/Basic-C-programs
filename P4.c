#include <stdio.h>

#define N_4 20
/* Ej1: Inicializar y visualizar vector 10 enteros por funciones*/
int inicializar_vector(int v[], int n) {
    for (int i = 0; i < n; i++)
    {
        printf("Introduzca el valor del elemento %d: ", i);
        scanf("%d", &v[i]);
    }
}
void visualizar_vector(int v[], int n) {
    printf("\nElementos del vector:\n");
    for (int i = 0; i < n; i++)
    {
        printf("v[%d] = %d\n", i, v[i]);
    }
}

int Ej01() {
    const int N = 10;
    int v[N];
    inicializar_vector(v, N);
    visualizar_vector(v, N);
    return 0;
}

/* Ej2: Frecuencia elementos (1-10)*/
int Ej02() {
    int v[10];
    int frecuencia[10] = { 0 };
    printf("Introduce 10 enteros comprendidos entre 1 y 10:\n");
    for (int i = 0; i < 10; i++) {
        do {
            printf("Elemento %d: ", i + 1);
            scanf("%d", &v[i]);
        } while (v[i] < 1 || v[i] > 10);
        frecuencia[v[i] - 1]++;
    }
    printf("\nResultado:\n");
    for (int i = 0; i < 10; i++) {
        if (frecuencia[i] > 0) {
            printf("Existen %d elementos del número %d\n", frecuencia[i], i + 1);
        }
    }
    return 0;
}


void NormalizarVector(float vector[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        vector[i] = (vector[i] - min) / (max - min);
    }
}
void NormalizarVectorEnCopia(const float origen[], float destino[], int n, int min, int max) {
    for (int i = 0; i < n; i++) {
        destino[i] = (origen[i] - min) / (max - min);
    }
}

int Ej03() {

    float estadisticas[N_4] = { 0 };
    float estadisticas2[N_4] = { 0 };

    printf("Rellenando vector:\n");
    for (int i = 0; i < N_4; i++) {
        // scanf("%f", &estadisticas[i]);
        estadisticas[i] = i - 5;
    }

    float min = estadisticas[0];
    float max = estadisticas[0];

    for (int i = 1; i < N_4; i++) {
        if (min > estadisticas[i])
            min = estadisticas[i];
        if (max < estadisticas[i])
            max = estadisticas[i];
    }

    if (max != min)
    {
        NormalizarVectorEnCopia(estadisticas, estadisticas2, N_4, min, max);
        NormalizarVector(estadisticas, N_4, min, max);
    }

    printf("\nVector normalizado:\n");
    for (int i = 0; i < N_4; i++)
        printf("%.2f ", estadisticas[i]);

    printf("\nVector copia normalizado: \n");
    for (int i = 0; i < N_4; i++)
        printf("%.2f ", estadisticas2[i]);

    return 0;
}

int main() {
    int opcion;

    do {
        printf("\n==================================================\n");
        printf("        MENÚ GENERAL DE PRÁCTICAS (1 - 39)        \n");
        printf("==================================================\n");
        printf(" [1]  Vector de 10 enteros (func.)       [21] Inversa de cadena\n");
        printf(" [2]  Frecuencia elementos (1-10)        [22] Comprobar palíndromo\n");
        printf(" [3]  Normalizar 20 números reales       [23] Cadena numérica a entero\n");
        printf(" [4]  Máximo de vector con punteros      [24] Comprimir cadena\n");
        printf(" [5]  Evaluación expresiones punteros    [25] Primera posición coincidente\n");
        printf(" [6]  Búsqueda en vector (fin 0)         [26] Estructura persona y búsqueda\n");
        printf(" [7]  Producto escalar de vectores       [27] Estaciones meteorológicas\n");
        printf(" [8]  Desviación típica                  [28] Ventas de vendedores\n");
        printf(" [9]  Matriz traspuesta                  [29] Diccionario Inglés/Español\n");
        printf(" [10] Producto de matrices               [30] Alumnos y notas globales\n");
        printf(" [11] Copiar matriz cuadrada             [31] Control permanencia laboral\n");
        printf(" [12] Comparar matrices iguales          [32] Ventas diarias de empleados\n");
        printf(" [13] Comprobar matriz simétrica         [33] Fichero de texto (Menú)\n");
        printf(" [14] Producto diagonal vs externo       [34] Copiar fichero y contar chars\n");
        printf(" [15] Cuadrado latino de orden N         [35] Fichero binario con struct\n");
        printf(" [16] Longitud de cadena sin string.h    [36] Eliminar duplicados vector din.\n");
        printf(" [17] Concatenar cadenas sin string.h    [37] Añadir bit de paridad (par)\n");
        printf(" [18] Menú operaciones de cadenas        [38] Matriz dinámica (main)\n");
        printf(" [19] Contar carácter en cadena          [39] Matriz dinámica (funciones)\n");
        printf(" [20] Carácter más repetido              [ 0] Salir del programa\n");
        printf("--------------------------------------------------\n");
        printf("Seleccione una opción (0-39): ");

        if (scanf("%d", &opcion) != 1) {
            printf("\n[Error] Entrada no válida. Introduzca un número entero.\n");
            int c;
            while ((c = getchar()) != '\n' && c != EOF);
            opcion = -1;
            continue;
        }

        int c;
        while ((c = getchar()) != '\n' && c != EOF); // Limpiar buffer de entrada

        switch (opcion) {
        case 0:  printf("\n¡Hasta pronto!\n"); break;
        case 1:  Ej01(); break;
        case 2:  Ej02(); break;
        case 3:  Ej03(); break;
            /**
                    case 4:  Ej04(); break;
                    case 5:  Ej05(); break;
                    case 6:  Ej06(); break;
                    case 7:  Ej07(); break;
                    case 8:  Ej08(); break;
                    case 9:  Ej09(); break;
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
                    case 26: Ej26(); break;
                    case 27: Ej27(); break;
                    case 28: Ej28(); break;
                    case 29: Ej29(); break;
                    case 30: Ej30(); break;
                    case 31: Ej31(); break;
                    case 32: Ej32(); break;
                    case 33: Ej33(); break;
                    case 34: Ej34(); break;
                    case 35: Ej35(); break;
                    case 36: Ej36(); break;
                    case 37: Ej37(); break;
                    case 38: Ej38(); break;
                    case 39: Ej39(); break;
            /**/
        default: printf("\n[Aviso] Opción incorrecta (Elija entre 0 y 39).\n"); break;
        }

        if (opcion >= 1 && opcion <= 39) {
            printf("\nPresione [Enter] para volver al menú principal...");
            while ((c = getchar()) != '\n' && c != EOF);
        }

    } while (opcion != 0);

    return 0;
}