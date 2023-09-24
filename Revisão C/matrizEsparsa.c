#include <stdio.h>

#define MAXIMO 10

int matrizEhEsparsa(int matriz[][MAXIMO], int linhas, int colunas) {
    int total = linhas * colunas;
    int zeros = 0;

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            if (matriz[i][j] == 0) {
                zeros++;
            }
        }
    }

    float percZeros = (float)zeros / total;
    return percZeros > 0.7 ? 1 : 0;
}

int main() {
    int linhas, colunas;

    scanf("%d", &linhas);
    scanf("%d", &colunas);

    int matriz[MAXIMO][MAXIMO];

    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }

    int matrizEsp = matrizEhEsparsa(matriz, linhas, colunas);
    if (matrizEsp) {
        printf("A matriz é esparsa");
    } else {
        printf("A matriz não é esparsa");
    }

    return 0;
}