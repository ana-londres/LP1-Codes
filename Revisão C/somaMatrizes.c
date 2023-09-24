#include <stdio.h>

#define MAX_LINHAS 10
#define MAX_COLUNAS 10

void sumMatriz(int linhas, int colunas, int A[][MAX_COLUNAS], int B[][MAX_COLUNAS]) {
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            A[i][j] += B[i][j];
            printf("%d ", A[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int linhas, colunas;

    scanf("%d", &linhas);
    scanf("%d", &colunas);

    int matrizA[MAX_LINHAS][MAX_COLUNAS];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matrizA[i][j]);
        }
    }

    int matrizB[MAX_LINHAS][MAX_COLUNAS];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matrizB[i][j]);
        }
    }

    sumMatriz(linhas, colunas, matrizA, matrizB);

    return 0;
}