#include <stdio.h>
#include <math.h>

#define N_4 20
#define N_5 5
#define N_12 3

void print_menu() {
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
}

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

/* Ej03: Normalizar 20 números reales */
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

/* Ej04: Máximo de vector con punteros */
void leer_vector(int* vector) {
    for (int i = 0; i < N_5; i++) {
        printf("Elemento %d: ", i);
        scanf("%d", (vector + i));
    }
}
void maximo(int* vector, int* max) {
    *max = *vector;
    for (int i = 1; i < N_5; i++) {
        if (*(vector + i) > *max) {
            *max = *(vector + i);
        }
    }
}
int Ej04() {
    int v[N_5];
    int max;
    leer_vector(v);
    maximo(v, &max);
    printf("El valor máximo es: %d\n", max);
    return 0;
}

/* Ej05: Evaluación expresiones punteros */
int Ej05() {
    int vector[4] = { 1, 7, 3, 4 };
    printf("Expresión 1 (*vector + (*(vector + 1))) = %d\n", *vector + (*(vector + 1)));
    printf("Expresión 2 (*(vector + 3)) = %d\n", *(vector + 3));
    return 0;
}

/* Ej06: Búsqueda en vector */
int Ej06() {
    int vector[N_4];
    int valor, encontrado, pos, i;
    //Manual input
    /*
    printf("Introduce %d números enteros distintos:\n", N_4);
    for (i = 0; i < N_4; i++) {
        scanf("%d", &vector[i]);
    }
    */
	// Automatic input
    for (i = 0; i < N_4; i++) {
        vector[i] = i + 1;
    }

    do {
        printf("\nIntroduce un número a buscar (0 para salir): ");
        scanf("%d", &valor);
        if (valor == 0) break;
        encontrado = 0;
        for (i = 0; i < N_4; i++) {
            if (vector[i] == valor) {
                encontrado = 1;
                pos = i;
                break;
            }
        }
        if (encontrado) printf("El número %d está en la posición %d.\n", valor, pos);
        else printf("El número %d NO está contenido.\n", valor);
    } while (valor != 0);
    return 0;
}

/* Ej07: Producto escalar de dos vectores */
int Ej07() {
    int v1[3], v2[3];
    int producto_escalar = 0;
    printf("Introduce 3 componentes del vector 1:\n");
    for (int i = 0; i < 3; i++)
        scanf("%d", &v1[i]);
    printf("Introduce 3 componentes del vector 2:\n");
    for (int i = 0; i < 3; i++)
        scanf("%d", &v2[i]);
    for (int i = 0; i < 3; i++)
        producto_escalar += v1[i] * v2[i];
    printf("El producto escalar es: %d\n", producto_escalar);
    return 0;
}

/* Ej08: Desviación típica */
int Ej08() {
    float x[5], suma = 0, media, suma_cuadrados = 0;
    int i;
    printf("Introduce 5 números reales:\n");
    for (i = 0; i < 5; i++) {
        scanf("%f", &x[i]);
        suma += x[i];
    }
    media = suma / 5;
    for (i = 0; i < 5; i++) suma_cuadrados += pow(x[i] - media, 2);
    printf("La desviación típica es: %.4f\n", sqrt(suma_cuadrados / 5));
    return 0;
}

void print_matriz(int N, int M, float matriz[N][M]) {
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%6.1f ", matriz[i][j]);
		printf("\n");
	}
    printf("\n");
}

/* Ej09: Traspuesta de una matriz */
int Ej09() {
    float matriz[N_5][N_5], traspuesta[N_5][N_5];
    int i, j;
    
    printf("Introduce elementos de la matriz %dx%d:\n", N_5, N_5);
    for (i = 0; i < N_5; i++) {
        for (j = 0; j < N_5; j++) {
            //scanf("%f", &matriz[i][j]); // Manual input            
            matriz[i][j] = i * 3 + j + 1; // Automatic input
            traspuesta[j][i] = matriz[i][j];
        }
    }

    printf("\nMatriz Original:\n");
    print_matriz(N_5, N_5, matriz);

    printf("\nMatriz Traspuesta:\n");
    print_matriz(N_5, N_5, traspuesta);

    return 0;
}

/* Ej10: Multiplicación de matrices */
int Ej10() {
    float A[N_5][N_5], B[N_5][N_5], Producto[N_5][N_5] = { 0 };
    printf("Introduce matriz A (%dx%d):\n", N_5, N_5);
    for (int i = 0; i < N_5; i++) {
        for (int j = 0; j < N_5; j++) {
			// scanf("%f", &A[i][j]); // Manual input
			A[i][j] = i * 3 + j + 1; // Automatic input
        }
    }
    printf("Introduce matriz B (%dx%d):\n", N_5, N_5);
    for (int i = 0; i < N_5; i++) {
        for (int j = 0; j < N_5; j++) {
            // scanf("%f", &B[i][j]); // Manual input
			B[i][j] = i * 2 + j + 3; // Automatic input
        }
    }

    for (int i = 0; i < N_5; i++) {
        for (int j = 0; j < N_5; j++) {
            for (int k = 0; k < N_5; k++) {
                Producto[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    printf("\nMatriz Producto:\n");
    print_matriz(N_5, N_5, Producto);
    return 0;
}

/* Ej11: Copiar matriz cuadrada */
void Ej11_copiar_matriz(int N, int M, float origen[N][M], float destino[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            destino[i][j] = origen[i][j];
        }
    }
}

int Ej11() {
    float A[N_5][N_5];
    float B[N_5][N_5];
    for (int i = 0; i < N_5; i++) {
        for (int j = 0; j < N_5; j++) {
            // scanf("%f", &A[i][j]); // Manual input
            A[i][j] = i * 2 + j + 5; // Automatic input
        }
    }

    Ej11_copiar_matriz(N_5, N_5, A, B);
    printf("Matriz B copiada con éxito.\n");
    print_matriz(N_5, N_5, B);
    return 0;
}

/* Ej12: Comparar matrices iguales */
int Ej12_compara(int N, int M, float A[N][M], float B[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != B[i][j]) {
                return 0;
            }
        }
    }
    return 1;
}

int Ej12() {
    float A[N_12][N_12] = { {1,2,3},{4,5,6},{7,8,9} };
    float B[N_12][N_12] = { {1,2,3},{4,5,6},{7,8,9} };
	printf("\nComparando matrices A y B:\n");
    print_matriz(N_12, N_12, A);
    print_matriz(N_12, N_12, B);
    if (Ej12_compara(N_12, N_12, A, B))
        printf("Son iguales.\n");
    else 
        printf("Son distintas.\n");

    float C[N_12][N_12] = { {1,2,3},{4,5,6},{7,9,9} };
    printf("\nComparando matrices A y C:\n");
    print_matriz(N_12, N_12, A);
    print_matriz(N_12, N_12, C);
    if (Ej12_compara(N_12, N_12, A, C))
        printf("Son iguales.\n");
    else
        printf("Son distintas.\n");
    return 0;
}

/* Ej13: Comprobar matriz simétrica */
int Ej13_es_simetrica(int N, int M, float A[N][M]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (A[i][j] != A[j][i]) {
                return 0;
            }
        }
    }
    return 1;
}
int Ej13() {
    float A[N_12][N_12] = { {1,2,3},{2,5,6},{3,6,9} };
	printf("\nLa matriz A:\n");
	print_matriz(N_12, N_12, A);
    if (Ej13_es_simetrica(3, 3, A)) 
        printf("Es simétrica.\n");
    else 
        printf("No es simétrica.\n");

    float B[N_12][N_12] = { {1,3,3},{2,5,6},{3,6,9} };
    printf("\nLa matriz B:\n");
    print_matriz(N_12, N_12, B);
    if (Ej13_es_simetrica(3, 3, B))
        printf("Es simétrica.\n");
    else
        printf("No es simétrica.\n");

    return 0;
}

/* Ej14: Producto diagonal vs externo */
int Ej14() {
    float A[N_12][N_12];
    int encontrado = 0;
    int i, j, k, l;
    printf("Introduce matriz 3x3:\n");
    for (i = 0; i < N_12; i++){
        for (j = 0; j < N_12; j++) {
            //scanf("%f", &A[i][j]);
			A[i][j] = 1.0; // Automatic input meeting criteria
			A[i][j] = i * 2.0 + j + 5.0; // Automatic input  not meeting criteria
        }
    }
    printf("\nLa matriz introducida:\n");
	print_matriz(N_12, N_12, A);
    for (i = 0; i < N_12 && !encontrado; i++) {
        for (j = 0; j < N_12 && !encontrado; j++) {
            if (i != j) {
                float val = A[i][j];
                for (k = 0; k < N_12 && !encontrado; k++) {
                    for (l = 0; l < N_12 && !encontrado; l++) {
                        if (k != l && (k != i || l != j)) {
                            if (A[k][k] * A[l][l] == val) {
                                printf("¡Encontrado! A[%d][%d]*A[%d][%d] = A[%d][%d] (%.1f*%.1f=%.1f)\n", k, k, l, l, i, j, A[k][k], A[l][l], val);
                                encontrado = 1;
                            }
                        }
                    }
                }
            }
        }
    }
    
    if (!encontrado) 
        printf("No se cumple la condición.\n");

    return 0;
}


int main() {
    int opcion;

    do {
        print_menu();

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
/**
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